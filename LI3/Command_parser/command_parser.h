#ifndef PARSER_H
#define PARSER_H

#include "../Guiao1_Exercicio/deque.h"

typedef struct cmd
{
    char *command;
    char *args;
    int nargs;
} Cmd;

void printInt(void *i);

void processCommand(Deque *deque, Cmd *cmd);

Cmd *parseLine(char *line);

#endif
