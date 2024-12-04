#include <stdio.h>
#include <string.h>
#include "functions.h"
#define MAX_LINEA 256

void mostrarNotasEstudiantes()
{
  FILE *archivoNotas;
  char linea[MAX_LINEA];
  char cedulaBuscada[MAX_LINEA];
  char cedulaEstudiante[MAX_LINEA];
  char nombreEstudiante[MAX_LINEA];
  char actividad[MAX_LINEA];
  float nota;
  int encontrada = 0;

  printf("Ingrese la cédula del estudiante: ");
  limpiarBuffer();
  fgets(cedulaBuscada, MAX_LINEA, stdin);
  cedulaBuscada[strcspn(cedulaBuscada, "\n")] = '\0';

  archivoNotas = fopen("archivos/notasestudiantes.txt", "r");
  if (archivoNotas == NULL)
  {
    printf("El archivo notasestudiantes.txt no existe o no se puede abrir.\n");
    return;
  }

  printf("\nIngrese de nuevo número de cédula: %s\n", cedulaBuscada);
  printf("-------------------------------\n");

  while (fgets(linea, MAX_LINEA, archivoNotas) != NULL)
  {
    char *token;

    token = strstr(linea, "Estudiante: ");
    if (token)
    {
      token += strlen("Estudiante: ");
      sscanf(token, "%[^|]", cedulaEstudiante);

      if (strcmp(cedulaEstudiante, cedulaBuscada) == 0)
      {
        encontrada = 1;

        char *inicioNombre = strchr(token, '|');
        if (inicioNombre)
        {
          inicioNombre += 1;
          char *finNombre = strchr(inicioNombre, '|');
          if (finNombre)
          {
            size_t len = finNombre - inicioNombre;
            strncpy(nombreEstudiante, inicioNombre, len);
            nombreEstudiante[len] = '\0';
          }
        }

        token = strstr(linea, "Actividad: ");
        if (token)
        {
          token += strlen("Actividad: ");
          char *finActividad = strchr(token, '|');
          if (finActividad)
          {
            size_t len = finActividad - token;
            strncpy(actividad, token, len);
            actividad[len] = '\0';
          }
        }

        token = strstr(linea, "Nota: ");
        if (token)
        {
          token += strlen("Nota: ");
          sscanf(token, "%f", &nota);
        }

        printf("Estudiante: %s | Actividad: %s | Nota: %.1f\n",
               nombreEstudiante, actividad, nota);
      }
    }
  }
  fclose(archivoNotas);

  if (!encontrada)
  {
    printf("No se encontraron notas para la cédula: %s\n", cedulaBuscada);
  }
  printf("-------------------------------\n");
}

void mostrarNotasMateria()
{
  FILE *archivoNotas;
  char linea[MAX_LINEA];
  char codigoMateria[MAX_LINEA];
  char estudiante[MAX_LINEA], codigoActividad[MAX_LINEA], actividad[MAX_LINEA];
  float nota;
  int porcentaje;
  int encontrada = 0;

  printf("Ingrese el código de la materia: ");
  limpiarBuffer();
  fgets(codigoMateria, MAX_LINEA, stdin);
  codigoMateria[strcspn(codigoMateria, "\n")] = '\0';

  archivoNotas = fopen("archivos/notasestudiantes.txt", "r");
  if (archivoNotas == NULL)
  {
    printf("El archivo notasestudiantes.txt no existe o no se puede abrir.\n");
    return;
  }

  printf("\nNotas de la materia con código: %s\n", codigoMateria);

  printf("-------------------------------------\n");

  while (fgets(linea, MAX_LINEA, archivoNotas) != NULL)
  {
    char *token;

    token = strstr(linea, "Actividad: ");
    if (token)
    {
      token += strlen("Actividad: ");
      sscanf(token, "%[^|]|%[^|]|%*d", codigoActividad, actividad);

      if (strcmp(codigoActividad, codigoMateria) == 0)
      {
        token = strstr(linea, "Estudiante: ");
        if (token)
        {
          token += strlen("Estudiante: ");
          sscanf(token, "%[^|]", estudiante);
        }

        token = strstr(linea, "Nota: ");
        if (token)
        {
          token += strlen("Nota: ");
          sscanf(token, "%f", &nota);
        }

        printf("Estudiante: %s | Actividad: %s | Nota: %.1f\n",
               estudiante, actividad, nota);
        encontrada = 1;
      }
    }
  }
  fclose(archivoNotas);

  if (!encontrada)
  {
    printf("No se encontraron notas para la materia con código: %s\n", codigoMateria);
  }
}