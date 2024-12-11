#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "tab_printing.h"

int main()
{
  setlocale(LC_ALL, "pt_BR.UTF-8");
  int x, y;

  wprintf(L"Digite o numero de linhas: ");
  scanf("%d", &x);
  wprintf(L"Digite o numero de Colunas: ");
  scanf("%d", &y);
  //imprimir_linhas(x, y, L'', L'', L'', L'', L'', L'', L'', L'', L'', L'', L'', L'', L'', L'');

  imprimir_linhas(x, y, '|', 'i', '-', 'T', 'L', '.', 'q', 'w', 'a', 's', 'd', 'b', 'D', 'B');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'╪', L'│', L'─', L'╥', L'╨', L'─', L'╓', L'╖', L'╙', L'╜', L'│', L'│', L'╪', L'╪');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'╬', L'║', L'═', L'╦', L'╩', L'═', L'╔', L'╗', L'╚', L'╝', L'║', L'║', L'╠', L'╣');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'╪', L'│', L'═', L'╤', L'╧', L'═', L'╒', L'╕', L'╘', L'╛', L'│', L'│', L'╞', L'╡');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'┼', L'│', L'─', L'┬', L'┴', L'─', L'╭', L'╮', L'╰', L'╯', L'│', L'│', L'├', L'┤');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'+', L'♪', L'.', L'+', L'+', L' ', L'♫', L'♫', L'♫', L'♫', L'♪', L'♪', L'♫', L'♫');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'.', L'|', L'─', L'.', L'.', L'.', L'◤', L'◥', L'◣', L'◢', L'|', L'|', L'▲', L'▲');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'♟', L'♝', L'∼', L'|', L'|', L'⎯', L'♜', L'♜', L'♜', L'♜', L'♝', L'♝', L'♚', L'♛');
  wprintf(L"\n\n");
  imprimir_linhas(x, y, L'⎪', L'⎪', L'═', L'⎪', L'⎪', L'═', L'⎧', L'⎫', L'⎩', L'⎭', L'⎪', L'⎪', L'⎪', L'⎪');
  return 0;
}
