#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;

void mostrarAlumnosConMaterias(eAlumno alumnos[], int tamAlumnos, eMateria materias[], int tamMaterias, eInscripcion inscripcion[], int tamInscripcion);
void mostrarMateriasConCantidadDeInscriptos(eMateria materias[], int tamMateria, eInscripcion inscripciones[], int tamInscripciones);
int maximosInscriptos(int materia, eInscripcion inscripciones[], int tamInscripcion);
void materiaMasCursada(eMateria materias[], int tamMateria, eInscripcion inscripciones[], int tamInscripciones);
//void mostrarMateriasConAlumnos()



