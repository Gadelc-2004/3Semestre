#include <stdio.h>
#include <stdlib.h>

int range = 15;
int vet_size = 10;
int trades = 0, comps = 0;
void insertion_sort(int **veta);
void selection_sort(int **veta);
void print_vet(int *vet);
int menu();

int main()
{
  int a, b, *vet;

  vet = (int*)malloc(vet_size * sizeof(int));

  void(*sort[2])(int **veta);
  sort[0] = insertion_sort;
  sort[1] = selection_sort;

  void randomizer(int **veta)
  {
    int *vet = *veta;
    for(int i = 0; i < vet_size; i++)
    {
      vet[i] = rand() % range;
      if((rand() % 2) % 2 == 0)
      {
        vet[i] *= -1;
      }
    }
  }

  int choice;

  while((choice = menu()) != 0)
  {
    randomizer(&vet);
    system("clear");

    sort[choice - 1](&vet);

    printf("Vetor Final:\n");
    print_vet(vet);
    printf("\nElementos: %d\nComparacoes: %d\nTrocas: %d", vet_size, comps, trades);
    printf("\n\nAperte enter para continuar");
    getchar();
  }
  return 0;
}

void print_vet(int *vet)
{
  for(int i = 0; i < vet_size; i++)
  {
    printf("%d\t", vet[i]);
  }
  printf("\n");
  return;
}

void insertion_sort(int **veta)
{
  int *vet = *veta;
  int aux;
  trades = 0;
  comps = 0;

  printf("INSERTION SORT\n\nVetor Original:\n");
  print_vet(vet);

  for(int i = 1; i < vet_size; i++)
  {
    int pos = i;
    comps ++;
    while(vet[pos] < vet[(pos - 1)])
    {
      aux = vet[pos];
      vet[pos] = vet[(pos - 1)];
      vet[(pos - 1)] = aux;
      print_vet(vet);
      pos --;
      comps++;
      trades++;
    }
  }
}

void selection_sort(int **veta)
{
  int *vet = *veta;
  int aux, minor, mpos;
  trades = 0;
  comps = 0;

  printf("SELECTION SORT\n\nVetor Original:\n");
  print_vet(vet);

  for(int i = 0; i < (vet_size - 1); i++)
  {
    minor = vet[i];
    mpos = i;
    for(int j = i + 1; j < vet_size; j++)
    {
      comps ++;
      if(vet[j] < minor)
      {
        minor = vet[j];
        mpos = j;
      }
    }
    comps ++;
    if(vet[i] > minor)
    {
      aux = vet[i];
      vet[i] = vet[mpos];
      vet[mpos] = aux;
      trades ++;
    }
    print_vet(vet);
  }
  return;
}

int menu()
{
  system("clear");
  printf("|Programa de algoritimos de ordenação\n");
  printf("|------------------------------------\n");
  printf("|0 -> Sair do Programa\n");
  printf("|1 -> InsertinSort\n");
  printf("|2 -> SelectionSort\n");
  printf("Digite a opcao que deseja: ");
  int choice;
  scanf("%d", &choice);
  while(choice < 0 || choice > 2)
  {
    printf("Digite uma opcao valida: ");
    scanf("%d", &choice);
  }
  setbuf(stdin, NULL);
  return choice;
}
