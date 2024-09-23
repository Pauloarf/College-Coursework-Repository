#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

struct pt{
    float x;
    float y;
};
typedef struct pt ponto;

typedef struct {
    int tamanho;
    ponto pontos[max];
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
    extende(&l,a);
    extende(&l,b);
    printf("{%.1f,%.1f}\n", l.pontos[1].x, l.pontos[1].y);
    return 0;
}