#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countWords(char *str)
{
    int count = 0;
    char *token = strsep(&str, " ");

    while (token)
    {
        if (strlen(token) > 0) // ignorar espacos consecutivos
        {
            count++;
        }
        token = strsep(&str, " "); // obter proximo token
    }

    return count;
}

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    if (argc < 2)
    { // se nao recebemos um ficheiro por argumento lemos do stdin (stdio.h)
        fp = stdin;
    }
    else
    {
        char *filename = argv[1];
        fp = fopen(filename, "r");
        if (!fp)
        {
            perror("Error");
            return 2;
        }
    }

    char *line = NULL;
    __ssize_t read;
    size_t len;
    int count = 0;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        line[read - 1] = '\0'; // ignorar new line (\n)
        count += countWords(line);
    }

    printf("%d\n", count);

    return 0;
}