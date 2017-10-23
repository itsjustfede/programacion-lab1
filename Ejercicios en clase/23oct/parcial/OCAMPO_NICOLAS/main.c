#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lib.h"
int main()
{
    ArrayList* al_producto=al_newArrayList();
    char seguir='s';
    int opcion;
    while(seguir=='s'){
        printf("1 - CARGAR PRODUCTOS\n2 - FILTRAR\n3 - LISTAR\n4 - SALIR\n\nELIJA LA OPCION DESEADA: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                producto_parse(al_producto,"MOCK_DATA.csv");
                break;
            case 2:
                printf("\nINGRESE CATEGORIA: ");
                scanf("%d", &opcion);
                al_producto=filter(al_producto, opcion);
                break;
            case 3:
                producto_listar(al_producto);
                break;
            case 4:
                seguir='n';
                break;
            default:
                printf("\nOPCION INCORRECTA, REINTENTE\n");
                break;
        }
    }
    return 1;
}
