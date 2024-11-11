#include <stdio.h>

int main()
{
  int multi6[2][3], num;
  num = 6;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 1; j <= 3; j++)
    {
      if (i == 0)
      {
        num = 6 * j;
        printf("%i,  ", num);
      }
      else
      {
        if (i == 1)
        {
          num = num + 6;
          printf("%i, ", num);
        }
      }
    }
    printf("\n");
  }
}
