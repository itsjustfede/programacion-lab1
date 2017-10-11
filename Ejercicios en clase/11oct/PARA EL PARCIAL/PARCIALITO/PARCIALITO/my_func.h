#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct{
    long int dni;
    int turno;
    int atendido;//0 si no se lo atendio, 1 si esta atendido
    int tramite;//si es 0 es regular, si es 1 es urgente
    int uso;
}Cliente;

/** \brief Comprueba si se ingreso numeros en una cadena
 * \param  aux[] Cadena a revisar
 * \return 0 si contiene caracteres, 1 si contiene solo numeros
 */
int isnumber(char aux[]);
/** \brief Recibe una estructura y carga los datos
 * \param Cliente array[] La cadena de estructuras a cargar los datos en los campos
 * \param size El largo de la cadena de estructuras
 * \param tramite 0 si es tramite regular, 1 si es tramite urgente
 */
void cargaDatosEstructura(ArrayList* pArrayList, int tramite);
/** \brief Muestra en pantalla las estructuras de clientes que no fueron atendidos
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo atendido es igual a 0
 * \param size El largo de la cadena de estructuras
 */
void listar(ArrayList* pList);
/** \brief Muestra en pantalla la estructura del cliente que tiene que ser atendido
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo atendido es igual a 0
 * \param size Tamaño del array de estructuras
 */
void mostrar(Cliente array[], int size);
/** \brief Muestra en pantalla todos los campos del array d Estructuras
 * \param Cliente array[] La cadena de estructuras a mostrar en pantalla si su campo uso es igual a 1
 * \param size Tamaño del array de estructuras
 */
void proximoTurno(ArrayList* pList);
/** \brief Ordena la cadena de Estructuras. Deja adelante las estructuras con el campo tramite en 1
 * \param Cliente array[] La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructura(Cliente array[], int size);
/** \brief Ordena la cadena de Estructuras por DNI en forma descendente
 * \param Cliente array[] La cadena de estructuras a ordenar
 * \param size Tamaño del array de estructuras
 */
void ordenarEstructuraDni(Cliente array[], int size);



Cliente* cliente_new(void);
