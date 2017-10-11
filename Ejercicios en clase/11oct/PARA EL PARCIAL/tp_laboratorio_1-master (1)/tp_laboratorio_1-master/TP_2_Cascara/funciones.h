#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 20

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
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Carga valores correspondientes a una estructura
 * @param lista lista de registros para validar
 * @return estructura cargaga con los datos de la persona
 */
EPersona AgregarPersona (EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[]);

/**
 * Ordena la lista por nombre y la muestra
 * @param lista lista a ordenar
 */
void ordenamientoFunc (EPersona lista[]);

/**
 * Genera un grafico que muestra a los menores de 19, los que estan entre 19 y 35
 * @param lista recibe la lista de personas a graficar
 */
void graficoEdades (EPersona lista[]);

 /**
  * Valida si el nombre solo contiene letras
  * @param palabra nombre a validar
  * @return uno si es un nombre correcto, cero si no lo es
  */
int validarNombre(char palabra[]);

/**
 * Valida si no se ingreso una letra por error
 * @param numero numero a validar como palabra
 * @return el numero convertido a numero
 */
int validarNumero (char numero[]);

/**
 * Elimina una persona del registro
 * @param lista registro a eliminar
 * @param ubicacion ubicacion del registro
 * @return registro liberado
 */
EPersona borrarPersona(EPersona lista,int ubicacion);

/**
 * Verifica si el dni ingresado no esta repetido
 * @param lista dni a verificar
 * @param listaGeneral referencia
 * @return uno si esta repetido cero si no lo esta
 */
int validarIgualdad (EPersona lista,EPersona listaGeneral[]);



#endif // FUNCIONES_H_INCLUDED
