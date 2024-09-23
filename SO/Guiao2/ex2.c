#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pid = fork();

    if (pid == 0) {
        printf("[filho] - pid=%d pai=%d\n", getpid(), getppid());
        _exit(0);
    } else {
        printf("[pai] - pid=%d pai=%d filho=%d\n", getpid(), getppid(), pid);
        int status;
        pid_t terminated = wait(&status);

        if (WIFEXITED(status)) {
            printf("[pai] - exit status filho=%d\n", WEXITSTATUS(status));
        } else {
            printf("[pai] - erro!!");
        }
    }
    printf("Done!!\n");
    return 0;
}