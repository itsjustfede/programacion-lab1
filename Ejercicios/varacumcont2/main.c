#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero...\n");
    scanf("%d", &num1);

    printf("Ingrese otro numero...\n");
    scanf("%d", &num2);

    resultado = num1 + num2;

    printf("La suma es: %d", resultado);

    return 0;
}
