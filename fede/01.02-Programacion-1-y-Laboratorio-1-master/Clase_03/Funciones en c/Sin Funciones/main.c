#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2;
    int suma;
    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

     printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    suma = numero1 + numero2;

    printf("La suma es: %d", suma );


    return 0;
}
