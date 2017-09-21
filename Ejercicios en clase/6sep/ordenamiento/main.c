#include <stdio.h>
#include <stdlib.h>

int main()
{
    int legajo[] = {33, 45, 65, 23, 76};
    int i, j, vec;

    for(i=0; i<FIL-1; i++)
    {
        for(j=i+1; j<FIL; j++)
        {
            if(vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }




    return 0;
}
