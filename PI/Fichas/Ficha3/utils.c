#ifndef UTILS_H
#define UTILS_H

int fact(int n)
{
    int res = 1;
    if (n == 0)
        return res;
    while (n > 0)
    {
        res = res * n;
        n--;
    }
    return res;
}

void print_arr(int v[], int N)
{
    printf("Array content: ");
    putchar('[');
    for (int i = 0; i < N; i++)
    {
        printf("%d", v[i]);
        if (i < N - 1)
            putchar(',');
    }
    putchar(']');
    putchar('\n');
}

#endif
