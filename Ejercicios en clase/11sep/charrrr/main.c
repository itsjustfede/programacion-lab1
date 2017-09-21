#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cad[], int tam);

int main()
{
    char nombre[20];
    char auxcad[100];

    printf("Ingrese el nombre:\n");
    fflush(stdin);
    gets(auxcad);

    while (!validarCadena(auxcad, 20))
    {
        printf("Error!!! Noombre demasiado largo, reingrese:\n");
        gets(auxcad);
    }

    strcpy(nombre, auxcad);
    printf("El nombre es: %s", nombre);

    return 0;
}

int validarCadena(char cad[], int tam)
{
    int valor = 0;

    if(strlen(cad) < tam)
    {
        valor = 1;
    }

    return valor;
}


