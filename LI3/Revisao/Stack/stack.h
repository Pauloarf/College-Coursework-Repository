#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack{
    int size;
    Node* top;
    void (*elemPrint) (void *); //funcao para imprimir um elemento da stack
} Stack;

Stack* stackCreate(void (*elemPrint)(void *));
void stackPush(Stack* stack, void* data);
void* stackPop(Stack* stack);
void stackPrint(Stack* stack);

#endif