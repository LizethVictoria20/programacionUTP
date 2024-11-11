#include <stdio.h>
#include <string.h>
#include "functions.h"

void menu();

struct alumno {
  int id;
  char nombre[50];
};

struct docente {
  int id;
  char nombre[50];
};

struct asignatura {
  int id;
  char nombre[50];
  struct docente docente;
};


int main(){
  login();
 return 0;
}

