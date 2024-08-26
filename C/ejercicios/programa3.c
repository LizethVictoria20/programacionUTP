#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
  float x = 3.5;
  float v = 1.4;
  float p = 6.0;
  int i = 5;
  int k = 2;
  int cont = -4;
  char letra = 'p';
  char c = 't';
  bool bandera = false;
  bool terminar = true;




  //1 - Válida.
  x = v + (float)((int)letra);
  printf("Punto 1 - %f\n", x);


  //2 - Válida.
  k = (k - 2 * cont) * (k - 2 * cont) + i * (cont - k / 2.0 ) / cont;
  printf("Punto 2 - %d\n", k);


  //3 - Válida.
  v = x + (p - sqrt(x) * (v - x) + 3.0) * p;
  printf("Punto 3 - %f\n", v);


  //4 - Invalido, no se puede hacer doble asignación a una variable.
  // bandera = (terminar || !(i + 2 < cont || p >= v)) || (x + v) = p;
  // printf("Punto 4 - %d\n", bandera);


  //5 - Válida, iperación entre enteros.
  cont = cont + 1;
  printf("Punto 5 - %d\n", cont);



  //6 - Válida
  i = cont * (int)(x * v - p / 2.0) + k - i;
  printf("Punto 6 - %d\n", i);


  //7 - Válida
  p = p + x - (float)(floor(p + x) + 5 );
  printf("Punto 7 - %f\n", p);

  //8 - Válida
  letra = (char)(k);
  printf("Punto 8 - %c\n", letra);

  //9 - Válida
  // k = (k + cont ) % (floor(p) + ceil(v));

}
