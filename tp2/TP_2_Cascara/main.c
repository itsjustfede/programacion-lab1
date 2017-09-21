#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20


int main()
{
    char seguir='s';
    int opcion=0;

    EPersona persona[MAX];

    inicializarArray(persona, MAX);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(persona);
                break;
            case 2:
                system("cls");
                borrarPersona(persona);
                break;
            case 3:
                system("cls");
                ordenarPersonas(persona, MAX);
                mostrarPersonas(persona, MAX);
                break;
            case 4:

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
