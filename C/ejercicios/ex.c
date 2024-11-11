#include <stdio.h>

int main() {
    int n, i, j, x, y, dx = 0, dy = -1, num_primos = 2, es_primo;

    printf("Ingrese el tamaño del cuadrado (impar mayor que 1): ");
    scanf("%d", &n);

    if (n < 3 || n % 2 == 0) {
        printf("El número debe ser impar y mayor que 1.\n");
        return 1;
    }

    x = y = n / 2;

    int total = n * n; 
    int pasos = 1; 
    int contador_pasos = 0;
    int cambios_direccion = 0; 

    printf("1\n");  


    for (int k = 2; k <= total; k++) {
        es_primo = 0;
        while (!es_primo) {
            es_primo = 1;
            for (int d = 2; d * d <= num_primos; d++) {
                if (num_primos % d == 0) {
                    es_primo = 0; 
                    break;
                }
            }
            if (!es_primo) {
                num_primos++;  
            }
        }

        printf("%3d ", num_primos);
        num_primos++;  

        if (contador_pasos == pasos) {
            contador_pasos = 0;
            cambios_direccion++;

            if (dx == 0 && dy == -1) {
                dx = -1; dy = 0;  
            } else if (dx == -1 && dy == 0) {
                dx = 0; dy = 1;   
            } else if (dx == 0 && dy == 1) {
                dx = 1; dy = 0;  
            } else if (dx == 1 && dy == 0) {
                dx = 0; dy = -1; 
            }

            if (cambios_direccion % 2 == 0) {
                pasos++;  
            }
        }
        x += dx;
        y += dy;
        contador_pasos++;
        if (k % n == 0) {
            printf("\n");
        }
    }

    return 0;
}
