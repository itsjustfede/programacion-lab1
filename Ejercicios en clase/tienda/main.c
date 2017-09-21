#include <stdio.h>
#include <stdlib.h>

#define max 10

int main()
{
    int codigo[max];
    float precio[max];
    char marca[max];
    int i;
    int estado[max];
    int flag;

   /* for(i=0;i<max;i++)
    {
        estado[0]= 0;
    }

    do
    {
    flag=0;

    for(i=0;i<max;i++)
    {
        if(estado[i]=0=0)
        {
            printf("legajo: ");
            scanf("%d", &legajo[i]);

            estado[i]=1;
            flag = 1;
            break;
        }
    }
    if (flag==0)
    {
    printf("no hay espacio");
    }
*/

    for(i = 0; i < max; i++)
    {
        printf("Marca: ");
        scanf("%d", &marca[i]);
        printf("Precio: ");
        scanf("%f", &precio[i]);
        printf("codigo: ");
        scanf("%c", &codigo[i]);
    }

    for (i = 0; i < max; i++)
    {
        if ()




    }


    return 0;
}
