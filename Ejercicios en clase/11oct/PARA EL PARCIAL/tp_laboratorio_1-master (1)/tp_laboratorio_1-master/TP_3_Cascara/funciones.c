#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void Mk_Str_Movie(EMovie *ePeliPunt)
{

    EMovie ePelicula;
    int i,validar=1;
    float puntuacion;
    ///------------------------------------------///
    printf("Ingrese el nombre de la pelicula\n");
    fflush(stdin);
    gets(ePelicula.titulo);
    ///------------------------------------------///
    while(validar)
    {
        printf("Ingrese el genero de la pelicula\n");
        fflush(stdin);
        gets(ePelicula.genero);
        for (i=0;i<(strlen(ePelicula.genero));i++)
        {
            if (!isdigit(ePelicula.genero[i]))
            {
                validar=0;
                continue;
            }
        }
    }
    validar=1;
    strlwr(ePelicula.genero);
    toupper(ePelicula.genero[0]);
    ///------------------------------------------///
    while(validar)
    {
        printf("Ingrese la duracion de la pelicula\n");
        fflush(stdin);
        gets(ePelicula.duracion);
        validar=0;
        for (i=0;i<(strlen(ePelicula.duracion));i++)
        {
             if (!isdigit(ePelicula.duracion[i]))
             {
                 validar=1;
                 break;
             }

        }

    }
    validar=1;
    ///------------------------------------------///
    printf("Ingrese la descripcion de la pelicula\n");
    fflush(stdin);
    gets(ePelicula.descripcion);
    ///------------------------------------------///
    while(validar)
    {
        printf("Ingrese la puntuacion de la pelicula\n");
        fflush(stdin);
        gets(ePelicula.puntaje);
        validar=0;
        for (i=0;i<(strlen(ePelicula.puntaje));i++)
        {
            if (!isdigit(ePelicula.puntaje[i])&&ePelicula.puntaje[i]!='.')
            {
                validar=1;
                break;
            }

        }
        puntuacion=atof(ePelicula.puntaje);
        if (puntuacion>10||puntuacion<1)
        {
            printf("Error!. Ingrese una puntuacion del 1 al 10 \n");
            validar=1;
        }
    }
    validar=1;
    ///------------------------------------------///
    printf("Ingrese el link de la imagen de portada\n");
    fflush(stdin);
    gets(ePelicula.linkImagen);
    ///------------------------------------------///

    *ePeliPunt=ePelicula;
}

int agregarPelicula(EMovie movie)
{
    int retorno=1;
    char adjuntado[300]="";

    FILE *pArchPelis;

    pArchPelis=fopen("Pelis.bin","ab+");
    if(pArchPelis==NULL)
        retorno=0;

    strcat(adjuntado,movie.titulo);
    strcat(adjuntado,",");
    strcat(adjuntado,movie.genero);
    strcat(adjuntado,",");
    strcat(adjuntado,movie.descripcion);
    strcat(adjuntado,",");
    strcat(adjuntado,movie.duracion);
    strcat(adjuntado,",");
    strcat(adjuntado,movie.puntaje);
    strcat(adjuntado,",");
    strcat(adjuntado,movie.linkImagen);
    strcat(adjuntado,"\r\n");

    fprintf(pArchPelis,"%s",adjuntado);

    fclose(pArchPelis);
    return retorno;
}

int borrarPelicula(EMovie movie)
{

}

void generarPagina(char nombre[])
{
    FILE *pArchPelis;
    FILE *pArchHTML;
    EMovie almacenar;

    pArchPelis=fopen("Pelis.bin","rb");
    if(pArchPelis==NULL)
        exit(0);
    pArchHTML=fopen(nombre,"w+");
    if(pArchPelis==NULL)
        exit(0);

    while(!feof(pArchPelis))
    {

        fflush(pArchPelis);
        fflush(pArchHTML);
        fscanf(pArchPelis,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]\n",almacenar.titulo,almacenar.genero,almacenar.descripcion,almacenar.duracion,almacenar.puntaje,almacenar.linkImagen);

        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n\n",almacenar.titulo,almacenar.genero,almacenar.descripcion,almacenar.duracion,almacenar.puntaje,almacenar.linkImagen);

        fprintf(pArchHTML,"<article class='col-md-4 article-intro'>\n");
        fprintf(pArchHTML,"\t<a href='#'>\n");
        fprintf(pArchHTML,"\t\t<img class=''alt='%s'\n>",almacenar.linkImagen);
        fprintf(pArchHTML,"\t</a>\n");
        fprintf(pArchHTML,"\t<h3>\n");
        fprintf(pArchHTML,"\t\t<a href='#'>%s</a>\n",almacenar.titulo);
        fprintf(pArchHTML,"\t</h3>\n");
        fprintf(pArchHTML,"\t<ul>");
        fprintf(pArchHTML,"\t\t<li>Género:%s</li>\n",almacenar.genero);
        fprintf(pArchHTML,"\t<li>Puntaje:%s</li>\n",almacenar.puntaje);
        fprintf(pArchHTML,"\t<li>Duración:%s</li>\n",almacenar.duracion);
        fprintf(pArchHTML,"\t</ul>\n");
        fprintf(pArchHTML,"\t<p>%s</p>\n",almacenar.descripcion);
    }

    fclose(pArchPelis);

    fclose(pArchHTML);



}

