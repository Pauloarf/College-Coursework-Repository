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

/* This function prints the highest value from an array*/
void print_max(int *v){
    int HIGHER = v[0];
    for(int i = 0; v[i] != 0; i++){
        if(v[i] > HIGHER) HIGHER = v[i];
    }
    printf("O maior valor introduzido foi: %d \n", HIGHER);
}

int main(){
    int v[SIZE];
    read_n_numbers(v,SIZE);
    print_max(v);
    return 0;
}