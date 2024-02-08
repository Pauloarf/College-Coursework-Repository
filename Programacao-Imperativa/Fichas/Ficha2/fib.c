#include <stdio.h>
#include <math.h>

// Exercise 6 a)
int fib(int n)
{
    int f;
    if (n < 2)
        f = n;
    else
        f = fib(n - 1) + fib(n - 2);
    return f;
}

// Exercise 6 b)
int fastfib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
