//Close Adressing
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct nodo {
    char *chave;
    int ocorr;
    struct nodo *prox;
} Nodo, *THash[SIZE];

unsigned hash(char *str) {
    unsigned hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /*hash * 33 + c*/
    }

    return hash%SIZE;
}

void initEmpty(THash t) {
    int i;

    for (i = 0; i < SIZE; t[i++] = NULL)
        ;
}

void add(char *s, THash t) {
    int indice = hash(s);
    int new;
    Nodo *iter;
    for (iter = t[indice]; iter != NULL && (strcmp(s, iter->chave) != 0); iter = iter->prox)
        ;
    if (iter != NULL) {
        iter->ocorr++;
        new = 0;
    } else {
        iter = (Nodo *)malloc(sizeof(Nodo));
        if (iter == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        iter->chave = malloc(strlen(s) + 1);
        if (iter->chave == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(iter->chave, s);
        iter->ocorr = 1;
        iter->prox = t[indice];
        t[indice] = iter;
        new = 1;
    }
    return new;
}

int lookup(char *s, THash t) {
    int indice = hash(s);
    Nodo *iter;

    for (iter = t[indice]; iter != NULL && strcmp(s, iter->chave) != 0; iter = iter->prox);

    if (iter != NULL) {
        return iter->ocorr;
    } else {
        return 0;
    }
}

int remove(char *s, THash t){
    int indice = hash(s);
    Nodo **iter, *tmp;

    for(*iter = t+indice; *iter != NULL && strcmp((*(iter))->chave,s) != 0; iter=&((*iter)->prox));

    if(*iter!=NULL && (*iter)->ocorr > 1){
        return --(*iter)->ocorr;
    }
    if(*iter!=NULL){
        tmp = *iter;
        *iter = (*iter)->prox;
        free(tmp->chave);
        free(tmp);
        return 1;
    }
    return 0;
}