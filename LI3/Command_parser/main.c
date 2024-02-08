#include "command_parser.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    if (argc < 2)
    {
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

    Deque *deque = create();

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1)
    {
        Cmd *cmd = parseLine(line);
        processCommand(deque, cmd);

        // Libere a memória alocada para o comando
        free(cmd->command);
        free(cmd->args);
        free(cmd);
    }

    free(line);
    fclose(fp);

    // Libere a memória da deque e dos elementos restantes
    while (!isEmpty(deque))
    {
        free(pop(deque));
    }
    destroy(deque);

    return 0;
}