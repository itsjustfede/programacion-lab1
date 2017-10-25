#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "validaciones.h"

/** \brief valida que lo que se ingreso sea numero
 *
 * \param numero[] cadena donde se guardan los numeros
 * \return int devuelve 1 si es numero, 0 si no lo es
 *
 */
int validarNumero(char numero[])
{
   int i = 0, devuelve = 1;

   while(numero[i] != '\0')
   {
       if(numero[i] < '0' || numero[i] > '9')
       {
           devuelve = 0;
           break;
       }

       i++;
   }
   return devuelve;
}

/** \brief valida que lo que se ingreso son solo letras
 *
 * \param letras cadena donde se guardan las letras
 * \return devuelve 1 si son letras, 0 si no lo son
 *
 */
int validarSoloLetras (char letras[])
{
   int i = 0, devuelve = 1;

   while(letras[i] != '\0')
   {
       if((letras[i] < 'a' || letras[i] > 'z') && (letras[i] < 'A' || letras[i] > 'Z'))
       {
           devuelve = 0;
           break;
       }
       i++;
   }

   return devuelve;
}


















