#include <stdio.h>

int main()
{
  int opt;
  printf("Ingrese la opción que desea consultar\n");
  printf("1.Mostrar el último dato primo de un arreglo.\n2.Suma de elementos impares del arreglo.\n3.Elementos con los cuadrados de los 10 primeros elementos.\n");
  printf("4.Calcular el promedio de los elementos del arreglo\n");
  scanf("%d", &opt);

  switch (opt)
  {
  case 1:
  {
    //1. Hacer un programa que reciba un arreglo, y muestre el último dato primo del arreglo.
    int n, i, j, isPrime, lastPrime = -1;

    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    // Llenar arreglo
    printf("Ingresa los elementos del arreglo:\n");
    for (i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
      if (arr[i] > 1)
      {
        isPrime = 1;
        for (j = 2; j * j <= arr[i]; j++)
        {
          if (arr[i] % j == 0)
          {
            isPrime = 0;
            break;
          }
        }
        if (isPrime)
        {
          lastPrime = arr[i];
        }
      }
    }

    if (lastPrime != -1)
    {
      printf("El último número primo en el arreglo es: %d\n", lastPrime);
    }
    else
    {
      printf("No hay números primos en el arreglo.\n");
    }
  }
  break;
  case 2: {
    //2. Dado un arreglo con solo números, realizar la suma de sus elementos impares.
    int n, i, sum = 0;

    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    // Llenar arreglo
    printf("Ingresa los elementos del arreglo:\n");
    for (i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
      if (arr[i] % 2!= 0)
      {
        sum += arr[i];
      }
    }

    printf("La suma de los elementos impares del arreglo es: %d\n", sum);
  }
  break;
  case 3: {
    //Llenar un arreglo V de 10 elementos con los cuadrados de los 10 primeros elementos.
    //Ej: (arreglos 1 4 9 16 25 36 49 64 81 100)
    int arrV[10];
    int i;

    for (i = 1; i <= 10; i++)
    {
      arrV[i] = i * i;
    }

    printf("El arreglo V es: ");
    for (i = 1; i <= 10; i++)
    {
      printf("%d ", arrV[i]);
    }
    printf("\n");
  }
  break;
  case 4: {
    //4. Dado un arreglo con n números. Calcular el promedio de los elementos del arreglo y 
    //colocarlos en otro arreglo los numeros mayores al promedio.
    printf("Falta");
  }
  break;
  case 4: {
    //5. Dado un arreglo V de enteros y un número X, devolver el valor que corresponde al 
    //número de veces que está X en el arreglo.
    
  }
  break;
  default:
    break;
  }

  return 0;
}
