#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "es_ES.UTF-8");
  menus();
}

// Funciones de ejemplo
void crearPerfilProfesor()
{
  Docente profesor;
  FILE *archivo;

  // Solicitar los datos del profesor
  printf("\n=== Crear Perfil del Profesor ===\n");
  printf("Ingrese la cédula: ");
  scanf("%s", profesor.cedula);
  printf("Ingrese el nombre: ");
  getchar(); // Para consumir el salto de línea anterior
  fgets(profesor.nombre, 50, stdin);
  profesor.nombre[strcspn(profesor.nombre, "\n")] = '\0'; // Eliminar el salto de línea
  printf("Ingrese la especialidad: ");
  fgets(profesor.especialidad, 50, stdin);
  profesor.especialidad[strcspn(profesor.especialidad, "\n")] = '\0'; // Eliminar el salto de línea
  printf("Ingrese el correo: ");
  scanf("%s", profesor.correo);

  // Abrir el archivo en modo "a" (adición) para agregar nuevos profesores
  archivo = fopen("/archivos/profesores.txt", "a");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    return;
  }

  // Escribir los datos del profesor en el archivo
  fprintf(archivo, "%s|%s|%s|%s\n", profesor.cedula, profesor.nombre, profesor.especialidad, profesor.correo);

  // Cerrar el archivo
  fclose(archivo);

  printf("Perfil del profesor guardado exitosamente.\n");
}
void editarProfesor()
{
  printf("Función para editar perfil de profesor.\n");
}
void eliminarProfesor()
{
  printf("Función para eliminar profesor.\n");
}
void listarProfesores()
{
  FILE *archivo;
  char linea[200]; // Línea temporal para leer cada registro

  // Abrir el archivo en modo lectura
  archivo = fopen("archivos/profesores.txt", "r");
  if (archivo == NULL)
  {
    printf("No se pudo abrir el archivo 'profesores.txt' o no existen profesores registrados.\n");
    return;
  }

  printf("\n=== Lista de Profesores ===\n");

  // Leer línea por línea el archivo
  while (fgets(linea, sizeof(linea), archivo) != NULL)
  {
    char cedula[15], nombre[50], especialidad[50], correo[50];

    // Separar la línea en campos usando '|' como delimitador
    sscanf(linea, "%[^|]|%[^|]|%[^|]|%[^\n]", cedula, nombre, especialidad, correo);

    // Mostrar la información del profesor
    printf("Cédula: %s\n", cedula);
    printf("Nombre: %s\n", nombre);
    printf("Especialidad: %s\n", especialidad);
    printf("Correo: %s\n", correo);
    printf("---------------------------\n");
  }

  // Cerrar el archivo
  fclose(archivo);
}
void crearAsignatura()
{
  Asignatura asignatura;
  FILE *archivo;

  // Solicitar los datos de la asignatura
  printf("\n=== Crear Perfil de la Asignatura ===\n");
  printf("Ingrese el código de la asignatura: ");
  scanf("%s", asignatura.codigo);
  getchar();
  printf("Ingrese el nombre de la asignatura: ");
  fgets(asignatura.nombre, 50, stdin);
  asignatura.nombre[strcspn(asignatura.nombre, "\n")] = '\0';
  printf("Ingrese el número de créditos: ");
  scanf("%d", &asignatura.creditos);
  printf("Ingrese la cédula del docente asignado: ");
  scanf("%s", asignatura.docenteCedula);

  archivo = fopen("/archivos/asignaturas.txt", "a");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    return;
  }

  // Escribir los datos de la asignatura en el archivo
  fprintf(archivo, "%s|%s|%d|%s\n", asignatura.codigo, asignatura.nombre, asignatura.creditos, asignatura.docenteCedula);

  // Cerrar el archivo
  fclose(archivo);

  printf("Asignatura creada y guardada exitosamente.\n");
}
void editarAsignatura()
{
  printf("Función para editar asignatura.\n");
}
void eliminarAsignatura()
{
  printf("Función para eliminar asignatura.\n");
}
void listarAsignaturas()
{
  FILE *archivo;
  char linea[200];


  archivo = fopen("/archivos/asignaturas.txt", "r");
  if (archivo == NULL)
  {
    printf("No se pudo abrir el archivo 'asignaturas.txt' o no existen asignaturas registradas.\n");
    return;
  }

  printf("\n=== Lista de Asignaturas ===\n");

  while (fgets(linea, sizeof(linea), archivo) != NULL)
  {
    char codigo[10], nombre[50], docenteCedula[15];
    int creditos;

    sscanf(linea, "%[^|]|%[^|]|%d|%[^\n]", codigo, nombre, &creditos, docenteCedula);

    printf("Código: %s\n", codigo);
    printf("Nombre: %s\n", nombre);
    printf("Créditos: %d\n", creditos);
    printf("Cédula del Docente: %s\n", docenteCedula);
    printf("---------------------------\n");
  }

  // Cerrar el archivo
  fclose(archivo);
}
void asignarMateriaProfesor()
{
  printf("Función para asignar materia al profesor.\n");
}
void eliminarAsignacionProfesor()
{
  printf("Función para eliminar asignación del profesor.\n");
}
void listarAsignaturaProfesor()
{
  printf("Función para listar asignatura y su profesor.\n");
}
void asignarMateriaEstudiante()
{
  printf("Función para asignar materia al estudiante.\n");
}
void eliminarAsignacionEstudiante()
{
  printf("Función para eliminar asignación del estudiante.\n");
}
void listarAsignaturaEstudiante()
{
  printf("Función para listar asignaturas y sus estudiantes.\n");
}
