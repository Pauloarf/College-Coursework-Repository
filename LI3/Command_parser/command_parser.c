#include "command_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printInt(void *i)
{
    int *i_ = i;
    printf("%d", *i_);
}

void processCommand(Deque *deque, Cmd *cmd)
{
    if (strcmp(cmd->command, "PUSH") == 0 || strcmp(cmd->command, "PUSH_FRONT") == 0)
    {
        if (cmd->args != NULL)
        {
            char *args_copy = strdup(cmd->args); // Crie uma cópia dos argumentos para evitar modificar cmd->args
            char *args = args_copy;
            char *token = NULL;

            while ((token = strsep(&args, " ")) != NULL)
            {
                if (strlen(token) > 0)
                {
                    int *num = malloc(sizeof(int));
                    *num = atoi(token);
                    if (strcmp(cmd->command, "PUSH") == 0)
                    {
                        push(deque, num);
                    }
                    else if (strcmp(cmd->command, "PUSH_FRONT") == 0)
                    {
                        pushFront(deque, num);
                    }
                }
            }

            free(args_copy); // Libere a cópia dos argumentos
        }
    }
    else if (strcmp(cmd->command, "POP") == 0)
    {
        free(pop(deque));
    }
    else if (strcmp(cmd->command, "POP_FRONT") == 0)
    {
        free(popFront(deque));
    }
    else if (strcmp(cmd->command, "SIZE") == 0)
    {
        printf("Size of deque: %d\n\n", size(deque));
    }
    else if (strcmp(cmd->command, "REVERSE") == 0)
    {
        reverse(deque);
    }
    else if (strcmp(cmd->command, "PRINT") == 0)
    {
        printDeque(deque, &printInt);
        printf("\n");
    }
}

Cmd *parseLine(char *line)
{
    Cmd *cmd = malloc(sizeof(Cmd));
    cmd->nargs = 0;

    // Inicialize command e args como NULL
    cmd->command = NULL;
    cmd->args = NULL;

    char *token = strsep(&line, " ");
    while (token)
    {
        if (strlen(token) > 0)
        {
            cmd->nargs++;
            if (cmd->nargs == 1)
            {
                cmd->command = strdup(token);
            }
            else
            {
                // Concatene os argumentos com um espaço entre eles
                if (cmd->args == NULL)
                {
                    cmd->args = strdup(token);
                }
                else
                {
                    cmd->args = realloc(cmd->args, strlen(cmd->args) + strlen(token) + 2);
                    strcat(cmd->args, " ");
                    strcat(cmd->args, token);
                }
            }
        }
        token = strsep(&line, " ");
    }

    return cmd;
}
