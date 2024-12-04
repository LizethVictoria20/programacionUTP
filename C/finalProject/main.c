#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <locale.h>

int main()
{
  const char *archivoUsuarios = "archivos/accesos.txt";

  printf("*** Sistema de Login ***\n");

  if (login(archivoUsuarios)) {
      printf("\nSesión cerrada.\n");
  } else {
      printf("\nNo se pudo iniciar sesión.\n");
  }
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