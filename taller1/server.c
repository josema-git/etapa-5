#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void error(const char *msg) { // manejo de errores
    perror(msg);
    exit(1);
}

void add_client(int client_socket) {
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (client_sockets[i] == 0) {
			client_sockets[i] = client_socket; // se busca un socket libre para agregar al cliente en ese socket
            client_count++;
			break;
		}
	}
}

void remove_client(int client_socket) {
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (client_sockets[i] == client_socket) {
			client_sockets[i] = 0; // se busca el socket del cliente a desconectar y se borra
            client_count--;
			break;
		}
	}
}

void send_to_all_clients(int sender_sock, const char *message) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_sock) {
            if (write(client_sockets[i], message, strlen(message)) < 0) { // se envia del servidor a todos los sockets que hay agregados, el mensaje del cliente que lo mando 
                perror("Error al enviar mensaje a cliente");
            }
        }
    }
}

void handle_client(int *newsockfd_ptr) {
    int newsockfd = *(int *)newsockfd_ptr; // se crea un nuevo socket para el nuevo cliente
    free(newsockfd_ptr);  // se libera el espacio del socket
    char buffer[BUFFER_SIZE]; // buffer para mensajes
    struct sockaddr cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    getpeername(newsockfd, &cli_addr, &cli_len); // se obtiene la direccion del cliente
    char ip[INET_ADDRSTRLEN];
    int n;

    printf("Cliente conectado e identificado como: %s\n", ip);

    add_client(newsockfd);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("Error al leer del socket");
        }
        if (n == 0) {
            break;
        }
        printf("Cliente %s: %s", ip, buffer);

        char message[BUFFER_SIZE + BUFFER_SIZE];
        snprintf(message, sizeof(message), "%s: %s", ip, buffer);
        send_to_all_clients(newsockfd, message);
    }

    close(newsockfd);
    remove_client(newsockfd);
    printf("Cliente desconectado: %s\n", ip);
}

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error al abrir el socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error al hacer bind");
    }

    listen(sockfd, MAX_CLIENTS );
    clilen = sizeof(cli_addr);

    printf("Servidor escuchando en el puerto: %d\n", PORT);

    bzero(client_sockets, sizeof(client_sockets));

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0 || client_count == MAX_CLIENTS) {
            error("Error al aceptar la conexión");
        }
        pthread_t thread;
        int *newsockfd_ptr = malloc(sizeof(int));
        *newsockfd_ptr = newsockfd;
        pthread_create(&thread, NULL, handle_client, newsockfd_ptr);
    }

    close(sockfd);
    return 0;
}
