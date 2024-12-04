#include <stdio.h>
#include <string.h>
#define MAX_LINEA 256

void mostrarNotasPorMateria() {
    FILE *archivoNotas;
    char linea[MAX_LINEA];
    char materia[MAX_LINEA];
    int encontrada = 0;

    // Solicitar al usuario el nombre de la materia
    printf("Ingrese el nombre de la materia: ");
    fgets(materia, MAX_LINEA, stdin);
    materia[strcspn(materia, "\n")] = '\0'; // Eliminar el salto de línea

    // Abrir el archivo de notas en modo lectura
    archivoNotas = fopen("archivos/notasestudiantes.txt", "r");
    if (archivoNotas == NULL) {
        printf("El archivo notasestudiantes.txt no existe o no se puede abrir.\n");
        return;
    }

    // Leer el contenido del archivo línea por línea
    printf("Notas para la materia: %s\n", materia);
    printf("---------------------------------\n");
    while (fgets(linea, MAX_LINEA, archivoNotas) != NULL) {
        // Verificar si la línea contiene el nombre de la materia
        if (strstr(linea, materia) != NULL) {
            printf("%s", linea); // Imprimir la línea que coincide
            encontrada = 1;
        }
    }
    fclose(archivoNotas);

    if (!encontrada) {
        printf("No se encontraron notas para la materia: %s\n", materia);
    }
    printf("---------------------------------\n");
}
