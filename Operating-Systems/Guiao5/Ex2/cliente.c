#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc < 1){
        printf("Not enough arguments!");
        return -1;
    }

    int fd = open("fifo", O_WRONLY);
    
    if(write(fd, argv[1], strlen(argv[1])) == -1);
    
    close(fd);

    return 0;
}

// argv < 1
//por acabar