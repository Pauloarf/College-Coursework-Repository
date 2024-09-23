#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 //Size of the array

/* This function reads the numbers from the input until you put 0*/
int read_n_numbers(int *v, int N){
    int i = 0, x;
    while(i < N){
        scanf("%d", &x);
        v[i] = x;
        if(x == 0) return 1;
        i++;
    }
    return 0;
}

/* This function prints the median value from the array*/
void print_media(int *v){
    int n = 0, x = 0;
    while (v[n] != 0){
        x += v[n];
        n++;
    }
    x /= n;
    printf("A media dos valores no array e: %d \n", x);
}

int main(){
    int v[SIZE];
    read_n_numbers(v,SIZE);
    print_media(v);
    return 0;
}