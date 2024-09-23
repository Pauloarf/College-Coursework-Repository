

typedef struct dinStack{
    int size;       // Guarda o tamanho do array values
    int sp;
    int *values;
}*DStack;

typedef struct dinQueue{
    int size;       // Guarda o tamanho do array values
    int front;
    int length;
    int *values;
}*DQueue;