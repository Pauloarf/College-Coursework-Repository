#include "node.h"
#include <stdlib.h>

Node *createNode(void *data)
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}