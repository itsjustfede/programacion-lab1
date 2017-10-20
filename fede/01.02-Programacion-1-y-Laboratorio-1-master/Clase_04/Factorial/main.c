#include <stdio.h>
#include <stdlib.h>

int main()
{
    int factorial=1;
    int numero;
    int i;

    printf("Ingresar un numero: ");
    scanf("%i", &numero);

    for(i=1; i<=numero; i++)
    {
        factorial=factorial*i;
    }

    printf("Factorial de %i es %i:", numero, factorial);


    return 0;
}
