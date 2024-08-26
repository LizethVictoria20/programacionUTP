#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main(){
 
  float tiempo = 200;
  float velocidad = 50;
  float peso = 5;
  int contador;
  int itera = 49;
  int suma;
  char letra, primo;
  bool bandera;
  int resultado;
  bool resultBool;

  //a.Válido
  resultado = (tiempo + itera) / (velocidad + peso);
  printf("Resultado de la operacion %d\n", resultado);

  //b. Inválido, no se puede operar un float con un booleano.
  resultBool = ((floor(tiempo) + contador) < (itera * suma)) && !bandera;
  printf("La expresion es: %d\n", resultado);

  //c.
  resultBool = tiempo * velocidad < bandera && peso >= 0.0;
  printf("La expresion es: %d\n", resultado);

  //d. Inválido, no se pueden hacer operaciones aritmeticas entre char y enteros.
  // letra + contador * suma;
  // printf("La expresion es: %c\n", letra);

  //e. Válida
  resultado = ceil(velocidad) * suma + floor(tiempo) * itera;
  printf("La expresion es: %d\n", resultado);

}
