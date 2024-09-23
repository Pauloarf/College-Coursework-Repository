#include "multInt.c"
#include "mdc.c"
#include "fib.c"

int main()
{
    int n, a, b, r1, r2, r3, r4,
        c1 = 0, c2 = 0;
    float f, f1, f2, f3;

    puts("Choose the exercise you want to test!\n");
    puts("1. Exercises regarding multiplication.");
    puts("2. Exercises regarding mdc.");
    puts("3. Exercises regarding the fibonacci sequence.\n");

    scanf("%d", &n);

    switch (n)
    {
    case 1:
        puts("\nChoose two numbers to use as input for the multiplication functions: ");
        scanf("%d", &a);
        scanf("%f", &f);
        f1 = multInt1(a, f);
        f2 = multInt2(a, f);
        f3 = multInt3(a, f, &c1);
        printf("\nResults: Ex1 - %.2f, Ex2.1 - %.2f, Ex2.2 - %.2f (%d)\n", f1, f2, f3, c1);
        break;
    case 2:
        puts("\nChoose two numbers to use as input for the mdc functions: ");
        scanf("%d", &a);
        scanf("%d", &b);

        r1 = mdc1(a, b);
        r2 = mdc2(a, b);
        r3 = mdc3(a, b, &c1);
        r4 = mdc4(a, b, &c2);
        printf("\nResults: %d, %d, %d (%d), %d (%d)\n", r1, r2, r3, c1, r4, c2);
        break;
    case 3:
        puts("\nChoose a number to use as input for the fibonacci functions: ");
        scanf("%d", &a);
        printf("\nFib (%d) = %d \n", a, fib(a));  // test with 45-46
        printf("\nFastFib (%d) = %d \n", a, fastfib(a));
        break;
    default:
        puts("\nInvalid number. Ending program...");
        break;
    }
    return 0;
}
