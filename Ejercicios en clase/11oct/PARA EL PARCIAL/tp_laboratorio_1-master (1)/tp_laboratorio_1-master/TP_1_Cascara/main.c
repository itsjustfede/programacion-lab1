#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int resultadoFac;
    float oper1=0,oper2=0,resultado;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=%.3f)\n",oper1);
        printf("2- Ingresar 2do operando (B=%.3f)\n",oper2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("    Ingrese el primer operando\n    ");
                scanf("%f",&oper1);
                break;
            case 2:

                printf("    Ingrese el segundo operando\n    ");
                scanf("%f",&oper2);
                break;
            case 3:
                resultado=FuncionSumar(oper1,oper2);
                printf("        el resultado de la suma  es: %.3f\n\n",resultado);
                break;
            case 4:
                resultado=FuncionRestar(oper1,oper2);
                printf("        el resultado de la resta es: %.3f\n\n",resultado);
                break;
            case 5:
                if (oper2==0)
                    printf("        ERROR!!!! \a\n\n");
                     else
                            resultado=FuncionDividir(oper1,oper2);
                            printf("        el resultado de la division es: %.3f \n\n",resultado);
                break;
            case 6:
                resultado=FuncionMultiplicar(oper1,oper2);
                printf("        el resultado de la multiplicacion es: %.3f\n\n",resultado);
                break;
            case 7:
                if (oper1<0)
                        printf("        ERROR!!!! \a\n\n");
                    else
                            resultadoFac=FuncionFactorial (oper1);
                            printf("        La factorial del primer operador es: %d\n\n",resultadoFac);
                break;
            case 8:
                printf("\n      la suma es: %.3f\n",FuncionSumar (oper1, oper2));
                printf("\n      la resta es: %.3f\n",FuncionRestar (oper1, oper2));
                printf("\n      la division es: %.3f\n",FuncionDividir (oper1, oper2));
                printf("\n      la multiplicacion es: %.3f\n",FuncionMultiplicar (oper1, oper2));
                printf("\n      el factorial es: %d\n",FuncionFactorial (oper1));
                break;
            case 9:

                seguir = 'n';
                break;
        }

    }
            printf("\n\n\nAdios!\a\n ");
    return 0;
}
