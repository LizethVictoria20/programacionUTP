#include <stdio.h>
#include <string.h>
#include "functions.h"

int login(const char *archivoUsuarios)
{
  char usuario[50], password[50], rol[20];
  char usuarioIngresado[50], passwordIngresado[50];
  int autenticado = 0;

  FILE *archivo = fopen(archivoUsuarios, "r");
  if (!archivo)
  {
    printf("Error al abrir el archivo.\n");
    return 0;
  }

  printf("Usuario: ");
  scanf("%s", usuarioIngresado);
  printf("Contraseña: ");
  scanf("%s", passwordIngresado);

  while (fscanf(archivo, "%s %s %s", usuario, password, rol) != EOF)
  {
    if (strcmp(usuario, usuarioIngresado) == 0 && strcmp(password, passwordIngresado) == 0)
    {
      autenticado = 1;
      printf("\nInicio de sesión exitoso como %s (%s).\n", usuario, rol);
      fclose(archivo);

      if (strcmp(rol, "administrador") == 0)
      {
        menuAdministrador();
      }
      else if (strcmp(rol, "estudiante") == 0)
      {
        menuEstudiante();
      }
      else if (strcmp(rol, "docente") == 0)
      {
        menuDocente();
      }
      else
      {
        printf("Rol no reconocido.\n");
      }
      return 1;
    }
  }

  fclose(archivo);
  if (!autenticado)
  {
    printf("\nCredenciales incorrectas.\n");
  }

  return 0;
}
void menus()
{
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
    printf("3. Crear perfil del estudiante\n");
    printf("4. Asignar materia al profesor\n");
    printf("5. Asignar materia al estudiante\n");
    printf("6. Listar profesores\n");
    printf("7. Listar asignaturas\n");
    printf("8. Listar estudiantes\n");
    printf("9. Listar materia/profesor\n");
    printf("10. Volver\n");
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
      crearPerfilEstudiante();
      break;
    case 4:
      asignarMateriaProfesor();
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
      listarEstudiantes();
      break;
    case 9:
      listarMateriaProfesor();
      break;
    case 10:
      return;
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
    printf("2. Agregar nota a estudiante\n");
    printf("3. Mostrar notas de todos los estudiantes\n");
    printf("4. Volver\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      crearActividades();
      break;
    case 2:
      agregarNotaEstudiante();
      break;
    case 3:
      listarNotasEstudiantes();
      break;
    case 4:
      return;
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
      mostrarNotasEstudiantes();
      break;
    case 2:
      mostrarNotasMateria();
      break;
    case 3:
      return;
    default:
      printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != 3);
}
