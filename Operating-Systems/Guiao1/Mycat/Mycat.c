#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>  /* O_RDONLY, O_WRONLY, O_CREAT, O-* */

int mycat()
{
    int bytes_read = 0;
    char buffer[100];
    while ((bytes_read = read(STDIN_FILENO, buffer, 100)) > 0)
    {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    mycat();
}
