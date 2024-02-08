#include "deque.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//==============
// Esta resolucao mostra como exemplo uma deque que guarda valores do tipo int.
//==============

/* Operations to test the deque */
typedef enum dequeOp
{
    PUSH,
    PUSH_FRONT,
    POP,
    POP_FRONT,
    REVERSE,
    SIZE,
    IS_EMPTY
} DequeOp;

/* Returns a random DequeOp */
DequeOp randomOp()
{
    return rand() % 7;
}

/* Allocates and returns a random integer between 0 and 99 */
int *randomInt()
{
    int *data = malloc(sizeof(int));
    *data = rand() % 100;
    return data;
}

/* Prints the value of an integer pointer */
void printInt(void *i)
{
    int *i_ = i;
    printf("%d", *i_);
}

/* Tests a deque of integers */
void testDeque(int nOps)
{
    /* initial deque with three random elements */
    Deque *deque = create();
    push(deque, randomInt());
    push(deque, randomInt());
    push(deque, randomInt());

    printf("Initial deque: ");
    printDeque(deque, &printInt);
    printf("\n");

    /* do nOps random operations on the deque */
    for (int i = 0; i < nOps; i++)
    {
        DequeOp op = randomOp();
        int *data = NULL;

        switch (op)
        {
        case PUSH:
            data = randomInt();
            printf("PUSH(%d) = ", *data);
            push(deque, data);
            break;

        case PUSH_FRONT:
            data = randomInt();
            printf("PUSH_FRONT(%d) = ", *data);
            pushFront(deque, data);
            break;

        case POP:
            printf("POP = ");
            data = pop(deque);
            if (data)
            {
                free(data);
            }
            break;

        case POP_FRONT:
            printf("POP_FRONT = ");
            data = popFront(deque);
            if (data)
            {
                free(data);
            }
            break;

        case REVERSE:
            printf("REVERSE = ");
            reverse(deque);
            break;

        case SIZE:
            printf("SIZE: %d ", size(deque));
            break;

        case IS_EMPTY:
            printf("IS_EMPTY: %d ", isEmpty(deque));
            break;
        }

        printDeque(deque, &printInt);
        printf("\n");
    }

    /* free any remaining elements */
    int *data = pop(deque);
    while (data)
    {
        free(data);
        data = pop(deque);
    }

    destroy(deque);
}

/* Main */
int main(int argc, char **argv)
{
    srand(time(NULL));
    puts("TESTING DEQUE\n");
    testDeque(20);

    return 0;
}
