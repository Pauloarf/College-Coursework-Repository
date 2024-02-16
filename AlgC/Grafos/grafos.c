#include <stdio.h>
#include <stdlib.h>

#define NV 10

typedef struct aresta{
    int dest;
    int custo;
    struct aresta *prox;
} *LAdj, *GrafoL [NV];

typedef int GrafoM [NV][NV];

void fromMat(GrafoL in, GrafoL out){
    
}