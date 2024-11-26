#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Estructura para Estudiante
typedef struct
{
  char cedula[15];
  char nombre[50];
  int edad;
  char correo[50];
} Estudiante;

// Estructura para Docente
typedef struct
{
  char cedula[15];
  char nombre[50];
  char especialidad[50];
  char correo[50];
} Docente;

// Estructura para Materia
typedef struct
{
  char codigo[10];
  char nombre[50];
  int creditos;
  char docenteCedula[15];
} Materia;

// Estructura para Nota
typedef struct
{
  char estudianteCedula[15];
  char materiaCodigo[10];
  float nota;
} Nota;



int main()
{
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
  printf("Función para crear asignatura.\n");
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
  printf("Función para listar asignaturas.\n");
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
void crearPerfilEstudiante()
{
  printf("Función para crear perfil de estudiante.\n");
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
  printf("Función para listar estudiantes.\n");
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
