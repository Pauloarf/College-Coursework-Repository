#include "node.h"
#include <stdlib.h>

Node* nodeCreate(void* data){
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

