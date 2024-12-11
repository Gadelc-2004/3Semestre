#include "trianguloRet.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TrianguloRet 
{
    float a;
    float b;
    float c; //hipotenusa
};

struct TrianguloRet * triRet_cria(float a, float b, float c);

float triRet_Base (struct TrianguloRet *);
float triRet_Altura (struct TrianguloRet *);
float triRet_Hitotenusa (struct TrianguloRet *);
void  triRet_imprime(struct TrianguloRet *);
float triRet_Alfa (struct TrianguloRet *);
float triRet_Beta (struct TrianguloRet *);
float triRet_Area (struct TrianguloRet *);
float triRet_Perimetro (struct TrianguloRet *);
float triRet_SenoAlfa (struct TrianguloRet *);
float triRet_CossenoAlfa (struct TrianguloRet *);
float triRet_TangeteAlfa (struct TrianguloRet *);
float triRet_SenoBeta (struct TrianguloRet *);
float triRet_CossenoBeta (struct TrianguloRet *);
float triRet_TangeteBeta (struct TrianguloRet *);
