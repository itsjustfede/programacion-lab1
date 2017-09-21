#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, resultado;

    printf("Ingrese primer numero...\n");
    scanf("%d", &num1);

    printf("Ingrese segundo numero...\n");
    scanf("%d", &num2);

    resultado = num1 - num2;

    if (resultado < 0)
    {
        printf("El resultado es negativo");
    }
    else
    {
        printf("El resultado es positivo");
    }

    return 0;
}
