#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Estacionamiento.h"

#define DUENOS 10
#define CARS 10

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int main()
{
    int salir = 1;
    int banderaCars = 1;
    int banderaDuenos = 1;

    int* pBanderaCars;
    int* pBanderaDuenos;

    pBanderaCars = &banderaCars;
    pBanderaDuenos = &banderaDuenos;

    int recaudacion[] = {0, 0, 0, 0, 0};

    eDueno duenos[DUENOS];//= {{1, "Marcos Meriggi", "Calle 13 N113", 11111, 1}, {2, "Federico Arevalo", "Calle 177 N1938", 11112, 1}, {3, "Juan Perez", "Calle 223 N4000 Piso 3", 11113, 1}, {4, "Susana Horia", "Calle 4000 N312", 11114, 1}, {5, "Esteban Dido", "Calle 933 N1024", 11115, 1}};
    eCars cars[CARS];

    inicializarVectorDuenos(duenos, DUENOS);
    inicializarVectorCars(cars, CARS);
    //hardcodearCars(cars);


    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            altaDueno(duenos, DUENOS, pBanderaDuenos);
            getch();
            break;

        case 2:
            system("cls");
            if (banderaDuenos)
            {
                printf("Se debe realizar el alta al menos un dueno");
            }
            else
            {
                modificarDueno(duenos, DUENOS);
            }
            getch();
            break;
        case 3:
            system("cls");
            if (banderaDuenos)
            {
                printf("Se debe realizar el alta al menos un dueno");
            }
            else
            {
                ingresoAutmovil(duenos, DUENOS, cars, CARS, pBanderaCars);
            }
            getch();
            break;

        case 4:
            system("cls");
            if (banderaCars)
            {
                printf("Se debe realizar el alta al menos un auto");
            }
            else
            {
                egresoAutmovil(duenos, DUENOS, cars, CARS, recaudacion);
            }
            getch();
            break;

        case 5:
            system("cls");
            if (banderaCars)
            {
                printf("Se debe realizar el alta al menos un auto");
            }
            else
            {
                ordenarAutomoviles(cars, CARS);
                mostrarAutomovilesEstacionados(duenos, DUENOS, cars, CARS);
                printf("\n------------------------------------------------------------\n");
                mostrarPropietariosDeAudis(duenos, DUENOS, cars, CARS);
                printf("\n------------------------------------------------------------\n");
                mostrarRecaudacion(recaudacion);

            }
            getch();
            break;
        case 6:
            salir = 0;
            break;
        default:
            system("cls");
            printf("Opcion incorrecta");
            getch();
            break;
        }
    }
    while(salir);

    return 0;
}

