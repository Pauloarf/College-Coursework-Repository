#include <stdio.h>
#include <stdlib.h>
#include "Dstructs.h"

/* This function prints the stack*/
void ShowDStack(DStack s){
    printf("%d Items: ", s->sp);
    for(int i = 0; i < s->sp; i++){
        printf("%d ", s->values[i]);
    }
    putchar('\n');
}

/* This function prints the queue*/
void ShowDQueue(DQueue q){
    printf("%d Items: ", q->length);
    for(int i = 0; i < q->length; i++){
        printf("%d ", q->values[i]);
    }
    putchar('\n');
}

/* This function allocates more memory for the stack */
int DupStack(DStack s){
    int r = 0;
    int *new = malloc(2 * s->size * sizeof(int));
    if(new == NULL) r = 1;
    else{
        for(int i = 0; i < s->size; i++) new[i] = s->values[i];
        free(s->values);
        s->values = new;
        s->size *= 2;
    }
    return r;
}

// Exercise 1
void DinitStack(DStack s){
    s->sp = 0;
    s->values = malloc(sizeof(int));
    s->size = 1;
}

// Exercise 2
int DisEmpty(DStack s){
    return(s->sp == 0);
}

// Exercise 3
int Dpush(DStack s, int x){
    int r;
    if(s->sp == s->size) r = DupStack(s);
    s->values[s->sp] = x;
    s->sp++;
    return r;
}

// Exercise 4
int Dpop(DStack s, int *x){
    int r = 0;
    if(s->sp == 0) r = 1;
    else {
        *x = s->values[s->sp - 1];
        s->sp--;
    }
    return r;
}

// Exercise 5
int Dtop (DStack s, int *x){
    int r = 0;
    if(s->sp == 0) r= 1;
    else {
        *x = s->values[s->sp - 1];
    }
    return r;
}

/* This function allocates more memory for the queue */
int dupQueue(DQueue q){
    int r = 0;
    int *new = malloc(2 * q->size * sizeof(int));
    if (new == NULL) r = 1;
    else {
        for(int i = 0; i < q->size; i++) new[i] = q->values[i];
        free(q->values);
        q->values = new;
        q->size *= 2;
    }
    return r;
}

// Exercise 6
void DinitQueue(DQueue q){
    q->length = 0;
    q->values = malloc(sizeof(int));
    q->size = 1;
}

// Exercise 7
int DisEmptyQ(DQueue q){
    return(q->length == 0);
}

// Exercise 8
int Denqueue(DQueue q, int x){
    int r;
    if(q->size == q->length) r = dupQueue(q);
    else{
        q->values[q->length] = x;
        q->length++;
    }
    return r;
}

// Exercise 9
int Ddequeue(DQueue q, int *x){
    int r = 0;
    if(q->length == 0) r = 1;
    else{
        *x = q->values[0];
        for(int i = 0; i < q->length; i++) q->values[i] = q->values[i+1];
        q->length--;
        q->front = q->values[0];
    }
    return r;
}

// Exercise 10
int Dfront(DQueue q, int *x){
    int r = 0;
    if(q->length == 0) r = 1;
    else{
        *x = q->values[0];
    }
    return r;
}