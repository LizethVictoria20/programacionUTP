#include <stdio.h>

int main() {
    int valorCM, valorMt, valorKm;

    printf("Ingrese el valor en cm: ");
    scanf("%d", &valorCM);
    
    printf("Ingrese el valor en m: ");
    scanf("%d", &valorMt);
    int conversionMtToCm = valorMt * 100;     
    
    printf("Ingrese el valor en km: ");
    scanf("%d", &valorKm);
    int conversionKmToMt = valorKm * 1000;   

    printf("---------------------------------------------------------------------------------------------------|\n");
    printf("|\tVALOR\t\t|\tCONVERSIÓN\t|\tCm\t|\tMt\t|\tKm\t\n");
    
    printf("---------------------------------------------------------------------------------------------------|\n");
    printf("|\t%d\t\t|\tCm\t\t|\t%d\t|\t-\t|\t-\t\n", valorCM, valorCM);
    
    printf("---------------------------------------------------------------------------------------------------|\n");
    printf("|\t%d\t\t|\tMt\t\t|\t%d\t|\t%d\t|\t-\t\n", valorMt, conversionMtToCm, valorMt);
    
    printf("---------------------------------------------------------------------------------------------------|\n");
    printf("|\t%d\t\t|\tKm\t\t|\t%d\t|\t%d\t|\t%d\t\n", valorKm, conversionKmToMt, conversionKmToMt, valorKm);
    printf("---------------------------------------------------------------------------------------------------|\n");

    return 0;
}
