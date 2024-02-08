#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_ARG_SIZE 1024

int main(int argc, char *argv[]){
    mkfifo("fifo",0644);
    
    char buffer[MAX_ARG_SIZE];
    int bytes_read;

    int from_fd;
    if(from_fd = open("fifo", O_RDONLY) == -1){
        perror("open");
        return -1;
    } else {
        printf("[DEBUG] opened fifo for reading\n");
    }

    int logfile = open("log.txt", O_CREAT | O_TRUNC | O_WRONLY, 0640);
    if (logfile < 0)
    {
        printf("Unable to open log");
        return -1;
    }

    while((bytes_read = read(from_fd, buffer, MAX_ARG_SIZE)) > 0){
        write(logfile, buffer, bytes_read);
        buffer[bytes_read] = '\0';
    }

    return 0;
}

//por acabar