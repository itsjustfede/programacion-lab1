#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char opcion,seguir='s';
    EPersona lista[CANT];
    int i,ubicacion;


    for (i=0;i<CANT;i++)
        lista[i].estado=0;


    while(seguir=='s')
        {

        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
            {
            case '1':
                ubicacion=obtenerEspacioLibre(lista);
                if (ubicacion!=-1)
                lista[ubicacion]=AgregarPersona(lista);
                else
                    printf("\nERROR!!!!!. No hay espacios disponibles para guardar otra persona.\n");

                break;
            case '2':
                ubicacion=buscarPorDni(lista);
                lista[ubicacion]=borrarPersona(lista[ubicacion],ubicacion);
                break;
            case '3':
                ordenamientoFunc (lista);
                break;
            case '4':
                graficoEdades (lista);
                break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("ERROR!!!!!. Ingrese un numero entre 1 y 5\n\n");
            }

        }

    return 0;
}
