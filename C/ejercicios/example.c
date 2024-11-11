#include <stdio.h>

int main()
{
  int a, b;
  int sum = 0;
  printf("Ingrese a: \n");
  scanf("%d", &a);
  printf("Ingrese b: ");
  scanf("%d", &b);

  for (int i = a; i <= b; i++)
  {
    sum += i;
  }
  printf("%d", sum);
}