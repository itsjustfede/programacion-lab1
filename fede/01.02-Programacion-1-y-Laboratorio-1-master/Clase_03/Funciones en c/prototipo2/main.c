#include <stdio.h>
#include <stdlib.h>

void sumarNumeros(int n1, int n2);

int main()
{

    int numero1, numero2;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

     printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    sumarNumeros(numero1, numero2);


    return 0;
}


void sumarNumeros(int n1, int n2)
{
    int suma;

    suma = n1+n2;

    printf("La suma es: %d", suma );
}
