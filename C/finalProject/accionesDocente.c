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