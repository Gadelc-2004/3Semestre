#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

/*struct retangulo
{
  float base, altura;
};*/

struct retangulo criar_retangulo(float b, float a)
{
  struct retangulo r;
  r.base = b;
  r.altura = a;
  return r;
}

float calcula_area(struct retangulo r)
{
  return (r.base * r.altura);
}

float calcula_perimetro(struct retangulo r)
{
  return (2 * (r.base + r.altura));
}

struct retangulo amplia(struct retangulo r, float fator)
{
  struct retangulo nr;
  nr.base = (r.base * fator);
  nr.altura = (r.altura * fator);

  return nr;
}

void imprime(struct retangulo r)
{
  printf("Base do retangulo: %f\n", r.base);
  printf("Altura do retangulo: %f\n", r.altura);
}
