#include <stdio.h>
#include <stdlib.h>
#include "Sstructs.h"

/* This function prints the stack */
void printStack(SStack s){
    printf("%d Items: ", ((s->sp)+1));
    for(int i = 0; i <= s->sp; i++){
        printf("%d ", s->values[i]);
    }
    putchar('\n');
}

/* This function prints the queue */
void printQueue(SQueue q){
    printf("%d Items: ", (q->length));
    for(int i = 0; i < q->length; i++){
        printf("%d ", q->values[i]);
    }
    putchar('\n');
}

// Exercise 1
void SinitStack(SStack s){
    s->sp = -1;      
}

// Exercise 2
int SisEmpty(SStack s){
    return (s->sp == -1);
}

// Exercise 3
int Spush(SStack s, int x){
    int r = 0;
    if(s->sp < MAX - 1){
        s->sp++;
        s->values[s->sp] = x;
    }
    else r = 1;
    return r;
}

// Exercise 4
int Spop(SStack s, int *x){
    int r = 0;
    if(s->sp != -1){
        *x = s->values[s->sp];
        s->sp--;
    }
    else r = 1;
    return r;
}

// Exercise 5
int Stop(SStack s, int *x){
    int r = 0;
    if(s->sp != -1){
        *x = s->values[s->sp];
    }
    else r = 1;
    return r;
}

// Exercise 6
void SinitQueue(SQueue q){
    q->length = 0;
}

// Exercise 7
int SisEmptyQ(SQueue q){
    return (q->length == 0);
}

// Exercise 8
int Senqueue(SQueue q, int x){
    int r = 0;
    if(q->length == MAX) r = 1;
    else {
        q->values[q->length] = x;
        q->length++;
    }
    return r;
}

// Exercise 9
int Sdequeue(SQueue q, int *x){
    int r = 0;
    if(q->length != 0){
        *x = q->values[0];
        for(int i = 0; i < q->length; i++){
            q->values[i] = q->values[i+1];
        }
        q->length--;
        q->front = q->values[0];
    }
    else r = 1; 
    return r;
}

// Exercise 10
int Sfront(SQueue q, int *x){
    int r = 0;
    if(q->length != 0){
        *x = q->values[0];
    }
    else r = 1;
    return r;
}