#include <stdio.h>

// Exercise 3 (Making a vertical # (char) triangle!)
void triangulo_horizontal(int n)
{
    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n - i; j++)
        {
            if (j <= i)
                putchar('#');
        }
        putchar('\n');
    }
}