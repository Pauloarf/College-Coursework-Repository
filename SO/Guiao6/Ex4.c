#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int pd[2];
    pipe(pd);

    if(fork() == 0){
        close(pd[1]);
        dup2(pd[0], STDIN_FILENO);
        close(pd[0]);

        execlp("wc", "wc", NULL);
        perror("error");
        _exit(1);
    }
    return 0;
}