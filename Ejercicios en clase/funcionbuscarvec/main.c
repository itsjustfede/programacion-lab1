#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int, int[], int);

int main()
{
    int leg[] = {128, 356, 198, 215, 320};
    int num, indice;

    printf("Ingrese un numero...\n");
    scanf("%d", &num);

    indice = buscarNumero(num, leg, 5);

    if (indice == -1)
    {
        printf("\nEl numero no pertenece al array\n");
    }
    else
    {
        printf("\nEl numero pertenece al indice %d del array\n", indice);
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
