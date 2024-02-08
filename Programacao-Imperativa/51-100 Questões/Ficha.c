#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura necessária a realização da ficha
typedef struct lligada
{
    int valor;
    struct lligada *prox;
} *LInt;

// Exercicios!!!

// Exercico 1
int lenght(LInt first)
{
    int result = 0;
    LInt temp = first;

    while (temp != NULL)
    {
        result++;
        temp = temp->prox;
    }
    return result;
}

// Exercicio 2
void freeL(LInt l)
{
    LInt atual = l;
    while (atual != NULL)
    {
        LInt proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

// Exercicio 3
void imprimeL(LInt l)
{
    LInt tmp = l;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->valor);
        tmp = tmp->prox;
    }
}

// Exercicio 4
LInt reverseL(LInt l)
{
    LInt prev = NULL;
    LInt current = l;
    LInt next = NULL;

    while (current != NULL)
    {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Exercicio 5
void insertOrd(LInt *l, int valor)
{
    LInt newLInt = malloc(sizeof(LInt));
    newLInt->valor = valor;
    newLInt->prox = NULL;

    if (*l == NULL || valor <= (*l)->valor)
    {
        newLInt->prox = *l;
        *l = newLInt;
    }
    else
    {
        LInt current = *l;

        while (current->prox != NULL && valor > current->prox->valor)
        {
            current = current->prox;
        }

        newLInt->prox = current->prox;
        current->prox = newLInt;
    }
}

// Exercicio 6
int removeOneOrd(LInt *l, int valor)
{
    LInt current = *l;
    LInt prev = NULL;

    while (current != NULL)
    {
        if (current->valor == valor)
        {
            if (prev == NULL)
            {
                *l = current->prox;
            }
            else
            {
                prev->prox = current->prox;
            }
            free(current);
            return 0;
        }
        prev = current;
        current = current->prox;
    }

    return 1;
}

// Exercicio 7
void merge(LInt *r, LInt a, LInt b)
{
    if (a == NULL)
    {
        *r = b;
        return;
    }
    if (b == NULL)
    {
        *r = a;
        return;
    }

    if (a->valor < b->valor)
    {
        *r = a;
        merge(&(a->prox), a->prox, b); // duvida
    }
    else
    {
        *r = b;
        merge(&(b->prox), a, b->prox);
    }
}

// Exercicio 8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx)
{
    LInt menor = NULL; // Lista para os elementos menores que x
    LInt maior = NULL; // Lista para os elementos maiores ou iguais a x
    LInt curr = l;     // Ponteiro auxiliar para percorrer a lista original

    while (curr != NULL)
    {
        if (curr->valor < x)
        {
            if (menor == NULL)
            {
                menor = curr;
                *mx = menor;
            }
            else
            {
                menor->prox = curr;
                menor = menor->prox;
            }
        }
        else
        {
            if (maior == NULL)
            {
                maior = curr;
                *Mx = maior;
            }
            else
            {
                maior->prox = curr;
                maior = maior->prox;
            }
        }

        curr = curr->prox;
    }

    if (menor != NULL)
    {
        menor->prox = NULL;
    }
    if (maior != NULL)
    {
        maior->prox = NULL;
    }
}

// Exercicio 9
LInt parteAmeio(LInt *l)
{
    LInt newList = NULL;
    LInt temp = *l;
    int tamanho = lenght(temp);

    if (tamanho > 1)
    {
        newList = *l;
        temp = newList;
    }
    for (int i = 0; i < tamanho / 2; i++)
    {
        *l = (*l)->prox;
    }
    while (temp != *l && temp->prox != *l)
    {
        temp = temp->prox;
    }
    temp->prox = NULL;
    return newList;
}

// Exercicio 10
int removeAll(LInt *l, int x)
{
    int result = 0;
    LInt prev = NULL;
    LInt current = *l;
    LInt next = NULL;

    while (current != NULL)
    {
        next = current->prox;

        if (current->valor == x)
        {
            if (prev != NULL)
            {
                prev->prox = next;
            }
            else
            {
                *l = next; // Atualiza o início da lista
            }
            free(current);
            current = next;
            result++;
        }
        else
        {
            prev = current;
            current = next;
        }
    }

    return result;
}

// Exercicio 11
int removeDups(LInt *l)
{
    if (*l == NULL)
    {
        return 0; // Lista vazia, nenhum elemento para remover
    }

    int count = 0;     // Contador de elementos removidos
    LInt current = *l; // Nó atual

    while (current != NULL && current->prox != NULL)
    {
        LInt runner = current; // Nó para comparar com o nó atual
        while (runner->prox != NULL)
        {
            if (runner->prox->valor == current->valor)
            {
                LInt duplicate = runner->prox;
                runner->prox = runner->prox->prox;
                free(duplicate);
                count++;
            }
            else
            {
                runner = runner->prox;
            }
        }
        current = current->prox; // Avança para o próximo nó
    }
    return count;
}

// Exercicio 12
int removeMaiorL(LInt *l)
{
    int result = 0;
    LInt current = *l;
    LInt prev = NULL;

    if (current == NULL)
    {
        return result; // Lista vazia, nenhum elemento para remover
    }

    LInt maiorL = current;
    LInt prevMaiorL = NULL;

    while (current != NULL)
    {
        if (current->valor > maiorL->valor)
        {
            maiorL = current;
            prevMaiorL = prev;
        }
        prev = current;
        current = current->prox;
    }

    result = maiorL->valor;

    if (prevMaiorL != NULL)
    {
        prevMaiorL->prox = maiorL->prox;
    }
    else
    {
        *l = maiorL->prox;
    }

    free(maiorL);

    return result;
}

// Exercicio 13
void init(LInt *l)
{
    LInt current = *l;
    LInt prev = NULL;

    if (current->prox == NULL)
    {
        free(*l);
        *l = NULL;
        return;
    }
    while (current->prox != NULL)
    {
        prev = current;
        current = current->prox;
    }
    prev->prox = NULL;
    free(current);
}

// Exercice 14
void appendL(LInt *l, int valor)
{
    LInt current = *l;
    LInt newNode = malloc(sizeof(LInt));

    newNode->prox = NULL;
    newNode->valor = valor;

    if (current == NULL)
    {
        (*l) = newNode;
        return;
    }

    while (current->prox != NULL)
    {
        current = current->prox;
    }

    current->prox = newNode;
}

// Exercise 15
void concatL(LInt *a, LInt b)
{
    LInt current = *a;

    if (*a == NULL)
    {
        *a = b;
        return;
    }
    while (current->prox != NULL)
    {
        current = current->prox;
    }
    current->prox = b;
}

// Exercicio 16
LInt cloneL(LInt head)
{
    if (head == NULL)
    {
        return NULL; // Lista vazia, retorna uma nova lista vazia
    }

    LInt newHead = malloc(sizeof(struct lligada));
    newHead->valor = head->valor;
    newHead->prox = NULL;

    LInt current = head->prox;
    LInt newCurrent = newHead;

    while (current != NULL)
    {
        LInt newNode = malloc(sizeof(struct lligada));
        newNode->valor = current->valor;
        newNode->prox = NULL;

        newCurrent->prox = newNode;
        newCurrent = newCurrent->prox;

        current = current->prox;
    }

    return newHead;
}

// Exercicio 17
LInt cloneRev(LInt l)
{
    return reverseL(cloneL(l));
}

// Exercicio 18
int maximo(LInt l)
{
    LInt current = l;

    int resultado = current->valor;

    while (current != NULL)
    {
        if (current->valor > resultado)
        {
            resultado = current->valor;
        }
        current = current->prox;
    }

    return resultado;
}

// Exercicio 19
int take(int n, LInt *l)
{
    int result = 0;
    LInt current = *l;
    LInt prev = NULL;

    for (result = 0; result < n && current != NULL; result++)
    {
        prev = current;
        current = current->prox;
    }

    if (prev == NULL)
    {
        while (current != NULL)
        {
            LInt next = current->prox;
            free(current);
            current = next;
        }
        *l = NULL;
    }
    else
    {
        while (current != NULL)
        {
            LInt next = current->prox;
            free(current);
            current = next;
        }
        prev->prox = NULL;
    }

    return result;
}

// Exercico 20
int drop(int n, LInt *l)
{
    int result = 0;
    LInt current = *l;
    LInt prev = NULL;

    while (current != NULL && n > 0)
    {
        prev = current;
        current = current->prox;
        free(prev);
        prev = NULL;
        n--;
        result++;
    }

    (*l) = current;

    return result;
}

// Exercicio 21
LInt NForward(LInt l, int N)
{
    while (N > 0)
    {
        l = l->prox;
        N--;
    }
    return l;
}

// Exercicio 22
int listToArray(LInt l, int v[], int N)
{
    int result = 0, i = 0;
    LInt current = l;

    while (current != NULL && N > 0)
    {
        v[i] = current->valor;
        current = current->prox;
        i++;
        N--;
        result++;
    }

    return result;
}

// Exercicio 23
LInt arrayToList (int v[], int N){
   if(N == 0){
        return NULL;
    }
    int i = 0;
    LInt head = malloc(sizeof(LInt));
    head->valor = v[i];
    head->prox = NULL;

    LInt atual = head;

    for(i = 1; i < N; i++){
        LInt newNode = malloc(sizeof(LInt));
        newNode->valor = v[i];
        atual->prox = newNode;
        atual = newNode;
    }
    return head;
}

// Exercicio 24
LInt somasAcL(LInt l) {
    if (l == NULL) {
        return NULL;  // Lista vazia
    }
    
    LInt result = NULL;  // Lista resultante
    LInt curr = l;  // Cursor para percorrer a lista original
    LInt prev = NULL;  // Nó anterior na lista resultante
    
    int sum = 0;  // Soma acumulada
    
    while (curr != NULL) {
        sum += curr->valor;  // Acumula o valor atual
        
        LInt novo = malloc(sizeof(struct lligada));  // Cria um novo nó
        novo->valor = sum;  // Atribui a soma acumulada ao novo nó
        novo->prox = NULL;
        
        if (result == NULL) {
            result = novo;  // Primeiro nó da lista resultante
        } else {
            prev->prox = novo;  // Liga o novo nó ao nó anterior
        }
        
        prev = novo;  // Atualiza o nó anterior
        curr = curr->prox;  // Move para o próximo nó na lista original
    }
    
    return result;
}

// Exercicio 25
// Exercicio 26
// Exercicio 27
// Exercicio 28
// Exercicio 29
// Exercicio 30
// Exercicio 31
// Exercicio 32
// Exercicio 33
// Exercicio 34
// Exercicio 35
// Exercicio 36
// Exercicio 37
// Exercicio 38
// Exercicio 39
// Exercicio 40
// Exercicio 41
// Exercicio 42
// Exercicio 43
// Exercicio 44
// Exercicio 45
// Exercicio 46
// Exercicio 47
// Exercicio 48
// Exercicio 49
// Exercicio 50
// Exercicio 51

int main(int argc, char *argv[])
{
    /* A IMPLEMENTAR
    int opcao = 0;
    bool leave_loop = false;

    while (!leave_loop)
    {
        printf("Introduza o numero da questao que quer resolver(51-100): \n");
        printf("[0] - Sair!\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Ex1");
            printf("\n\n\n");
            break;
        case 2:
            printf("Ex2");
            printf("\n\n\n");
            break;
        case 3:
            printf("Ex3");
            printf("\n\n\n");
            break;
        case 0:
            printf("GoodBye!! ;)\n");
            leave_loop = true;
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    */

    return 0;
}