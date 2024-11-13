#include <stdio.h>
#include <string.h>
#include "functions.h"

void crearAsignatura() {
    struct asignatura nueva_asignatura;
    printf("Ingrese el ID de la asignatura: ");
    scanf("%d", &nueva_asignatura.id);
    printf("Ingrese el nombre de la asignatura: ");
    scanf("%s", nueva_asignatura.nombre);

    FILE *file = fopen("./archivos/asignaturas.txt", "ab+");
    if (file == NULL) {
        perror("Error al abrir el archivo asignaturas.txt");
        return;
    }

    fwrite(&nueva_asignatura, sizeof(struct asignatura), 1, file);

    fclose(file);
    printf("Asignatura creada y guardada exitosamente.\n");
}

void leerAsignaturas() {
    struct asignatura asignatura_leida;
    FILE *file = fopen("./archivos/asignaturas.txt", "rb+");

    if (file == NULL) {
        perror("Error al abrir el archivo asignaturas.txt");
        return;
    }

    printf("Asignaturas guardadas:\n");
    while (fread(&asignatura_leida, sizeof(struct asignatura), 1, file)) {
        printf("ID: %d, Nombre: %s\n", asignatura_leida.id, asignatura_leida.nombre);
    }

    fclose(file);
}