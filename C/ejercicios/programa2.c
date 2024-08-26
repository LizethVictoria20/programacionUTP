#include <stdio.h>
#include <stdbool.h>


int main(){
  float x = 3.5;
  float v = 1.4;
  float p = 6.0;
  float z;


  //Primera operación es válida para la variable z.
  z = v - p / ( x + p / x - v);
  printf("El valor de z es: %.2f\n", z);
  //Segunda operación es válida para la variable z.
  z = p / x / v + p / x * v;
  printf("El valor de z es: %.2f\n", z);


  //Tercera operación es válida para la variable z.
  z = ( v - 3.0 * x / p) / (4.0 - v / (5.0 + p / x));
  printf("El valor de z es: %.2f\n", z);


  //Cuarta operación es válida para la variable z.
  z = 2.0 * p - 4.0 / v + 5.0 * x / (3.0 + v * p - x);
  printf("El valor de z es: %.2f\n", z);

}
