#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(void);
int main()
{
    int suma;
    suma=sumarNumeros();

    printf("La suma es: %d", suma);
    return 0;
}

int sumarNumeros(void)
{
    int numero1, numero2;
    int suma;
    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

     printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    suma = numero1 + numero2;

   return suma;
}
