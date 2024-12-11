#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

int main()
{
  struct retangulo r;
  r = criar_retangulo(4, 3);

  imprime(r);
  printf("Area: %f\n", calcula_area(r));
  printf("Perimetro: %f\n", calcula_perimetro(r));


  struct retangulo ra;
  ra = amplia(r, 2);
  imprime(ra);
  printf("Area: %f\n", calcula_area(ra));
  printf("Perimetro: %f\n", calcula_perimetro(ra));

  return 0;
}
