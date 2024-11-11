#include <stdio.h>

int main()
{
  int n, m;

  printf("Introduce el valor de n: ");
  scanf("%d", &n);
  printf("Introduce el valor de m: ");
  scanf("%d", &m);

  printf("Números primos impares entre %d y %d:\n", n, m);

  for (int i = n; i <= m; i++)
  {
    if (i % 2 != 0)
    {
      int es_primo = 1;
      if (i < 2)
      {
        es_primo = 0;
      }
      for (int j = 2; j * j <= i; j++)
      {
        if (i % j == 0)
        {
          es_primo = 0;
          break;
        }
      }
      if (es_primo)
      {
        printf("%d ", i);
      }
    }
  }

  printf("\n");
  return 0;
}
