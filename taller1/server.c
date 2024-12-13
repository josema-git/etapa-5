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
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void add_client(int client_socket) {
	pthread_mutex_lock(&clients_mutex);
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (client_sockets[i] == 0) {
			client_sockets[i] = client_socket;
			break;
		}
	}
	pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int client_socket) {
	pthread_mutex_lock(&clients_mutex);
	for (int i = 0; i < MAX_CLIENTS; i++) {
		if (client_sockets[i] == client_socket) {
			client_sockets[i] = 0;
			break;
		}
	}
	pthread_mutex_unlock(&clients_mutex);
}

void send_to_all_clients(int sender_sock, const char *message) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_sock) {
            if (write(client_sockets[i], message, strlen(message)) < 0) {
                perror("Error al enviar mensaje a cliente");
            }
        }
    }
}

void *handle_client(void *newsockfd_ptr) {
    int newsockfd = *(int *)newsockfd_ptr;
    free(newsockfd_ptr);
    char buffer[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    int n;

    // Leer el nombre del cliente
    bzero(name, BUFFER_SIZE);
    n = read(newsockfd, name, BUFFER_SIZE - 1);
    if (n < 0) 
        error("Error al leer del socket");
    name[strcspn(name, "\n")] = 0;

    printf("Cliente conectado e identificado como: %s\n", name);

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
        printf("Cliente %s: %s", name, buffer);

        // Reenviar el mensaje a todos los clientes
        char message[BUFFER_SIZE + BUFFER_SIZE];
        snprintf(message, sizeof(message), "%s: %s", name, buffer);
        send_to_all_clients(newsockfd, message);
    }

    close(newsockfd);
    remove_client(newsockfd);
    printf("Cliente desconectado: %s\n", name);
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

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Servidor escuchando en el puerto: %d\n", PORT);

    // Inicializar la lista de sockets de clientes
    bzero(client_sockets, sizeof(client_sockets));

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Error al aceptar la conexión");
        }
        pthread_t thread;
        int *newsockfd_ptr = malloc(sizeof(int));
        *newsockfd_ptr = newsockfd;
        pthread_create(&thread, NULL, handle_client, newsockfd_ptr);
        pthread_detach(thread);
    }

    close(sockfd);
    return 0;
}
