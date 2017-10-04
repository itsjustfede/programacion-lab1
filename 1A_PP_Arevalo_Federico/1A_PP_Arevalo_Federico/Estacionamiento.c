#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Estacionamiento.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int menu()
{
    int opcion;
    system("cls");
    printf("\n***ESTACIONAMIENTO***\n\n\n");
    printf("1- Alta Dueno\n");
    printf("2- Modificacion Dueno\n");
    printf("3- Baja Dueno\n");
    printf("4- Ingreso Automovil\n");
    printf("5- Egreso Automovil\n");
    printf("6- Listado de Automoviles\n");
    printf("7- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void inicializarVectorDuenos(eDueno duenos[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        duenos[i].estado = 0;
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void inicializarVectorCars(eCars cars[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cars[i].estado = 0;
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarDuenoLibre(eDueno duenos[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarDueno(int id, eDueno dueno[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (dueno[i].idDueno == id && dueno[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void altaDueno(eDueno duenos[], int tam)
{
    eDueno nuevoDueno;
    int esta, id, lugar;

    lugar = buscarDuenoLibre(duenos, tam);

    if (lugar == -1)
    {
        printf("No hay lugar en el sistema");
    }
    else
    {
        printf("\nIngrese el ID: ");
        scanf("%d", &id);

        esta = buscarDueno(id, duenos, tam);

        if (esta != -1)
        {
            printf("Ese dueno ya esta registrado");
        }
        else
        {
            nuevoDueno.idDueno = id;

            printf("Ingrese nombre y apellido: ");
            fflush(stdin);
            gets(nuevoDueno.nombreYApellido);

            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(nuevoDueno.direccion);

            printf("Ingrese numero de tarjeta de credito: ");
            scanf("%d", &nuevoDueno.numeroDeTarjetaDeCredito);

            nuevoDueno.estado = 1;

            duenos[lugar] = nuevoDueno;
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarDuenos(eDueno duenos[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado != 0)
            printf("\n%d- %s \n", duenos[i].idDueno, duenos[i].nombreYApellido);
    }
}

int buscarAutomovilLibre(eCars cars[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (cars[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarAtomovil(char patente[], eCars cars[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (strcmp(cars[i].patente, patente) == 0 && cars[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ingresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam)
{
    eCars nuevoAutomovil;
    int esta, lugar;
    char patente[30];

    lugar = buscarAutomovilLibre(cars, tam);

    if (lugar == -1)
    {
        printf("No hay lugar en el estacionamiento");
    }
    else
    {
        printf("\nIngrese el la patente: ");
        fflush(stdin);
        gets(patente);

        esta = buscarAtomovil(patente, cars, tam);

        if (esta != -1)
        {
            printf("Ese auto ya esta");
        }
        else
        {
            strcpy(nuevoAutomovil.patente, patente);

            printf("Ingrese marca \n 1- Alpha Romeo \n 2- Ferrari \n 3- Audi \n 4- Otro \n\n");
            scanf("%d", &nuevoAutomovil.marca);

            printf("Ingrese dueno por ID: ");
            mostrarDuenos(duenos, tamDuenos);
            scanf("%d", &nuevoAutomovil.dueno);

            printf("Ingrese horario de entrada: ");
            scanf("%d", &nuevoAutomovil.horarioDeEntrada);

            nuevoAutomovil.estado = 1;

            cars[lugar] = nuevoAutomovil;
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarAutomovilesEstacionados(eDueno duenos[], int tamDuenos, eCars cars[], int tam)
{
    int i;

    printf("Patente -- H de Entrada -- Marca -- Dueno  -- Direccion  --  N Tarjeta de C\n\n");

    for (i = 0; i < tam; i++)
    {
        mostrarAutomovilEstacionado(duenos, tamDuenos, cars[i]);
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarAutomovilEstacionado(eDueno duenos[], int tamDuenos, eCars cars)
{
    int i;
    char marca[20];

    if (cars.marca == 1)
    {
        strcpy(marca, "Alpha Romeo");
    }
    else if (cars.marca == 2)
    {
        strcpy(marca, "Ferrari");
    }
    else if (cars.marca == 3)
    {
        strcpy(marca, "Audi");
    }
    else
    {
        strcpy(marca, "Otro");
    }

    if (cars.estado == 1)
    {
        printf("%s -- %d -- %s -- ", cars.patente, cars.horarioDeEntrada, marca);
    //recorro dueños
    for (i = 0; i < tamDuenos; i++)

    {
        if (duenos[i].estado == 1 && duenos[i].idDueno == cars.dueno)
        {
            printf("%s -- %s -- %d\n", duenos[i].nombreYApellido, duenos[i].direccion, duenos[i].numeroDeTarjetaDeCredito);
        }
    }
    }

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void ordenarAutomoviles(eCars cars[], int tam)
{
    int i, j;

    eCars aux;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (stricmp(cars[i].patente, cars[j].patente) > 0)
            {
                aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }
            if (strcmpi(cars[i].patente, cars[j].patente) == 0)
                if (cars[i].horarioDeEntrada > cars[j].horarioDeEntrada)
                {
                    aux = cars[i];
                    cars[i] = cars[j];
                    cars[j] = aux;
                }
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void hardcodearCars(eCars cars[])
{
    char patente[][10] =  {"ABC123", "DFG456", "HIJ674", "JRD842", "KLM654"};
    int marca[] =  {1, 1, 2, 4, 4};
    int dueno[] = {1, 2, 3, 4, 5};
    int horario[] = {10, 12, 12, 13, 13};

    int i;

      for (i = 0; i < 5; i++)
    {
        strcpy(cars[i].patente, patente[i]);
        cars[i].dueno = dueno[i];
        cars[i].marca = marca[i];
        cars[i].horarioDeEntrada = horario[i];
        cars[i].estado = 1;
    }

}





