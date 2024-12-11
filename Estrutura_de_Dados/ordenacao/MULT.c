#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void printArray(int values[], int began, int end, int pivot_index) {
    for (int i = began; i < end; i++) {
        if (i == pivot_index) {
            printf("[%d] ", values[i]);
        } else {
            printf("%d ", values[i]);
        }
    }
    printf("\n");
}

void quicksort(int values[], int began, int end) {
    if (began < end - 1) {
        int i = began, j = end - 1;
        int pivot_index = (began + end) / 2;
        int pivot = values[pivot_index];
        int aux;

        printf("Pivot escolhido: %d\n", pivot);
        printArray(values, began, end, pivot_index);

        while (i <= j) {
            while (values[i] < pivot) {
                i++;
                comparisons++;
            }
            comparisons++;  // Contando a comparação que falhou no while
            
            while (values[j] > pivot) {
                j--;
                comparisons++;
            }
            comparisons++;  // Contando a comparação que falhou no while

            if (i <= j) {
                if (i != j) {
                    printf("Troca: %d <-> %d\n", values[i], values[j]);
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

void testQuickSort(int array[], int size) {
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

int main() {
    int escolha;

    printf("Escolha o tipo de teste para QuickSort:\n");
    printf("1. Melhor caso (array ordenado)\n");
    printf("2. Pior caso (array inversamente ordenado)\n");
    printf("3. Caso médio (array aleatório)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        int melhorCaso[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        testQuickSort(melhorCaso, 8);
    } else if (escolha == 2) {
        int piorCaso[8] = {8, 7, 6, 5, 4, 3, 2, 1};
        testQuickSort(piorCaso, 8);
    } else if (escolha == 3) {
        int casoMedio[8] = {4, 2, 8, 7, 1, 5, 3, 6};
        testQuickSort(casoMedio, 8);
    } else {
        printf("Escolha inválida!\n");
    }

    return 0;
}
