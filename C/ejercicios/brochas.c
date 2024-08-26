#include <stdio.h>

int main()
{
  int cantidadBrochas;
  int cantidadRodillos;

  int precioBrochas = 20000;
  int precioRodillos = 15000;

  printf("Ingrese la cantidad de brochas: ");
  scanf("%d", &cantidadBrochas);

  printf("Ingrese la cantidad de rodillos: ");
  scanf("%d", &cantidadRodillos);

  int totalBrochas = cantidadBrochas * precioBrochas;
  int descuentoBrochas = totalBrochas * .20;
  int precioFinalBrochas = totalBrochas - descuentoBrochas;
  printf("Precio total de brochas aplicando descuento: $%d\n", precioFinalBrochas);

  int totalRodillos = cantidadRodillos * precioRodillos;
  int descuentoRodillos = totalRodillos * .15;
  int precioFinalRodillos = totalRodillos - descuentoRodillos;
  printf("Precio total de rodillos aplicando descuento: $%d\n", precioFinalRodillos);

  int total = precioFinalBrochas + precioFinalRodillos;
  int totalDescuento = total * .07;  
  int totalFinal = total - totalDescuento;
  
  printf("Total pagando de contado: $%d\n", totalFinal);
  printf("Total pagando de a crédito: $%d\n", total);

}

