#include <stdio.h>
#include <stdlib.h>

int suma(int n1, int n2);
int resta(int n1, int n2);
float division(float n1, float n2);
int multiplicacion(int n1, int n2);
int pedirNumero();  // prototipo, es el que le da consistencia al programa
//no va nada en los parentesis porque la funcion no nesecita parametros para correr
int main()
{
    int num1, num2, rta;

    /* printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2); */

    num1 = pedirNumero();
    num2 = pedirNumero();

    /* rta = num1 + num2;*/

    rta = multiplicacion(num1, num2);
    printf("Resultado %d", rta);

    return 0;
}
int suma (int n1, int n2)
{
    int resp;
    resp = n1 + n2;
    return resp;
}
int pedirNumero()
{
    int num;
    printf("Ingrese un numero:");
    scanf("%d", &num);
    return num;
}
int resta (int n1, int n2)
{
    int resp;
    resp = n1 - n2;
    return resp;
}
int multiplicacion (int n1, int n2)
{
    int resp;
    resp = n1 * n2;
    return resp;
}
float division (float n1, float n2)
{
    float resp;
    resp = n1 / n2;
    return resp;
}
