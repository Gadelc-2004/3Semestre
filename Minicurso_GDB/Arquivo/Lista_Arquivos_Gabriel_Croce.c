//  Trabalho referente ao ListaArquivos1.pdf
//  Nome: Gabriel Almeida Della Croce

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

struct Estado{
  char estado[20], sigla_estado[3];
};

struct Dados{
  int ID;
  char genero, nome[20], sobrenome[20], email[40], username[25], password[25], cidade[25], sigla_estado[3];
};

int menu();
void Exe_2(FILE *f, FILE *uf, struct Estado *e, int pass);
int Exe_3(FILE *f, struct Dados *d, int pass);
void Exe_4(struct Estado *e, struct Dados *d);
int Exe_5(struct Dados *d, struct Estado *e, int pass);
int Exe_6(struct Dados *d, struct Estado *e, int pass);
int Exe_8(struct Dados *d);

int main()
{
  struct Dados p;
  struct Estado e[27];
  struct Dados d[1000];

  system("clear");
  printf("Execucao do exercicio 2 e 3\n");

  FILE *f = fopen("./pessoas.txt", "r");
  if(f == NULL)
  {
    printf("Erro ao abrir o arquivo: pessoas.txt\n");
    return -1;
  }

  FILE *uf = fopen("./UF.txt", "w");
  if(uf == NULL)
  {
    printf("Erro ao abrir o arquivo: UF.txt\n");
    return -1;
  }

  Exe_3(f, d, 0);
  printf("Exercicio 3 executado com sucesso\n");
  Exe_2(f, uf, e, 0);
  printf("Exercicio 2 executado com sucesso\n");
  int choice = 0, pass = 0, pass5 = 0;

  printf("\nAperte enter para continuar");
  getchar();

  while(choice != 1)
  {
    choice = menu();
    setbuf(stdin, NULL);

    switch(choice)
    {
      case 1:
      {
        break;
      }

      case 2:
      {
        system("clear");
        Exe_2(f, uf, e, 1);
        break;
      }

      case 3:
      {
        system("clear");
        Exe_3(f, d, 1);
        break;
      }

      case 4:
      {
        system("clear");
        Exe_4(e, d);
        break;
      }

      case 5:
      {
        system("clear");
        if(Exe_5(d, e, pass5) == -1)
        {
          return -1;
        }
        pass5 = 1;
        break;
      }

      case 6:
      {
        system("clear");
        if(Exe_6(d, e, pass) == -1)
        {
          return -1;
        }

        pass = 1;
        break;
      }

      case 8:
      {
        int choice8 = 1;
        while(choice8 == 1)
        {
          system("clear");
          choice8 = Exe_8(d);
        }
        break;
      }
    }
  }

  return 0;
}

int menu()
{
  system("clear");
  int choice = 0;
  printf("|Exercicio: Manipulacao de arquivo\n");
  printf("|=================================\n");
  printf("|1 -> Sair.\n");
  printf("|2 -> Imprimir o vetor do Exercicio 2.\n");
  printf("|3 -> Imprimir os dados das primeiras 25 pessoas do vetor do Exercicio 3.\n");
  printf("|4 -> Executar o Exercicio 4.\n");
  printf("|5 -> Executar o Exercicio 5.\n");
  printf("|6 -> Executar o Exercicio 6/7.\n");
  printf("|8 -> Executar o Exercicio 8.\n\n");
  printf("Digite a opcao que deseja executar: ");
  scanf("%d", &choice);

  while((choice < 1) || (choice > 8))
  {
    printf("Digite a opcao valida: ");
    scanf("%d", &choice);
  }

  return choice;
}

void Exe_2(FILE *f, FILE *uf, struct Estado *e, int pass)
{
  char aux, ES[3], Esta[25];
  int passar = 0, found = 0, i = 0, j = 0, es = 0;

  if(pass <= 0)
  {
    rewind(f);
    while(1)
    {
      fscanf(f, "%c", &aux);
      if(aux == '\n')
      {
        break;
      }
    }

    for(int i = 0; i < 999; i++)
    {
      passar = 0;
      while(1)
      {
        fscanf(f, "%c", &aux);
        if(aux == ';')
        {
          passar++;
        }

        if(passar == 9)
        {
          break;
        }
      }

      fscanf(f, "%2[^;];", &ES);
      fscanf(f, "%20[^;];", &Esta);

      while(1)
      {
        fscanf(f, "%c", &aux);
        if(aux == '\n')
        {
          break;
        }
      }

      found = 0;

      if(es == 0)
      {
        e[es].sigla_estado[0] = ES[0];
        e[es].sigla_estado[1] = ES[1];
        e[es].sigla_estado[2] = '\0';
        strcpy(e[es].estado, Esta);
        es++;
        continue;
      }
      else
      {
        for(int j = 0; j < es; j++)
        {
          if(strcmp(ES, e[j].sigla_estado) == 0)
          {
              found = 1;
              break;
          }
        }

        if(!found)
        {
          e[es].sigla_estado[0] = ES[0];
          e[es].sigla_estado[1] = ES[1];
          e[es].sigla_estado[2] = '\0';
          strcpy(e[es].estado, Esta);
          es++;
        }
        if(es == 26)
        {
          e[es].sigla_estado[0] = 'R';
          e[es].sigla_estado[1] = 'R';
          e[es].sigla_estado[2] = '\0';
          strcpy(e[es].estado, "Roraima");
          break;
        }
      }
    }
    for(int i = 0; i < 27; i++)
    {
      fprintf(uf, "%s;%s\n", e[i].sigla_estado, e[i].estado);
    }
    fclose(f);
    fclose(uf);
  }

  if(pass > 0)
  {
    printf("| i| SE | Estado\n");
    printf("|--|----|-------\n");
    for(int i =0; i < 27; i++)
    {
      printf("|%02d| %s | %s\n", i, e[i].sigla_estado, e[i].estado);
    }

    printf("\nAperte enter para continuar");
    getchar();
  }

  return;
}

int Exe_3(FILE *f, struct Dados *d, int pass)
{
  char aux;

  if(pass == 0)
  {
    rewind(f);
    while(1)
    {
      fscanf(f, "%c", &aux);
      if(aux == '\n')
      {
        break;
      }
    }

    for(int i = 0; i < 999; i++)
    {
      fscanf(f, "%d;", &d[i].ID);
      fscanf(f, "%c;", &d[i].genero);
      int j = 0;
      while(fscanf(f, " %c", &aux) != EOF)
      {
        if(aux == ';')
        {
          j++;
        }
        if(j == 3)
        {
          fscanf(f, "%20[^;];", &d[i].nome);
          fscanf(f, " %c", &aux);
          fscanf(f, " %c", &aux);
          break;
        }
      }
      fscanf(f, "%20[^;];", &d[i].sobrenome);
      while(fscanf(f, " %c", &aux) != EOF)
      {
        if(aux == ';')
        {
          break;
        }
      }
      fscanf(f, "%25[^;];", &d[i].cidade);
      fscanf(f, "%2[^;];", &d[i].sigla_estado);
      j = 0;
      while(fscanf(f, " %c", &aux) != EOF)
      {
        if(aux == ';')
        {
          j++;
        }
        if(j == 4)
        {
          fscanf(f, "%40[^;];", &d[i].email);
          fscanf(f, "%25[^;];", &d[i].username);
          fscanf(f, "%25[^;];", &d[i].password);
          break;
        }
      }
      while(1)
      {
        fscanf(f, "%c", &aux);
        if(aux == '\n')
        {
          break;
        }
      }
    }
  }

  if(pass == 1)
  {
    for(int i = 0; i < 25; i++)
    {
      printf("|ID:%04d|G:%c|Nome: %s %s|C:%s|E:%s|Email:%s|User:%s|Pass:%s\n", d[i].ID, (d[i].genero - 32), d[i].nome, d[i].sobrenome, d[i].cidade, d[i].sigla_estado, d[i].email, d[i].username, d[i].password);
    }

    printf("Aperte enter para continuar");
    getchar();
  }
  return 0;
}

void Exe_4(struct Estado *e, struct Dados *d)
{
  printf("|ID|Nome                 Sobrenome           |Cidade                   | E|Estado\n");
  for(int i = 0; i < 25; i++)
  {
    printf("|%02d|%-20s %-20s|%-25s|%s|%-20s\n", d[i].ID, d[i].nome, d[i].sobrenome, d[i].cidade, e[i].sigla_estado, e[i].estado);
  }

  printf("\n\nAperte enter para continuar");
  getchar();

  return;
}

int Exe_5(struct Dados *d, struct Estado *e, int pass)
{
  char check[3];
  char choice = '1';
  int confirmation = 0;

  if(pass == 1)
  {
    printf("Voce ja executou esse exercicio anteriormente.\n\nDigite:\n|1 para subscrever os dados salvos\n|2 para sair\n ");
    scanf(" %c", &choice);
    while((choice != '1') && (choice != '2'))
    {
      printf("Digite uma opcao valida(1 ou 2): ");
      scanf(" %c", &choice);
    }
    setbuf(stdin, NULL);
  }

  if(choice == '2')
  {
    printf("\nAperter enter para voltar ao menu");
    getchar();
    getchar();
    return 0;
  }

  printf("|Digite a sigla do estado que voce deseja(0 para voltar ao menu): ");
  scanf("%2s", &check);
  setbuf(stdin, NULL);

  if((check[0] == '0') && (check[1] == '\0'))
  {
    printf("Saida confirmada");
    getchar();
    return 0;
  }

  while(confirmation == 0)
  {
    for(int i = 0; i < 27; i++)
    {
      printf("Check: %s| ES: %s\n", check, e[i].sigla_estado);
      //if(strcmp(check, e[i].sigla_estado) == 0)
      if(((check[0] == e[i].sigla_estado[0]) || (check[0] == (e[i].sigla_estado[0] + 32))) && ((check[1] == e[i].sigla_estado[1]) || (check[1] == (e[i].sigla_estado[1] + 32))))
      {
        confirmation = 1;
        break;
      }

      if(i == 26)
      {
        printf("|Digite uma sigla de estado valida(0 para voltar ao menu): ");
        scanf("%2s", &check);
        setbuf(stdin, NULL);
        if((check[0] == '0') && (check[1] == '\0'))
        {
          return 0;
        }
        i = -1;
      }
    }
  }

  //FILE *pe = fopen("/home/gabriel/Programas/2semestre/Arquivos/pessoas.out", "w");
  FILE *pe = fopen("./pessoas.out", "w");
  if(pe == NULL)
  {
    printf("Erro ao abrir o arquivo: pessoas.out\n");
    return -1;
  }

  for(int i = 0; i < 999; i++)
  {
    //if(strcmp(d[i].sigla_estado, check) == 0)
    if(((check[0] == d[i].sigla_estado[0]) || (check[0] == (d[i].sigla_estado[0] + 32))) && ((check[1] == d[i].sigla_estado[1]) || (check[1] == (d[i].sigla_estado[1] + 32))))
    {
      fprintf( pe, "%d;%c;%s;%s;%s;%s;%s;%s;%s\n", d[i].ID, d[i].genero, d[i].nome, d[i].sobrenome, d[i].cidade, d[i].sigla_estado, d[i].email, d[i].username, d[i].password);
    }
  }

  fclose(pe);

  printf("\n\nAperte enter para continuar");
  getchar();

  return 0;
}

int Exe_6(struct Dados *d, struct Estado *e, int pass)
{
  int c = 0;
  char caminho[100];

  struct stat sts = {0};

  if(pass == 0)
  {
    if(stat("./Estados", &sts) == -1)
    {
      printf("|Pasta Estados criada com sucesso\n");
      printf("Aperte enter para continuar");
      getchar();
      mkdir("./Estados", S_IRWXU);
    }

    FILE *ES[27];
    for(int i = 0; i < 27; i++)
    {
      //snprintf(caminho, sizeof(caminho), "./Estados/%s.txt", e[i].sigla_estado);
      sprintf(caminho, "./Estados/%s.txt", e[i].sigla_estado);

      ES[i] = fopen(caminho, "w");
      if(ES[i] == NULL)
      {
        printf("Erro ao abrir o arquivo: %s.txt\n", e[i].sigla_estado);
        return -1;
      }
    }

    for(int i = 0; i < 999; i++)
    {
      for(int j = 0; j < 27; j++)
      {
        c = 0;
        if(strcmp(d[i].sigla_estado, e[j].sigla_estado) == 0)
        {
          c = 1;
          fprintf(ES[j], "%d;%c;%s;%s;%s;%s;%s;%s;%s\n", d[i].ID, d[i].genero, d[i].nome, d[i].sobrenome, d[i].cidade, d[i].sigla_estado, d[i].email, d[i].username, d[i].password);
        }
      }
      if(c = 0)
      {
        printf("Estado: %s nao encontrado\n", d[i].sigla_estado);
      }
    }

    for(int i =0; i < 27; i++)
    {
      fclose(ES[i]);
    }
  }

  printf("|Arquivos criados com sucesso\n\nAperte enter para continuar");
  getchar();

  return 0;
}

int Exe_8(struct Dados *d)
{
  char aux[100] = {2};
  char  auxp[100];
  int copy, login = 0, choice = 0, i = 0;

  printf("|Sistema de login\n");
  printf("|===============\n");
  printf("|Digite seu usuario(0 para sair): ");
  scanf("%100s", &aux);
  getchar();
  if((aux[0] == '0' && aux[1] == '\0'))
  {
    return 0;
  }
  printf("|Digite sua senha: ");
  scanf("%100s", &auxp);
  getchar();

  while(login == 0)
  {
    for(int i = 0; i < 999; i++)
    {
      if(((strcmp(aux, d[i].email) == 0) || (strcmp(aux, d[i].username) == 0)) && ((strcmp(auxp, d[i].password) == 0)))
      {
        copy = i;
        login = 1;
        break;
      }
    }

    if(login == 0)
    {
      printf("|Acesso negado\n\n");
      printf("|Digite seu usuario(0 para sair): ");
      scanf("%100s", &aux);
      if((aux[0] == '0' && aux[1] == '\0'))
      {
        return 0;
      }
      printf("|Digite sua senha: ");
      scanf("%100s", &auxp);
    }
  }

  if(login == 1)
  {
    system("clear");
    printf("Seja bem vindo(a) %s %s\nAperte enter para continuar", d[copy].nome, d[copy].sobrenome);
    getchar();
    system("clear");
    printf("|1 -> Fazer mais um login\n|2 -> Voltar ao menu\n\nDigite a opcao que deseja executar: ");
    scanf("%d", &choice);
    while((choice != 1) && (choice != 2))
    {
      printf("Digite uma opcao valida: ");
      scanf("%d", &choice);
    }
  }

  return choice;
}
