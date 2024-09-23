#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

typedef struct pt{
    float x;
    float y;
}ponto;
//typedef struct pt ponto;

typedef struct {
    int tamanho;
    ponto *pontos;
}poligonal;

int extende(poligonal *l, ponto p){
    if(l->tamanho == max) return 1;
    l->pontos[l->tamanho] = p;
    l->tamanho++;
    return 0;
}

int main(){
    ponto a = {1,5}, b = {2,3};
    poligonal l;
    l.tamanho = 0;
    l.pontos = malloc(sizeof(ponto)* max);
    extende(&l,a);
    extende(&l,b);
    printf("{%.1f,%.1f}\n", l.pontos[1].x, l.pontos[1].y);
    free(l.pontos);
    return 0;
}