#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char [], int );
void mostarNombres(char [][20], int );
void mostrarNombre(char []);
void ordenarNombres(char [][20], int );

int main()
{
    char nombres[5][20];
    char auxcad[100];
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:\n");
        fflush(stdin);
        gets(auxcad);

        while (!validarCadena(auxcad, 20))
        {
            printf("Error!!! Noombre demasiado largo, reingrese:\n");
            gets(auxcad);
        }

        strcpy(nombres[i], auxcad);
    }

    /*for (i = 0; i < 5; i++)
    {
        printf("El nombre es: %s\n", nombres[i]);
    }*/

    printf("\n\n");

    mostarNombres(nombres, 5);

    printf("\n\n");

    ordenarNombres(nombres, 5);

    printf("\n\n");

    mostarNombres(nombres, 5);

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

void mostarNombres(char cad[][20], int filas)
{
    int i;
    for (i = 0; i < filas; i++)
    {
        mostrarNombre(cad[i]);
    }
}

void mostrarNombre(char cad[])
{
    printf("El nombre es: %s\n", cad);
}

void ordenarNombres(char cad[][20], int filas)
{
    int i, j;
    char aux[20];

    for(i=0; i < filas-1; i++)
    {
        for(j = i+1; j < filas; j++)
        {
            if(strcmpi(cad[i], cad[j]) > 0)
            {
                strcpy(aux, cad[i]);
                strcpy(cad[i], cad[j]);
                strcpy(cad[j], aux);
            }
        }
    }
}










