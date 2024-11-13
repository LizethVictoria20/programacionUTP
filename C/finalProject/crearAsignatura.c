#include <stdio.h>
#include <string.h>
#include "functions.h"

void crearAsignatura() {
    struct asignatura nueva_asignatura;
    // Pedir al usuario el ID y nombre de la asignatura
    printf("Ingrese el ID de la asignatura: ");
    scanf("%d", &nueva_asignatura.id);
    printf("Ingrese el nombre de la asignatura: ");
    scanf("%s", nueva_asignatura.nombre);

    // Abrir el archivo en modo binario de "append" para agregar nuevas asignaturas
    FILE *file = fopen("./archivos/asignaturas.txt", "ab");
    if (file == NULL) {
        perror("Error al abrir el archivo asignaturas.txt");
        return;
    }

    // Escribir la estructura en el archivo
    fwrite(&nueva_asignatura, sizeof(struct asignatura), 1, file);

    // Cerrar el archivo
    fclose(file);
    printf("Asignatura creada y guardada exitosamente.\n");
}