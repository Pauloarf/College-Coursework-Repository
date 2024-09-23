#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("failed to exec");
        _exit(1);
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("child exited!\n");
        } else {
            printf("error\n");
        }
    }
    return 0;
}