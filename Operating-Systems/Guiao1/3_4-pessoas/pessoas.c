#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "person.h"

int main(int argc, char* argv[]) {
    int fd;
    Pessoa* pessoa = criaPessoa();

    if (argc < 3) {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if (strcmp(argv[1], "-i") == 0) {
        fd = open("Registos", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

        if (fd == -1) {
            puts("ERROR - Couldn't open or create registry file.");
            return 1;
        }

        setName(pessoa, argv[2]);
        setAge(pessoa, atoi(argv[3]));

        if (write(fd, pessoa, getBytetSize()) < 1) {
            puts("ERROR - Couldn't write to registry file.");
            close(fd);
            return 1;
        }

        struct stat st;
        fstat(fd, &st);
        off_t filesize = st.st_size;
        int pos = (int)filesize / getBytetSize();

        printf("Insertion succccessful - registo %d\n", pos);

        close(fd);
    }

    if (strcmp(argv[1], "-l") == 0) {
        fd = open("Registos", O_RDONLY | S_IRUSR | S_IWUSR);

        if (fd == -1) {
            puts("ERROR - Couldn't open or create registry file.");
            return 1;
        }

        struct stat st;
        fstat(fd, &st);
        off_t filesize = st.st_size;
        int pos = (int)filesize / getBytetSize();

        for (int i = 0; i < atoi(argv[2]) && i < pos; i++) {
            read(fd, pessoa, getBytetSize());
            printf("Nome: %s\nIdade: %d\n\n", getName(pessoa), getAge(pessoa));
        }

        printf("Read succccessful\n");

        close(fd);
    }

    if (strcmp(argv[1], "-u") == 0) {
        fd = open("Registos", O_RDWR);
        if (fd == -1) {
            perror("open");
            return 1;
        }

        off_t pos = 0;
        while (read(fd, pessoa, getBytetSize()) == getBytetSize()) {
            if (strcmp(getName(pessoa), argv[2]) == 0) {
                setAge(pessoa, atoi(argv[3]));

                if (lseek(fd, pos, SEEK_SET) == -1) {
                    perror("lseek");
                    close(fd);
                    return 1;
                }

                if (write(fd, pessoa, getBytetSize()) != getBytetSize()) {
                    perror("write");
                    close(fd);
                    return 1;
                }

                printf("Age updated successfully for %s\n", getName(pessoa));
                close(fd);
                freePessoa(pessoa);
                return 0;
            }
            pos += getBytetSize();
        }

        printf("Person not found: %s\n", argv[2]);
        close(fd);
    }

    if (strcmp(argv[1], "-o") == 0) {
        fd = open("Registos", O_RDWR);
        if (fd == -1) {
            perror("open");
            return 1;
        }

        off_t pos = (atoi(argv[2]) - 1) * getBytetSize();

        if (lseek(fd, pos, SEEK_SET) == -1) {
            perror("lseek");
            close(fd);
            return 1;
        }

        if (read(fd, pessoa, getBytetSize()) != getBytetSize()) {
            perror("read");
            close(fd);
            return 1;
        }

        setAge(pessoa, atoi(argv[3]));

        if (lseek(fd, pos, SEEK_SET) == -1) {
            perror("lseek");
            close(fd);
            return 1;
        }

        if (write(fd, pessoa, getBytetSize()) != getBytetSize()) {
            perror("write");
            close(fd);
            return 1;
        }

        printf("Age updated successfully for %s\n", getName(pessoa));
        close(fd);
    }

    freePessoa(pessoa);
    return 0;
}
