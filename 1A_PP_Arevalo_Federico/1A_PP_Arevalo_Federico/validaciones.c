#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"

/** \brief
 *
 * \param numero[] char
 * \return int
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

int pedirStringLetras(char mensaje[],char input[])
{
    char aux[256];
    pedirString(mensaje,aux);
    if(validarSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void pedirString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int validarSoloLetras (char str[])
{
   int i = 0, devuelve = 1;

   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           devuelve = 0;
           break;
       }
       i++;
   }

   return devuelve;
}


















