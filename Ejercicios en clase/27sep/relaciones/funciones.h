#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    char nombre[20];
    int categoria;
    int proyecto;
    float sueldo;
    int cantHsTrab;
    int estado;
}eProgramador;

typedef struct
{
    int id;
    char descripcion[11];
    int valorPorHora;
}eCategoria;

typedef struct
{
    int idProy;
    char descrip[500];
    int id;
}eProyecto;

typedef struct
{
    int idProg;
    int idProy;
    int hs;
    int estado;
}eProy_Prog;

//a = Senior
//b = SemiSenior
//c = Junior

int menu();

void mostrarProgramador(eProgramador , eProy_Prog[], eProyecto[]);
void mostrarProgramadores(eProgramador [], eProy_Prog[], eProyecto[], int );
void inicializarVector(eProgramador[], eProy_Prog[], int );
int buscarLibre(eProgramador[], int );
int buscarProgramador(int, eProgramador[], int );
void altaProgramador(eProgramador[] , int );
void bajaProgramador(eProgramador[], eProy_Prog[], eProyecto[] , int );
void modificarProgramador(eProgramador [], eProy_Prog [], eProyecto [], int );
void hardCodearCat(eCategoria[], int );
void hardCodearProyectos(eProyecto proyectos[], int tam);
void hardCodearProgramador(eProgramador[], int );
void mostrarCategoria(eProgramador [],eCategoria [], int);
int calcularSueldo(int horasTrabajadas, int categoria);
