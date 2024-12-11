/*
  Atividade avaliativa - Algoritmos de ordenação - QuickSort
  Alunos: Gabriel Almeida Della Croce e André Campos Junior
*/
#include <stdio.h>
#include <stdlib.h>

void printArray(int values[], int began, int end, int pivot_index);
void quicksort(int values[], int began, int end);
void testQuickSort(int array[], int size);

int comparisons = 0;
int swaps = 0;

int main()
{
    int size = 8;

    system("clear");

    printf("Melhor Caso\n");
    int melhorCaso[] = {1, 2, 3, 4, 5, 6, 7, 8};
    testQuickSort(melhorCaso, size);
    printf("\n=====================================================\n\n");

    printf("Pior Caso\n");
    int piorCaso[] = {8, 7, 6, 5, 4, 3, 2, 1};
    testQuickSort(piorCaso, size);
    printf("\n=====================================================\n\n");

    printf("Caso medio\n");
    int casoMedio[] = {4, 2, 8, 7, 1, 5, 3, 6};
    testQuickSort(casoMedio, size);

    return 0;
}

void printArray(int values[], int began, int end, int pivot_index)
{
  for(int i = began; i < end; i++)
  {
    if(i == pivot_index)
    {
      printf("\033[31m[%d]\033[0m ", values[i]);
      //printf("[%d] ", values[i]);
      continue;
    }
    printf("%d ", values[i]);
  }
  printf("\n");
}

void quicksort(int values[], int began, int end)
{
  if(began < end - 1)
  {
    int i = began, j = end - 1;
    int pivot_index = (began + end) / 2;
    int pivot = values[pivot_index];
    int aux;

    printf("Pivot escolhido: \033[31m[%d]\033[0m\n", pivot);
    printArray(values, began, end, pivot_index);

    while(i <= j)
    {
      while(values[i] < pivot)
      {
        i++;
        comparisons++;
      }
      comparisons++;

      while(values[j] > pivot)
      {
        j--;
        comparisons++;
      }
      comparisons++;

      if(i <= j)
      {
        if(i != j)
        {
          printf("Troca: \033[33m%d <-> %d\033[0m\n", values[i], values[j]);
          //printf("Troca: %d <-> %d\n", values[i], values[j]);
          swaps++;
        }
        aux = values[i];
        values[i] = values[j];
        values[j] = aux;
        i++;
        j--;
        printArray(values, began, end, pivot_index);
      }
    }
    quicksort(values, began, j + 1);
    quicksort(values, i, end);
  }
}

void testQuickSort(int array[], int size)
{
    comparisons = 0;
    swaps = 0;

    printf("Array original:\n");
    printArray(array, 0, size, -1);

    quicksort(array, 0, size);

    printf("Array ordenado:\n");
    printArray(array, 0, size, -1);

    printf("Total de comparações: %d\n", comparisons);
    printf("Total de trocas: %d\n", swaps);
}
