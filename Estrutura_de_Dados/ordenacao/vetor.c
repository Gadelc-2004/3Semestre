#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vet[5];

  printf("0: ");
  scanf("%d", &vet[0]);
  printf("1: ");
  scanf("%d", &vet[1]);
  printf("2: ");
  scanf("%d", &vet[2]);
  printf("3: ");
  scanf("%d", &vet[3]);
  printf("4: ");
  scanf("%d", &vet[4]);

  printf("0 - %d, 1 - %d, 2 - %d, 3 - %d, 4 - %d\n\n", vet[0], vet[1], vet[2], vet[3], vet[4]);

  for(int i = 0; i < 5; i++)
  {
    printf("%d - %d,", i, vet[i]);
  }

  return 0;
}
