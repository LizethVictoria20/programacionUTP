#include <stdio.h>

// Imprimir el área de un círculo
int radioCirculo()
{
  float radio = 7.0;
  float area;
  area = 3.1416 * radio * radio;
  printf("El área del círculo con radio %.2f es: %.2f\n", radio, area);
  return 0;
}


// Imprimir un string
int printString()
{
  char mensaje[] = "Este es un string en C";
  printf("%s\n", mensaje);
  return 0;
}

// Imprimir un string con comillas
int printStringComillas()
{
  printf("Este es un mensaje con \"comillas dobles\" en C.\n");
  return 0;
}

// Imprimir un patrón sencillo
int printPatron()
{
  printf("Este un patrón sencillo\n");
  printf("*****\n");
  printf("****\n");
  printf("***\n");
  printf("**\n");
  printf("*\n");
  return 0;
}

// Imprimir 10 números naturales
int printNumeros()
{
  printf("Los primeros 10 números naturales son:\n");
  for (int i = 1; i <= 10; i++)
  {
    printf("%d\n", i);
  }
  
  return 0;
}

int main()
{
  radioCirculo();
  printString();
  printStringComillas();
  printPatron();
  printNumeros();
  return 0;
}