#include <stdio.h>
#include <string.h>

void menu()
{
  printf("--Menú de opciones-- \n");
  printf(" 1. Listar productos \n");
  printf(" 2. Venta producto \n");
  printf(" 3. Compra producto \n");
  printf(" 4. Ventas del día \n");
  printf(" 5. Salir \n");
}

void login()
{
  FILE *pf;
  char user[10], pwd[10], logUser[10], logpwd[10];
  char sino;

  printf("**********\n");
  printf("*  LOGIN ALMACÉN EL IMPERIO  *\n");
  printf("**********\n");

  printf("-> Ingrese el usuario: ");
  scanf("%s", logUser);
  printf("-> Ingrese la contraseña: ");
  scanf("%s", logpwd);

  pf = fopen("credentials.txt", "r");

  fscanf(pf, "%s", user);
  fscanf(pf, "%s", pwd);

  if (strcmp(logUser, user) == 0 && strcmp(logpwd, pwd) == 0)
  {
    printf("Bienvenido \n");
    menu();
  }
  else
  {
    printf(" Error: Usuario o contraseña incorrecta\n");
    printf("¿Desea intentar de nuevo? (s/n)\n");
    fflush(stdin);
    scanf(" %c", &sino);
    printf("%c", sino);
    if (sino == 's')
    {
      login();
    }
    else
    {
      printf("Gracias por visitar nuestro sitio");
    }
  }

  fclose(pf);
}