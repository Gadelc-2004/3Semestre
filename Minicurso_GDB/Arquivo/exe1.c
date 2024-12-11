#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estado{
  char estado[20], sigla_estado[3];
};

struct Dados{
  int ID;
  char genero, nome[20], sobrenome[20], email[40], username[25], password[25], cidade[25], sigla_estado[3];
};

int main(int argc, char *argv[])
{
  int quant = argv[1];

  return 0;
}

int transferir_infos(struct aluno **ender)
{
  //atribuir_string eh uma funcao para copiar uma string dinamicamente
  void atribuir_string(char *origem, char **destino)
  {
    *destino = (char*)malloc((strlen(origem) + 1) * sizeof(char));
    strcpy(*destino, origem);
    return;
  }

  struct aluno *A = *ender;

  FILE *lista = fopen("./alunos.csv", "r");
  if(lista == NULL)
  {
    printf("Erro ao abrir o arquivo alunos.csv");
    return -1;
  }

  char *aux = (char*)malloc(500 * sizeof(char));
  int auxra;

  int linhas = 0, fim;

  A = (struct aluno*)malloc(quant * sizeof(struct aluno));

  rewind(lista);//voltando para o comeco do arquivo

  fscanf(lista, "%[^\n]\n", aux);//pulando a primeira linha

  for(int i = 0; i < quant; i++)//laco para percorrer todos os alunos do arquvo para coleta de dados
  {
    fscanf(lista, "%d,", &auxra);
    A[i].RA = auxra;

    fscanf(lista, "%[^,],", aux);
    atribuir_string(aux, &A[i].nome);

    fscanf(lista, "%[^,],", aux);
    atribuir_string(aux, &A[i].sobrenome);

    fscanf(lista, "%[^,],", aux);
    A[i].genero = (aux[0] - 32);

    fscanf(lista, "%[^,],", aux);
    atribuir_string(aux, &A[i].curso);

    fscanf(lista, "%d,", &auxra);
    A[i].presenca = auxra;
  }
  *ender = A;//atualiza o ponteiro para apontar para os dados preenchidos

  free(aux);//liberando a memoria de aux
  fclose(lista);//fechando o arquivo de leitura
  return 0;
}

