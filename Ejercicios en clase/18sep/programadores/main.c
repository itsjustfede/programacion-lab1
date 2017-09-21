#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



typedef struct
{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;

//a = Senior
//b = SemiSenior
//c = Junior

int menu();

void mostrarProgramador(eProgramador );
void mostrarProgramadores(eProgramador [], int );
void inicializarVector(eProgramador[], int );
int buscarLibre(eProgramador[], int );
int buscarProgramador(int, eProgramador[], int );
void altaProgramador(eProgramador[] , int );
void bajaProgramador(eProgramador[] , int );


int main()
{
    eProgramador equipo[50];
    int salir = 1;

    inicializarVector(equipo, 50);

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            altaProgramador(equipo, 50);
            getch();

            break;

        case 2:
            system("cls");
            printf("Opcion2");
            getch();


            break;
        case 3:
            system("cls");
            printf("Opcion3");
            getch();

            break;

        case 4:
            system("cls");
            //printf("Opcion4");
            mostrarProgramadores(equipo, 50);
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


int menu()
{
    int opcion;
    system("cls");
    printf("\n***Programadores***\n\n\n");
    printf("1- Alta Programador\n");
    printf("2- Modificacion Programador\n");
    printf("3- Baja Programador\n");
    printf("4- Listado Programadores\n");
    printf("5- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void mostrarProgramador(eProgramador developer)
{
    char cat[11];

    if (developer.categoria == 'a')
    {
        strcpy(cat, "Senior");
    }
    else if (developer.categoria == 'm')
    {
        strcpy(cat, "Semisenior");
    }
    else
    {
        strcpy(cat, "Junior");
    }

    printf("%d \t  %s \t  %s \t %d", developer.id, developer.nombre, cat, developer.proyecto);
}

void mostrarProgramadores(eProgramador developer[], int tam)
{
    int i;
    int flag = 0;

    printf("ID \t NOMBRE \t CATEGORIA \t PROYECTO\n");
    for (i = 0; i < tam; i++)
    {
        if (developer[i].estado != 0)
        {
            mostrarProgramador(developer[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay programadores para mostrar.");
    }

}

void inicializarVector(eProgramador developer[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        developer[i].estado = 0;
    }
}

int buscarLibre(eProgramador developer[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (developer[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarProgramador(int id, eProgramador developer[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (developer[i].id == id && developer[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaProgramador(eProgramador developer[], int tam)
{
    eProgramador nuevoDeveloper;
    int esta, id, lugar;

    lugar = buscarLibre(developer, tam);

    if (lugar == -1)
    {
        printf("No hay lugar en el sistema");
    }
    else
    {
        printf("\nIngrese el ID: ");
        scanf("%d", &id);

        esta = buscarProgramador(id, developer, 50);

        if (esta != -1)
        {
            printf("Ese ID ya esta registrado");
        }
        else
        {
            nuevoDeveloper.id = id;

            printf("Ingrese nombre:");
            fflush(stdin);
            gets(nuevoDeveloper.nombre);

            printf("Ingrese categoria:");
            fflush(stdin);
            scanf("%c", &nuevoDeveloper.categoria);

            printf("Ingrese proyecto:");
            fflush(stdin);
            scanf("%d", &nuevoDeveloper.proyecto);

            nuevoDeveloper.estado = 1;

            developer[lugar] = nuevoDeveloper;
        }
    }
}
/*
void bajaProgramador(eProgramador developer[] , int tam);
{


    //int esta;

    //esta = buscarProgramador(id )
}*/










