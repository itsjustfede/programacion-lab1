#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misValidaciones.h"

int obtenerInt(char mensaje[],char mensajeError[],char maximo[],char minimo[])
{
    char buffer[1];
    char seguir = 's';
    int num;

    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%s",buffer);

        int aux;
        int aux1;
        int aux2;


        //if(strcmp(buffer,minimo) >0 ||strcmp(buffer,maximo)<0 || soloNumeros(buffer)==0)
        aux= soloNumeros(buffer);
        aux1 = strcmp(buffer,minimo);
        aux2 = strcmp(buffer,maximo);
        if( aux1<0 || aux2>0 || aux==0)
        {
             printf(mensajeError);
        }
        else
        {
            seguir = 'n';
            num = atoi(buffer);
        }


    }while(seguir == 's');

    return num;
}

/*long int obtenerDni(char mensaje[],char mensajeError[],char maximo[],char minimo[])
{
    char buffer[10];
    char seguir = 's';
    long int dni;
    int aux, aux1, aux2;
    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%s",buffer);
        aux = soloNumeros_dni(buffer);
        aux1 = strcmp(buffer,minimo);
        aux2 = strcmp(buffer,maximo);
        if(aux1 > minimo || aux2 < maximo || aux == 0)
        {
             printf(mensajeError);
        }
        else
        {
            dni = atol(buffer);
            seguir = 'n';
        }
    }while(seguir == 's');
    return dni;
}*/
/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int soloNumeros(char num[])
{
    int i=0;
    int retorno = 1;
    while(num[i] != '\0')
    {
         if(num[i]<'0' || num[i]> '9')
            retorno = 0;
        i++;
    }
     return retorno;
}
long int soloNumeros_dni(char num[])
{
    int i=0;
    long int retorno = 1;
    while(num[i] != '\0')
    {
        if(num[i]<'0' || num[i]>'9')
            retorno = 0;
        i++;
    }
     return retorno;
}
/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if((str[i]!= ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            retorno = 0;
        i++;
    }

    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int alfanumerico(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            retorno = 0;
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo n�meros, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    int retorno;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < '0' || str[i] > '9') && (str[i] != '-'))
            retorno = 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones == 1)
    {
        retorno = 1;
    }//VALIDO QUE EL TELEFRONO DEBE CONTENER UN SOLO GUION
    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s",input);
    fflush(stdin);
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[255];
    getString(mensaje,aux);
    if(soloNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
