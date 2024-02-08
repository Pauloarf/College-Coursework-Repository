// Open adressing
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define FREE 0
#define USED 1
#define DEL 2

typedef struct bucket {
    int status;  // FREE, USED, DEL
    char *chave;
    int occor;
} THash[SIZE];

unsigned hash(char *str) {
    unsigned hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /*hash * 33 + c*/
    }

    return hash % SIZE;
}

// Probe functiom (if a colision happens, it calculates the new position to store the value)
int where(char *s, THash t) {
    int indice = hash(s), tmp;
    int count;

    for (count = SIZE;
         count > 0 && t[indice].status == USED && strcmp(t[indice].chave, s) != 0;
         count--)
        indice = (indice + 1) % SIZE;
    if (strcmp(t[indice].chave, s) != 0) {
        if (count == 0)
            indice = -1;  // HashTable is full
        else {
            tmp = indice;
            while (count > 0 && t[indice].status != FREE && strcmp(t[indice].chave, s) != 0) {
                count--;
                indice = (indice + 1) % SIZE;
            }
            if (strcmp(t[indice].chave, s) != 0) indice = tmp;
        }
    }
}

void initEmpty(THash t) {
    int i;

    for (i = 0; i < SIZE; t[i++].status = FREE, t[i].chave = NULL)
        ;
}

void add(char *s, THash t) {
    int indice = where(*s, t);

    if (indice < 0)
        ;
    else if (strcmp(t[indice].chave, s) == 0) {
        t[indice].status = USED;
        t[indice].occor++;
    } else {
        t[indice].status = USED;
        strcpy(t[indice].chave, s);
        t[indice].occor = 1;
    }
}

int lookup(char *s, THash t) {
    int indice = where(s, t);
    int found;

    if (indice >= 0 && strcmp(t[indice].chave, s) == 0 && t[indice].status == USED) {
        found = 1;
    } else
        found = 0;

    return found;
}

int remove(char *s, THash t) {
    int indice = where(s, t);
    int r = 0;

    if (indice > 0 && strcmp(t[indice].chave, s) == 0 && t[indice].status == USED && t[indice].occor > 1) {
        t[indice].occor--;
    }
    if (indice > 0 && strcmp(t[indice].chave, s) == 0 && t[indice].status == USED) {
        t[indice].occor--;
        t[indice].status = DEL;
    } else {
        r = 1;
    }
    return r;
}

// Analise a complexidade
int garb_collection(THash t) {
}