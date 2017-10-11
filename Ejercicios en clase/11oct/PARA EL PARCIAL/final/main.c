#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "post.h"
#include "usuario.h"
#include "funcionesVarias.h"
int main()
{
    ArrayList* al_usuarios=al_newArrayList();
    ArrayList* al_post=al_newArrayList();
    char seguir='s';
    int opcion;
    while(seguir=='s'){
        printf("1 - CARGAR USUARIOS\n2 - CARGAR POST\n3 - GENERAR ARCHIVO feed.csv\n4 - LISTAR\n5 - SALIR\n\nELIJA LA OPCION DESEADA: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                parseUsuario(al_usuarios);
                break;
            case 2:
                parsePost(al_post);
                break;
            case 3:

                break;
            case 4:
                listar(al_post, al_usuarios);
                break;
            case 5:
                seguir='n';
                break;
            default:
                printf("\nOPCION INCORRECTA, REINTENTE\n");
                break;
        }
    }
    return 1;
}
