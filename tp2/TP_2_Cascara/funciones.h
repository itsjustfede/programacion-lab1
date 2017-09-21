#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int tam);

/** \brief agrega una persona
 *
 * \param lista el array donde se ubicara a la persona agregada
 *
 */
void agregarPersona(EPersona lista[]);

/** \brief incia todo el array en 0
 *
 * \param lista el array a ser inciado
 * \param tam el tamaño del array
 *
 */
void inicializarArray(EPersona lista[], int tam);

/** \brief elimina una persona del array
 *
 * \param lista array donde se busca la persona a eliminar
 *
 */
void borrarPersona(EPersona lista[]);

/** \brief imprime los datos de una persona
 *
 * \param lista la estructura que contiene los datos a imprimir
 *
 */
void mostrarPersona(EPersona lista);

/** \brief imprime un array de estructuras
 *
 * \param lista el array de las estructuras de personas
 * \param tam el tamaño del array
 *
 */
void mostrarPersonas(EPersona lista[], int tam);

/** \brief ordena alfabeticamente mediante burbujeo
 *
 * \param lista array de estructuras para ordenar
 * \param tam tamaño del array
 *
 */
void ordenarPersonas(EPersona lista[], int tam);
#endif // FUNCIONES_H_INCLUDED
