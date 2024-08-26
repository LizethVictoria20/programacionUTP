#include <stdio.h>

int main()
{

  int opc;
  char caracter;

  printf("Ingrese 1 para consultar precio de brochas y rodillos.\n");
  printf("Ingrese 2 para consultar el valor de impuestos a pagar.\n");
  printf("Ingrese 3 para consultar el calendario.\n");
  printf("Ingrese 4 para consultar las horas trabajadas.\n\n");
  printf("Ingrese el la opción que desea consultar: ");

  scanf("%i", &opc);

  if (opc >= 1 && opc <= 4)
  {

    if (opc == 1)
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
    else if (opc == 2)
    {
      int valorProducto;

      printf("Ingrese el valor del producto: ");
      scanf("%d", &valorProducto);

      if (valorProducto <= 300000)
      {
        printf("El producto no paga impuestos.\n");
      }
      else if (valorProducto > 300000 && valorProducto < 600000)
      {
        int impuesto = 0.30 * valorProducto;
        int totalPagar = valorProducto + impuesto;

        printf("El impuesto a pagar es: %d\n", impuesto);
        printf("El total a pagar es: %d\n", totalPagar);
      }
      else if (valorProducto > 800000)
      {
        int impuesto = 0.50 * valorProducto;
        int totalPagar = valorProducto + impuesto;

        printf("El impuesto a pagar es: %d\n", impuesto);
        printf("El total a pagar es: %d\n", totalPagar);
      }
    }
    else if (opc == 3)
    {
      // Programa que pide un número del 1 al 7 y dice el dia de la semana .
      printf("Falta ejercicio de calendario ");
    }
    else if (opc == 4)
    {
      char nombreEmpleado[20];
      int horasTrabajadas;
      int valorHoraStandar = 20000;

      printf("Ingrese el nombre del empleado: ");
      scanf("%s", nombreEmpleado);

      printf("Ingrese las horas trabajadas: ");
      scanf("%d", &horasTrabajadas);

      if (horasTrabajadas <= 40)
      {
        int sueltoTotal = valorHoraStandar * horasTrabajadas;
        printf("Horas trabajadas %d y sueldo total es: %d", horasTrabajadas, sueltoTotal);
      }
      else if (horasTrabajadas > 40 && horasTrabajadas < 50)
      {
        int horasExtra = horasTrabajadas - 40;

        int sueldo = (horasTrabajadas - horasExtra) * valorHoraStandar;
        printf("suelto neto sin horas extras: %d\n", sueldo);

        int extra = horasExtra * (valorHoraStandar * 2);
        printf("Valor de horas extras: %d\n", extra);

        int sueldoTotal = sueldo + extra;
        printf("Sueldo total: %d", sueldoTotal);
      }

      else if (horasTrabajadas > 50)
      {
        int horasExtra = horasTrabajadas - 50;

        int sueldo = (horasTrabajadas - horasExtra) * valorHoraStandar;
        printf("suelto neto sin horas extras: %d\n", sueldo);

        int extra = horasExtra * (valorHoraStandar * 3);
        printf("Valor de horas extras: %d\n", extra);

        int sueldoTotal = sueldo + extra;
        printf("Sueldo total: %d\n", sueldoTotal);

        int pagoDeImpuesto = sueldoTotal * .12;
        printf("Valor a pagar de impuestos: %d\n", pagoDeImpuesto);

        int sueltoConImpuestos = sueldoTotal - pagoDeImpuesto;

        printf("Pago definitivo: %d", sueltoConImpuestos);
      }
    }
  }
  else
    printf("Opcion invalida");
  return 0;
}
