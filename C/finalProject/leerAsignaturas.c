#include <stdio.h>
#include <string.h>
#include "functions.h"


void leerAsignaturas() {
    struct asignatura asignatura_leida;
    FILE *file = fopen("./archivos/asignaturas.txt", "r");

    if (file == NULL) {
        perror("Error al abrir el archivo asignaturas.txt");
        return;
    }

    printf("Asignaturas guardadas:\n");
    printf("+----+------------------------------+\n");
    printf("| ID \t | Nombre                       \n");
    printf("+----+------------------------------+\n");

    while (fscanf(file, "%d %[^\n]", &asignatura_leida.id, asignatura_leida.nombre) == 2) {
      printf("| %d \t | %s |\n", asignatura_leida.id, asignatura_leida.nombre);
    }

    printf("+----+------------------------------+\n");

    fclose(file);
}