#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main() {
  float x = 3.5;
  float v = 1.4;
  float p = 6.0;
  float raiz2_x;
  float nuevo_valor_v;
  char letra = 'p';
  int i = 5;
  int cont = -4;
  int k = 2;
  bool terminar = true;
  bool bandera;
  raiz2_x = sqrt(x);// Calcular la raíz cuadrada de x
  nuevo_valor_v = x + (p - raiz2_x * (v - x) + 3.0) * p;
  printf("El nuevo valor de v es: %.2f\n", nuevo_valor_v);

//----------------------------------------------------------------------------------------------------------------------------------------------------------    

  bool condicion1 = (i + 2 <= cont) || (p >= v);
  bool negacion_condicion1 = !condicion1;
  bool resultado_primera_parte = terminar || negacion_condicion1;
  bool condicion2 = (x + v) == p;
  bandera = resultado_primera_parte || condicion2;
  printf("El valor de bandera es: %s\n", bandera ? "verdadero" : "falso");

//----------------------------------------------------------------------------------------------------------------------------------------------------------
  int realAentero = (int)(x * v - p / 2.0);
  i = cont * realAentero + k - i;
  printf("El nuevo valor de i es: %d\n", i);
    
//----------------------------------------------------------------------------------------------------------------------------------------------------------

  int parte1 = (k - 2 * cont) * (k - 2 * cont);
  float parte2 = (float)i * (cont - k / 2.0) / cont;
  k = parte1 + (int)parte2;
  printf("El nuevo valor de k es: %d\n", k);// llama i del punto anterior
    
//----------------------------------------------------------------------------------------------------------------------------------------------------------
  int valorEntero = (int) letra;
  float valorReal = (float) valorEntero;
  x = v + valorReal;
  printf("El valor de x es: %.2f\n", x);
    
//----------------------------------------------------------------------------------------------------------------------------------------------------------

  cont = cont + 1;
  printf("EL valor de cont despues del incremento es: %d\n", cont);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------