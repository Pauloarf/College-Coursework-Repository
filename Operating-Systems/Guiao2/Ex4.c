#include <stdio.h>
#include <unistd.h> //chamadas ao sistema
#include <fcntl.h> // O_WRONLY; O_CREATE ...
#include <sys/types.h> 
#include <sys/wait.h> //chamadas wait e relacionadas


int main(int argc, char *argv[]){
    pid_t pid;
    int i, status;

    for(i = 0; i < 10; i++){
        if((pid = fork()) == 0)
        {
            // Código processo filho
            printf("child pid: %d\n", getpid());
            printf("child ppid: %d\n", getppid());
            sleep(2);
            _exit(0);
        }
    }
    i = 0;
    while(i < 10){
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