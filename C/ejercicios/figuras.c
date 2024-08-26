#include <stdio.h>


//Color
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"



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


  //Rombo
  int ladoRombo = 6;
  int menorRombo = 10;
  int mayorRombo = 8;
  int perimetroRombo = 4 * ladoRombo;
  int areaRombo = (mayorRombo * menorRombo) / 2;

  //Romboide
  int baseRomboide = 20;
  int alturaRomboide = 12;
  int perimetroRomboide = (2 * baseRomboide) + (2 * alturaRomboide);
  int areaRomboide = baseRomboide * alturaRomboide;

  //Trapecio
  int lTrapecio = 3;
  int mTrapecio = 9;
  int nTrapecio = 4;
  int oTrapecio = 8;
  int baseMenorTrapecio = 12;
  int baseMayorTrapecio = 18;
  int alturaTrapecio = 10;
  int perimetroTrapecio = lTrapecio + mTrapecio + nTrapecio + oTrapecio;
  int areaTrapecio = alturaTrapecio * ( baseMayorTrapecio + baseMenorTrapecio) / 2;
  

  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(GREEN "|\tFORMA\t\t|\tELEMENTOS\t\t|\tFÓRMULA PERÍMETRO\t|\tFÓRMULA ÁREA\t\t\t|\n");
  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(YELLOW "|\tTRIÁNGULO\t|\tb: Base - %d\t\t|\tP = l + m + n\t\t|\tA = b * h / 2\t\t\t|\n", b);
  printf(YELLOW "|\t\t\t|\th: Altura- %d\t\t|\t%d =  %d + %d + %d\t\t|\t%d = %d * %d / 2\t\t\t|\n", h, totalTriangulo, l, m, n, areaTriangulo, b, h);
  printf(YELLOW "|\t\t\t|\tl: Lado 1 - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", l);
  printf(YELLOW "|\t\t\t|\tm: Lado 2 - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", m);
  printf(YELLOW "|\t\t\t|\tn: Lado 3 - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", n);

  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(BLUE "|\tCUADRADO\t|\ta: Lado\t\t\t|\tP = 4a\t\t\t|\tA = a ^ 2\t\t\t|\n");
  printf(BLUE "|\t\t\t|\ta: %d\t\t\t|\t%d = 4 * %d\t\t|\t%d = %d ^ 2\t\t\t|\n", a, P, a, A, a);

  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(MAGENTA "|\tRÉCTANGULO\t|\tb: Base - %d\t\t|\tP = 2 * b + 2h\t\t|\tA = b * h\t\t\t|\n", baseRec);
  printf(MAGENTA "|\t\t\t|\th: Altura - %d\t\t|\t%d = 2 * %d + 2 * %d\t|\t%d = %d * %d\t\t\t|\n", alturaRec, totalReactangulo, baseRec, alturaRec, areaRectangulo, baseRec, alturaRec);


  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(RED "|\tROMBO\t\t|\ta: Lado - %d\t\t|\tP = 4 * 2\t\t|\tA = D * d / 2\t\t\t|\n", ladoRombo);
  printf(RED "|\t\t\t|\td: Diagonal menor - %d\t|\t%d = 4 * %d\t\t|\t%d = %d * %d / 2\t\t\t|\n", menorRombo, perimetroRombo, ladoRombo,areaRombo,mayorRombo, menorRombo);
  printf(RED "|\t\t\t|\tD: Diagonal mayor - %d\t|\t\t\t\t|\t\t\t\t\t|\n", mayorRombo);


  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(GREEN "|\tROMBOIDE\t|\tb: Base - %d\t\t|\tP = 2b + 2h\t\t|\tA = b * h\t\t\t|\n", baseRomboide);
  printf(GREEN "|\t\t\t|\th: Altura - %d\t\t|\t%d = 2 * %d + 2 * %d\t|\t%d = %d * %d\t\t\t|\n", alturaRomboide, perimetroRomboide, baseRomboide, alturaRomboide, areaRomboide, baseRomboide, alturaRomboide);


  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");
  printf(CYAN "|\tTRAPECIO\t|\tl: Lado 1 - %d\t\t|\tP = l + m + n + o\t|\tA = h (B + b) / 2\t\t|\n", lTrapecio);
  printf(CYAN "|\t\t\t|\tm: Lado 2 - %d\t\t|\t%d = %d + %d + %d + %d\t|\t%d = %d * (%d + %d) / 2\t|\n", mTrapecio, perimetroTrapecio, lTrapecio, mTrapecio, nTrapecio, oTrapecio, areaTrapecio,alturaTrapecio, baseMayorTrapecio, baseMenorTrapecio);
  printf(CYAN "|\t\t\t|\tn: Lado 3 - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", nTrapecio);
  printf(CYAN "|\t\t\t|\to: Lado 4 - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", oTrapecio);
  printf(CYAN "|\t\t\t|\tb: Base menor - %d\t|\t\t\t\t|\t\t\t\t\t|\n", baseMenorTrapecio);
  printf(CYAN "|\t\t\t|\tB: Base mayor - %d\t|\t\t\t\t|\t\t\t\t\t|\n", baseMayorTrapecio);
  printf(CYAN "|\t\t\t|\th: Altura - %d\t\t|\t\t\t\t|\t\t\t\t\t|\n", alturaTrapecio);

  printf(RESET "---------------------------------------------------------------------------------------------------------------------------------\n");

  return 0;
}
