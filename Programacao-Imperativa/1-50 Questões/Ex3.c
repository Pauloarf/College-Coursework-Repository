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

/* This function removes the highest value from an array and prints the second highest one*/
void print_second_max(int *v){
    int HIGHER = v[0];
    int n = 0, i = 0;
    for(; v[i] != 0; i++){
        if(v[i] > HIGHER) HIGHER = v[i], n = i;
    }
    while(n < i){
        v[n] = v[n+1];
        n++;
    }
    HIGHER = i = 0;
    for(; v[i] != 0; i++){
        if(v[i] > HIGHER) HIGHER = v[i], n = i;
    }
    printf("O segundo maior valor introduzido foi: %d \n", HIGHER);
}

int main(){
    int v[SIZE];
    read_n_numbers(v,SIZE);
    print_second_max(v);
    return 0;
}