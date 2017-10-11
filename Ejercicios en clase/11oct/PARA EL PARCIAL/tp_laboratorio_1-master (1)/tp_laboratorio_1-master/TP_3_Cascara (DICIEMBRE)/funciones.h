#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[30];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(char nombre[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 void Mk_Str_Movie(EMovie *ePelicula);

#endif // FUNCIONES_H_INCLUDED
