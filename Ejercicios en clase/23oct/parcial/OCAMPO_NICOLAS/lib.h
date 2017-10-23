#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
typedef struct{
    int id_producto;
    char name_producto[32];
    char version_producto[32];
    int category_producto;
}s_producto;


/** \brief Crea una estructura dinamicamente
 *
 * \param void
 *
 * \return Puntero a la estructura creada
 */
 s_producto* producto_new();


 /** \brief Carga el campo id_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param id_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setId(s_producto* pProducto, char* id_producto);


/** \brief Carga el campo name_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param name_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setName(s_producto* pProducto, char* name_producto);


/** \brief Carga el campo version_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param version_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setVersion(s_producto* pProducto, char* version_producto);


/** \brief Carga el campo category_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param category_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setCategory(s_producto* pProducto, char* category_producto);


/** \brief Carga los campos de una estructura y lo guarda en el ArrayList
 *
 * \param al_producto puntero al Arraylist
 * \param pProducto puntero a la estructura
 * \param id_producto campo a cargar en la estructura
 * \param name_producto campo a cargar en la estructura
 * \param version_producto campo a cargar en la estructura
 * \param category_producto campo a cargar en la estructura
 */
void producto_append(ArrayList* al_producto, s_producto* pProducto, char* id_producto, char* name_producto, char* version_producto, char* category_producto);


/** \brief Carga los datos de un archivo de texto a un ArrayList
 *
 * \param al_producto puntero al Arraylist a cargar
 * \param nombreArchivo Nombre del archivo a leer
 */
void producto_parse(ArrayList* al_producto, char* nombreArchivo);


/** \brief Muestra en pantalla los elementos del ArrayList
 *
 * \param al_producto puntero al Arraylist a listar
 *
 */
void producto_listar(ArrayList* al_producto);


/** \brief Devuelve un nuevo ArrayList cargado con los productos pertenecientes a la categoria indicada por parametro
 *
 * \param al_producto puntero al Arraylist a filtrar
 * \param category_producto entero que indica categoria de filtrado
 * \return devuelve un nuevo ArrayList cargado con los elementos de la categoria pasada por parametro
 *
 */
ArrayList* filter(ArrayList* al_producto, int category_producto);

