#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <locale.h>


void limpiarBuffer()
{
    while (getchar() != '\n');
}
void crearPerfilProfesor()
{
    Docente profesor;
    FILE *archivo;

    printf("\n=== Crear Perfil del Profesor ===\n");
    printf("Ingrese la cédula: ");
    scanf("%d", &profesor.cedula);
    limpiarBuffer();
    printf("Ingrese el nombre: ");
    fgets(profesor.nombre, 50, stdin);
    profesor.nombre[strcspn(profesor.nombre, "\n")] = '\0'; 
    printf("Ingrese la especialidad: ");
    fgets(profesor.especialidad, 50, stdin);
    profesor.especialidad[strcspn(profesor.especialidad, "\n")] = '\0';
    printf("Ingrese el correo: ");
    scanf("%s", profesor.correo);

    archivo = fopen("archivos/profesores.txt", "a+");
    if (archivo == NULL)
    {
        perror("Error al abrir o crear el archivo 'profesores.txt'");
        return;
    }

    fprintf(archivo, "%d|%s|%s|%s\n", profesor.cedula, profesor.nombre, profesor.especialidad, profesor.correo);

    fclose(archivo);

    printf("Perfil del profesor guardado exitosamente.\n");
}

void listarProfesores()
{
  FILE *archivo;
  char linea[200];

  archivo = fopen("archivos/profesores.txt", "r");
  if (archivo == NULL)
  {
    printf("No se pudo abrir el archivo 'profesores.txt' o no existen profesores registrados.\n");
    return;
  }

  printf("\n=== Lista de Profesores ===\n");

  while (fgets(linea, sizeof(linea), archivo) != NULL)
  {
    char cedula[15], nombre[50], especialidad[50], correo[50];

    sscanf(linea, "%[^|]|%[^|]|%[^|]|%[^\n]", cedula, nombre, especialidad, correo);

    printf("Cédula: %s\n", cedula);
    printf("Nombre: %s\n", nombre);
    printf("Especialidad: %s\n", especialidad);
    printf("Correo: %s\n", correo);
    printf("---------------------------\n");
  }

  fclose(archivo);
}
void crearAsignatura()
{
    Asignatura asignatura;
    FILE *archivo;

    printf("\n=== Crear Perfil de la Asignatura ===\n");
    printf("Ingrese el código de la asignatura: ");
    scanf("%s", asignatura.codigo);
    limpiarBuffer();
    printf("Ingrese el nombre de la asignatura: ");
    fgets(asignatura.nombre, 50, stdin);
    asignatura.nombre[strcspn(asignatura.nombre, "\n")] = '\0';
    printf("Ingrese el número de créditos: ");
    scanf("%d", &asignatura.creditos);
    limpiarBuffer();
    printf("Ingrese la cédula del docente asignado: ");
    scanf("%s", asignatura.docenteCedula);

    archivo = fopen("archivos/asignaturas.txt", "a+");
    if (archivo == NULL)
    {
        perror("Error al abrir o crear el archivo 'asignaturas.txt'");
        return;
    }

    fprintf(archivo, "%s|%s|%d|%s\n", asignatura.codigo, asignatura.nombre, asignatura.creditos, asignatura.docenteCedula);

    fclose(archivo);

    printf("Asignatura creada y guardada exitosamente.\n");
}

void listarAsignaturas()
{
  FILE *archivo;
  char linea[200];


  archivo = fopen("archivos/asignaturas.txt", "r");
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

  fclose(archivo);
}

void asignarMateriaProfesor()
{
    char codigoMateria[10], cedulaProfesor[15];
    FILE *archivoMaterias, *archivoProfesores, *archivoAsignaciones;
    char linea[200];
    int materiaEncontrada = 0, profesorEncontrado = 0;

    printf("\n=== Asignar Materia a Profesor ===\n");
    printf("Ingrese el código de la materia: ");
    scanf("%s", codigoMateria);

    archivoMaterias = fopen("archivos/asignaturas.txt", "r");
    if (archivoMaterias == NULL)
    {
        printf("Error: No se pudo abrir el archivo 'asignaturas.txt'. Asegúrese de que el archivo exista.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivoMaterias) != NULL)
    {
        char codigo[10], nombre[50];
        int creditos;
        sscanf(linea, "%[^|]|%[^|]|%d|%*s", codigo, nombre, &creditos);
        if (strcmp(codigo, codigoMateria) == 0)
        {
            materiaEncontrada = 1;
            printf("Materia encontrada: %s - %s (%d créditos)\n", codigo, nombre, creditos);
            break;
        }
    }
    fclose(archivoMaterias);

    if (!materiaEncontrada)
    {
        printf("Error: La materia con código '%s' no existe.\n", codigoMateria);
        return;
    }

    printf("Ingrese la cédula del profesor: ");
    scanf("%s", cedulaProfesor);

    archivoProfesores = fopen("archivos/profesores.txt", "r");
    if (archivoProfesores == NULL)
    {
        printf("Error: No se pudo abrir el archivo 'profesores.txt'. Asegúrese de que el archivo exista.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivoProfesores) != NULL)
    {
        char cedula[15], nombre[50];
        sscanf(linea, "%[^|]|%[^|]|%*s|%*s", cedula, nombre);
        if (strcmp(cedula, cedulaProfesor) == 0)
        {
            profesorEncontrado = 1;
            printf("Profesor encontrado: %s - %s\n", cedula, nombre);
            break;
        }
    }
    fclose(archivoProfesores);

    if (!profesorEncontrado)
    {
        printf("Error: El profesor con cédula '%s' no existe.\n", cedulaProfesor);
        return;
    }

    archivoAsignaciones = fopen("archivos/asignaciones.txt", "a+");
    if (archivoAsignaciones == NULL)
    {
        perror("Error al abrir o crear el archivo 'asignaciones.txt'");
        return;
    }

    fprintf(archivoAsignaciones, "%s|%s\n", codigoMateria, cedulaProfesor);
    fclose(archivoAsignaciones);

    printf("Asignación guardada exitosamente: Materia '%s' asignada al Profesor '%s'.\n", codigoMateria, cedulaProfesor);
}

void listarMateriaProfesor()
{
    FILE *archivoMaterias, *archivoProfesores, *archivoAsignaciones;
    char lineaAsignacion[100], lineaMateria[200], lineaProfesor[200];
    char codigoMateria[10], cedulaProfesor[15];
    int encontrado;

    archivoAsignaciones = fopen("archivos/asignaciones.txt", "r");
    if (archivoAsignaciones == NULL)
    {
        printf("Error: No se pudo abrir el archivo 'asignaciones.txt'. Asegúrese de que existan asignaciones.\n");
        return;
    }

    printf("\n=== Lista de Materias Asignadas a Profesores ===\n");

    while (fgets(lineaAsignacion, sizeof(lineaAsignacion), archivoAsignaciones) != NULL)
    {
        sscanf(lineaAsignacion, "%[^|]|%[^\n]", codigoMateria, cedulaProfesor);

        archivoMaterias = fopen("archivos/asignaturas.txt", "r");
        if (archivoMaterias == NULL)
        {
            printf("Error: No se pudo abrir el archivo 'asignaturas.txt'.\n");
            fclose(archivoAsignaciones);
            return;
        }

        encontrado = 0;
        char nombreMateria[50];
        while (fgets(lineaMateria, sizeof(lineaMateria), archivoMaterias) != NULL)
        {
            char codigo[10], nombre[50];
            sscanf(lineaMateria, "%[^|]|%[^|]|%*d|%*s", codigo, nombre);
            if (strcmp(codigo, codigoMateria) == 0)
            {
                strcpy(nombreMateria, nombre);
                encontrado = 1;
                break;
            }
        }
        fclose(archivoMaterias);

        if (!encontrado)
        {
            printf("Error: Materia con código '%s' no encontrada.\n", codigoMateria);
            continue;
        }

        archivoProfesores = fopen("archivos/profesores.txt", "r");
        if (archivoProfesores == NULL)
        {
            printf("Error: No se pudo abrir el archivo 'profesores.txt'.\n");
            fclose(archivoAsignaciones);
            return;
        }

        encontrado = 0;
        char nombreProfesor[50];
        while (fgets(lineaProfesor, sizeof(lineaProfesor), archivoProfesores) != NULL)
        {
            char cedula[15], nombre[50];
            sscanf(lineaProfesor, "%[^|]|%[^|]|%*s|%*s", cedula, nombre);
            if (strcmp(cedula, cedulaProfesor) == 0)
            {
                strcpy(nombreProfesor, nombre);
                encontrado = 1;
                break;
            }
        }
        fclose(archivoProfesores);

        if (!encontrado)
        {
            printf("Error: Profesor con cédula '%s' no encontrado.\n", cedulaProfesor);
            continue;
        }

        printf("Materia: %s | Profesor: %s\n", nombreMateria, nombreProfesor);
    }

    fclose(archivoAsignaciones);
}

void crearPerfilEstudiante()
{
  Estudiante alumno;
  FILE *archivo;

  printf("\n=== Crear Perfil del Estudiante ===\n");
  printf("Ingrese la cédula: ");
  scanf("%d", &alumno.cedula);
  printf("Ingrese el nombre: ");
  getchar(); 
  fgets(alumno.nombre, 50, stdin);
  alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0';
  printf("Ingrese la edad: ");
  scanf("%d", &alumno.edad);
  getchar(); 
  printf("Ingrese el correo: ");
  scanf("%s", alumno.correo);

  archivo = fopen("archivos/estudiantes.txt", "a");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    return;
  }

  fprintf(archivo, "%d|%s|%d|%s\n", alumno.cedula, alumno.nombre, alumno.edad, alumno.correo);

  fclose(archivo);

  printf("Perfil del estudiante guardado exitosamente.\n");
}

void listarEstudiantes()
{
  FILE *archivo;
  char linea[200]; 

  archivo = fopen("archivos/estudiantes.txt", "r");
  if (archivo == NULL)
  {
    printf("No se pudo abrir el archivo 'estudiantes.txt' o no existen estudiantes registrados.\n");
    return;
  }

  printf("\n=== Lista de Estudiantes ===\n");

  while (fgets(linea, sizeof(linea), archivo) != NULL)
  {
    int cedula; char nombre[50]; int edad; char correo[50];

    sscanf(linea, "%d|%[^|]|%d|%[^\n]", &cedula, nombre, &edad, correo);

    printf("Cédula: %d\n", cedula);
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);
    printf("Correo: %s\n", correo);
    printf("---------------------------\n");
  }

  fclose(archivo);
}