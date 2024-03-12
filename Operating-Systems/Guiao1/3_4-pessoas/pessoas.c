#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "person.h"


int main(int argc, char* argv[]){

    int fd;
    Pessoa person;

    if ( argc < 3 )
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if ( strcmp(argv[1],"-i") == 0 )
    {
        fd = open("Registos", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
        
        if(fd == -1) {
            puts("ERROR - Couldn't open or create registry file.");
            return 1;
        }

        strcpy(person.name, argv[2]);
        person.age = atoi(argv[3]);

        if(write(fd, &person, sizeof(struct pessoas)) < 1) {
            puts("ERROR - Couldn't write to registry file.");
            close(fd);
            return 1;
        }

        //This little section gets the file size, and then divides it by the struct size, to get the number of people in the registry, aka, the index of the most recent entry.
        struct stat st;
        fstat(fd, &st);
        off_t filesize = st.st_size;
        int pos = (int)filesize / sizeof(struct pessoas);

        printf("Insertion succccessful - registo %d\n", pos);

        close(fd);
    }

    if ( strcmp(argv[1],"-l") == 0 )
    {
        // TO DO
    }

    if ( strcmp(argv[1],"-u") == 0 )
    {
        int fd = open("registo", O_RDWR);
        if(fd == -1) {
            puts("ERROR - Couldn't open registry file.");
            return 1;
        }

        int registry = -1;
        int i = 1;

        if(isdigit(*argv[2]))
            registry = atoi(argv[2]);

        while(read(fd, &person, sizeof(struct pessoas)) > 0) {
            if((registry == -1 && strcmp(person.name,argv[2]) == 0) || registry == i) {
                person.age = atoi(argv[3]);
                lseek(fd, - sizeof(struct pessoas), SEEK_CUR);
                if(write(fd, &person, sizeof(struct pessoas)) < 1) {
                    puts("ERROR - Couldn't write to registry file.");
                    close(fd);
                    return 1;
                }
                goto UPDATE_SUCCESS;
            }
            i++;
        }
        puts("ERROR - Registry entry not found");
        UPDATE_SUCCESS:
        close(fd);
    }

    if ( strcmp(argv[1],"-o") == 0 )
    {
        // TO DO
    }

    return 0;
}
