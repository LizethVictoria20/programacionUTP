#include <stdio.h>
#include <string.h>
#include "functions.h"

void menuGeneral()
{
  printf("Menu\n");
}

void menuEst()
{
  printf("Estudiante\n");
}


void menuDoc()
{
  int opcion;
  printf("\nMenú Profesor\n");
  printf("\n");
  printf("1. Crear Asignatura\n");
  printf("2. Ver Asignaturas\n");
  printf("3. Agregar Nota\n");
  printf("4. Ver Alumnos\n");
  printf("5. Salir\n");
  printf("\n");
  printf("Seleccione una opción: ");
  scanf("%d", &opcion);


  switch (opcion)
  {
  case 1:
    crearAsignatura();
    menuDoc();
    break;
  case 2:
    leerAsignaturas();
    menuDoc();
    break;
  default:
    printf("Opción inválida.\n");
  }
}