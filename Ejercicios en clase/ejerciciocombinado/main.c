#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);

int main()
{
    int leg[] = {128, 356, 198, 215, 320};
    int n1[] = {2, 2, 2, 7, 10};
    int n2[] = {7, 2, 8, 6, 9};
    int i, indice, num;
    float promedios[5];

    printf("--------------------------------------\n\n");
    printf("Legajo    Nota 1    Nota 2   Promedio\n\n");

    for (i = 0; i < 5; i++)
    {
        promedios[i] =(float) (n1[i] + n2[i]) / 2;

    }

    for(i = 0; i < 5; i++)
    {
    printf("\n%d       %d         %d        %.2f", leg[i], n1[i], n2[i], promedios[i]);
    }

    printf("\n--------------------------------------");

    printf("\nIngrese un legajo...\n");
    scanf("%d", &num);

    indice = buscarNumero(num, leg, 5);

    if (indice == -1)
    {
        printf("\nEl numero no pertenece al array\n");
    }
    else
    {
        printf("Legajo: %d Nota1: %d Nota2: %d Promedio: %.2f", indice, n1[indice], n2[indice], promedios[indice]);
    }





    return 0;
}

int buscarNumero(int num, int vec[], int tam)
{
    int val = -1;
    int i;
    for (i = 0; i < tam; i++)
    {
        if (num == vec[i])
        {
            val = i;
            break;
        }
    }
    return val;


}
