#include <stdio.h>
#include <unistd.h> //chamadas ao sistema
#include <fcntl.h> // O_WRONLY; O_CREATE ...
#include <sys/types.h> 
#include <sys/wait.h> 

int main(int argc, char *argv[]){
    pid_t pid;
    if((pid = fork()) == 0)
    {
        char * ls_argv[] = {"ls","-l", NULL};
        //Este comando executa o comando ls
        execv("/usr/bin/ls", ls_argv);
        _exit(5);
    }

    printf("After fork:\n");
    int status;
    int terminated_pid = wait(&status);
    printf("Status: %d\n", WEXITSTATUS(status));
    printf("Child PID: %d\n", terminated_pid);

}
