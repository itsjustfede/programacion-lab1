#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idDueno;
    char nombreYApellido[70];
    char direccion[30];
    int numeroDeTarjetaDeCredito;
    int estado;
}eDueno;

typedef struct
{
    char patente[30];
    int marca;
    int dueno;
    int horarioDeEntrada;
    int estado;
}eCars;



int menu();
void inicializarVectorDuenos(eDueno[], int );
void inicializarVectorCars(eCars cars[], int tam);
int buscarDuenoLibre(eDueno duenos[], int tam);
int buscarDueno(int id, eDueno dueno[], int tam);
void altaDueno(eDueno duenos[], int tam);
void mostrarDuenos(eDueno duenos[], int tam);
int buscarAutomovilLibre(eCars cars[], int tam);
int buscarAtomovil(char patente[], eCars cars[], int tam);
void ingresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam);
void mostrarAutomovilesEstacionados(eDueno duenos[], int tamDuenos, eCars cars[], int tam);
void mostrarAutomovilEstacionado(eDueno duenos[], int tamDuenos, eCars cars);
void ordenarAutomoviles(eCars cars[], int tam);
void hardcodearCars(eCars cars[]);


