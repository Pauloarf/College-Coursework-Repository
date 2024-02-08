#include <math.h>
#include <stdlib.h>
#include "utils.c"

// Exercise 1
void swapM(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

// Exercise 2
void swap(int v[], int i, int j)
{
    swapM(v + i, v + j); // v + i == &v[i]
}

// Exercise 3
int soma(int v[], int N)
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res += v[i];
    }
    return res;
}

// Exercise 4
void inverteArray1(int v[], int N)
{
    for (int i = 0; i < N / 2; i++)
    {
        swapM(v + i, v + (N - i - 1));
    }
}

void inverteArray2(int v[], int N)
{
    for (int i = 0; i < N / 2; i++)
    {
        swap(v, i, N - i - 1);
    }
}

// Exercise 5
int maximum(int v[], int N, int *m)
{
    for (int i = 0; i < N; i++)
    {
        if (*m < v[i])
            *m = v[i];
    }
    return 0;
}

// Exercise 6
void quadrados(int q[], int N)
{
    for (int i = 0; i < N; i++)
    {
        // q[i] = i*i;
        q[0] = 0;
        q[i] = q[i - 1] + (2 * (i - 1) + 1);
    }
}

// Exercise 7
void pascal(int v[], int N)
{
    for (int n = 0; n < N; n++)
    {
        v[n] = 1;
        for (int i = n - 1; i > 0; i--)
        {
            v[i] = v[i] + v[i - 1];
        }
    }
}

// Exercise 8
void pascal_n_lines(int N)
{
    for (int n = 0; n <= N; n++)
    {
        for (int k = 0; k <= n; k++)
        {                   
            int y = fact(n) / (fact(k) * fact(n - k));                          // Pascal function using combinations
            printf("%d ", y);                                                  // n! / k! * (n-k!)
        }
        printf("\n");
    }
}
