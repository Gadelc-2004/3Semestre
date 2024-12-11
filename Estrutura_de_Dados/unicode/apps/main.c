#include <wchar.h>
#include <locale.h>

int main(void)
{
  setlocale(LC_ALL, "pt_BR.UTF-8");
  
  wchar_t c = L'©';
  wprintf(L"%lc\n", c);
  wprintf(L"©\n", c);
  return 0;
}
