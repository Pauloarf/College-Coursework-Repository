#ifndef NODE_H
#define NODE_H

typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev;
} Node;

Node *createNode(void *data);

#endif