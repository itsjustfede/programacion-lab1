#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CONSTANTE 200
int main()
{
    EMovie peliculas;
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Mostrar peliculas\n");
        printf("5- Generar pagina web\n");
        printf("6- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                agregarPelicula(&peliculas);
                break;
            case 2:
                if(mostrarPeliculas())
                    borrarPelicula(&peliculas);
                break;
            case 3:
                if(mostrarPeliculas())
                {
                    if(buscarpelicula(&peliculas))
                        modificarPelicula(&peliculas);
                }
               break;
            case 4:
                mostrarPeliculas();
                break;
            case 5:
                generarPagina();
                break;
            case 6:
                seguir='n';
                break;
            default:
                printf("\n\nOPCION NO VALIDA\n\n");
                break;
        }
    }
    return 0;
}
