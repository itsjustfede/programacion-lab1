#include <stdio.h>
#include <stdlib.h>

void swap (int*, int*);

int main()
{
    int x =15, y = 20;

    printf("Antes del swap\n");

    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    swap(&x, &y);

    printf("\nDespues del swap\n");

    printf("X = %d\n", x);
    printf("Y = %d\n", y);


    return 0;
}

void swap (int* x, int* y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;

    printf("\nDentro de la funcion swap\n");

    printf("X = %d\n", *x);
    printf("Y = %d\n", *y);
}
