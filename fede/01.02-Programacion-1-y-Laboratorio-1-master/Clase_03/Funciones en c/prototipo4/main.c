#include <stdio.h>
#include <stdlib.h>

int sumarNumeros(int n1, int n2);
int main()
{
    int numero1, numero2;
    int suma;
   /* printf("Ingrese un numero: ");
    scanf("%d", &numero1);

     printf("Ingrese otro numero: ");
    scanf("%d", &numero2);
*/
    suma=sumarNumeros(6, 4);

    printf("La suma es: %d", suma);

    return 0;
}

int sumarNumeros(int n1, int n2)
{
    int suma;

    suma = n1 + n2;

    return suma;
}
