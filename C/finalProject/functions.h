#ifndef MENUS_H
#define MENUS_H

typedef struct
{
  int cedula;
  char nombre[50];
  int edad;
  char correo[50];
} Estudiante;

typedef struct
{
  int cedula;
  char nombre[50];
  char especialidad[50];
  char correo[50];
} Docente;

typedef struct
{
  char codigo[15];
  char nombre[50];
  int creditos;
  char docenteCedula[15];
} Asignatura;

typedef struct
{
  int estudianteCedula;
  char materiaCodigo[10];
  float nota;
} Nota;

// Declaraciones de las funciones de los menús
void menus();
void crearPerfilProfesor();
void listarProfesores();
void crearAsignatura();
void listarAsignaturas();
void asignarMateriaProfesor();
void listarAsignaturaProfesor();
void crearPerfilEstudiante();
void listarEstudiantes();
void asignarMateriaEstudiante();
void eliminarAsignacionEstudiante();
void listarAsignaturaEstudiante();
void listarMateriaProfesor();

void menuAdministrador();
void menuDocente();
void menuEstudiante();
void crearActividades();
void limpiarBuffer();
void agregarNotaActividad(const char *nombreArchivo);
void agregarNotaEstudiante();
void listarNotasEstudiantes();
void mostrarNotasEstudiantes();
void mostrarNotasMateria();
int login(const char *archivoUsuarios);
#endif // MENUS_H
