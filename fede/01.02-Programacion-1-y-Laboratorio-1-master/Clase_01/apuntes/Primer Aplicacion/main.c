#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int edad;
    float altura;
    char sexo;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su altura: ");
    scanf("%f", &altura);

    printf("Ingrese sexo: ");
    sexo = getche();

    printf("\nLa edad es: %d - la altura es: %.2f - y el sexo es: %c", edad, altura, sexo);
    return 0;
}
