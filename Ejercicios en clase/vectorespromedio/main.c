#include <stdio.h>
#include <stdlib.h>

int main()
{
    int leg[] = {128, 356, 198, 215, 320};
    int n1[] = {2, 2, 2, 7, 10};
    int n2[] = {7, 2, 8, 6, 9};
    int i;
    float promedios[5];

    printf("--------------------------------------\n\n");
    printf("Legajo    Nota 1    Nota 2   Promedio\n\n");

    for (i = 0; i < 5; i++)
    {
        promedios[i] =(float) (n1[i] + n2[i]) / 2;

    }

    for(i = 0; i < 5; i++)
    {
    printf("%d       %d         %d        %.2f\n", leg[i], n1[i], n2[i], promedios[i]);
    }

    printf("\n--------------------------------------");

    return 0;
}
