#include <stdio.h>

int main()
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
