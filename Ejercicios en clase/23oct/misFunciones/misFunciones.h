#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

typedef struct {
    int idCliente;
    char apellido[50];
    char nombre[50];
    int edad;
    int dni;

}ECliente;

typedef struct
{
    char patente[7];
    int estado;
    int marca;
    int idDueno;
    int entrada;

}eEstacionamiento;

typedef struct
{
    int idMarca;
    char nombreMarca[20];
}eMarcas;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ECliente lista[]);

/** \brief Se ejecuta obtenerEspacioLibre, si hay espacio toma los datos y los guarda, caso contrario avisa falta de espacio
 *
 * \param recibe la estructura "lista"
 * \return void guarda un registro o avisa falta de espacio
 *
 */
void agregarCliente(ECliente lista[]);

/**
 * Busca el dni y obtiene el indice correspondiente.
 * @param lista el array se pasa como parametro.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorId(ECliente lista[]);

/** \brief Recibe la estructura, ejecuta buscarPorId, si el dni existe se muestra y pregunta si se quiere eliminar o no, caso afirmativo el estado pasa a 0, si no existe dni sale una advertencia,
 *
 * \param recibe la estructura "lista"
 * \return void uestra el dni buscado para eliminar y lo elimina si el usuario asi lo decide
 *
 */
void eliminarCliente(ECliente lista[]);

/** \brief Recibe la estructura, la ordena alfabeticamente y la muestra en pantalla.
 *
 * \param recibe la estructura "lista"
 * \return void muestra y guarda la estructura ordenada alfabeticamente
 *
 */
void mostrarOrdenado(ECliente lista[]);

/** \brief Recibe la estructura, el id y el indice, para validar que no se repita el ID y modificar el indice.
 *
 * \param lista[] ECliente
 * \param int id
 * \param int indice
 * \return void
 *
 */
void validarId(ECliente lista[],int,int);

int lugarEstacionamiento(eEstacionamiento estacionamiento[]);

void entradaEstacionamiento(ECliente lista[],eEstacionamiento estacionamiento[]);

#endif // FUNCIONES_H_INCLUDED
