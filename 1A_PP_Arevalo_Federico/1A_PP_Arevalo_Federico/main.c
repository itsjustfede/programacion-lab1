#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Estacionamiento.h"

#define DUENOS 5
#define CARS 10

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int main()
{
    int salir = 1;

    eDueno duenos []= {{1, "Marcos Meriggi", "Calle 13 N113", 11111, 1}, {2, "Federico Arevalo", "Calle 177 N1938", 11112, 1}, {3, "Juan Perez", "Calle 223 N4000 Piso 3", 11113, 1}, {4, "Susana Horia", "Calle 4000 N312", 11114, 1}, {5, "Esteban Dido", "Calle 933 N1024", 11115, 1}};
    eCars cars[CARS];

    //inicializarVectorDuenos(duenos, DUENOS);
    inicializarVectorCars(cars, CARS);
    hardcodearCars(cars);


    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            altaDueno(duenos, DUENOS);
            getch();
            break;

        case 2:
            system("cls");
            modificarDueno(duenos, DUENOS);
            getch();
            break;

        case 3:
            system("cls");

            getch();
            break;

        case 4:
            system("cls");
            ingresoAutmovil(duenos, DUENOS, cars, CARS);
            getch();
            break;

        case 5:
            system("cls");

            getch();
            break;

        case 6:
            system("cls");
            ordenarAutomoviles(cars, CARS);
            //mostrarAutomovilesEstacionados(duenos, DUENOS, cars, CARS);

            mostrarPropietariosDeAudis(duenos, DUENOS, cars, CARS);
            getch();

            break;

        case 7:
            salir = 0;

            break;

        }

    }
    while(salir);

    return 0;
}

