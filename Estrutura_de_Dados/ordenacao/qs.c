/*
  Atividade avaliativa - Algoritmos de ordenação - QuickSort
  Alunos: Gabriel Almeida Della Croce e André Campos Silva Junior
*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int vet[], int start, int end);
void testSort(int array[], int size);
void printvet(int vet[], int start, int end, int p_pivot, int i, int j);

int comps = 0;
int swaps = 0;

int main()
{
    int size = 8;

    system("clear");

    printf("Melhor Caso\n");
    int melhorCaso[] = {1, 2, 3, 4, 5, 6, 7, 8};
    testSort(melhorCaso, size);
    printf("\n=====================================================\n\n");

    printf("Caso medio\n");
    int piorCaso[] = {8, 7, 6, 5, 4, 3, 2, 1};
    testSort(piorCaso, size);
    printf("\n=====================================================\n\n");

    printf("Pior caso\n");
    int casoMedio[] = {4, 2, 8, 7, 1, 5, 3, 6};
    testSort(casoMedio, size);

    return 0;
}

void QuickSort(int vet[], int start, int end)
{
  if(start < end - 1)
  {
    int i = start, j = end - 1;
    int p_pivot = (start + end) / 2;
    int pivot = vet[p_pivot];
    int aux;

    printf("Comecando a ordenacao de %d a %d\n", start, end);
    printf("Pivot escolhido: \033[31mPosicao = %d | Valor|%d|\033[0m\n",p_pivot, pivot);
    printvet(vet, start, end, p_pivot, -1, -1);

    while(i <= j)
    {
      while((vet[i] < pivot) && (i < end))
      {
        i++;
        comps++;
      }
      comps++;

      while((vet[j] > pivot) && (j > start))
      {
        j--;
        comps++;
      }
      comps++;

      if(i <= j)
      {
        if(i != j)
        {
          printf("Vetor com I e J escolhidos: \n");
          printvet(vet, start, end, p_pivot, i, j);
          printf("Troca: \033[33m%d <-> %d\033[0m\n", vet[i], vet[j]);
          //printf("Troca: %d <-> %d\n", vet[i], vet[j]);
          swaps++;
        }
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
        printf("Vetor Pós troca: \n");
        printvet(vet, start, end, p_pivot, -1, -1);
        printf("\n");
      }
    }
    printf("Ordenacao de %d a %d terminada\n", start, end);
    QuickSort(vet, start, j + 1);
    QuickSort(vet, i, end);
  }
}

void testSort(int array[], int size)
{
    comps = 0;
    swaps = 0;

    printf("Vetor original:\n");
    printvet(array, 0, size, -1, -1, -1);
    printf("\n");

    QuickSort(array, 0, size);

    printf("Vetor ordenado:\n");
    printvet(array, 0, size, -1, -1, -1);

    printf("Total de comparações: %d\n", comps);
    printf("Total de trocas: %d\n", swaps);
}

void printvet(int vet[], int start, int end, int p_pivot, int i, int j)
{
  printf("[");
  for(int k = start; k < end; k++)
  {
    if(k == p_pivot)
    {
      if((p_pivot == i) || (p_pivot == j))
      {
        printf("\033[38;5;214m|%d|\033[0m ", vet[p_pivot]);
        continue;
      }
      printf("\033[31m|%d|\033[0m ", vet[k]);
      continue;
    }
    if (k == i)
    {
      printf("\033[33m|%d|\033[0m ", vet[k]);
      continue;
    }
    if (k == j)
    {
      printf("\033[33m|%d|\033[0m ", vet[k]);
      continue;
    }
    printf("%d ", vet[k]);
  }
  printf("\b]\n");
}
