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
    int i, j, contador;

    printf("\n---- Materias con cantidad de inscriptos ----\n\n");

    for (i = 0; i < tamMateria; i++)
    {
        printf("%s: ", materias[i].descripcion);
        contador = 0;

        for (j = 0; j < tamInscripciones; j++)
        {
            if (materias[i].id == inscripciones[j].idMateria)
                contador++;
        }
        printf("%d\n", contador);
    }
}

void materiaMasCursada(eMateria materias[], int tamMateria, eInscripcion inscripciones[], int tamInscripciones)
{
    int i, j, contador, max, flag = 1;

    printf("\n---- Materia mas cursada ----\n\n");

    for (i = 0; i < tamMateria; i++)
    {
        contador = 0;
        for (j = 0; j < tamInscripciones; j++)
        {
            if (materias[i].id == inscripciones[j].idMateria)
            {
                contador++;
            }
        }
        if (flag)
        {
            flag = 0;
            max = contador;
        }
        else if (contador > max)
            max = contador;


    }

}








