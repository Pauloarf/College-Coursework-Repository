#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (mkfifo("fifo", 0600) == -1) {
        perror("error creating fifo");
        return 1;
    }
    return 0;
}