#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"

int enteroValidado(char numero[])
{
    int numerin, numerovalido;

    do
    {
        printf("Ingrese un numero: \n");
        scanf("%s",numero);
        numerin = validarEntero(numero);

    }
    while(numerin == 0);

    numerovalido = atoi(numero);

    return numerovalido;
}
int validarEntero(char num[])
{
    int i, numero = 1;

    for(i = 0; i<strlen(num); i++)
    {
        if(!(isdigit(num[i])))
        {
            printf("\nNumero invalido! Reingrese: \n");
            getch();
            numero = 0;
            break;
        }
    }

    return numero;
}

