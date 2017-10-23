#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <limits.h>
#include "misFunciones.h"

int obtenerEspacioLibre(ECliente lista[])
{
    int i;
    int resultado;
    int flagEspacio=0;
    for(i=0; i<20; i++)
    {
        if(lista[i].idCliente==0) // SI ENCUENTRA LUGAR
        {
            resultado=i;
            flagEspacio=1;
            break;
        }
    }
    if(flagEspacio==0)
    {
        resultado=-1;
    }
    return resultado;
}

void validarId(ECliente lista[],int idABuscar, int ubicacionLista)
{
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i].idCliente==idABuscar || idABuscar==0)
        {
            while(lista[i].idCliente==idABuscar || idABuscar==0)
            {
                printf("El ID esta ocupado, ingrese uno nuevo: ");
                fflush(stdin);
                scanf("%d",&idABuscar);
            }
            break;
        }
    }
    lista[ubicacionLista].idCliente=idABuscar;
}

void agregarCliente(ECliente lista[])
{
    int ubicacionLista=obtenerEspacioLibre(lista);
    char auxNombre[100]= {};
    char auxApellido[100]= {};
    int auxId;
    int largo;
    int i;
    if(ubicacionLista==-1) // SI NO HAY ESPACIO
    {
        printf("Se completo el espacio, necesita borrar un cliente\n");
    }
    else // SI HAY ESPACIO
    {
        printf("Ingrese el ID de cliente: ");
        scanf("%d",&auxId);
        validarId(lista,auxId,ubicacionLista);
        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(auxApellido);
        while(strlen(auxApellido)>49)
        {
            printf("Demasiado extenso, reingrese el apellido: ");
            fflush(stdin);
            gets(auxApellido);
        }
        largo=strlen(auxApellido);
        for(i=0; i<largo; i++)
        {
            auxApellido[i]=toupper(auxApellido[i]);
        }
        strcpy(lista[ubicacionLista].apellido,auxApellido);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxNombre);
        while(strlen(auxNombre)>49)
        {
            printf("Demasiado extenso, reingrese el nombre: ");
            fflush(stdin);
            gets(auxNombre);
        }
        largo=strlen(auxNombre);
        for(i=0; i<largo; i++)
        {
            auxNombre[i]=toupper(auxNombre[i]);
        }
        strcpy(lista[ubicacionLista].nombre,auxNombre);
        printf("Ingresar edad: ");
        scanf("%d",&lista[ubicacionLista].edad);
        printf("Ingresar DNI: ");
        scanf("%d",&lista[ubicacionLista].dni);
    }
}

int buscarPorId(ECliente lista[])
{
    int i;
    int resultado;
    int flagId=0;
    int idCliente;
    printf("Ingrese el ID del Cliente a buscar: ");
    scanf("%d",&idCliente);
    for(i=0; i<20; i++)
    {
        if(idCliente==lista[i].idCliente)
        {
            resultado=i;
            flagId=1;
            break;
        }
    }
    if(flagId==0)
    {
        resultado=-1;
    }
    return resultado;
}

void eliminarCliente(ECliente lista[])
{
    int ubicacionLista=buscarPorId(lista);
    char respuesta='n';
    if(ubicacionLista==-1 || lista[ubicacionLista].idCliente==0) // SI EL DNI NO EXISTE
    {
        printf("El ID ingresado es erroneo\n");
    }
    else // SI EL DNI EXISTE
    {
        printf("\nDNI: %d\tNOMBRE: %s\tAPELLIDO: %s\tEDAD: %d",lista[ubicacionLista].dni,lista[ubicacionLista].nombre,lista[ubicacionLista].apellido,lista[ubicacionLista].edad);
        printf("\nDesea eliminarlo? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta=='s')
        {
            lista[ubicacionLista].idCliente=0;
            printf("Persona eliminada de la lista\n");
        }
        else
        {
            printf("Accion cancelada\n");
        }
    }
}

void mostrarOrdenado(ECliente lista[])
{
    int i,j;
    ECliente aux= {};
    for(i=0; i<20-1; i++)
    {
        for(j=i+1; j<20; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    for(i=0; i<20; i++)
    {
        if(lista[i].idCliente!=0)
        {
            printf("\nID CLIENTE: %d\tNOMBRE: %s\tAPELLIDO: %s\tEDAD: %d",lista[i].idCliente,lista[i].nombre,lista[i].apellido,lista[i].edad);
        }
    }
    printf("\n");
}

int lugarEstacionamiento(eEstacionamiento estacionamiento[])
{
    int i;
    int flagLugar=0;
    for(i=0;i<20;i++)
    {
        if(estacionamiento[i].estado==1)
        {
            flagLugar=1;
            break;
        }
    }
    if(flagLugar==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void entradaEstacionamiento(ECliente lista[],eEstacionamiento estacionamiento[])
{
    int hayLugar=lugarEstacionamiento(estacionamiento);
    char auxPatente[20]={};
    int auxMarca=0;
    int auxDueno=0;
    int flagDueno=0;
    int horario;
    int i=0;
    if(hayLugar==-1)
    {
        printf("No hay lugar, regrese mas tarde");
    }
    else
    {
        printf("Ingrese la patente: ");
        fflush(stdin);
        scanf("%s",auxPatente);
        while(strlen(auxPatente)>7)
        {
            printf("La patente no es valida, reingrese: ");
            fflush(stdin);
            scanf("%s",auxPatente);
        }
        strcpy(estacionamiento[hayLugar].patente,auxPatente);
        do
        {
            printf("Ingrese la marca del vehiculo (1-2-3-4): ");
            scanf("%d",&auxMarca);
        }while(auxMarca<1 || auxMarca>4);
        estacionamiento[hayLugar].marca=auxMarca;
        printf("Ingrese su ID de Cliente: ");
        scanf("%d",&auxDueno);
        for(i=0;i<20;i++)
        {
            if(lista[i].idCliente==auxDueno && auxDueno!=0)
            {
                flagDueno=1;
            }
        }
        while(flagDueno!=1)
        {
            printf("ID incorrecto, reingrese: ");
            fflush(stdin);
            scanf("%d",&auxDueno);
            for(i=0;i<20;i++)
            {
                if(lista[i].idCliente==auxDueno && auxDueno!=0)
                {
                    flagDueno=1;
                }
            }
        }
        printf("Ingrese la hora de entrada: ");
        scanf("%d",&horario);
        while(horario<0 || horario>24)
        {
            printf("Error, reingrese la hora de entrada: ");
            scanf("%d",&horario);
        }
    }
}
