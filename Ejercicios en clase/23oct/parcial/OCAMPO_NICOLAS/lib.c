#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "lib.h"
/** \brief Crea una estructura dinamicamente
 *
 * \param void
 *
 * \return Puntero a la estructura creada
 */
s_producto* producto_new(){
    s_producto* returnAux=(s_producto*)malloc(sizeof(s_producto));
    return returnAux;
}
/** \brief Carga el campo id_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param id_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setId(s_producto* pProducto, char* id_producto){
    int returnAux=0;
    if(pProducto!=NULL){
        pProducto->id_producto=atoi(id_producto);
        returnAux=1;
    }
    return returnAux;
}
/** \brief Carga el campo name_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param name_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setName(s_producto* pProducto, char* name_producto){
    int returnAux=0;
    if(pProducto!=NULL){
        strcpy(pProducto->name_producto,name_producto);
        returnAux=1;
    }
    return returnAux;
}
/** \brief Carga el campo version_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param version_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setVersion(s_producto* pProducto, char* version_producto){
    int returnAux=0;
    if(pProducto!=NULL){
        strcpy(pProducto->version_producto,version_producto);
        returnAux=1;
    }
    return returnAux;
}
/** \brief Carga el campo category_producto de la estructura
 *
 * \param pProducto puntero a la estructura
 * \param category_producto campo a cargar en la estructura
 *
 * \return 0 = ERROR, 1=OK
 */
int producto_setCategory(s_producto* pProducto, char* category_producto){
    int returnAux=0;
    if(pProducto!=NULL){
        pProducto->category_producto=atoi(category_producto);
        returnAux=1;
    }
    return returnAux;
}
/** \brief Carga los campos de una estructura y lo guarda en el ArrayList
 *
 * \param al_producto puntero al Arraylist
 * \param pProducto puntero a la estructura
 * \param id_producto campo a cargar en la estructura
 * \param name_producto campo a cargar en la estructura
 * \param version_producto campo a cargar en la estructura
 * \param category_producto campo a cargar en la estructura
 */
void producto_append(ArrayList* al_producto, s_producto* pProducto, char* id_producto, char* name_producto, char* version_producto, char* category_producto){
    producto_setId(pProducto,id_producto);
    producto_setName(pProducto,name_producto);
    producto_setVersion(pProducto,version_producto);
    producto_setCategory(pProducto,category_producto);
    al_producto->add(al_producto, (void*)pProducto);
}
/** \brief Carga los datos de un archivo de texto a un ArrayList
 *
 * \param al_producto puntero al Arraylist a cargar
 * \param nombreArchivo Nombre del archivo a leer
 */

void producto_parse(ArrayList* al_producto, char* nombreArchivo){
    s_producto* pProducto;
    FILE* pFile;
    int flag=0;
    char name_producto[15], id_producto[15], version_producto[15], category_producto[15];
    pFile=fopen(nombreArchivo,"r");
    if(pFile==NULL){
        printf("\n\nERROR FATAL AL ABRIR EL ARCHIVO\n\n"); return;
    }
    while(!(feof(pFile)))
    {
        pProducto=producto_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id_producto,name_producto,version_producto,category_producto);
        if(flag==0){
            flag=1;
            continue;
        }
        producto_append(al_producto, pProducto,id_producto,name_producto,version_producto,category_producto);
    }
    fclose(pFile);
    printf("\nTAMAÑO DEL ARRAYLIST: %d\n\n", al_len(al_producto));
}
/** \brief Muestra en pantalla los elementos del ArrayList
 *
 * \param al_producto puntero al Arraylist a listar
 *
 */
void producto_listar(ArrayList* al_producto){
    system("cls");
    s_producto* pProducto;;
    int i=0;
    for(i=0;i<al_producto->size;i++){
        pProducto=producto_new();
        pProducto=(s_producto*)al_get(al_producto,i);
        printf("ID: %i - NOMBRE: %s - VERSION: %s - CATEGORIA: %i/ ",pProducto->id_producto,pProducto->name_producto,pProducto->version_producto,pProducto->category_producto);
    }
    system("pause");
    system("cls");
}
/** \brief Devuelve un nuevo ArrayList cargado con los productos pertenecientes a la categoria indicada por parametro
 *
 * \param al_producto puntero al Arraylist a filtrar
 * \param category_producto entero que indica categoria de filtrado
 * \return devuelve un nuevo ArrayList cargado con los elementos de la categoria pasada por parametro
 *
 */
ArrayList* filter(ArrayList* al_producto, int category_producto){
    ArrayList* aux=al_newArrayList();
    s_producto* pProducto;
    int i=0, flag=0;
    for(i=0;i<al_producto->size;i++){
        pProducto=producto_new();
        pProducto=(s_producto*)al_get(al_producto,i);
        if(pProducto->category_producto==category_producto)
        {
            al_add(aux,(void*)pProducto);
            flag=1;
        }
    }
    if(flag==0){
        printf("\n\nNO SE ENCONTRO LA CATEGORIA DESEADA PARA FILTRAR\n\n");
        return al_producto;
    }
    al_deleteArrayList(al_producto);
    printf("\n\nFILTRADO EXITOSO\n\n");
    printf("\nTAMAÑO DEL ARRAYLIST: %d\n\n", al_len(aux));
    return aux;
}
