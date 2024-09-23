#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int new_input_fd = open("etc/passwd", O_CREAT | O_RDONLY, 0600);
    if (new_input_fd == -1) {
        perror("Error opening passwd");
        return -1;
    }

    int new_output_fd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0600);
    if (new_output_fd == -1) {
        perror("Error opening saida");
        return -1;
    }

    int new_error_fd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0600);
    if (new_error_fd == -1) {
        perror("Error opening erros");
        return -1;
    }

    int in_fd = dup(STDIN_FILENO);
    int out_fd = dup(STDOUT_FILENO);
    int err_fd = dup(STDERR_FILENO);
    dup2(new_input_fd, STDIN_FILENO);
    dup2(new_output_fd, STDOUT_FILENO);
    dup2(new_error_fd, STDERR_FILENO);
    close(new_error_fd);
    close(new_input_fd);
    close(new_output_fd);

    pid_t pid;
    int status;
    // Codigo filho
    if ((pid = fork()) == 0) {
        write(STDOUT_FILENO, "[FILHO] - Hello World\n", 23);
        execlp("ls", "ls", NULL);
    }

    wait(&status);
    char buffer[100];
    if (WEXITSTATUS(status)) {
        snprintf(buffer, 100, "[PAI] - O filho terminou com status %d\n", WEXITSTATUS(status));
        write(out_fd, buffer, 100);
        perror("error");
        _exit(1);
    } else {
        write(out_fd, "[PAI] - ERROR NO STATUS DO FILHO\n", 34);
    }

    return 0;
}