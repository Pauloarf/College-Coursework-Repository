#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("pid=%d\n",getpid());
    printf("pai=%d\n",getppid());
    sleep(10); // tempo para verififar PID com ps -a noutro terminal
    return 0;
}