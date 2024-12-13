#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define DIR_IP "192.168.1.166"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void *handleMessages(void *newsockfd_ptr){
    int newsockfd = *(int *)newsockfd_ptr;
    char buffer[BUFFER_SIZE];
    int n;

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("Error al leer del socket");
        }
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(DIR_IP);
    if (server == NULL || sockfd < 0) {
        fprintf(stderr, "Error, servidor no valido\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error al conectar");
    }

    pthread_t thread;
    pthread_create(&thread, NULL, handleMessages, &sockfd);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE - 1, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error al escribir en el socket");
        }
    }

    close(sockfd);
    return 0;
}
