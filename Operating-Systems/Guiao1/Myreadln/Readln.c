#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O-* */

ssize_t readln(int fd, char *line, size_t size)
{
    int i = 0;
    int bytes_read = 0;
    while (i < size - 1)
    {
        bytes_read = read(fd, &line[i], 1);
        if (bytes_read < 1)
            break;
        if (line[i++] == '\n')
            break;
    }
    line[i] = '\0'; // = 0 ??
    return i;
}

int main(int argc, char const *argv[])
{
    char buffer[100];
    int bytes_read = 0;

    int fd = open(argv[1], O_RDONLY);
    
    bytes_read = readln(fd, buffer, 100);
    write(STDOUT_FILENO, buffer, bytes_read);

    close(fd);
}
