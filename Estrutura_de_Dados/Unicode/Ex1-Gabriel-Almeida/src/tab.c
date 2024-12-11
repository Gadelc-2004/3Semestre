#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "tab_printing.h"

int space = 8;

void imprimir_colunas(int y, wchar_t bar, wchar_t trace, wchar_t l, wchar_t r) 
{
  wprintf(L"%lc", l);
  for(int b = 0; b < space; b++)
  {
    wprintf(L"%lc", trace);
  }

  for(int j = 0; j < y - 1; j++)
  {
    wprintf(L"%lc", bar);
    for(int b = 0; b < space; b++)
    {
      wprintf(L"%lc", trace);
    }
  }
  wprintf(L"%lc\n", r); 
  return;
}
void imprimir_linhas(int x, int y, wchar_t bar, wchar_t abar, wchar_t trace, 
                     wchar_t t, wchar_t d, wchar_t midle, 
                     wchar_t tl, wchar_t tr, wchar_t dl, wchar_t dr, 
                     wchar_t bl, wchar_t br, wchar_t abl, wchar_t abr)
{
  imprimir_colunas(y, t, trace, tl, tr);
  imprimir_colunas(y, abar, ' ', bl, br);
  for(int i = 0; i < x - 1; i++)
  {
    imprimir_colunas(y, bar, midle, abl, abr);
    imprimir_colunas(y, abar, ' ', bl, br);
  }
  imprimir_colunas(y, d, trace, dl, dr);
  return;
}
