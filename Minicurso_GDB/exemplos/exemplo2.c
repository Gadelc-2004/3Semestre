#include <stdio.h>

int main()
{
  for(int i = 1; i < 20; i++)
  {
    int count = 0;
    for(int j = 1; j < i; j++)
    {
      if(i % j == 0)
      {
        count++;
      }
    }

    if(count = 2)
    {
        printf("%d = PRIMO\n", i);
    }
  }

  return 0;
}
