#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "defs.h"

int main(int argc, char* argv[]) {
    // vetor
    MSG* msg = malloc(sizeof(MSG));
    msg->needle = 0;
    msg->occurrences = 0;
    msg->pid = 0;

    printf("Escolha o valor a procurar:\n");
    
    char numero[10];
    read(STDIN_FILENO, &numero, sizeof(char)*10);
    msg->needle = atoi(numero);

    int fd_server = open(SERVER, O_RDONLY, 0600);
    if (fd_server == -1) {
        perror("[Server] - Unable to open fifo_server");
        return -1;
    }
    printf("fifo_server open!\n");

    int fd_client = open(CLIENT, O_WRONLY, 0600);
    if (fd_client == -1) {
        perror("[Server] - Unable to open fifo_client");
        return -1;
    }
    printf("fifo_client open");

    write(fd_client, msg, sizeof(MSG));
    printf("msg enviada\n");

    read(fd_server, msg, sizeof(MSG));

    printf("O numero de ocorrencias foi %d, e o pid foi %d\n", msg->occurrences, msg->pid);

    return 0;
}