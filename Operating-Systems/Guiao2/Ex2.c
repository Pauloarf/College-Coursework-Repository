#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*
pid_t getpid(void);
pid_t getppid(void);
pid_t fork(void);
void _exit(int status);
pid_t wait(int *status);
pid_t waitPID(pid_t pid, int *status, int options);
int WIFEXITED(int status); macro
int WEXITSTATUS(int status); macro
*/

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;

    if ((pid = fork()) == 0)
    {
        // Código processo filho
        printf("child pid: %d\n", getpid());
        printf("child ppid: %d\n", getppid());
        _exit(0);
    }
    // Código preocesso pai
    printf("pid: %d\n", getpid());
    printf("ppid: %d\n", getppid());

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
    printf("parent is existing...\n");
    // sleep(10);
    return 0;
}