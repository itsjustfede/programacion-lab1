#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void cargarVector(int*, int);
void mostrarVector(int*, int);

int main()
{
    int vec[TAM];

    cargarVector(vec, TAM);

    printf("\n\n");

    mostrarVector(vec, TAM);

    return 0;
}

void cargarVector(int* vectorcito, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", (vectorcito + i));
    }
}

void mostrarVector(int* vectorcito, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%d ", *(vectorcito + i));
    }
}




