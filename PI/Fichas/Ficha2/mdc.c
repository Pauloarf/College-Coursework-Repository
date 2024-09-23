#include <stdio.h>
#include <math.h>

// Exercise 3
int mdc1(int a, int b)
{
    int c;
    if (a < b)
    {
        for (c = a; c > 0; c--)
        {
            if (a % c == 0 && b % c == 0)
                break;
        }
    }
    else
        for (c = b; c > 0; c--)
        {
            if (b % c == 0 && a % c == 0)
                break;
        }
    return c;
}

// Exercise 4.1
int mdc2(int a, int b)
{
    int c = 0;
    do
    {
        while (a <= b && a > 0)
            b -= a;
        while (b <= a && b > 0)
            a -= b;
    } while (b > 0 && a > 0);
    if (a == 0)
        c = b;
    else if (b == 0)
        c = a;
    return c;
}

// Exercise 4.2
int mdc3(int a, int b, int *count)
{
    int c = 0;
    do
    {
        while (a <= b && a > 0)
            b -= a, *count += 1;
        while (b <= a && b > 0)
            a -= b, *count += 1;
    } while (b > 0 && a > 0);
    if (a == 0)
        c = b;
    else if (b == 0)
        c = a;
    return c;
}

// Exercise 5
int mdc4(int a, int b, int *count)
{
    int c = 0;
    do
    {
        while (a <= b && a > 0)
            b %= a, *count += 1;
        while (b <= a && b > 0)
            a %= b, *count += 1;
    } while (b > 0 && a > 0);
    if (a == 0)
        c = b;
    else if (b == 0)
        c = a;
    return c;
}
