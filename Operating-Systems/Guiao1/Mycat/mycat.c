#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // In case cat runs without file
    if (argc < 2) {
        char buffer[1024];
        ssize_t r;
        while ((r = read(STDIN_FILENO, buffer, 1)) != 0) {
            write(STDOUT_FILENO, buffer, r);
        }
        return 0;
        // In case cat runs with file
    } else {
        int fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
            return -1;
        }
        char buffer[1024];
        ssize_t r;
        while ((r = read(fd, buffer, 1)) != 0) {
            write(STDOUT_FILENO, buffer, r);
        }
        close(fd);
    }
    return 0;
}