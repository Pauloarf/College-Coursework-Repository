#ifndef NODE_H
#define NODE_H

typedef struct node{
    void* data;
    struct node* next;
} Node;

// Cria um novo Node
Node* nodeCreate(void* data);

#endif

