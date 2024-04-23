#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_SIZE 10

int main(int argc, char const *argv[]) {
    int pd[2];
    pipe(pd);

    if (!fork()) {
        // exec wc
        close(pd[1]);
        dup2(pd[0], 0);
        close(pd[0]);
        execlp("wc", "wc", "-l", NULL);
        perror("error executing wc");
        _exit(1);
    }

    // exec ls
    close(pd[0]);
    dup2(pd[1], 1);
    close(pd[1]);
    execlp("ls", "-ls", "/etc", NULL);
    perror("error");
    return 1;
}