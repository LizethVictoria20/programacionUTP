#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main(){
  #define MAX 100
  #define PI 3.1416
  float x, v, p;
  int cont, i, k;
  char letra, c;
  bool band, terminar;

  //1. Leer - válida
  scanf("%c", &letra);
  printf("Punto 1 - %c\n", letra);

  //2. Escribir - válida
  printf("Punto 2 - %d\n", MAX);

  //3. Leer - válida
  scanf("%d", &cont);
  printf("Punto 3 - %d\n", cont);

  //4. Escribir - válida
  printf("Punto 4 - %f\n", x);
 
  //5. Leer - Inválida, no se puede asiganar un valor valiable a una constante. -----
  //  scanf("Punto 5 - %d", MAX);

  //6. Leer - Inválido porque esta operación retorna un tipo de dato double.
  //  scanf("%f", v);

  //7 - Inválida - La 
  x = (float)k + 2.0 * PI;
  printf("Punto 7 - %f\n", x);

  //8. Válida
  letra = 'p';
  printf("Punto 8 - %c\n", letra);

  //9. Inválida - Debe tener comillas simples al estar imprimiendo un caracter
  // letra = "p";
  // printf("Punto 9 - %c\n", letra);
  

  //10. Inválida, no es posible porque se le está asiganando una variable de tipo float a una variable tipo char 
  letra = 'p';
  p = 1.3;
  letra = p;
  printf("Punto 10 - %c\n", letra);

  //11. Válida
  letra = 'f';
  c = 'x';
  letra = c;
  printf("Punto 11 - %c\n", letra);

  //12. Inválida porque está haciendo operación entre tipo de datos flotantes y un booleano.
  p = 16.6;
  v = 3.4;
  x = 5.3;
  band = true;
  p = v / x * sqrt(p) - band;
  printf("Punto 12 - %f\n", p);

  //13. Inválida - No se puede asiganr cadena de caracteres a una variable de tipo float.
  // x = "3.2444" + "1.4e-4";
  // printf("Punto 13 - %f\n", x);

  //14. Válida
  x = 3.2444 + 1.4e-4;
  printf("Punto 14 - %f\n", x);

  //15. Inválida - No se puede asiganar caracteres a una variable de tipo float.
  x = 'v' + 'p';
  printf("Punto 15 - %f\n", x);

  //16. Válida
  p = 82.2;
  v = 6.5;
  x = 1.4;
  terminar = true;
  terminar = p > v >= x;
  printf("Punto 16 - %d\n", terminar);

  //17. Válido
  terminar = false;
  printf("Punto 17 - %d\n", terminar);

  //18. Inválido, no se puede asignar una cadena de caracteres a una variable de tipo booleano.
  terminar = "falso";
  printf("Punto 18 - %d\n", terminar);

  //19. Válida
  terminar = true;
  terminar = 'f' <= letra;
  printf("Punto 19 - %d\n", terminar);

  //20. Inválida, la asignación no es correcta.
  // x + 3.0 = v;

  //21. Válido.
  x = 4.5;
  p = 3.2;
  v = x * p + (float)((int)letra);
  printf("Punto 21 - %f\n", v);

  //22. Válida
  band = (x + v) * p || terminar || cont <= k + i;
  printf("Punto 22 - %d\n", band);

  //23. Válido 
  k =  (int)(letra + (int)c) + k;
  printf("Punto 23 - %d\n", k);

}
