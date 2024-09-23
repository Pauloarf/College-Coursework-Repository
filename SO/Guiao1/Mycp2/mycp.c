#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int from_fd = open(argv[1], O_RDONLY);
    if (from_fd < 0) {
        write(STDIN_FILENO, "Unable to open original file!\n", 31);
        return -1;
    }
    int to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (to_fd < 0) {
        write(STDIN_FILENO, "Unable to open copy file!\n", 26);
        return -1;
    }
    // Considerar usar malloc
    char buffer[1024];
    ssize_t r;

    while ((r = read(from_fd, buffer, 5)) != 0) {
        write(to_fd, buffer, r);
    };

    close(from_fd);
    close(to_fd);

    return 0;
}