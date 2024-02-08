#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //toupper

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

    char str[100];
    while (fgets(str, 100, fp))
    {
        toUpperStr(str);
        printf("%s", str);
    }

    fclose(fp);
    return 0;
}
