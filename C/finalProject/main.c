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