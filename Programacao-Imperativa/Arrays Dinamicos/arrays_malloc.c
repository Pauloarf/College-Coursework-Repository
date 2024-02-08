#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min 1

typedef struct pt{
    float x;
    float y;
}ponto;
//typedef struct pt ponto;

typedef struct {
    int capacidade;
    int tamanho;
    ponto *pontos;
}poligonal;

int aloca_poligonal(poligonal *l){
    l->capacidade = min;
    l->tamanho = 0;
    l->pontos = malloc(l->capacidade * sizeof(ponto));
    if(l->pontos == NULL) return 1;
    return 0;
}

void liberta(poligonal *l){
    free(l->pontos);
}

int extende(poligonal *l, ponto p){
    if(l->tamanho == l->capacidade){
        ponto *new = malloc(2 * l->capacidade * sizeof(ponto));
        if(new == NULL) return 1;
        for(int i = 0; i < l->tamanho; i++) new[i] = l->pontos[i];
        free(l->pontos);
        l->pontos = new;
        l->capacidade *= 2;
    }
    l->pontos[l->tamanho] = p;
    l->tamanho++;
    return 0;
}

int main(){
    ponto a = {1,5}, b = {2,3}, c = {3,4};
    poligonal l;
    aloca_poligonal(&l);
    extende(&l,a);
    extende(&l,b);
    extende(&l,c);
    printf("{%.1f,%.1f}\n",l.pontos[1].x,l.pontos[1].y);
    liberta(&l);
    return 0;
}