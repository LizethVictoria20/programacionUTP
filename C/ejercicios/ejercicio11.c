#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define RESET "\x1b[0m"
#define BOLD_RED "\x1b[1;31m"
#define BOLD_GREEN "\x1b[1;32m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_BLUE "\x1b[1;34m"
#define BOLD_MAGENTA "\x1b[1;35m"
#define BOLD_CYAN "\x1b[1;36m"
#define BOLD_GRAY "\x1b[1;90m"
#define TEXT_COLOR(R, G, B) "\x1b[38;2;" #R ";" #G ";" #B "m"

int main()
{
  setlocale(LC_ALL, "es_ES.UTF-8");

  int opc;
  printf(TEXT_COLOR(255, 0, 0) "\n\n************** MENU **************\n" RESET);
  printf(TEXT_COLOR(52, 126, 184) "1) Mostrar números del 1 al 100\n" RESET);
  printf(TEXT_COLOR(41, 175, 154) "2) Mostrar números del 100 al 1\n" RESET);
  printf(TEXT_COLOR(124, 41, 175) "3) Mostrar números de n a m\n" RESET);
  printf(TEXT_COLOR(175, 41, 150) "4) Mostrar los números impares de n hasta m\n" RESET);
  printf(TEXT_COLOR(175, 126, 41) "5) Mostrar los números pares de n hasta m\n" RESET);
  printf(TEXT_COLOR(255, 0, 0) "6) Mostrar la suma de los números pares de n hasta m\n" RESET);
  printf(TEXT_COLOR(175, 172, 41) "7) Notas de N estudiantes y su promedio\n" RESET);
  printf(TEXT_COLOR(175, 86, 41) "8) Notas de estudiantes y promedio (-1 para finalizar)\n" RESET);
  printf(TEXT_COLOR(41, 160, 175) "9) Mostrar múltiplos de 3 hasta m\n" RESET);
  printf(TEXT_COLOR(140, 184, 173) "10) Mostrar los múltiplos de m hasta n\n" RESET);
  printf(TEXT_COLOR(140, 184, 172) "11) Mostrar la tabla de multiplicar n\n" RESET);
  printf(TEXT_COLOR(255, 0, 0) "12) Mostrar el factorial de un número n\n" RESET);
  printf(TEXT_COLOR(52, 126, 184) "13) Mostrar si un número es primo \n" RESET);
  printf(TEXT_COLOR(124, 41, 175) "14) Mostrar serie Fibonacci \n" RESET);
  printf(TEXT_COLOR(41, 160, 175) "15) Mostrar la descomposición de un número \n" RESET);
  printf(TEXT_COLOR(52, 126, 184) "16) Mostrar en número mayor \n" RESET);


  printf("Por favor ingrese una opción: ");
  scanf("%i", &opc);

  switch (opc)
  {
  case 1:
  {
    int i = 1;
    while (i <= 100)
    {
      printf("%i", i);
      if (i < 100)
      {
        printf(", ");
      }
      i++;
    }
  }
  break;

  case 2:
  {
    int num = 100;
    while (num >= 1)
    {
      printf("%i", num);
      if (num > 1)
      {
        printf(", ");
      }
      num--;
    }
  }

  break;

  case 3:
  {
    int num1, num2;
    printf("Por favor ingrese dos números separados por un espacio: ");
    scanf("%i %i", &num1, &num2);

    if (num1 < num2)
    {
      while (num1 <= num2)
      {
        printf("%i", num1);
        if (num1 < num2)
        {
          printf(", ");
        }
        num1++;
      }
    }
    else
    {
      while (num1 >= num2)
      {
        printf("%i", num1);
        if (num1 > num2)
        {
          printf(", ");
        }
        num1--;
      }
    }
  }
  break;

  case 4:
  {
    int nume1, nume2;
    printf("Por favor ingrese dos números separados por un espacio: ");
    scanf("%i %i", &nume1, &nume2);

    if (nume1 <= nume2)
    {
      while (nume1 <= nume2)
      {
        if (nume1 % 2 != 0)
        {
          printf("%i", nume1);
          if (nume1 < nume2 - 1)
          {
            printf(",");
          }
        }
        nume1++;
      }
    }
    else
    {
      while (nume1 >= nume2)
      {
        if (nume1 % 2 != 0)
        {
          printf("%i", nume1);
          if (nume1 > nume2 + 1)
          {
            printf(",");
          }
        }
        nume1--;
      }
    }
  }

  break;

  case 5:
  {
    int numer1, numer2;
    printf("Por favor ingrese dos números separados por un espacio: ");
    scanf("%i %i", &numer1, &numer2);

    if (numer1 <= numer2)
    {
      while (numer1 <= numer2)
      {
        if (numer1 % 2 == 0)
        {
          printf("%i", numer1);
          if (numer1 < numer2)
          {
            printf(",");
          }
        }
        numer1++;
      }
    }
    else
    {
      while (numer1 >= numer2)
      {
        if (numer1 % 2 == 0)
        {
          printf("%i", numer1);
          if (numer1 > numer2)
          {
            printf(",");
          }
        }
        numer1--;
      }
    }
  }

  break;

  case 6:
  {
    int numero1, numero2, suma;
    printf("Por favor ingrese dos números separados por un espacio: ");
    scanf("%i %i", &numero1, &numero2);

    if (numero1 <= numero2)
    {
      while (numero1 <= numero2)
      {
        if (numero1 % 2 == 0)
        {
          suma += numero1;
        }
        numero1++;
      }
      printf("%i", suma);
    }
    else
    {
      while (numero1 >= numero2)
      {
        if (numero1 % 2 == 0)
        {
          suma += numero1;
        }
        numero1--;
      }
      printf("%i", suma);
    }
  }

  break;

  case 7:
  {
    int n, nota, promedio = 0, aux;
    printf("\nPor favor ingrese el número de notas: ");
    scanf("%i", &n);
    aux = n;
    while (n > 0)
    {
      printf("Ingrese la nota: ");
      scanf("%i", &nota);
      promedio = promedio + aux;
      n = n - 1;
    }
    promedio = promedio / aux;
    printf("\n\nEl promedio de notas es: %i", promedio);
  }

  break;

  case 8:
  {
    int not = 0, prome = 0, ct = 0;
    while (not != -1)
    {
      printf("\nPor favor ingrese la nota: ");
      scanf("%i", &not );
      prome = prome + not ;
      ct = ct + 1;
    }
    prome = (prome - 1) / (ct - 1);
    printf("\n\nEl promedio es: %i", prome);
  }

  break;

  case 9:
  {
    int multiplo = 3, limite = 0;
    printf("Por favor ingrese el limite: ");
    scanf("%i", &limite);

    while (multiplo <= limite)
    {
      printf("%i", multiplo);
      multiplo += 3;
      if (multiplo <= limite)
      {
        printf(",");
      }
    }
  }

  break;

  case 10:
  {
    int multip, limit = 0;
    printf("Por favor ingrese el multiplo y el limite separado por espacio: ");
    scanf("%i %i", &multip, &limit);

    int inicio = multip;
    while (inicio <= limit)
    {
      printf("%i", inicio);
      inicio += multip;
      if (inicio <= limit)
      {
        printf(",");
      }
    }
  }
  break;
  case 11:
  {
    int mult = 1, n;
    int result;
    printf("Por favor ingrese un número para ver su tabla de multiplicar: ");
    scanf("%d", &n);
    while (mult <= 10)
    {
      result = mult * n;
      printf("%d * %d = %d\n", mult, n, result);
      mult++;
    }
  }
  break;
  case 12:
  {
    int fact, n;
    int i = 1;
    int result;
    printf("Por favor ingrese un número para conocer su factorial: ");
    scanf("%d", &n);
    while (i <= n)
    {
      fact = fact * i;
      i++;
    }
    printf("El factoria de %i es: %d", n, fact);
  }
  break;
  case 13:
  {
    int x, num, i;
    i = 0;
    x = 1;
    printf("Ingrese un numero para comprobar si es primo: ");
    scanf("%i", &num);
    while (x <= num)
    {
      if (num % x == 0)
      {
        i++;
      }
      x++;
    }
    if (i == 2)
    {
      printf("\nEl numero %i es primo", num);
    }
    else
    {
      printf("\nEl numero %i no es primo", num);
    }
  }
  break;
  case 14:
  {
    int x, y, aux, n;
    x = 1;
    y = 1;
    printf("Ingrese el número de Fibonnaci que desea conocer \n");
    scanf("%i", &n);
    while (n >= 1)
    {
      printf("%i ", x);
      aux = x + y;
      x = y;
      y = aux;
      n--;
    }
  }
  break;
  case 15:
  {
    int num, invertido;
    int unidad, decena, centena, millar;

    printf("Ingrese un numero entero de 4 cifras: ");
    scanf("%d", &num);

    unidad = num % 10;          // última cifra
    decena = (num / 10) % 10;   // segunda cifra
    centena = (num / 100) % 10; // tercera cifra
    millar = num / 1000;        // primera cifra

    printf("La unidad es %d, la decena es: %d0, la centena es: %d00, el mil es: %d000\n", unidad, decena, centena, millar);
  }
  break;
  case 16:
  {
    int n, i = 1, num, max;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);

    printf("Ingrese un número: ");
    scanf("%d", &num);
    max = num;

    while (i < n)
    {
      printf("Ingrese un número: ");
      scanf("%d", &num);
      if (num > max)
      {
        max = num;
      }
      i++;
    }
    printf("El número mayor es: %d\n", max);
  }
  break;
  default:
    printf("ERROR! Ingrese una opcion del 1 al 16\n");
  }

  return main();
}
