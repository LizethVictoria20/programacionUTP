// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct asignatura {
    int id;
    char nombre[50];
};

struct alumno {
  int id;
  char nombre[50];
};

void login();
void menuGeneral();
void menuEst();
void menuDoc();
void crearAsignatura();
void leerAsignaturas();
void crearAlumno();
void leerAlumnos();
#endif
