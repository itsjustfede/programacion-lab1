#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include "misFunciones.h"

int main()
{
    ECliente lista[20];
    eEstacionamiento estacionamiento[20];
    int i;
    int opcion=0;
    char respuesta='s';
    int flagCarga=0;
    for(i=0;i<20;i++)
    {
        strcpy(lista[i].apellido," ");
        strcpy(lista[i].nombre," ");
        lista[i].edad=0;
        lista[i].idCliente=0;
        lista[i].dni=0;
    }
    do
    {
        flagCarga=0;
        opcion=0;
        for(i=0;i<20;i++)
        {
            if(lista[i].idCliente!=0)
            {
                flagCarga=1;
            }
        }
        if(flagCarga==0)
        {
            printf("1- Agregar Cliente\n");
        }
        else
        {
            printf("1- Agregar Cliente\n");
            printf("2- Modificar Cliente\n");
            printf("3- Eliminar Cliente\n");
            printf("4- Mostrar Cliente\n");
            printf("5- Mostrar Clientes\n");
            printf("6- Salir\n");
        }
        fflush(stdin);
        scanf("%d",&opcion);
        while(flagCarga==0 && opcion!=1)
        {
            printf("Para gestionar otras opciones primero debe dar de alta un cliente, por favor presione 1: ");
            fflush(stdin);
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                agregarCliente(lista);
                break;
            case 2:
                break;
            case 3:
                eliminarCliente(lista);
                break;
            case 4:
                entradaEstacionamiento(lista,estacionamiento);
                break;
            case 5:
                mostrarOrdenado(lista);
                break;
            case 6:
                respuesta='n';
                break;
            default:
                printf("No es una opcion valida del menu\n");
                break;
        }
        system("pause");
        system("cls");
    }while(respuesta!='n');
    return 0;
}
