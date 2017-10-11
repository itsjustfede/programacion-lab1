#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "funciones.h"
#define CONSTANTE 200
/**
 *  Agrega una pelicula al archivo binario
 *  @param peliculas la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie *peliculas)
{
    printf("\n\nIngrese el nombre de la pelicula: ");
    scanf("%s", peliculas->titulo);
    printf("Ingrese el genero de la pelicula: ");
    scanf("%s", peliculas->genero);
    printf("Ingrese la duracion de la pelicula: ");
    scanf("%i", &peliculas->duracion);
    printf("Ingrese la descripcion de la pelicula: ");
    scanf("%s", peliculas->descripcion);
    printf("Ingrese la puntuacion de la pelicula: ");
    scanf("%i", &peliculas->puntaje);
    printf("Ingrese url de la imagen: ");
    scanf("%s", peliculas->linkImagen);
    FILE *pArch;
    pArch=fopen("peliculas.dat","ab+");
    if(pArch==NULL)
    {
        printf("\n\nPROBLEMAS AL LEER EL ARCHIVO BINARIO\n\n");
        exit(0);
    }
    fwrite(peliculas, sizeof(EMovie),1,pArch);
    fclose(pArch);
}
/**
 *  Borra una pelicula del archivo binario
 *  @param peliculas la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula(EMovie *borrarPelicula)
{
    FILE *pBorrar;
    FILE *pBorrarAux;
    EMovie peliculasAux;
    if(!(buscarpelicula(borrarPelicula)))
            return;
    pBorrarAux=fopen("peliculasAux.dat","wb");
    pBorrar=fopen("peliculas.dat","rb");
    if(pBorrar==NULL || pBorrarAux==NULL)
    {
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\n");
        exit(0);
    }
    while(fread(&peliculasAux, sizeof(EMovie),1, pBorrar) != 0)
    {
        if (strcmp(borrarPelicula->titulo, peliculasAux.titulo)!=0)
        {
            fwrite(&peliculasAux, sizeof(EMovie),1, pBorrarAux);
        }
    }
    fclose(pBorrar);
    fclose(pBorrarAux);
    pBorrarAux=fopen("peliculasAux.dat","rb");
    pBorrar=fopen("peliculas.dat","wb");
    while(fread(&peliculasAux, sizeof(EMovie),1, pBorrarAux))
    {
        fwrite(&peliculasAux, sizeof(EMovie),1, pBorrar);
    }
    fclose(pBorrar);
    fclose(pBorrarAux);
    printf("\n\nBORRADO EXITOSO\n\n");
}
/**
 * Busca en el archivo binario el nombre de la pelicula ingresada
 *  @param peliculas la estructura a guardar el nombre de la pelicula a buscar
 *  @return retorna 1 o 0 de acuerdo a si pudo encontrar la pelicula o no.
 */
int buscarpelicula(EMovie *buscarPeliculas)
{
    char aux[CONSTANTE];
    printf("\n\nINGRESE EL NOMBRE DE LA PELICULA A BORRAR: ");
    scanf("%s", aux);
    FILE *pBuscar;
    pBuscar=fopen("peliculas.dat","rb");
    if(pBuscar==NULL)
    {
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\n");
        exit(0);
    }
    while(fread(buscarPeliculas, sizeof(EMovie), 1, pBuscar)!=0);
    {
        if(strcmp(buscarPeliculas->titulo,aux)==0)
        {
            fclose(pBuscar);
            return 1;
        }
    }
    printf("\n\nNO SE ENCONTRO LA PELICULA\n\n");
    return 0;
}
/**
 * Muestra en pantalla las estructuras guardadas en el archivo binario
 */
int mostrarPeliculas()
{
    int flag=0;
    FILE *mostrar;
    EMovie movie;
    EMovie* pMovie=&movie;
    mostrar=fopen("peliculas.dat","rb+");
    if(mostrar==NULL)
    {
        exit(0);
    }
        while(fread(pMovie,sizeof(EMovie),1,mostrar)!=0)
    {
        printf("TITULO: %s\nDESCRIPCION: %s\nGENERO: %s\nIMAGEN: %s\nDURACION: %d\nPUNTUACION: %d\n\n", movie.titulo, movie.descripcion, movie.genero, movie.linkImagen, movie.duracion, movie.puntaje);
        flag=1;
    }
    if(flag==0)
    {
        printf("\n\nNO HAY PELICULAS INGRESADAS EN EL ARCHIVO\n\n");
        return 0;
    }
    return 1;
}
/**
 *  Borra una pelicula del archivo binario
 */
void modificarPelicula(EMovie *modificarPelicula)
{
    FILE *pModificar;
    FILE *pModificarAux;//se declara los punteros para cada archivo binario
    EMovie peliculasAux;
    pModificarAux=fopen("peliculasAux.dat","wb");
    pModificar=fopen("peliculas.dat","rb");
    if(pModificar==NULL || pModificarAux==NULL)
    {
        printf("\n\nPROBLEMAS AL LEER EL ARCHIVO BINARIO\n\n");
        exit(0);
    }
    while(fread(&peliculasAux, sizeof(EMovie),1, pModificar) != 0)/*CON ESTE WHILE COPIAMOS LAS PELICULAS QUE NO TENGAN EL TITULO QUE BUSCAMOS AL BINARIO AUXILIAR*/
    {
        if (strcmp(modificarPelicula->titulo, peliculasAux.titulo)==0)
        {
            printf("Ingrese el nuevo nombre de la pelicula: ");
            scanf("%s",peliculasAux.titulo);
            printf("Ingrese el genero de la pelicula: ");
            scanf("%s",peliculasAux.genero);
            printf("Ingrese la duracion de la pelicula: ");
            scanf("%i", &peliculasAux.duracion);
            printf("Ingrese la descripcion de la pelicula: ");
            scanf("%s",peliculasAux.descripcion);
            printf("Ingrese la puntuacion de la pelicula: ");
            scanf("%i", &peliculasAux.puntaje);
            printf("Ingrese url de la imagen: ");
            scanf("%s",peliculasAux.linkImagen);
        }
        fwrite(&peliculasAux, sizeof(EMovie),1, pModificarAux);
    }
        fclose(pModificar);
        fclose(pModificarAux);
        pModificarAux=fopen("peliculasAux.dat","rb");
        pModificar=fopen("peliculas.dat","wb");
        while(fread(&peliculasAux, sizeof(EMovie),1, pModificarAux))
        {
            fwrite(&peliculasAux, sizeof(EMovie),1, pModificar);
        }
        fclose(pModificar);
        fclose(pModificarAux);
        printf("MODIFICADO EXITOSAMENTE");
    }
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(void)
{
    EMovie html;
    FILE *pHtml;
    FILE *pPeli;
    pHtml = fopen("index.html", "w+");
    pPeli = fopen("peliculas.dat", "rb");
    if(pHtml == NULL || pPeli==NULL)
    {
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        exit(0);
    }
    while((fread(&html,sizeof(EMovie),1,pPeli))!=0)
    {
        fprintf(pHtml, "<article class='col-md-4 article-intro'>\n<a href=\'#\'>\n<img class=\'img-responsive img-rounded\' src=\'%s\n\'alt=\'\'>\n", html.linkImagen);
        fprintf(pHtml, "</a><h3><a href=\'#\'>%s</a>\n</h3>\n<ul>\n<li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d</li>\n</ul>\n<p>%s</p>\n</article>", html.titulo, html.genero, html.puntaje, html.duracion, html.descripcion);
    }
    fclose(pHtml);
    fclose(pPeli);
    printf("\n\nHTML REALIZADO CON EXITO\n\n");
}
