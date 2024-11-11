#include <stdio.h>
#include <string.h>

void crearArchivoUsuario();
void login();
void menu();

int main() {
    crearArchivoUsuario(); // Crear el archivo al inicio, si no existe
    login();
    return 0;
}

void crearArchivoUsuario() {
    FILE *pf = fopen("users.txt", "r");
    if (pf == NULL) {  // Si el archivo no existe, crearlo
        pf = fopen("users.txt", "w");
        if (pf != NULL) {
            fprintf(pf, "admin\n1234\n");  // Escribe usuario y contraseña predeterminados
            fclose(pf);
            printf("Archivo 'users.txt' creado con usuario y contraseña predeterminados.\n");
        } else {
            printf("Error: No se pudo crear el archivo de usuarios.\n");
        }
    } else {
        fclose(pf);  // Cierra el archivo si ya existe
    }
}

void login() {
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

    pf = fopen("users.txt", "r");
    if (pf == NULL) {
        printf("Error: No se pudo abrir el archivo de usuarios.\n");
        return;
    }

    fscanf(pf, "%s", user);
    fscanf(pf, "%s", pwd);

    if (strcmp(logUser, user) == 0 && strcmp(logpwd, pwd) == 0) {
        printf("Bienvenido \n");
        menu();
    } else {
        printf("Error: Usuario o contraseña incorrecta\n");
        printf("¿Desea intentar de nuevo? (s/n): ");
        getchar();
        sino = getchar();
        if (sino == 's' || sino == 'S') {
            login();
        } else {
            printf("Gracias por visitar nuestro sitio\n");
        }
    }

    fclose(pf);
}

void menu() {
    printf("--Menú de opciones-- \n");
    printf(" 1. Listar productos \n");
    printf(" 2. Venta producto \n");
    printf(" 3. Compra producto \n");
    printf(" 4. Ventas del día \n");
    printf(" 5. Salir \n");
}
