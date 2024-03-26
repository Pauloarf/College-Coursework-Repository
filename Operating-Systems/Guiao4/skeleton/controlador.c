#include <stdio.h>

#include "mysystem.h"

void controller(int N, char** commands) {
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            int res = 1;
            int counter = 0;
            while (res != 0) {
                res = mysystem(commands[i]);
                counter++;
            }
            _exit(counter);
        }
    }

    for (int i = 0; i < N; i++) {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("command %s was called %d\n", commands[i], WEXITSTATUS(status));
        } else {
            printf("error\n");
        }
    }
}

int main(int argc, char* argv[]) {
    char* commands[argc - 1];
    int N = 0;
    for (int i = 1; i < argc; i++) {
        commands[N] = strdup(argv[i]);
        printf("command[%d] = %s\n", N, commands[N]);
        N++;
    }

    controller(N, commands);

    return 0;
}