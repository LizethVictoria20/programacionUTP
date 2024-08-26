#include <stdio.h>

int main()
{
  int valorProducto;

  printf("Ingrese el valor del producto: ");
  scanf("%d", &valorProducto);

  if(valorProducto <= 300000) {
    printf("El producto no paga impuestos.\n");
  }
  else if(valorProducto > 300000 && valorProducto < 600000) {
    int impuesto = 0.30 * valorProducto;
    int totalPagar = valorProducto + impuesto;

    printf("El impuesto a pagar es: %d\n", impuesto);
    printf("El total a pagar es: %d\n", totalPagar);
  }
  else if(valorProducto > 800000) {
    int impuesto = 0.50 * valorProducto;
    int totalPagar = valorProducto + impuesto;

    printf("El impuesto a pagar es: %d\n", impuesto);
    printf("El total a pagar es: %d\n", totalPagar);
  }
}
