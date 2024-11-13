#include <stdio.h>
#include <string.h>
#include "functions.h"



void login()
{
  FILE *accesoDoc;
  FILE *accesoEst;
  char user[10], pwd[10], logUser[10], logpwd[10];
  char sino;
  int isDocente = -1;

  printf("*********************\n");
  printf("*  PORTAL DE NOTAS  *\n");
  printf("*********************\n");

  printf("-> Ingrese el usuario: ");
  scanf("%s", logUser);
  printf("-> Ingrese la contraseña: ");
  scanf("%s", logpwd);

  accesoDoc = fopen("./archivos/credentialsDoc.txt", "r");
  fscanf(accesoDoc, "%s", user);
  fscanf(accesoDoc, "%s", pwd);
  if (strcmp(logUser, user) == 0 && strcmp(logpwd, pwd) == 0)
  {
    isDocente = 1;
  }
  fclose(accesoDoc);

  if (isDocente == -1)
  {
    accesoEst = fopen("./archivos/credentialsEst.txt", "r");
    fscanf(accesoEst, "%s", user);
    fscanf(accesoEst, "%s", pwd);
    if (strcmp(logUser, user) == 0 && strcmp(logpwd, pwd) == 0)
    {
      isDocente = 0;
    }
    fclose(accesoEst);
  }

  if (isDocente == 1)
  {
    menuDoc();
  }
  else if (isDocente == 0)
  {
    menuEst();
  }
  else
  {
    printf("Error: Usuario o contraseña incorrecta\n");
    printf("¿Desea intentar de nuevo? (s/n): ");
    fflush(stdin);
    scanf("%c", &sino);
    if (sino == 's' || sino == 'S')
    {
      login();
    }
    else
    {
      printf("Bye!!!\n");
    }
  }
}
