#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Estacionamiento.h"

#define TOTAL 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int menu()
{
    int opcion;
    system("cls");
    printf("\n***ESTACIONAMIENTO***\n\n\n");
    printf("1- Alta Dueno\n");
    printf("2- Modificacion Dueno\n");
    printf("3- Ingreso Automovil\n");
    printf("4- Egreso Automovil\n");
    printf("5- Informes\n");
    printf("6- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void inicializarVectorDuenos(eDueno duenos[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        duenos[i].estado = 0;
    }
}

void inicializarVectorCars(eCars cars[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cars[i].estado = 0;
    }
}

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

void altaDueno(eDueno duenos[], int tam, int* bandera)
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

            *bandera = 0;
        }
    }
}

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

void ingresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam, int* bandera)
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

            printf("Ingrese dueno por ID: \n");
            mostrarDuenos(duenos, tamDuenos);
            scanf("%d", &nuevoAutomovil.dueno);

            printf("Ingrese horario de entrada: ");
            scanf("%d", &nuevoAutomovil.horarioDeEntrada);

            nuevoAutomovil.estado = 1;

            cars[lugar] = nuevoAutomovil;

            *bandera = 0;
        }
    }
}

void mostrarAutomovilesEstacionados(eDueno duenos[], int tamDuenos, eCars cars[], int tam)
{
    int i;

    printf("Patente -- H. Entrada -- Marca -- Dueno  -- Direccion  --  N Tarjeta de C\n\n");

    for (i = 0; i < tam; i++)
    {
        mostrarAutomovilEstacionado(duenos, tamDuenos, cars[i]);
    }
}

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

void ordenarAutomoviles(eCars cars[], int tam)
{
    int i, j;

    eCars aux;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (cars[i].horarioDeEntrada > cars[j].horarioDeEntrada)
            {
                aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }
            if (cars[i].horarioDeEntrada == cars[j].horarioDeEntrada)
                if (stricmp(cars[i].patente, cars[j].patente) > 0)
                {
                    aux = cars[i];
                    cars[i] = cars[j];
                    cars[j] = aux;
                }
        }
    }
}

void hardcodearCars(eCars cars[])
{
    char patente[][10] =  {"ABC123", "DFG456", "HIJ674", "JRD842", "KLM654"};
    int marca[] =  {AUDI, AUDI, 2, 4, 4};
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

void mostrarPropietariosDeAudis(eDueno duenos[], int tamDuenos, eCars cars[], int tamCars)
{
    int i, j, bandera = 1;

    printf("Todos los propietarios de autos de marca Audi\n\n");

    for (i = 0; i < tamCars; i++)
    {
        if (cars[i].estado == 1 && cars[i].marca == AUDI)
        {
            for (j = 0; j < tamDuenos; j++)
            {
                if (duenos[j].estado == 1 && duenos[j].idDueno == cars[i].dueno)
                {
                    printf("%s -- %s -- %d\n", duenos[j].nombreYApellido, duenos[j].direccion, duenos[j].numeroDeTarjetaDeCredito);
                    bandera = 0;
                }
            }
        }


    }

    if (bandera)
        printf("Ningun cliente posee un auto de marca Audi");

}

void modificarDueno(eDueno duenos[], int tam)
{
    int i, id, bandera;
    char respuesta;

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado == 1 && duenos[i].idDueno == id)
        {
            printf("Seguro que desea modificar a ");
            printf("%s? ", duenos[i].nombreYApellido);
            printf("S/N\n");
            fflush(stdin);
            scanf("%c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta == 's')
            {
                printf("Numero actual de tarjeta de credito: %d\n", duenos[i].numeroDeTarjetaDeCredito);
                printf("Ingrese el nuevo numero de tarjeta de credito: ");
                scanf("%d", &duenos[i].numeroDeTarjetaDeCredito);
                printf("Modificacion exitosa");
            }
            else
            {
                printf("Accion cancelada");
            }
            bandera = 0;
            break;
        }

    }

    if (bandera)
        printf("El ID no existe");
}

void egresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam, int arrayDeRecaudacion[])
{
    int i, esta, validar = 1, horaDeSalida, valorDeEstadia;
    char patente[30];
    char respuesta;


    printf("\nIngrese el la patente: ");
    fflush(stdin);
    gets(patente);

    esta = buscarAtomovil(patente, cars, tam);

    if (esta == -1)
    {
        printf("Ese auto no existe");
    }
    else
    {
        for (i = 0; i < tamDuenos; i++)
        {
            if (cars[esta].dueno == duenos[i].idDueno)
            {
                break;
            }

        }

        printf("El dueno de este auto es \"%s\"? S/N \n", duenos[i].nombreYApellido);
        fflush(stdin);
        scanf("%c", &respuesta);

        respuesta = tolower(respuesta);

        while(validar)
        {
            if (respuesta == 's')
            {
                validar = 0;
                printf("Ingrese la hora de salida (sabiendo que ingreso a la(s) %dhs): ", cars[esta].horarioDeEntrada);
                scanf("%d", &horaDeSalida);

                while(horaDeSalida < 0 || horaDeSalida > 24)
                {
                    printf("El auto ingreso a la(s) %dhs): ", cars[esta].horarioDeEntrada);
                    printf("y no puede permanecer mas de un dia, ingrese una hora correta: ");
                    scanf("%d", &horaDeSalida);
                }

                valorDeEstadia = calcularRecaudacionDeAuto(cars[esta].horarioDeEntrada, horaDeSalida, cars[esta].marca, arrayDeRecaudacion);

                generarTicket(cars[esta], duenos[i], valorDeEstadia, cars[esta].marca);

                cars[esta].estado = 0;

                break;

            }
            else if (respuesta == 'n')
            {
                validar = 0;
                printf("Accion cancelada");
                break;
            }
            printf("Ingrese S/N");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta = tolower(respuesta);
        }
    }
}

int calcularRecaudacionDeAuto(int horaDeEntrada, int horaDeSalida, int marca, int arrayDeRecaudacion[])
{
    int costo;

    if (marca == ALPHA_ROMEO)
    {
        costo = (horaDeSalida - horaDeEntrada) * 150;
    }
    else if (marca == FERRARI)
    {
        costo = (horaDeSalida - horaDeEntrada) * 175;
    }
    else if (marca == AUDI)
    {
        costo = (horaDeSalida - horaDeEntrada) * 200;
    }
    else
    {
        costo = (horaDeSalida - horaDeEntrada) * 250;
    }

    recaudar(costo, marca, arrayDeRecaudacion);

    return costo;
}

void generarTicket(eCars car, eDueno dueno, int valorDeEstadia, int marca)
{
    char marquita[20];

    printf("\n------------------------------------------------------------\n");

    printf("Nombre del dueno: %s\n", dueno.nombreYApellido);
    printf("Su patente: %s\n", car.patente);

    if (car.marca == ALPHA_ROMEO)
        strcpy(marquita, "Alpha Romeo");
    else if (car.marca == FERRARI)
        strcpy(marquita, "Ferrari");
    else if (car.marca == AUDI)
        strcpy(marquita, "Audi");
    else
        strcpy(marquita, "Otro");
    printf("La marca: %s\n", marquita);
    printf("Valor de la estadia: $%d", valorDeEstadia);

    printf("\n------------------------------------------------------------\n");
}

void recaudar(int recaudacion, int marca, int arrayDeRecaudacion[])
{
    if (marca == ALPHA_ROMEO)
    {
        arrayDeRecaudacion[ALPHA_ROMEO] = arrayDeRecaudacion[ALPHA_ROMEO] + recaudacion;
    }
    else if (marca == FERRARI)
    {
        arrayDeRecaudacion[FERRARI] = arrayDeRecaudacion[FERRARI] + recaudacion;
    }
    else if (marca == AUDI)
    {
        arrayDeRecaudacion[AUDI] = arrayDeRecaudacion[AUDI] + recaudacion;
    }
    else
    {
        arrayDeRecaudacion[OTRO] = arrayDeRecaudacion[OTRO] + recaudacion;
    }

    arrayDeRecaudacion[TOTAL] = arrayDeRecaudacion[TOTAL] + recaudacion;
}

void mostrarRecaudacion(int arrayDeRecaudacion[])
{
    printf("\n------------------------------------------------------------\n");
    printf("Recaudacion Total: %d\n\n", arrayDeRecaudacion[TOTAL]);
    printf("Recaudacion por marca\n\n");
    printf("Alfa Romeo: %d\n", arrayDeRecaudacion[ALPHA_ROMEO]);
    printf("Ferrari: %d\n", arrayDeRecaudacion[FERRARI]);
    printf("Audi: %d\n", arrayDeRecaudacion[AUDI]);
    printf("Otro: %d", arrayDeRecaudacion[OTRO]);
    printf("\n------------------------------------------------------------\n");
}











