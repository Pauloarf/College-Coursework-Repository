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

    dup2(new_input_fd, STDIN_FILENO);
    dup2(new_output_fd, STDOUT_FILENO);
    dup2(new_error_fd, STDERR_FILENO);

    write(STDOUT_FILENO, "Terminei!", 10);

    close(new_error_fd);
    close(new_input_fd);
    close(new_output_fd);

    return 0;
}