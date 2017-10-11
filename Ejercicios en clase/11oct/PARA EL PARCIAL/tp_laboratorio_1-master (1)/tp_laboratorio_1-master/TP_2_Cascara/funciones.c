#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[])
{
    int i;

    for (i=0;i<CANT;i++)
       {
        if (lista[i].estado==0)
            return i;
        if (lista[i].estado==1&&i==CANT-1)
            return -1;
        }



}

int validarIgualdad (EPersona lista,EPersona listaGeneral[])
{
    int i;

    for (i=0;i<CANT;i++)
        {
        if (lista.dni==listaGeneral[i].dni)
        {
            printf("Dni repetido\nRei");
            return 1;
        }
            else
                return 0;
        }
}


EPersona AgregarPersona (EPersona listaGeneral[])
    {
    EPersona lista;
    char numero_c[9],nombre_c[CANT];
    int comprobar,i;


    printf("I");
    do{
        printf("ngrese el nombre de la persona: ");
        fflush(stdin);
        comprobar=validarNombre(gets(nombre_c));
    }while (comprobar==0);
    strlwr(nombre_c);
    nombre_c[0]=toupper(nombre_c[0]);
    for (i=0;i<strlen(nombre_c);i++)
        {
        if (nombre_c[i]==' ')
            nombre_c[i+1]=toupper(nombre_c[i+1]) ;
        }
    strcpy(lista.nombre,nombre_c);


    ///////////////////////////////////////////
    printf("I");
    do{
    printf("ngrese el dni de la persona: ");
    fflush(stdin);
    lista.dni=validarNumero(gets(numero_c));
    if(validarIgualdad(lista,listaGeneral))
    lista.dni=0;
    }while (lista.dni==0);

    //              COMPROBAR QUE NO SE REPITA ESTE CAMPO
    printf("I");
    do{
    printf("ngrese la edad de la persona: ");
    fflush(stdin);
    lista.edad=validarNumero(gets(numero_c));
    }while (lista.edad==0);

    lista.estado=1;

    return lista;


    }

int validarNumero (char numero[])
{
    int i,numerico,tam;
    tam=strlen(numero);
        for (i=0;i<tam;i++)
        {
        if(isdigit(numero[i])==0)
            {
            printf("ERROR!!!!!. Rei");
            return 0;
            }
        }
        if(i==tam)
            {
            numerico=atoi(numero);
            return numerico;
            }

}

int validarNombre (char palabra[])
    {
        int i;
        for (i=0;i<strlen(palabra);i++)
        {
        if(isalpha(palabra[i])==0&&palabra[i]!=' ')
            {
            printf("ERROR!!!!!. Rei");
            return 0;
            }
        if(i==strlen(palabra))
            return 1;

    }

    }

int buscarPorDni(EPersona lista[])
{

    int i,cargarDni;
    char validarDni[9];

    printf("I");
        do{
        printf("ngrese el dni de la persona a borrar: ");
        fflush(stdin);
        cargarDni=validarNumero(gets(validarDni));
        }while(cargarDni==0);
    for (i=0;i<CANT;i++)
    {
        if (cargarDni==lista[i].dni)
            {
            printf("\nENCONTRO\n");
            return i;
            }
        if  (cargarDni!=lista[i].dni&&i==CANT-1)
            {
            printf("\nNO ENCONTRO\n");
            system("pause");
            return -1;
            }
    }

}

void ordenamientoFunc (EPersona lista[])
{
    int i,j;
    EPersona aux;

    for (i=0;i<CANT-1;i++)
    {
        for (j=i+1;j<CANT;j++)
        {
            if(stricmp(lista[j].nombre,lista[i].nombre)<0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }

    }
    printf("Nombre\t\t\tEdad\tDni\n----------------------------\n");
    for (i=0;i<CANT;i++)
    {
        if(lista[i].estado==1)
        printf("%s\t\t%d\t%u\t\n",lista[i].nombre,lista[i].edad,lista[i].dni);
    }

}

void graficoEdades (EPersona lista[])
{
    int i,men18=0,entre1935=0,may35=0,mayor,flag=0;

    printf("\n");

    for (i=0;i<CANT;i++)
        {
        if(lista[i].estado==1&&lista[i].edad<19)
            {
            men18++;
            }
            else
            if(lista[i].estado==1&&lista[i].edad>18&&lista[i].edad<36)
                {
                entre1935++;
                }
                else
                    {
                    if(lista[i].estado==1&&lista[i].edad>35)
                        {
                        may35++;
                        }
                    }
        }
    if(men18>=entre1935&&men18>=may35)
        {
        mayor=men18;
        }
        else
            {
            if(entre1935>=men18&&entre1935>=may35)
                {
                mayor=entre1935;
                }
            else
                {
                mayor=may35;
                }
            }

    for(i=mayor;i>0;i--)
        {
        if(i<10)
            {
            printf("\n%02d|",i);
            }
        else
            printf("\n%02d|",i);

        if(i<=men18)
            {
            printf("*");
            }
        if(i<=entre1935)
            {
            flag=1;
            printf("\t*");
            }
        if(i<=may35)
            {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
            }
        }

   printf("\n  |<18\t19-35\t>35\n");
    }

EPersona borrarPersona(EPersona lista,int ubicacion)
{
    char letra;
    if (ubicacion!=-1)
        {
        printf("Esta seguro que desea eliminar?.[S/N]\n");
        fflush(stdin);
        letra=tolower(getche());
        fflush(stdin);
        if (letra=='s')
            {
            lista.estado=0;
                printf("\nHa sido eliminado./a\n");
            }
        }
    return lista;
}














