#include <stdio.h>
#include <string.h>


void login();
void menú();

int main(){
    login();
 return 0;
}
 

void login(){
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

    pf= fopen("users.txt", "r");
    
    fscanf(pf, "%s", user);
    fscanf(pf, "%s", pwd);

    if(strcmp (logUser, user) == 0 && strcmp (logpwd, pwd) == 0 ){
        printf("Bienvenido \n");
        menú();
;    }
    else{
        printf(" Error: Usuario o contraseña incorrecta\n");
        printf("¿Desea intentar de nuevo? (s/n)\n");
        scanf("%c", &sino);
        printf("hhfsdf");
        printf("%c", sino);
        if (sino == 's')
        {
            login();
        }
        else {
            printf("Gracias por visitar nuestro sitio");
        }
    }

    fclose(pf);
}

void menú(){
    printf("--Menú de opciones-- \n");
    printf(" 1. Listar productos \n");
    printf(" 2. Venta producto \n");
    printf(" 3. Compra producto \n");
    printf(" 4. Ventas del día \n");
    printf(" 5. Salir \n");

}