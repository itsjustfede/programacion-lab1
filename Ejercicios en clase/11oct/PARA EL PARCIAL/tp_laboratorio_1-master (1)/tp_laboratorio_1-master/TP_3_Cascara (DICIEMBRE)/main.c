#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/// http://www.leelibros.com/biblioteca/files/Rambo_3.jpg
/// http://hoycinema.abc.es/archivos/201201/the-terminator-1984.jpg
/// http://www.linternainformativa.com.mx/wp-content/uploads/2015/09/Back-To-The-Future.jpg

int main()
{
    int validar;
    char seguir='s',opcion;
    char nombre_archivo[40];
    char extension[]=".html";
    EMovie ePelicula;






    while(seguir=='s')

    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        fflush(stdin);
        scanf("%c",&opcion);

        switch(opcion)
        {
            case '1':
                Mk_Str_Movie(&ePelicula);
                validar=agregarPelicula(&ePelicula);
                break;
            case '2':
                validar=borrarPelicula();
                break;
            case '3':
               break;
            case '4':
                printf("ingrese el nombre del archivo .html que desea crear: \n");
                    fflush(stdin);
                    scanf("%s",&nombre_archivo);
                    strcat(nombre_archivo,extension);
                    generarPagina(nombre_archivo);
               break;
            case '5':
                seguir = 'n';
                break;
            default:
                printf("ERROR!!!. ingrese una de las opciones correctas\n");
        }
    }


    return 0;
}
