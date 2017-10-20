#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vecA[10], vecB[10], vecC[10];
    int i;

    for(i=0; i<10; i++)
    {
        printf("Ingrese numero para A: ");
        scanf("%d", &vecA[i]);
        printf("Ingrese numero para B: ");
        scanf("%d", &vecB[i]);
    }

    for(i=0; i<10; i++)
    {
        if(vecA[i]>vecB[i])
        {
            vecC[i] = vecA[i];
        }
        else
        {
            vecC[i]= vecB[i];
        }
    }

    for(i=0; i<10; i++)
    {
        printf("%d\t%d\t%d\n", vecA[i], vecB[i], vecC[i]);
    }


    printf("Hello world!\n");
    return 0;
}
