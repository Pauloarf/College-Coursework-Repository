#include <stdio.h>
#include <unistd.h> //chamadas ao sistema
#include <fcntl.h> // O_WRONLY; O_CREATE ...
#include <sys/types.h> 
#include <sys/wait.h> 

int main(int argc, char *argv[]){
    pid_t pid;
    int i, status;

    if((pid = fork()) == 0)
    {  
        char * ls_argv[] = {"ls", NULL};
        //Este comando executa o comando ls
        execv("/usr/bin/ls", ls_argv);
        _exit(5);
    }
    if((pid = fork()) == 0)
    {  
        char * ls_argv[] = {"ps", NULL};
        //Este comando executa o comando ls
        execv("/usr/bin/ps", ls_argv);
        _exit(5);
    }
    if((pid = fork()) == 0)
    {  
        char * ls_argv[] = {"neofetch", NULL};
        //Este comando executa o comando ls
        execv("/usr/bin/neofetch", ls_argv);
        _exit(5);
    }
    i = 0;
    while(i < 3){
        if (wait(&status))
            {
                if (WIFEXITED(status))
                {
                    printf("exit value: %d\n", WEXITSTATUS(status));
                }
                else
                {
                    printf("bad exit\n");
                }
            }
        i++;
    }
    printf("pid: %d\n", getpid());
    printf("ppid: %d\n", getppid());
    return 0;
}