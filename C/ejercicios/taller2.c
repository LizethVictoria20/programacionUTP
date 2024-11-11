#include <stdio.h>

int main()
{
  int cases;
  // Programa I. Escribir un programa que solicite un número entero N, y que para todo
  // múltiplo X de N menor que 100, calcule el  producto de todos los números impares
  // menores que X. El programa deberá mostrar el valor de la suma de todos los productos
  // calculados. Para N=3:
  printf("Ingrese la opción del programa: ");
  scanf("%d", &cases);

  switch (cases)
  {
  case 1:
  {
    int N;
    int sum = 0;
    int product = 1;
    int i = 1;

    printf("Ingrese un número: ");
    scanf("%d", &N);

    while (i < N)
    {
      if (i % 2 != 0 && i < 100)
      {
        product *= i;
      }
      i++;
    }

    sum = product;

    printf("Sum of products: %d\n", sum);
  }
  break;

  case 2:
  {
    // Escribir un programa que lea las edades de un grupo de personas hasta que se
    // introduce un número negativo y calcule:
    /*• La edad media.
      • La edad máxima.
      • La edad mínima.
      • El número de personas que están jubiladas.
      • Cuántos son menores de edad.
 */
    int edad;
    float media;
    int maxima, minima, jubiladas, menores, count, sum;
    while (1)
    {
      printf("Ingrese las edades: ");
      scanf("%d", &edad);
      if (edad < 0)
      {
        break;
      }
      count++;
      sum += edad;
    }
    media = sum / count;
    printf("%.2f", media);
  }

  default:
    break;
  }

  return 0;
}
