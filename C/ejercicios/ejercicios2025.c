#include <stdio.h>
#include <math.h>

int main()
{
  int op;
  printf("Ingrese 1 para saber si la división de dos números.\nIngrese 2 para conocer area de diferentes triangulos.\nIngrese 3 para hacer conversión de masa.\nIngrese 4 para calcula impuestos.\nIngrese 5 para saber hora\nIngrese 6 para calcular aumento de sueldo\n");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
  {
    int num1, num2, num3;
    printf("Ingrese tres números enteros: \n");
    printf("Primer número: \n");
    scanf("%d", &num1);
    printf("Segundo número: \n");
    scanf("%d", &num2);
    printf("Tercer número: \n");
    scanf("%d", &num3);

    int division = num1 / num2;

    if (division == num3)
    {
      printf("El resultado de la división es igual al tercer número.\n");
    }
    else
    {
      printf("El resultado de la división no es igual al tercer número.\n");
    }
  }
  break;
  case 2:
  {
    int opTriangle;
    printf("Ingrese 1 para conocer area de triangulo Equilátero\nIngrease 2 para conocer area de triangulo Isósceles\nIngrease 3 para conocer area de triangulo Escaleno\n");
    scanf("%d", &opTriangle);
    switch (opTriangle)
    {
    case 1:
    {
      float lado;
      printf("Ingrese la base y altura del triangulo equilátero: ");
      scanf("%f", &lado);
      float area = (sqrt(3) / 4 * lado * lado);
      printf("El área del triángulo equilátero es: %.2f\n", area);
    }
    break;
    case 2:
    {
      float base, altura;
      printf("Ingrese la base y las alturas del triangulo isósceles: ");
      scanf("%f %f", &base, &altura);
      float area = (base * altura) / 2;
      printf("El área del triángulo isósceles es: %.2f\n", area);
    }
    break;
    case 3:
    {
      float lado1, lado2, lado3;
      printf("Ingrese la base y las alturas del triangulo escaleno: ");
      scanf("%f %f %f", &lado1, &lado2, &lado3);
      float area = (lado1 + lado2 + lado3) / 2;
      printf("El área del triángulo escaleno es: %.2f\n", area);
    }
    break;
    default:
      printf("Ingrese un opción correcta.\n");
    }
  }
  break;
  case 3:
  {
    int opKg;
    printf("Ingrese la opción a la que quiere hacer la conversion.\n");
    printf("1. Kg a hg\n");
    printf("2. Kg a dag\n");
    printf("3. Kg a g\n");
    printf("4. Kg a dg\n");
    printf("5. Kg a cg\n");
    printf("6. Kg a mg\n");
    scanf("%d", &opKg);

    int kg;
    printf("Ingrese la cantidad de kilogramos: ");
    scanf("%d", &kg);
    switch (opKg)

    {
    case 1:
    {
      int convertion = kg * 10;
      printf("%d Kg equivale a %d hg.\n", kg, convertion);
    }
    break;
    case 2:
    {
      int convertion = kg * 100;
      printf("%d Kg equivale a %d dag.\n", kg, convertion);
    }
    break;
    case 3:
    {
      int convertion = kg * 1000;
      printf("%d Kg equivale a %d g.\n", kg, convertion);
    }
    break;
    case 4:
    {
      int convertion = kg * 10000;
      printf("%d Kg equivale a %d dg.\n", kg, convertion);
    }
    break;
    case 5:
    {
      int convertion = kg * 100000;
      printf("%d Kg equivale a %d cg.\n", kg, convertion);
    }
    break;
    case 6:
    {
      int convertion = kg * 1000000;
      printf("%d Kg equivale a %d mg.\n", kg, convertion);
    }
    break;
    default:
      printf("Ingrese una opción correcta.\n");
      return main();
    }
  }
  break;
  case 4:
  {
    int importeBruto;
    ;
    printf("Ingrese importe bruto\n");
    scanf("%d", &importeBruto);

    if (importeBruto > 15.000)
    {
      int impuesto = importeBruto * .16;
      int importeNeto = importeBruto + impuesto;
      printf("Importe neto: %d\n", importeNeto);
    }
    else
    {
      int impuesto = importeBruto * .10;
      int importeNeto = importeBruto + impuesto;
      printf("Importe neto: %d\n", importeNeto);
    }
  }
  break;
  case 5:
  {
    int hora;
    int minuto;
    int segundo;
    printf("Ingrese la hora:\n");
    scanf("%d", &hora);

    printf("Ingrese el minuto:\n");
    scanf("%d", &minuto);

    printf("Ingrese el segundo:\n");
    scanf("%d", &segundo);

    if (segundo >= 59)
    {
      segundo = 0;
      minuto += 1;
      printf("La hora siguiente es: %d: %d: %d", hora, minuto, segundo);
    }
    else if (minuto >= 59)
    {
      minuto = 0;
      segundo += 1;
      hora += 1;
      printf("La hora siguiente es: %dh: %dm: %ds", hora, minuto, segundo);
    }
    else
    {
      printf("La hora actual es: %dh: %dm: %ds", hora, minuto, segundo);
    }
  }
  break;
  case 6:
  {
    int sueldoAnual = 40000;
    int anios;
    printf("Ingrese la cantidad de tiempo en años que ha trabajado en la empresa: ");
    scanf("%d", &anios);

    if (anios >= 10)
    {
      int aumento = sueldoAnual * .10;
      int sueldoAumento = sueldoAnual + aumento;
      printf("Sueldo anual total: %d\n", sueldoAumento);
    }
    else if (anios > 5 && anios <= 10)
    {
      int aumento = sueldoAnual * .07;
      int sueldoAumento = sueldoAnual + aumento;
      printf("Sueldo anual total: %d\n", sueldoAumento);
    }
    else if (anios > 3 && anios <= 5)
    {
      int aumento = sueldoAnual * .05;
      int sueldoAumento = sueldoAnual + aumento;
      printf("Sueldo anual total: %d\n", sueldoAumento);
    }
    else if (anios < 3)
    {
      int aumento = sueldoAnual * .3;
      int sueldoAumento = sueldoAnual + aumento;
      printf("Sueldo anual total: %d\n", sueldoAumento);
    }
  }
  break;
  default:
    printf("Ingrese una opción correcta.\n\n");
    main();
  }
}