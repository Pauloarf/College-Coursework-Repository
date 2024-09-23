#include <stdio.h>
#include <string.h>

int isVocal(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}

// Exercise 1
int contaVogais(char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isVocal(s[i]))
            count++;
    }
    return count;
}

// Exercise 2
int retiraVogaisRep(char *s)
{
    char arrAux[100] = {};
    int res = 0, i, k;
    for (i = 0, k = 0; s[i] != '\0'; i++)
    {
        if (isVocal(s[i]) && s[i] == s[i + 1])
        {
            res++;
            continue;
        }
        arrAux[k] = s[i];
        k++;
    }
    strcpy(s, arrAux);
    return res;
}