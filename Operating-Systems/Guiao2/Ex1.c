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
    printf("pid: %d", getpid());
    printf("ppid: %d", getppid());
    sleep(10); // tempo para verififar PID com ps -a noutro terminal
}