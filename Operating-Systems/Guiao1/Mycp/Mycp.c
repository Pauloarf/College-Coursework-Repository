#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O-* */

int mycp(char const *from_path, char const *to_path)
{
    int from_fd = open(from_path, O_RDONLY);
    if (from_fd < 0)
    {
        printf("Unable to open file");
        return -1;
    }
    int to_fd = open(to_path, O_CREAT | O_TRUNC | O_WRONLY, 0640);
    if (to_fd < 0)
    {
        printf("Unable to open file");
        return -1;
    }
    int read_bytes = 0;

    char buffer[20];

    while ((read_bytes = read(from_fd, buffer, 20)) > 0)
    {
        write(to_fd, buffer, read_bytes);
    }

    close(from_fd);

    close(to_fd);

    return 0;
}

int main(int argc, char const *argv[])
{
    mycp(argv[1], argv[2]);
}
