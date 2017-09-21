#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int cuadrado;

    int producto;

    printf("Ingrese el primer numero: \n");
    scanf("%d", &num1);
    while(num1 == 0)
    {
        printf("Error, el numero no debe ser 0, reingrese\n");
        scanf("%d", &num1);
    }

    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);
    while(num2 == 0)
    {
        printf("Error, el numero no debe ser 0, reingrese\n");
        scanf("%d", &num2);
    }


    producto = num1 + num2;

    printf("El producto es: %d\n", producto);

    cuadrado = num1 * num1;

    printf("El cuadrado del primer numero es: %d", cuadrado);



    return 0;
}
