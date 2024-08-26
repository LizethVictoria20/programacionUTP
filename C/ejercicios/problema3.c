#include <stdio.h>

int main() {
    #define PI  3.141592

    float R;

    printf("Ingrese el valor del radio R: ");
    scanf("%f", &R);

    float longitud1 = 2 * PI * R;
    float longitud2 = 2 * PI * 2 * R;
    float longitud3 = 2 * PI * 3 * R;

    float area1 = PI * R * R;
    float area2 = PI * (2 * R) * (2 * R);
    float area3 = PI * (3 * R) * (3 * R);

    printf("La longitud de la primera circunferencia es: %.2f\n", longitud1);
    printf("El área de la primera circunferencia es: %.2f\n", area1);

    printf("La longitud de la segunda circunferencia es: %.2f\n", longitud2);
    printf("El área de la segunda circunferencia es: %.2f\n", area2);

    printf("La longitud de la tercera circunferencia es: %.2f\n", longitud3);
    printf("El área de la tercera circunferencia es: %.2f\n", area3);

    return 0;
}
