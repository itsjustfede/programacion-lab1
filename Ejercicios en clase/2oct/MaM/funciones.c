#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void mostrarAlumnosConMaterias(eAlumno alumnos[], int tamAlumnos, eMateria materias[], int tamMaterias, eInscripcion inscripcion[], int tamInscripcion)
{
    int i, j, k;

    printf("---- Alumnos con materias ----\n\n");

    for (i = 0; i < tamAlumnos; i++)
    {
        printf("%s --> ", alumnos[i].nombre);

        for (j = 0; j < tamInscripcion; j++)
        {
            if (alumnos[i].legajo == inscripcion[j].legajo)
            {
                for (k = 0; k < tamMaterias; k++)
                {
                    if (inscripcion[j].idMateria == materias[k].id)
                        printf("%s ", materias[k].descripcion);
                }
            }
        }
        printf("\n");
    }
}

void mostrarMateriasConCantidadDeInscriptos(eMateria materias[], int tamMateria, eInscripcion inscripciones[], int tamInscripciones)
{
    int i, contador;

    printf("\n---- Materias con cantidad de inscriptos ----\n\n");

    for (i = 0; i < tamMateria; i++)
    {
        printf("%s: ", materias[i].descripcion);
        contador = 0;

        contador = maximosInscriptos(materias[i].id, inscripciones, tamInscripciones);

        /*for (j = 0; j < tamInscripciones; j++)
        {
            if (materias[i].id == inscripciones[j].idMateria)
                contador++;
        }*/

        printf("%d\n", contador);
    }
}

int maximosInscriptos(int materia, eInscripcion inscripciones[], int tamInscripciones)
{
    int cantidad = 0, i;

    for (i = 0; i < tamInscripciones; i++)
        {
            if (materia == inscripciones[i].idMateria)
                cantidad++;
        }

    return cantidad;
}

void materiaMasCursada(eMateria materias[], int tamMateria, eInscripcion inscripciones[], int tamInscripciones)
{
    int i, j, maximo, contador, flag = 1;

    printf("\n---- Materia mas cursada ----\n\n");

    for (i = 0; i < tamMateria; i++)
    {
        contador = 0;

        for (j = 0; j < tamInscripciones; j++)
        {
            if (inscripciones[j].idMateria == materias[i].id)
            {
                contador++;
            }
        }
        if (flag || contador > maximo)
        {
            maximo = contador;
            flag = 0;
        }

    }


printf("%d", maximo);

}







