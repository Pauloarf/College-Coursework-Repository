#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoas Pessoa;

Pessoa* criaPessoa();

/**
 * @brief Devolve o nome da pessoa, alocado na heap
 *
 * @param pessoa
 * @return char*
 */
char* getName(Pessoa *pessoa);

/**
 * @brief Devolve a idade da pessoa
 *
 * @param pessoa
 * @return int
 */
int getAge(Pessoa *pessoa);

void setName(Pessoa* pessoa, char* name);

void setAge(Pessoa* pessoa, int age);

int getBytetSize();

void freePessoa(Pessoa* pessoa);