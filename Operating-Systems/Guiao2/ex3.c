#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    int status;

    for (int i = 0; i < 10; i++) {
        if ((pid = fork()) == 0) {  // se for pai filho
            printf("[filho %d] - filho=%d pai=%d\n", i + 1, getpid(), getppid());
            _exit(i + 1);
        } else {
            wait(&status);
            if (WEXITSTATUS(status)) {
                printf("[Pai] - Filho terminou com status:  %d\n", WEXITSTATUS(status));
            } else {
                printf("[Pai] - Error\n");
            }
        }
    }

    return 0;
}