#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[21];
    char apellido[21];
    char nombreApellido[41];
    char buffer[2000];
    char cantNombre;
    char cantApellido;

    printf("Ingrese el nombre...\n");
    gets(buffer);
    cantNombre = strlen(buffer);

    while (cantNombre > 20)
    {
        printf("Error!!! Reingrese el nombre...\n");
        gets(buffer);
        cantNombre = strlen(buffer);
    }
    strcpy(nombre, buffer);


    printf("Ingrese el apellido...\n");
    gets(buffer);
    cantApellido = strlen(buffer);


    while (cantApellido > 20)
    {
        printf("Error!!! Reingrese el apellido...\n");
        gets(buffer);
        cantApellido = strlen(buffer);
    }
    strcpy(apellido, buffer);

    strcpy(nombreApellido, apellido);

    strcat(nombreApellido, ", ");

    strcat(nombreApellido, nombre);

    printf("%s", nombreApellido);



    return 0;
}
