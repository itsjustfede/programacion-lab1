#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 3


int main()
{
    eProgramador equipo[MAX];
    eCategoria categorias[MAX];
    eProy_Prog proyProg[MAX];
    eProyecto proyecto[4];

    int salir = 1;

    inicializarVector(equipo, proyProg, MAX);
    hardCodearCat(categorias, MAX);
    hardCodearProgramador(equipo, MAX);

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            //altaProgramador(equipo, MAX);
            getch();

            break;

        case 2:
            system("cls");
            //bajaProgramador(equipo, MAX)
            getch();


            break;
        case 3:
            system("cls");
            //modificarProgramador(equipo, MAX);
            getch();

            break;

        case 4:
            system("cls");
            mostrarProgramadores(equipo, proyProg, proyecto, MAX);
            mostrarCategoria(equipo, categorias, MAX);
            getch();
            break;



        case 5:
            salir = 0;
            break;
        }
    }
    while(salir);
    return 0;
}



