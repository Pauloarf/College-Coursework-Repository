#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "defs.h"

void lookup_value(MSG* msg, int* vetor) {
    for (int i = 0; i < (sizeof(int) * sizeof(vetor)) - 1; i++) {
        if (vetor[i] == msg->needle) {
            msg->occurrences++;
            printf("encontrado\n");
        }
    }
    printf("valor calculado\n");
}

int main(int argc, char* argv[]) {
    // vetor
    int vetor[] = {1,
                   2,
                   3,
                   4,
                   5,
                   6,
                   6,
                   6,
                   7,
                   8,
                   9};

    // criar ficheiro de log
    int fd_log = open("log.log", O_CREAT, O_WRONLY, O_TRUNC);

    // Server fica responsavel pela inicialização dos fifos
    if (mkfifo("fifo_server", 0600) == -1) {
        perror("error creating fifo_server");
        return 1;
    }

    write(fd_log, "O fifo foi criado com sucesso", 30);

    if (mkfifo("fifo_client", 0600) == -1) {
        perror("error creating fifo_client");
        return 1;
    }

    int fd_server = open(SERVER, O_WRONLY, 0600);
    if (fd_server == -1) {
        perror("[Server] - Unable to open fifo_server");
        return -1;
    }
    printf("fifo_server open!\n");

    int fd_client = open(CLIENT, O_RDONLY, 0600);
    if (fd_client == -1) {
        perror("[Server] - Unable to open fifo_client");
        return -1;
    }
    printf("fifo_client open\n");

    MSG* msg = malloc(sizeof(MSG));
    read(fd_client, msg, sizeof(MSG));

    lookup_value(msg, vetor);

    msg->pid = getpid();

    write(fd_server, msg, sizeof(MSG));

    close(fd_client);
    close(fd_server);
    free(msg);

    return 0;
}