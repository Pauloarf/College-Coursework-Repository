#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char* argv[]) {
    int fd = open("fifo", O_WRONLY, 0600);
    if (fd == -1) {
        perror("error opening fifo");
        return -1;
    }
    printf("fifo open\n");

    char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
    ssize_t r;
    while ((r = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        write(fd, buffer, r);
    }

    close(fd);
    free(buffer);
    return 0;
}