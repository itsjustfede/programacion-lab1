#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int salir = 1;

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");

            getch();
            break;

        case 2:
            system("cls");

            getch();
            break;
        case 3:
            system("cls");

            getch();
            break;

        case 4:
            system("cls");

            getch();
            break;

        case 5:
            system("cls");

            getch();
            break;
        case 6:
            salir = 0;
            break;
        default:
            system("cls");
            printf("Opcion incorrecta");
            getch();
            break;
        }
    }
    while(salir);

    return 0;
}
