#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void toUpperStr(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Missing filename.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        perror("Error");
        return 2;
    }

    char *line = NULL;
    __ssize_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaco para a string
    while ((read = getline(&line, &len, fp)) != -1)
    {
        toUpperStr(line); // Line contera a linha toda (incluindo o newline)
        printf("%s", line);
    }
    free(line); // E preciso libertar a memoria alocada

    fclose(fp);
    return 0;
}
