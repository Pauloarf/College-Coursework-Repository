#include <stdio.h>
#include <stdlib.h>

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
}