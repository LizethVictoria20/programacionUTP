#include <stdio.h>

int main() {
  //Triangulo
  int b = 5;
  int h = 12;
  int l = 5;
  int m = 6;
  int n = 7;
  int totalTriangulo = l + m + n;
  int areaTriangulo = (b * h) / 2;

  //Cuadrado
  int a = 5;
  int P = a * 4;
  int A = a * a;

  //Rectángulo
  int baseRec = 10;
  int alturaRec = 8;
  int totalReactangulo = 2 * baseRec + 2 * alturaRec;
  int areaRectangulo = baseRec * alturaRec;


  //Pentágono
  int g = 5;
  int h1 = 5;
  int i = 5;
  int j = 5;
  int k = 5;

  //Rombo
  int ladoRombo = 6;
  int menorRombo = 10;
  int mayorRombo = 8;
  int perimetroRombo = 4 * ladoRombo;
  int areaRombo = (mayorRombo + menorRombo) / 2;
  

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tFORMA\t\t|\tELEMENTOS\t|\tFÓRMULA PERÍMETRO\t|\tFÓRMULA ÁREA\t|\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tTRIÁNGULO\t|\tb: Base - %d\t|\tP = l + m + n\t\t|\tA = b * h / 2\t|\n", b);
    printf("\t\t\t|\th: Altura- %d\t|\t%d =  %d + %d + %d\t\t|\t%d = %d * %d / 2\t|\n", h, totalTriangulo, l, m, n, areaTriangulo, b, h);
    printf("\t\t\t|\tl: Lado 1 - %d\t|\t\t\t\t|\t\t\t|\n", l);
    printf("\t\t\t|\tm: Lado 2 - %d\t|\t\t\t\t|\t\t\t|\n", m);
    printf("\t\t\t|\tn: Lado 3 - %d\t|\t\t\t\t|\t\t\t|\n", n);

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tCUADRADO\t|\ta: Lado\t\t\t|\tP = 4a\t\t\t|\tA = a ^ 2\t|\n");
    printf("\t\t\t|\ta: %d\t\t\t|\t%d = 4 * %d\t\t|\t%d = %d ^ 2\t|\n", a, P, a, A, a);

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tRÉCTANGULO\t|\tb: Base - %d\t\t|\tP = 2 * b + 2h\t\t|\tA = b * h\t|\n", baseRec);
    printf("\t\t\t|\th: Altura - %d\t\t|\t%d = 2 * %d + 2 * %d\t|\t%d = %d * %d\t|\n", alturaRec, totalReactangulo, baseRec, alturaRec, areaRectangulo, baseRec, alturaRec);


    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tROMBO\t\t|\ta: Lado - %d\t\t|\t%d = 4 * %d\t\t|\t%d = %d * %d / 2\t|\n", ladoRombo, perimetroRombo, ladoRombo, areaRombo, mayorRombo, menorRombo);
    printf("\t\t\t|\td: Diagonal menor\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\tD: Diagonal mayor\t|\t\t\t\t|\t\t\t|\n");


    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tROMBOIDE\t|\tb: Base\t\t\t|\tP = 2b + 2h\t\t|\tA = b * h\t\t|\n");
    printf("\t\t\t|\th: Altura\t\t|\t\t\t\t|\t\t\t|\n");


    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\tTRAPECIO\t|\tl: Lado 1\t\t|\tP = l + m + n + o\t|\tA = h (B + b) / 2\t\t|\n");
    printf("\t\t\t|\tm: Lado 2\t\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\tn: Lado 3\t\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\to: Lado 4\t\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\tb: Base menor\t\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\tB: Base mayor\t\t|\t\t\t\t|\t\t\t|\n");
    printf("\t\t\t|\th: Altura\t\t|\t\t\t\t|\t\t\t|\n");

    printf("--------------------------------------------------------------------------------------------------------\n");

    return 0;
}
