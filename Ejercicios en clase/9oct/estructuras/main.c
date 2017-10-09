#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char modelo[20];
    int nucleos;
}eProcesador;

typedef struct
{
    char marca[20];
    eProcesador procesador;
    int ram;
    float precio;
}eNotebook;

void cargarNotebook(eNotebook*);
void mostrarNotebook(eNotebook);

int main()
{
    eNotebook notebook;

    cargarNotebook(&notebook);

    printf("\n\n");

    mostrarNotebook(notebook);
    return 0;
}

void mostrarNotebook(eNotebook note)
{
    printf("Marca: %s", note.marca);
    printf("\nRAM: %d", note.ram);
    printf("\nProcesador\n");
    printf("\t  Modelo: %s\n", note.procesador.modelo);
    printf("\t  Nucleos: %d", note.procesador.nucleos);
    printf("\nPrecio: %.2f", note.precio);
}

void cargarNotebook(eNotebook* notebook)
{
    printf("Ingresar marca: ");
    fflush(stdin);
    gets(notebook->marca);

    printf("Ingrese la cantidad de memoria RAM: ");
    scanf("%d", &notebook->ram);

    printf("Ingrese el modelo de procesador: ");
    fflush(stdin);
    gets(notebook->procesador.modelo);

    printf("Ingrese la cantidad de nucleos del procesador: ");
    scanf("%d", &notebook->procesador.nucleos);

    printf("Ingrese el precio de la computadora: ");
    scanf("%f", &notebook->precio);

}
