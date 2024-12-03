#ifndef MENUS_H
#define MENUS_H

// Estructura para Estudiante
typedef struct
{
  int cedula;
  char nombre[50];
  int edad;
  char correo[50];
} Estudiante;

// Estructura para Docente
typedef struct
{
  int cedula;
  char nombre[50];
  char especialidad[50];
  char correo[50];
} Docente;

// Estructura para Materia
typedef struct
{
  char codigo[15];
  char nombre[50];
  int creditos;
  char docenteCedula[15];
} Asignatura;

// Estructura para Nota
typedef struct
{
  int estudianteCedula;
  char materiaCodigo[10];
  float nota;
} Nota;

// Declaraciones de las funciones de los menús
// Declaración de funciones
void menus();
void crearPerfilProfesor();
void editarProfesor();
void eliminarProfesor();
void listarProfesores();
void crearAsignatura();
void editarAsignatura();
void eliminarAsignatura();
void listarAsignaturas();
void asignarMateriaProfesor();
void eliminarAsignacionProfesor();
void listarAsignaturaProfesor();
void crearPerfilEstudiante();
void editarEstudiante();
void eliminarEstudiante();
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

#endif // MENUS_H
