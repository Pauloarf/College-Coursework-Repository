#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void libertaLista(Palavras l){
    Palavras aux;
    while(l != NULL){
        aux = l;
        l = l->prox;
        free(aux);
    } 
}

Lista quantasP(Palavras l){

}

void listaPal(Palavras l){
    Palavras aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        printf("Palavra: %s, occorencias: %d\n", aux->palavra, aux->ocorr);
    }
}

char *ultima (Palavras l){

}

Palavras acrescentaInicio(Palavras l, char *p){
    Palavras nova;
    nova = malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

Palavras acrescentaFim(Palavras l, char *p){

}

Palavras acrescenta(Palavras l, char *p){

}

struct celula *maisFreq(Palavras l){
    
}
