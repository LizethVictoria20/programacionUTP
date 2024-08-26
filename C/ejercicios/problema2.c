#include <stdio.h>

int main() {
    float espacio1, tiempo1, velocidad1;
    float espacio2, tiempo2, velocidad2;
    float espacio3, tiempo3, velocidad3;
    float espacio4, tiempo4, velocidad4;
    float espacio5, tiempo5, velocidad5;

    printf("Ingrese el espacio recorrido por el cuerpo 1 (en metros): ");
    scanf("%f", &espacio1);
    printf("Ingrese el tiempo empleado por el cuerpo 1 (en segundos): ");
    scanf("%f", &tiempo1);
    
    printf("Ingrese el espacio recorrido por el cuerpo 2 (en metros): ");
    scanf("%f", &espacio2);
    printf("Ingrese el tiempo empleado por el cuerpo 2 (en segundos): ");
    scanf("%f", &tiempo2);
    
    printf("Ingrese el espacio recorrido por el cuerpo 3 (en metros): ");
    scanf("%f", &espacio3);
    printf("Ingrese el tiempo empleado por el cuerpo 3 (en segundos): ");
    scanf("%f", &tiempo3);
    
    printf("Ingrese el espacio recorrido por el cuerpo 4 (en metros): ");
    scanf("%f", &espacio4);
    printf("Ingrese el tiempo empleado por el cuerpo 4 (en segundos): ");
    scanf("%f", &tiempo4);
    
    printf("Ingrese el espacio recorrido por el cuerpo 5 (en metros): ");
    scanf("%f", &espacio5);
    printf("Ingrese el tiempo empleado por el cuerpo 5 (en segundos): ");
    scanf("%f", &tiempo5);

    velocidad1 = espacio1 / tiempo1;
    velocidad2 = espacio2 / tiempo2;
    velocidad3 = espacio3 / tiempo3;
    velocidad4 = espacio4 / tiempo4;
    velocidad5 = espacio5 / tiempo5;

    float media_espacio = (espacio1 + espacio2 + espacio3 + espacio4 + espacio5) / 5;
    float media_tiempo = (tiempo1 + tiempo2 + tiempo3 + tiempo4 + tiempo5) / 5;
    float media_velocidad = (velocidad1 + velocidad2 + velocidad3 + velocidad4 + velocidad5) / 5;

    printf("La velocidad del cuerpo 1 es: %.2f m/s\n", velocidad1);
    printf("La velocidad del cuerpo 2 es: %.2f m/s\n", velocidad2);
    printf("La velocidad del cuerpo 3 es: %.2f m/s\n", velocidad3);
    printf("La velocidad del cuerpo 4 es: %.2f m/s\n", velocidad4);
    printf("La velocidad del cuerpo 5 es: %.2f m/s\n", velocidad5);

    printf("La media del espacio es: %.2f metros\n", media_espacio);
    printf("La media del tiempo es: %.2f segundos\n", media_tiempo);
    printf("La media de la velocidad es: %.2f m/s\n", media_velocidad);

    return 0;
}
