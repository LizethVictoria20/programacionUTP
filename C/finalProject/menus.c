#include <stdio.h>
#include "functions.h"

void menus() {
   int opcion;

  do
  {
    printf("\nMenú Principal\n");
    printf("1. Administrador\n");
    printf("2. Docente\n");
    printf("3. Estudiante\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      menuAdministrador();
      break;
    case 2:
      menuDocente();
      break;
    case 3:
      menuEstudiante();
      break;
    case 4:
      printf("Saliendo del programa...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != 4);


}

void menuAdministrador()
{
  int opcion;

  do
  {
    printf("\nMenú Administrador\n");
    printf("1. Crear perfil del profesor\n");
    printf("2. Crear perfil de la asignatura\n");
    printf("3. Asignar materia al profesor\n");
    printf("4. Crear perfil del estudiante\n");
    printf("5. Asignar materia al estudiante\n");
    printf("6. Listar profesores\n");
    printf("7. Listar asignaturas\n");
    printf("8. Volver\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      crearPerfilProfesor();
      break;
    case 2:
      crearAsignatura();
      break;
    case 3:
      asignarMateriaProfesor();
      break;
    case 4:
      crearPerfilEstudiante();
      break;
    case 5:
      asignarMateriaEstudiante();
      break;
    case 6:
      listarProfesores();
      break;
    case 7:
      listarAsignaturas();
      break;
    case 8:
      printf("Volviendo al menú principal...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != 6);
}

void menuDocente()
{
  int opcion;

  do
  {
    printf("\nMenú Docente\n");
    printf("1. Crear actividades y porcentajes\n");
    printf("2. Crear notas para actividades\n");
    printf("3. Listar estudiantes\n");
    printf("4. Mostrar notas de todos los estudiantes\n");
    printf("5. Volver\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("Función para crear actividades.\n");
      break;
    case 2:
      printf("Función para crear notas.\n");
      break;
    case 3:
      listarEstudiantes();
      break;
    case 4:
      printf("Función para mostrar notas de todos los estudiantes.\n");
      break;
    case 5:
      printf("Volviendo al menú principal...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != 5);
}

void menuEstudiante()
{
  int opcion;

  do
  {
    printf("\nMenú Estudiante\n");
    printf("1. Mostrar todas las notas\n");
    printf("2. Mostrar notas de una materia específica\n");
    printf("3. Volver\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("Función para mostrar todas las notas.\n");
      break;
    case 2:
      printf("Función para mostrar notas específicas.\n");
      break;
    case 3:
      printf("Volviendo al menú principal...\n");
      break;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != 3);
}
