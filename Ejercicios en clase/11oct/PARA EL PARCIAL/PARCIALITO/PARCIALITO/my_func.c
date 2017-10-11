#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_func.h"
/** \brief Comprueba si se ingreso numeros en una cadena
 * \param  aux[] Cadena a revisar
 * \return 0 si contiene caracteres, 1 si contiene solo numeros
 */
int isnumber(char aux[]){
    int i=0;
    int retorno = 0;
    while(aux[i]!='\0'){
        if(isdigit(aux[i]) == 0){
            retorno = 0;
            break;
        }
        retorno = 1;
        i++;
    }
    return retorno;
}
/** \brief Recibe una estructura y carga los datos
 * \param Cliente array[] La cadena de estructuras a cargar los datos en los campos
 * \param size El largo de la cadena de estructuras
 * \param tramite 0 si es tramite regular, 1 si es tramite urgente
 */
void cargaDatosEstructura(ArrayList* pArrayList, int tramite){
    Cliente* pCliente=cliente_new();
    char validarNumero[10];
    long int numero=0;
    printf("\nINGRESE DNI (SIN PUNTOS|SOLO 8 DIGITOS): ");
    scanf("%s", validarNumero);
    numero=atoi(validarNumero);
    if(isnumber(validarNumero)==0 || numero<10000000 || numero>99999999){
        printf("\n\nERROR FATAL EN LA CARGA DE DATOS, REINTENTE OPCION\n\n");
        return;
    }
    pCliente->dni=atoi(validarNumero);
    pCliente->turno=(pArrayList->size)+1;
    pCliente->tramite=tramite;
    pCliente->uso=1;
    pCliente->atendido=0;
    pArrayList->add(pArrayList,pCliente);
    printf("\n\nTRAMITE REALIZADO CORRECTAMENTE\n\n");
    return;
}
/** \brief Muestra en pantalla las estructuras de clientes que no fueron atendidos
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo atendido es igual a 0
 * \param size El largo de la cadena de estructuras
 */
void listar(ArrayList* pList){
    int i=0;
    Cliente* pCliente;
    for(i=0;i<pList->size;i++){
        pCliente=cliente_new();
        pCliente=pList->get(pList,i);
        if(pCliente->atendido==0){
            printf("DNI: %ld\nTurno: %d\n",pCliente->dni,pCliente->turno);
            if(pCliente->tramite==1)
                printf("URGENTE\n");
            else
                printf("REGULAR\n");
            if(pCliente->atendido==0)
                printf("NO ATENDIDO\n\n");
            else
                printf("ATENDIDO\n\n");
        }
    }
}
/** \brief Muestra en pantalla la estructura del cliente que tiene que ser atendido
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo atendido es igual a 0
 * \param size Tamaño del array de estructuras
 */
void proximoTurno(ArrayList* pList){
    int i=0;
    Cliente* pCliente;
    for(i=0;i<pList->size;i++){
        pCliente=cliente_new();
        pCliente=pList->get(pList,i);
        if(pCliente->atendido==0){
            printf("\n\nPROXIMO CLIENTE A SER ATENDIDO: DNI: %ld\nTurno: %d\n",pCliente->dni,pCliente->turno);
            if(pCliente->tramite==1)
                printf("TRAMITE URGENTE\n\n");
            else
                printf("TRAMITE REGULAR\n\n");
            pCliente->atendido=1;
            return;
        }
    }
    printf("\nNO HAY TRAMITES PENDIENTES\n----------------------------------------------\n");
}
/** \brief Muestra en pantalla todos los campos del array d Estructuras
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo uso es igual a 1
 * \param size Tamaño del array de estructuras
 */
void mostrar(Cliente array[], int size){
    int i;
    for(i = 0; i<size ; i++){
        if(array[i].uso==1){
            printf("\nDNI: %ld\nTURNO: %d\n",array[i].dni,array[i].turno);
            if(array[i].tramite==1)
                printf("URGENTE\n");
            else
                printf("REGULAR\n");
            if(array[i].atendido==0)
                printf("NO ATENDIDO\n\n");
            else
                printf("ATENDIDO\n\n");
        }
    }
    printf("\n----------------------------------------------\n");
}
/** \brief Ordena la cadena de Estructuras. Deja adelante las estructuras con el campo tramite en 1
 * \param Cliente array[] La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructura(Cliente array[], int size){
    int i;
    int flagSwap = 1;
    int turno=0;
    Cliente aux;
    while(flagSwap){
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++){
            if(array[i].uso==1 && array[i+1].uso==1 && array[i].tramite<array[i+1].tramite){
                turno= array[i].turno;
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                array[i+1].turno=turno;
                flagSwap = 1;
            }
        }
    }
}
/** \brief Ordena la cadena de Estructuras por DNI en forma descendente
 * \param Cliente array[] La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructuraDni(Cliente array[], int size){
    int i;
    int flagSwap = 1;
    int turno=0;
    Cliente aux;
    while(flagSwap){
        flagSwap = 0;
        for(i = 0; i<size-1 ; i++){
            if(array[i].dni>array[i+1].dni && array[i].uso==1){
                turno= array[i].turno;
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                array[i+1].turno=turno;
                flagSwap = 1;
            }
        }
    }
}

Cliente* cliente_new(void){
    Cliente* retorno=(Cliente*)malloc(sizeof(Cliente));
    return retorno;
}
