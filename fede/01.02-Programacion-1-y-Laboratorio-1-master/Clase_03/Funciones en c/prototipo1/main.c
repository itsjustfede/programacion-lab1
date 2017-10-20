#include <stdio.h>
#include <stdlib.h>

//1. Declaracion de la funcion: prototipo
 void sumarNumeros(void);

int main()
{
    //2. llamada
    sumarNumeros();
    return 0;
}

//3. implementacion o desarrollo de la funcion
 void sumarNumeros(void)
 {
   int numero1, numero2;
    int suma;
    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

     printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    suma = numero1 + numero2;

    printf("La suma es: %d", suma );
 }
