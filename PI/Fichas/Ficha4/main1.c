#include <stdio.h>

int isVocal(char a){
    if (a == 'a' ||a == 'e' ||a == 'i' ||a == 'o' ||a == 'u'
        ||a == 'A' ||a == 'E' ||a == 'I' ||a == 'O' ||a == 'U') return 1;
    else return 0;
}

// Exercise 1
int contaVogais (char *s) {
    int c;
    for(int i = 0; s[i] != '\0'; i++){
        if (isVocal(s[i])) c++;
    }
    return c;
}

// Exercise 2
int retiraVogaisRep (char *s){
    int c, i = 0;
    while(s[i] != '\0'){
        if(isVocal(s[i]) && s[i] == s[i-1]){
            int j = i;
            while(s[j] != '\0'){
                s[j] = s[j+1];
                j++;
            }
            c++;
            continue;
        }
        i++;
    }
    return c;
}

int duplicaVogais2 (char *s){
    int c, i = 0;
    char str[100];
    for(int j = 0; s[i] != '\0';j++, i++){
        str[j] = s[i];
        if(isVocal(s[i])){
            str[j+1] = s[i];
            j++;
            c++;
        }
    }
    for(int j = 0; j <= i+c; j++){
        s[j] = str[j]; 
    }
    return c;
}

// Exercise 3
int duplicaVogais (char *s){
    int c, i;
    int aux = 1;
    for(int i = 0; s[i] != '\0'; i++, aux++);
    for(int i = 0; s[i] != '\0'; i++){
        if(isVocal(s[i])){
            int size = aux;
            while(size >= i){
                s[size + 1] = s[size];
                size--;
            }
            i++;
            aux++;
            c++;
        }
    }
    return c;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
   
    printf ("\nFim dos testes\n");

    return 0;
}