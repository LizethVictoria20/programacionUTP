#include <stdio.h>
#include <string.h>
#include "functions.h"

void crearAlumno() {
    struct alumno nueva_alumno;
    printf("Ingrese el ID del alumno: ");
    scanf("%d", &nueva_alumno.id);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nueva_alumno.nombre);

    FILE *file = fopen("./archivos/alumnos.txt", "ab+");
    if (file == NULL) {
        perror("Error al abrir el archivo alumnos.txt");
        return;
    }

    fwrite(&nueva_alumno, sizeof(struct alumno), 1, file);

    fclose(file);
    printf("Alumno creado y guardado exitosamente.\n");
}

void leerAlumnos() {
    struct alumno alumno_leido;
    FILE *file = fopen("./archivos/alumnos.txt", "rb+");

    if (file == NULL) {
        perror("Error al abrir el archivo alumnos.txt");
        return;
    }

    printf("Alumnos guardados:\n");
    printf("+----+------------------------------+\n");
    printf("| ID \t | Nombre                       |\n");
    printf("+----+------------------------------+\n");

    while (fread(&alumno_leido, sizeof(struct alumno), 1, file)) {
        printf("| %d \t | %s |\n", alumno_leido.id, alumno_leido.nombre);
    }

    printf("+----+------------------------------+\n");

    fclose(file);
}