#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define MAX 20

int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int espacio = -1;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (lista[i].estado == 0)
        {
            espacio = lista[i].estado;
        }
    }

    return espacio;
}

int buscarPorDni(EPersona lista[], int dni, int tam)
{
    int indice = -1;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (dni == lista[i].dni)
        {
            indice = i;
        }
    }

    return indice;
}

void agregarPersona(EPersona lista[])
{
    EPersona aux;
    int lugar, siEsta, dni;

    lugar = obtenerEspacioLibre(lista, MAX);

    if (lugar == -1)
    {
        printf("\nNo hay lugar en el sistema\n\n");
        getch();
    }
    else
    {
        printf("\nIngrese el DNI: ");
        scanf("%d", &dni);

        siEsta = buscarPorDni(lista, dni, MAX);

        if (siEsta != -1)
        {
            printf("Ese DNI ya esta registrado\n");
            getch();
        }
        else
        {
            aux.dni = dni;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(aux.nombre);

            printf("Ingrese la edad: ");
            scanf("%d", &aux.edad);

            aux.estado = 1;

            lista[lugar] = aux;

        }

    }

}

void inicializarArray(EPersona lista[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
}

void borrarPersona(EPersona lista[])
{
    int siEsta, dni;
    char confirmacion;

    printf("Ingrese DNI: ");
    scanf("%d", &dni);

    siEsta = buscarPorDni(lista, dni, MAX);

    if (siEsta == -1)
    {
        printf("\nEl DNI ingresado no esta registrado\n\n");
        getch();
    }
    else
    {
        printf("\nEsta seguro de que desea borrar esta persona? s/n\n\n");

        fflush(stdin);

        scanf("%c", &confirmacion);

        fflush(stdin);

        if (confirmacion == 's')
        {
            lista[siEsta].estado = 0;
            printf("\nPersona borrada con exito\n\n");
        }
        else
        {
            printf("\nAccion cancelada\n\n");
        }
    }
}

void mostrarPersona(EPersona lista)
{
    printf("%s \t %d \t %d \n", lista.nombre, lista.dni, lista.edad);
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;
    int bandera = 0;

    printf("NOMBRE \t DNI \t EDAD \n");

    for (i = 0; i < tam; i++)
    {
        if (lista[i].estado != 0)
        {
            mostrarPersona(lista[i]);
            bandera = 1;
        }
    }
    if (!bandera)
    {
        printf("\nNo hay personas registradas\n\n");
        getch();
    }
}

void ordenarPersonas(EPersona lista[], int tam)
{
    int i, j;
    EPersona aux;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (strcmpi(lista[i].nombre, lista[j].nombre) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}










