#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_func.h"
#include "ArrayList.h"
int main(){
    ArrayList* pArrayList;
    pArrayList=al_newArrayList();
    char seguir='s';
    char validarNumero[10];
    int opcion=0;
    while(seguir=='s'){
        printf("1 - TRAMITE URGENTE\n");
        printf("2 - TRAMITE REGULAR\n");
        printf("3 - PROXIMO CLIENTE\n");
        printf("4 - LISTAR\n");
        printf("5 - INFORMAR\n\n");
        printf("6 - SALIR\n\n");
        printf("ELIJA LA OPCION: ");
        scanf("%s", validarNumero);
        if(isnumber(validarNumero)==0){
            printf("\nERROR AL ELEGIR LA OPCION. REINTENTE\n\n");
            validarNumero[0]='\0';
            continue;
        }
        opcion=atoi(validarNumero);
        validarNumero[0]='\0';
        switch(opcion){
            case 1:
                cargaDatosEstructura(pArrayList,1);
                break;
            case 2:
                cargaDatosEstructura(pArrayList,0);
                break;
            case 3:
                proximoTurno(pArrayList);
                break;
            case 4:
                listar(pArrayList);
                break;
            case 5:

                break;
            case 6:
                seguir='n';
                break;
            default:
                printf("\nERROR AL ELEGIR LA OPCION. REINTENTE\n\n");
                break;
        }
    }
    return 0;
}
