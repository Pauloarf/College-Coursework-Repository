#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

Deque *create()
{
    Deque *deque = malloc(sizeof(Deque));
    deque->size = 0;
    deque->top = 0;
    deque->bottom = 0;
    deque->reversed = false;
    return deque;
}

void push(Deque *deque, void *data)
{
    Node *newNode = createNode(data);
    newNode->prev = deque->bottom;
    if (deque->size != 0)
        (deque->bottom)->next = newNode;
    else
        deque->top = newNode;
    deque->bottom = newNode;
    deque->size++;
}

void pushFront(Deque *deque, void *data)
{
    Node *newNode = createNode(data);
    newNode->next = deque->top;
    if (deque->size != 0)
        (deque->top)->prev = newNode;
    else
        deque->bottom = newNode;
    deque->top = newNode;
    deque->size++;
}

void *pop(Deque *deque)
{
    if (deque->size == 0)
    {
        return 0;
    }
    Node *bottom = deque->bottom;
    deque->bottom = bottom->prev;
    if (deque->size == 1)
        deque->top = NULL;
    else
        deque->bottom->next = NULL;
    void *data = bottom->data;
    free(bottom);
    deque->size--;
    return data;
}

void *popFront(Deque *deque)
{
    if (deque->size == 0)
    {
        return 0; // mesmo que NULL
    }
    Node *top = deque->top;
    deque->top = top->next;
    if (deque->size == 1)
        deque->bottom = NULL;
    else
        deque->top->prev = NULL;
    void *data = top->data;
    free(top);
    deque->size--;
    return data;
}

int size(Deque *deque)
{
    return deque->size;
}

bool isEmpty(Deque *deque)
{
    return (deque->size == 0);
}

void reverse(Deque *deque)
{
    Node *current = deque->top;
    while (current != NULL)
    {
        Node *next = current->next;

        current->next = current->prev;
        current->prev = next;

        current = next;
    }
    Node *temp = deque->top;
    deque->top = deque->bottom;
    deque->bottom = temp;
    if (deque->reversed == false)
        deque->reversed = true;
    else
        deque->reversed = false;
}

void printDeque(Deque *deque, void (*printFunc)(void *))
{
    Node *top = deque->top;
    while (top)
    {
        printFunc(top->data);
        printf(" <-> ");
        top = top->next;
    }
    printf("x\n");
}

void destroy(Deque *deque)
{
    Node *cur = deque->top;

    while (cur)
    {
        Node *n = cur;
        cur = n->next;
        free(n);
    }

    free(deque);
}