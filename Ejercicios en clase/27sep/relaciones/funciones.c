#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

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

void mostrarProgramador(eProgramador developer, eProy_Prog proyprog[], eProyecto proyecto[])
{
    int i, j;

    printf("%2d    %s    %5d        %5d         ", developer.id, developer.nombre, developer.categoria, developer.proyecto);

    //recorro proyecto_programadores
    for (i = 0; i < 3; i++)

    {
        if (proyprog[i].idProg == developer.id)
        {
            //recorro proyectos
            for (j = 0; j < 3; j++)
            {
                if (proyprog[i].idProy == proyecto[j].id)
                {

                    printf("%s\n", proyecto[j].descrip);


                }
            }
        }
    }
}

void mostrarProgramadores(eProgramador developer[], eProy_Prog proyprog[], eProyecto proyecto[], int tam)
{
    int i;
    int flag = 0;

    printf("Id -- Nombre -- Categoria -- Proyecto -- CantHsTrab -- Sueldo\n");
    for (i = 0; i < tam; i++)
    {
        if (developer[i].estado != 0)
        {
            mostrarProgramador(developer[i], proyprog, proyecto);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay programadores para mostrar.");
    }

}

void inicializarVector(eProgramador developer[], eProy_Prog progProy[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        developer[i].estado = 0;
        progProy[i].estado = 0;

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
            //scanf("%c", &nuevoDeveloper.categoria);

            printf("Ingrese proyecto:");
            fflush(stdin);
            scanf("%d", &nuevoDeveloper.proyecto);

            nuevoDeveloper.estado = 1;

            developer[lugar] = nuevoDeveloper;
        }
    }
}

void bajaProgramador(eProgramador developer[], eProy_Prog proyprog[], eProyecto proyecto[], int tam)
{
    int esta, id;
    char baja;

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    esta = buscarProgramador(id, developer, tam);

    if (esta != -1)
    {
        mostrarProgramador(developer[esta], proyprog, proyecto);
        printf("\nEsta seguro que desea eliminar esta persona?\n");
        fflush(stdin);
        scanf("%c", &baja);

        baja = tolower(baja);

        if (baja == 's')
        {
            developer[esta].estado = 0;
            printf("Persona eliminada con exito");
        }
        else if (baja == 'n')
        {
            printf("Accion cancelada");
        }
    }
    else
    {
        printf("El ID no esta registrado");
    }

}

void modificarProgramador(eProgramador developer[], eProy_Prog proyprog[], eProyecto proyecto[], int tam)
{
    int esta, id;
    char baja;
    eProgramador aux;

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    esta = buscarProgramador(id, developer, tam);


    if (esta != -1)
    {
        mostrarProgramador(developer[esta], proyprog, proyecto);
        printf("\nEsta seguro que desea modificar esta persona?\n");
        fflush(stdin);
        scanf("%c", &baja);

        baja = tolower(baja);

        if (baja == 's')
        {

            aux.id = developer[esta].id;

            printf("Reingrese nombre:");
            fflush(stdin);
            gets(aux.nombre);

            printf("Reingrese categoria:");
            fflush(stdin);
            scanf("%d", &aux.categoria);

            printf("Reingrese proyecto:");
            fflush(stdin);
            scanf("%d", &aux.proyecto);

            developer[esta] = aux;
        }
        else if (baja == 'n')
        {
            printf("Accion cancelada");
        }
    }
    else
    {
        printf("El ID no esta registrado");
    }



}

void hardCodearCat(eCategoria cat[], int tam)
{
    int id[] = {70, 75, 80};
    char desc[][30] = {"Junior", "Semisenior", "Senior"};
    float valor[] = {50, 75, 100};
    int i;

    for (i = 0; i < tam; i++)
    {
        cat[i].id = id[i];
        strcpy(cat[i].descripcion, desc[i]);
        cat[i].valorPorHora = valor[i];
    }
}

void hardCodearProyectos(eProyecto proyectos[], int tam)
{
    int id[] = {10, 11, 12, 13};
    char desc[][30] = {"SS.Gtion", "Afip", "Arba", "Web Service"};
    int i;

    for (i = 0; i < tam; i++)
    {
        proyectos[i].id = id[i];
        strcpy(proyectos[i].descrip, desc[i]);
    }
}

void hardCodearProgramador(eProgramador developer[], int tam)
{
    int id[] = {1, 2, 3};
    char nombre[][30] =  {"Fede", "Juan", "Andy"};
    int cat[] =  {70, 75, 80};
    int proyecto[] = {70, 70, 80};
    float sueldo[] = {400, 400, 600};
    int cantHsTrab[] = {20, 20, 20};

    int i;

      for (i = 0; i < tam; i++)
    {
        developer[i].id = id[i];
        strcpy(developer[i].nombre, nombre[i]);
        developer[i].categoria = cat[i];
        developer[i].proyecto = proyecto[i];
        developer[i].sueldo = sueldo[i];
        developer[i].cantHsTrab = cantHsTrab[i];
        developer[i].estado = 1;
    }

}

void mostrarCategoria (eProgramador developer[], eCategoria categorias[], int tam)
{
    int i;
    printf("\nID -- Descripcion -- Valor por hora\n");
    for(i=0; i<tam; i++)
    {
            printf("%d    ", categorias[i].id);
            printf("%s          ", categorias[i].descripcion);
            printf("%d \n", categorias[i].valorPorHora);

    }

}

int calcularSueldo(int horasTrabajadas, int categoria)
{
    int valor;

    valor = horasTrabajadas * categoria;

    return valor;
}
