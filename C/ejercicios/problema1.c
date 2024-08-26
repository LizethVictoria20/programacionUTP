#include <stdio.h>

int main() {
    int num, invertido;
    int unidad, decena, centena, millar;

    printf("Ingrese un numero entero de 4 cifras: ");
    scanf("%d", &num);

    unidad = num % 10;         // última cifra
    decena = (num / 10) % 10;  // segunda cifra
    centena = (num / 100) % 10; // tercera cifra
    millar = num / 1000;       // primera cifra

    invertido = unidad * 1000 + decena * 100 + centena * 10 + millar;

    printf("El numero invertido es: %d\n", invertido);

    return 0;
}
