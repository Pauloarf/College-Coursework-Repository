#include "mysystem.h"

#include <string.h>

// recebe um comando por argumento
// returna -1 se o fork falhar
// caso contrario retorna o valor do comando executado
int mysystem(const char* command) {
    int res = -1;
    char* command_dup = strdup(command);
    char* command_dup_start = command_dup;

    char** args = malloc(sizeof(char*) * 10);
    int n = 0;
    int size = 10;
    char* token;

    while ((token = strsep(&command_dup, " ")) != NULL) {
        args[n] = token;
        n++;
        if (n == size) {
            // realloc
        }
    }

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("failed to exec");
        _exit(127);
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            res = WEXITSTATUS(status);
        } else {
            printf("error\n");
        }
    }

    free(command_dup_start);
    free(args);
    return res;
}