#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, cuadrado;

    printf("Ingrese un numero...\n");
    scanf("%d", &num);

    while(num < 0)
    {
        printf("Error!! el numero debe ser mayor a 0...\n");
        scanf("%d", &num);
    }

    cuadrado = num * num;

    printf("El cuadrado del numero es: %d", cuadrado);

    return 0;
}
