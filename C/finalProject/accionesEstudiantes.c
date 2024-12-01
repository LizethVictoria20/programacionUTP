#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Función para crear perfil del estudiante 
void crearPerfilEstudiante()
{
  Estudiante alumno;
  FILE *archivo;

  // Solicitar los datos del estudiante
  printf("\n=== Crear Perfil del Estudiante ===\n");
  printf("Ingrese la cédula: ");
  scanf("%d", &alumno.cedula);
  printf("Ingrese el nombre: ");
  getchar(); // Para consumir el salto de línea anterior
  fgets(alumno.nombre, 50, stdin);
  alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0'; // Eliminar el salto de línea
  printf("Ingrese la edad: ");
  scanf("%d", &alumno.edad);
  getchar(); // Consumir el salto de línea restante
  printf("Ingrese el correo: ");
  scanf("%s", &alumno.correo);

  // Abrir el archivo en modo "a" (adición) para agregar nuevos estudiantes
  archivo = fopen("archivos/estudiantes.txt", "a");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    return;
  }

  // Escribir los datos del estudiante en el archivo
  fprintf(archivo, "%s|%s|%s|%s\n", alumno.cedula, alumno.nombre, alumno.edad, alumno.correo);

  // Cerrar el archivo
  fclose(archivo);

  printf("Perfil del estudiante guardado exitosamente.\n");
}
void editarEstudiante()
{
  printf("Función para editar perfil de estudiante.\n");
}
void eliminarEstudiante()
{
  printf("Función para eliminar estudiante.\n");
}
void listarEstudiantes()
{
  FILE *archivo;
  char linea[200]; // Línea temporal para leer cada registro

  // Abrir el archivo en modo lectura
  archivo = fopen("archivos/estudiantes.txt", "r");
  if (archivo == NULL)
  {
    printf("No se pudo abrir el archivo 'estudiantes.txt' o no existen estudiantes registrados.\n");
    return;
  }

  printf("\n=== Lista de Estudiantes ===\n");

  // Leer línea por línea el archivo
  while (fgets(linea, sizeof(linea), archivo) != NULL)
  {
    int cedula; char nombre[50]; int edad; char correo[50];

    // Separar la línea en campos usando '|' como delimitador
    sscanf(linea, "%[^|]|%[^|]|%[^|]|%[^\n]", cedula, nombre, edad, correo);

    // Mostrar la información del estudiante
    printf("Cédula: %s\n", cedula);
    printf("Nombre: %s\n", nombre);
    printf("Edad: %s\n", edad);
    printf("Correo: %s\n", correo);
    printf("---------------------------\n");
  }

  // Cerrar el archivo
  fclose(archivo);
}