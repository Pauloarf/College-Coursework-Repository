#define MAX 100

typedef struct staticStack {
	int sp;
	int values[MAX];
}*SStack;

typedef struct staticQueue
{
    int front;
    int length;
    int values[MAX];
}*SQueue;
