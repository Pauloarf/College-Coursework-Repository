#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    // criar pipe
    // criar processo filho

    // pai: fechar pipe[0]; ler do stdin e escreve no pipe[1];

    // filho: fechar pipe[1]; redirecionar STDIN -> pipe[0]; exec wc

    int pipe_fd[2];
    pipe(pipe_fd);

    if (fork() == 0)
    {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        execlp("wc", "wc", NULL);
    }
    else
    {
        close(pipe_fd[0]);
    }

    //codigo

    close(pipe_fd[1]);
    wait(NULL);

    return 0;
}