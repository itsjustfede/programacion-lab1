#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void Mk_Str_Movie(EMovie *ePeliPunt)
{

    EMovie ePelicula;
    char duracion[5];
    char puntaje[4];
    int i,validar=1;
    float puntuacion;
    if (ePeliPunt!=NULL)
    {
        ///------------------------------------------///
        printf("Ingrese el nombre de la pelicula\n");
        fflush(stdin);
        gets(ePelicula.titulo);
        toupper(ePelicula.titulo[0]);
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
            gets(duracion);
            validar=0;
            for (i=0;i<(strlen(duracion));i++)
            {
                 if (!isdigit(duracion[i]))
                 {
                     validar=1;

                     break;
                 }

            }


        }
        ePelicula.duracion=atoi(duracion);
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
            gets(puntaje);
            validar=0;
            for (i=0;i<(strlen(puntaje));i++)
            {
                if (!isdigit(puntaje[i])&&puntaje[i]!='.')
                {
                    printf("Error!. Ingrese una puntuacion del 1 al 10 \n");
                    validar=1;
                    break;
                }

            }
            puntuacion=atoi(puntaje);
            if (puntuacion>10||puntuacion<1)
            {
                printf("Error!. Ingrese una puntuacion del 1 al 10 \n");
                validar=1;
            }
        }
        ePelicula.puntaje=atoi(puntaje);
        validar=1;
        ///------------------------------------------///
        printf("Ingrese el link de la imagen de portada\n");
        fflush(stdin);
        gets(ePelicula.linkImagen);
        ///------------------------------------------///

        *ePeliPunt=ePelicula;

    }
        else
        {
            printf("Error.");
            exit(0);
        }
}

int agregarPelicula(EMovie *movie)
{
    int retorno=0;
    int comprobar;

    FILE *pArchPelis;
    if (movie!=NULL)
    {
        pArchPelis=fopen("Pelis.bin","rb+");
        if(pArchPelis==NULL)
            pArchPelis=fopen("Pelis.bin","wb+");
        if(pArchPelis!=NULL)
        {
            comprobar=fwrite(movie,sizeof(EMovie),1,pArchPelis);
            if(comprobar!=1)
                printf("\nError!!!!\n");
            retorno=1;
            fclose(pArchPelis);
        }
    }

    return retorno;
}

int borrarPelicula(EMovie movie)
{
    /**
    mostrar nombres de peliculas
    pedir que pelicula eliminar
    guardar todas las peliculas en un array dinamico EMovie
    cerrar archivo
    abrirlo para escritura (wb)
    escribir todos los registros nuevamente expto el eliminado
    listo :D
    */

}

int modificarPelicula (EMovie movie)
{
    /**
    mostrar nombres de peliculas
    pedir que pelicula modificar
    guardar todas las peliculas en un array dinamico EMovie
    cerrar archivo
    abrirlo para escritura (wb)
    escribir todos los registros nuevamente y reemplazar el registro marcado por el modificado
    */
}

void generarPagina(char nombre[])
{
    FILE *pArchPelis;
    FILE *pArchHTML;

    EMovie almacenar;
    int cant;

    pArchPelis=fopen("Pelis.bin","rb");
    if(pArchPelis==NULL)
        exit(0);
    pArchHTML=fopen(nombre,"w+");
    if(pArchPelis==NULL)
        exit(0);

    while(!feof(pArchPelis))
    {
        cant=fread(&almacenar,sizeof(EMovie),1,pArchPelis);
        if(cant!=1)
        {
            if(feof(pArchPelis))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        fread(&almacenar,sizeof(EMovie),1,pArchPelis);

        fprintf(pArchHTML,"<article class='col-md-4 article-intro'>\n");
        fprintf(pArchHTML,"\t<a href='#'>\n");
        fprintf(pArchHTML,"\t\t<img class=''alt='%s'\n>",almacenar.linkImagen);
        fprintf(pArchHTML,"\t</a>\n");
        fprintf(pArchHTML,"\t<h3>\n");
        fprintf(pArchHTML,"\t\t<a href='#'>%s</a>\n",almacenar.titulo);
        fprintf(pArchHTML,"\t</h3>\n");
        fprintf(pArchHTML,"\t<ul>");
        fprintf(pArchHTML,"\t\t<li>Género:%s</li>\n",almacenar.genero);
        fprintf(pArchHTML,"\t<li>Puntaje:%d</li>\n",almacenar.puntaje);
        fprintf(pArchHTML,"\t<li>Duración:%d</li>\n",almacenar.duracion);
        fprintf(pArchHTML,"\t</ul>\n");
        fprintf(pArchHTML,"\t<p>%s</p>\n",almacenar.descripcion);
    }

    fclose(pArchPelis);

    fclose(pArchHTML);



}

