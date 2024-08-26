#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main(){
 
  float tiempo = 3.0;
  float velocidad = -4.5;
  float peso = 8.0;
  int contador = 5;
  int itera = -2;
  int suma;
  char letra, primo;
  bool bandera = false;
  int cuenta = 4;
  int resultado;
  bool resultBool;

  //a. Inválido, no se puede operar números flotantes y enteros.
  float resultadoFloat = itera + floor(tiempo + velocidad) / (suma + itera);
  printf("A. %f\n", resultadoFloat);

  //b. Inválido, no se puede hacer la operación logica entre un número y un booleano
  // letra > primo && ceil(tiempo) / floor(velocidad) + cuenta < 5;

  //c. Válido
  resultado = peso * velocidad / ( tiempo + 5.6 );
  printf("C. %d\n", resultado);

  //d. Válida
  resultado = contador + ((itera)*(itera)* suma) / 4 - itera;
  printf("D. %d\n", resultado);

  //e. Válida
 resultado =  bandera && (sqrt(tiempo) <= peso * velocidad);
 printf("E. %d\n", resultado);

  //f. Válida
  resultado = contador < suma || tiempo > 1.0 && !(suma = itera);
  printf("F.%d\n", resultado);

  

}
