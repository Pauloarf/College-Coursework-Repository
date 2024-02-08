#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int to_fd, from_fd, erro_fd;

    from_fd = open("etc/passwd", O_RDONLY, 0666);
    to_fd = open("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0640);
    erro_fd = open("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0640);

    if(to_fd < 0){
        put("Unable to open input file! \n");
        return -1;
    }

    if(to_fd < 0){
        put("Unable to open out file! \n");
        return -1;
    }

    if(to_fd < 0){
        put("Unable to open error file! \n");
        return -1;
    }

    // 0 -> STDIN_FILENO
    // 1 -> STDOUT_FILENO
    // 2 -> STDERR_FILENO
    // 3 -> from_fd
    // 4 -> to_fd
    // 5 -> erro_fd

    if(dup2(from_fd,STDIN_FILENO) == -1){
        put("Unable to duplicate STDIN! \n");
        return -1;
    }

    // PARA NÃO PERDER O DESCRITOR DO OUTPUT PARA O TERMINAL
    int stdout_fd = dup(STDOUT_FILENO);

    // 0 -> from_fd
    // 1 -> STDOUT_FILENO
    // 2 -> STDERR_FILENO
    // 3 -> from_fd
    // 4 -> to_fd
    // 5 -> erro_fd
    // 6 -> stdout_fd

    if(dup2(to_fd,STDOUT_FILENO) == -1){
        put("Unable to duplicate STDOUT! \n");
        return -1;
    }

    if(dup2(erro_fd,STDERR_FILENO) == -1){
        put("Unable to duplicate STDERR! \n");
        return -1;
    }

    // 0 -> from_fd
    // 1 -> to_fd
    // 2 -> erro_fd
    // 3 -> from_fd
    // 4 -> to_fd
    // 5 -> erro_fd
    // 6 -> stdout_fd

    close(from_fd);
    close(to_fd);
    close(erro_fd);

    // 0 -> from_fd
    // 1 -> to_fd
    // 2 -> erro_fd
    // 3 -> [x]
    // 4 -> [x]
    // 5 -> [x]
    // 6 -> stdout_fd

    // A PARTIR DAQUI TEMOS O NOSSO AMBIENTE PREPARADO E PODEMOS EXECUTAR O CODIGO DO PROGRAMA
    int bytes_read = 0;
    char buffer[100];
    while ((bytes_read = read(STDIN_FILENO, buffer, 100)) > 0)
    {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // VOLTA A COLOCAR O STDOUT PARA O TERMINAL
    dup2(stdout_fd, STDOUT_FILENO);

    //FECHA O DESCRITOR QUE DUPLICAMOS
    close(stdout_fd);

    /// 0 -> from_fd
    // 1 -> stdout_fd
    // 2 -> erro_fd
    // 3 -> [x]
    // 4 -> [x]
    // 5 -> [x]
    // 6 -> [x]

    write(1, "Terminei!", 10);

    return 0;
}