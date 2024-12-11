/*
 faca um programa em c, em que o programa possua uma matriz do tipo char, 8x8, alocada dinamicamente.
 essa matriz deve ser preenchida de maneira que simule um tabuleiro de damas, depois de preenche-la, imprama ela na tela
*/
#include <stdio.h>
#include <stdlib.h>

void preenche_tab(char **A);
void print_matriz(char **A);

int main()
{
  char **Tabuleiro = (char **) malloc(8 * sizeof(char *));

  for(int i = 0; i < 8; i++)
  {
    Tabuleiro[i] = (char *) malloc(8 * sizeof(char));
  }

  preenche_tab(Tabuleiro);

  for(int i = 0; i < 8; i++)
  {
    free(Tabuleiro);
  }
  free(Tabuleiro);

  getchar();
  return 0;
}

void preenche_tab(char **A)
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if((i % 2 == 1 && j % 2 == 0) && (i % 2 == 0 && j % 2 == 1))
      {
        A[i][j] = ' ';
      }
      else
      {
        A[i][j] = '_';
      }
    }
  }

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(((i % 2 == 1 && j % 2 == 1) && (i % 2 == 0 && j % 2 == 0)))
      {
        A[i][j] = 'W';
      }
    }
  }

  for(int i = 5; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(((i % 2 == 0 && j % 2 == 0) && (i % 2 == 1 && j % 2 == 1))) 
      {
        A[j][i] = 'B';
      }
    }
  }
  print_matriz(A);
}

void print_matriz(char **A)
{
  system("clear");

  printf("\n\n\n");

  printf("     ");
  for(int i = 0; i < 8; i++)
  {
    printf("%5d", i);
  }

  printf("\n\n");

  for(int i = 0; i < 8; i++)
  {
    printf("%5d", i);
    for(int j = 0; j < 8; j++)
    {
      printf("%5c", A[i][j]);
    }
    printf("\n\n");
  }
}
