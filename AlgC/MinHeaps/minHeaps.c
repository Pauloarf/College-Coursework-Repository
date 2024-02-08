#include "stdio.h"

#define Max 100

typedef struct pQueue {
    int valores[Max];
    int tamanho;
} PriorityQueue;

void swap(int h[], int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}

/*
Note-se que, no pior caso (o caso em que o elemento inserido é menor do que todos os
que lá estão), o número de iterações do ciclo acima está limitado por log2(N) (em que
N corresponde ao valor inicial de i): cada iteração do ciclo divide o valor de i por 2
*/
void bubble_up(int i, int h[]) {
    int p = (i - 1) / 2;
    while (i > 0 && h[i] < h[p]) {
        swap(h, i, p);
        i = p;
        p = (i - 1) / 2;
    }
}

/*
Mais uma vez podemos constatar que por cada iteração do ciclo o valor de i é multiplicado por 2, pelo que ao
fim de no máximo log2(N) iterações o ciclo terminará.
Usando estes dois procedimentos de manipulação de min-heaps estamos em condições
de apresentar as definições das funções de manipulação de filas com prioridades.
*/
void bubble_down(int i, int h[], int N) {
    int f = 2 * i + 1;
    while (f < N) {
        if (f + 1 < N && h[f + 1] < h[f])
            f = f + 1;
        if (h[f] > h[i]) break;
        swap(h, i, f);
        i = f;
        f = 2 * i + 1;
    }
}

void empty(PriorityQueue *q) {
    q->tamanho = 0;
}

int isEmpty(PriorityQueue *q) {
    return (q->tamanho == 0);
}

int add(int x, PriorityQueue *q) {
    int r = 0;
    if (q->tamanho == Max)
        r = 1;
    else {
        q->valores[q->tamanho] = x;
        bubble_up(q->tamanho, q->valores);
        q->tamanho++;
    }
    return r;
}

int remove_here(PriorityQueue *q, int *rem) {
    int r = 0;
    if (q->tamanho == 0)
        r = 1;
    else{
        *rem = q->valores[0];
        q->valores[0] = q->valores[--q->tamanho];
        bubble_down(0, q->valores, q->tamanho);
    }
    return r;
}

void heapify_up(int v[], int N){
    int i;
    for(i=1;i<N;i++){
        bubble_up(i,v);
    }
}

void heapify_down(int v[], int N){
    for (int i = (N / 2) - 1; i >= 0; i--) {
        bubble_down(i, v, N);
    }
} 

void ordena_heap(int h[], int N){
    while(--N > 0){
        swap(h,0,N);
        bubble_down(0,h,N);
    }
}

void print_priority_queue(PriorityQueue* q){
    printf("PriorityQueue: {");
    for(int i = 0; i < q->tamanho; i++){
        printf("%d; ",q->valores[i]);
    }
    printf("NULL");
    printf("}\n");
}

int main() {
    PriorityQueue test;
    test.tamanho = 0; 
    
    printf("Is Empty: %s\n", isEmpty(&test) ? "True" : "False");

    add(10, &test);
    add(12, &test);
    add(9, &test);
    add(42, &test);
    add(52, &test);

    printf("Is Empty: %s\n", isEmpty(&test) ? "True" : "False");

    print_priority_queue(&test);
    ordena_heap(test.valores, test.tamanho);
    print_priority_queue(&test);

    return 0;
}