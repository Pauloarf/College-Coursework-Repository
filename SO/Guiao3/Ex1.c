#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    
    //Este comando executa o comando ls
    execl("/usr/bin/ls", "ls","-l", NULL);

    // Este programa não executa por causa do execl...
    write(STDOUT_FILENO, "teste\n", 6);

}
