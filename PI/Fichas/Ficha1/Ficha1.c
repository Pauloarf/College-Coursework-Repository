#include <stdio.h>
#include <stdlib.h>
#include "horizontal.c"
#include "vertical.c"

// Answers for sheet 1 (PI). Ano 2021/2022. Universidade do minho.

// Exercise 1 (Making a # (char) square!)
void ex1(int n)
{
  for (int l = 0; l < n; l++)
  {
    for (int m = n; m > 0; m--)
      putchar('#');
    putchar('\n');
  }
}

// Exercise 2 (Making a square that changes between # (char) and _ (char)!) (Chess board)
void ex2(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if ((i + j) % 2 == 0)
        putchar('#');
      else
        putchar('_');
    }
    putchar('\n');
  }
}

// Exercise 4 (Making a # (char) circle!)
void circulo(int n)
{
  for (int i = 0; i <= 2 * n; i++)
  {
    for (int j = 0; j <= 2 * n; j++)
    {
      if (((j - n) * (j - n) + (i - n) * (i - n)) <= n * n) // y^2 + x^2 <= radius^2
        putchar('#');
      else
        putchar(' ');
    }
    putchar('\n');
  }
}

int main(int arc, char *argv[])
{
  int n;
  int ex_variable;
  puts("Choose the exercise you want to test!\n");
  puts("1. Exercise 1");
  puts("2. Exercise 2");
  puts("3. Exercise 3.1");
  puts("4. Exercise 3.2");
  puts("5. Exercise 4\n");

  scanf("%d", &n);

  switch (n)
  {
  case 1:
    puts("\nExercise 1 - Choose the square's width:");
    scanf("%d", &ex_variable);
    ex1(ex_variable);
    break;
  case 2:
    puts("\nExercise 2 - Choose the chess's board width:");
    scanf("%d", &ex_variable);
    ex2(ex_variable);
    break;
  case 3:
    puts("\nExercise 3.1 - Choose the height of the triangle(Vertical):");
    scanf("%d", &ex_variable);
    triangulo_vertical(ex_variable);
    break;
  case 4:
    puts("\nExercise 3.2 - Choose the height of the triangle(Horizontal):");
    scanf("%d", &ex_variable);
    triangulo_horizontal(ex_variable);
    break;
  case 5:
    puts("\nExercise 4 - Choose the circle radius:");
    scanf("%d", &ex_variable);
    circulo(ex_variable);
    break;
  default:
    puts("\nInvalid number. Ending program...");
    break;
  }
  return 0;
}