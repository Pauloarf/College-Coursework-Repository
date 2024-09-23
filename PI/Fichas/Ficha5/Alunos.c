#include "Alunos.h"

/* This function prints the content of an array*/
void dumpV(int v[], int N){
    int i;
    for ( i = 0; i < N; i++) printf ("%d ", v[i]);
    printf("\n");
}

//Exercise 1
int nota(Aluno a){
    float n = 0, m = 0;
    for(int i = 0; i < 6; i++){
        m += a.miniT[i];
    }
    m *= 10;
    m /= 6;
    n = (m * 0.25) + (a.teste * 0.75);
    return n;
}

/* This function prints the students*/
void imprimeAluno(Aluno *a){
    int i;
    int x = nota(*a);
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i = 1; i < 6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f (%d)\n", a->teste, x);
}

//Exercise 2
int procuraNum(int num, Aluno t[], int N){
    for(int i = 0; i < N; i++){
        if(num == t[i].numero) return i;
    }
    return -1;
}

//Exercise 3
void ordenaPorNum(Aluno t[], int N){
    int i, j;
    for(i = N; i > 0; i--){
        for(j = 0; j < i-1; j++){
           if(t[j].numero > t[j+1].numero){
            Aluno aux = t[j];
            t[j] = t[j+1];
            t[j+1] = aux;
            } 
        }
    }
}

//Exercise 4
void criaIndPorNum(Aluno t[], int N, int ind[]){
    for(int i = 0; i < N; i++){
        int aux = 0;
        for(int j = 0; j < N; j++){
            if(t[i].numero > t[j].numero) aux++;
        }
        ind[i] = aux;
    }
}

//Exercise 5
void imprimeTurmaInd(int ind[], Aluno t[], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == ind[j]) imprimeAluno(t + j);
        }
    }
}

//Exercise 6
int procuraNumInd(int num, int ind[], Aluno t[], int N){
    for(int i = 0; i < N; i++){
        int aux = ind[i];
        if(t[aux].numero == num) return aux;
    }
    return -1;
}

//Exercise 7
void criaIndPorNome(Aluno t[], int N, int ind[]){
    for(int i = 0; i < N; i++){
        int aux = 0;
        for(int j = 0; j < N; j++){
            if(t[i].nome[0] > t[j].nome[0]) aux++;  //Not working well if the 1's letter is the same :3
        }
        ind[i] = aux;
    }
}