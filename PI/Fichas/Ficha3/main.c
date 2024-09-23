#include <stdio.h>
#include "exercises.c"

#define ARRAY_SIZE 10

int main(int argc, char *argv[])
{
    int arr[ARRAY_SIZE] = {10, 30, 50, 70, 90, 100, 80, 60, 40, 20};
    int arr2[ARRAY_SIZE] = {};
    int x, y;
    int n;
    puts("Choose the exercise you want to execute:\n");
    puts("1. Exercise 2");
    puts("2. Exercise 3");
    puts("3. Exercise 4");
    puts("4. Exercise 5");
    puts("5. Exercise 6");
    puts("6. Exercise 7");
    puts("7. Exercise 8.1");
    puts("8. Exercise 8.2\n");

    scanf("%d", &n);

    switch (n)
    {
    case 1:
        puts("\nChoose two integers to be exchanged:");
        scanf("%d%d", &x, &y);
        printf("Before Swap: x=%d   y=%d\n", x, y);
        swapM(&x, &y);
        printf("After Swap: x=%d    y=%d", x, y);
        break;
    case 2:
        puts("\nThis is the preseted array:");
        print_arr(arr, ARRAY_SIZE);
        puts("Choose the index's for the numbers you want to exchange position:");
        scanf("%d%d", &x, &y);
        swap(arr, x, y);
        puts("New array:");
        print_arr(arr, ARRAY_SIZE);
        break;
    case 3:
        puts("\nThis is the preseted array:");
        print_arr(arr, ARRAY_SIZE);
        printf("The sum of all the elements in the array is: %d", soma(arr, ARRAY_SIZE));
        break;
    case 4:
        puts("\nThis is the preseted array:");
        print_arr(arr, ARRAY_SIZE);
        puts("Inverted array by swapM:");
        inverteArray1(arr, ARRAY_SIZE);
        print_arr(arr, ARRAY_SIZE);
        puts("Previus array inverted by swap:");
        inverteArray2(arr, ARRAY_SIZE);
        print_arr(arr, ARRAY_SIZE);
        break;
    case 5:
        puts("\nThis is the preseted array:");
        print_arr(arr, ARRAY_SIZE);
        maximum(arr, ARRAY_SIZE, &x);
        printf("The biggest value in the Array is %d", x);
        break;
    case 6:
        puts("\nThis is the preseted array:");
        print_arr(arr2, ARRAY_SIZE);
        quadrados(arr2, ARRAY_SIZE);
        puts("\nThis is the array after function quadrados:");
        print_arr(arr2, ARRAY_SIZE);
        break;
    case 7:
        puts("\nThis is the preseted array:");
        print_arr(arr2, ARRAY_SIZE);
        puts("\nChoose the n for the Pascal Line:");
        scanf("%d", &x);
        pascal(arr2, x);
        print_arr(arr2, ARRAY_SIZE);
        break;
    case 8:
        puts("\nChoose the n for the Pascal triangle:");
        scanf("%d", &x);
        pascal_n_lines(x);
        break;
    default:
        puts("\nInvalid number. Ending program...");
        break;
    }
}