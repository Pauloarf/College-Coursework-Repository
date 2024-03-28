#include "person.h"

typedef struct pessoas {
    char name[100];
    int age;
} Pessoa;

Pessoa* criaPessoa() {
    Pessoa* pessoa = malloc(sizeof(Pessoa));
    return pessoa;
}

char* getName(Pessoa *pessoa) {
    char* name_copy = malloc(strlen(pessoa->name) + 1);
    if (name_copy == NULL) {
        fprintf(stderr, "Memory allocation for name failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(name_copy, pessoa->name);  // Copy the name
    return name_copy;
}

void setName(Pessoa* pessoa, char* name) {
    strcpy(pessoa->name, name);
}

int getAge(Pessoa *pessoa) {
    return pessoa->age;
}

void setAge(Pessoa* pessoa, int age) {
    pessoa->age = age;
}

int getBytetSize() {
    return sizeof(Pessoa);
}

void freePessoa(Pessoa* pessoa) {
    free(pessoa);
}