#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funcionesFede.h"

int menu()
{
    char opcion[10];
    system("cls");
    printf("\n***ESTACIONAMIENTO***\n\n\n");
    printf("1- Parse del archivo data.csv\n");
    printf("2- Listar Empleados\n");
    printf("3- Ordenar por nombre\n");
    printf("4- Agregar un elemento\n");
    printf("5- Elimina un elemento\n");
    printf("6- Salir\n");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    gets(opcion);

    while(validarNumero(opcion) == 0 || atoi(opcion) < 1 || atoi(opcion) > 6)
    {
        printf("Opcion incorrecta, debe ingresar valores del 1 al 6: ");
        fflush(stdin);
        gets(opcion);
    }

    return atoi(opcion);

}

int validarNumero(char numero[])
{
   int i = 0, devuelve = 1;

   while(numero[i] != '\0')
   {
       if(numero[i] < '0' || numero[i] > '9')
       {
           devuelve = 0;
           break;
       }

       i++;
   }
   return devuelve;
}
