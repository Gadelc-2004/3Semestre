#ifndef RETANGULO_H
#define RETANGULO_H

struct retangulo
{
  float base, altura;
};

struct retangulo criar_retangulo(float b, float a);
float calcula_area(struct retangulo r);
float calcula_perimetro(struct retangulo r);
struct retangulo amplia(struct retangulo r, float fator);
void imprime(struct retangulo r);

#endif // RETANGULO.H
