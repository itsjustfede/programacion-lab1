#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"


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
    ArrayList* pArrayListEmployee;
    pArrayListEmployee=al_newArrayList();
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
        {
            printf("***MENU***\n1. Parse del archivo data.csv\n2. Listar Empleados\n3. Ordenar por nombre\n4. Agregar un elemento\n5. Elimina un elemento\n6. Listar empleados (desde/hasta)\n\nElija una opcion: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    parserEmployee(pArrayListEmployee);
                    break;
                case 2:
                    employee_print(pArrayListEmployee);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                default:
                    printf("\n\nERROR AL INGRESAR LA OPCION DESEADA\n\n");
                    break;

            }

        }

    return 0;
}
