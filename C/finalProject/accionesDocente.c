#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <locale.h>


void crearActividades()
{
    FILE *archivo;
    char codigoMateria[10], actividad[50];
    int porcentaje, sumaPorcentajes = 0;

    printf("\n=== Crear Actividades para una Materia ===\n");
    printf("Ingrese el código de la materia: ");
    scanf("%s", codigoMateria);
    limpiarBuffer();

    archivo = fopen("archivos/actividades.txt", "a+");
    if (archivo == NULL)
    {
        perror("Error al abrir o crear el archivo 'actividades.txt'");
        return;
    }

    printf("Ingrese las actividades y sus porcentajes (hasta 100%%)\n");
    printf("\n");

    // Repetir hasta que la suma de porcentajes sea 100
    while (sumaPorcentajes < 100)
    {
        printf("Ingrese el nombre de la actividad: ");
        fgets(actividad, sizeof(actividad), stdin);
        actividad[strcspn(actividad, "\n")] = '\0';

        printf("Ingrese el porcentaje para esta actividad: ");
        scanf("%d", &porcentaje);
        limpiarBuffer();

        // Verificar que el porcentaje no exceda el límite permitido
        if (sumaPorcentajes + porcentaje > 100)
        {
            printf("Error: El porcentaje total no puede exceder el 100%%. Quedan %d%% disponibles.\n", 100 - sumaPorcentajes);
            continue;
        }

        // Guardar la actividad y el porcentaje en el archivo
        fprintf(archivo, "%s|%s|%d\n", codigoMateria, actividad, porcentaje);
        sumaPorcentajes += porcentaje;

        printf("Actividad '%s' con %d%% registrada exitosamente. Total acumulado: %d%%.\n", actividad, porcentaje, sumaPorcentajes);

        // Si se alcanza el 100%, salir del bucle
        if (sumaPorcentajes == 100)
        {
            printf("Todas las actividades han sido asignadas correctamente.\n");
            break;
        }
    }

    fclose(archivo);
}

#define MAX_LINEA 256

void agregarNotaActividad(const char *nombreArchivo) {
    FILE *archivo;
    char lineas[100][MAX_LINEA];
    int cantidadLineas = 0;
    int seleccion;
    float nota;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("El archivo %s no existe o no se puede abrir.\n", nombreArchivo);
        return;
    }

    while (fgets(lineas[cantidadLineas], MAX_LINEA, archivo) != NULL) {
        lineas[cantidadLineas][strcspn(lineas[cantidadLineas], "\n")] = '\0';
        cantidadLineas++;
    }
    fclose(archivo);

    if (cantidadLineas == 0) {
        printf("El archivo está vacío. Por favor, agrega actividades primero.\n");
        return;
    }

    printf("Actividades disponibles:\n");
    for (int i = 0; i < cantidadLineas; i++) {
        printf("%d. %s\n", i + 1, lineas[i]);
    }

    printf("Selecciona el número de la actividad a la que deseas agregar una nota: ");
    scanf("%d", &seleccion);

    if (seleccion < 1 || seleccion > cantidadLineas) {
        printf("Selección inválida. Por favor, selecciona un número válido.\n");
        return;
    }

    printf("Ingresa una nota entre 0 y 5 (pueden ser decimales): ");
    scanf("%f", &nota);

    if (nota < 0 || nota > 5) {
        printf("Nota inválida. Debe estar entre 0 y 5.\n");
        return;
    }

    char nuevaLinea[MAX_LINEA];
    snprintf(nuevaLinea, MAX_LINEA, "%s - Nota: %.1f", lineas[seleccion - 1], nota);
    strncpy(lineas[seleccion - 1], nuevaLinea, MAX_LINEA);

    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se puede abrir el archivo %s para escritura.\n", nombreArchivo);
        return;
    }

    for (int i = 0; i < cantidadLineas; i++) {
        fprintf(archivo, "%s\n", lineas[i]);
    }
    fclose(archivo);

    printf("Se ha agregado la nota %.1f a la actividad: %s\n", nota, lineas[seleccion - 1]);
}

