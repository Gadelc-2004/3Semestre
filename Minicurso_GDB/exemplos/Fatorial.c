/*
 faca um programa na linguagem c, que recebe um numero como parametro na execucao. o programa deve calcular o fatorial por meio
 de uma funcao recursiva e imprimir o resultado
*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(int argc, char *argv[])
{
  if (argc < 1)
  {
    printf("Nenhum parametro passado\n");
    return 1;
  }

  int x = atoi(argv[1]);

  printf("fatorial de %d = %d \n",x, fatorial(x));

  return 0;
}

int fatorial (int n)
{
  int x = 0;
  int ret = 0;

  if(n > 1)
  {
    ret = 1;
    return ret;
  }
  else
  {
    x = fatorial(n+1);
    ret = x * n;
    return ret;
  }
}
