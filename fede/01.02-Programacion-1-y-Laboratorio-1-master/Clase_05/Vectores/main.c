#include <stdio.h>
#include <stdlib.h>

#define A 3

int main()
{
    int legajos[A], edades[A], maxEdad, flagMax = 0, opcion, auxLeg, flagEncontro, flagIngreso=0 ;
    float notas[A], promedio, acumNotas, auxNota;
    int i,c;
    char seguir='s', respuesta;
    int posicion;

    do
    {
        printf("1.Cargar datos\n2.Mostrar Maximo\n3. Buscar por legajo \n4.promedio\n5.modificar \n6.Listar todo\n7.Bajas\n8. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            for(i=0; i<A; i++)
            {
                printf("Ingrese legajo: ");
                scanf("%d", &legajos[i]);
                printf("Ingrese edad: ");
                scanf("%d", &edades[i]);
                printf("Ingrese nota: ");
                scanf("%f", &notas[i]);
            }
            flagIngreso=1;
            break;
        case 2:
            if(flagIngreso==1)
            {
                for(i=0; i<A; i++)
                {
                    if(legajos[i]!=-1)
                    {
                        if(flagMax==0 || edades[i]>maxEdad)
                        {
                            maxEdad = edades[i];
                            flagMax = 1;
                        }
                    }

                }
                printf("Maximo\n");
                for(i=0; i<A; i++)
                {

                    if(legajos[i]!=-1 && edades[i]==maxEdad)
                    {
                        printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);
                    }
                }
            }
            else
            {
                printf("Debe ingresar datos para operar");
            }


            break;
        case 3:
            flagEncontro = 0;

            printf("Ingrese un lgajo a buscar: "),
                   scanf("%d", &auxLeg);
            for(i=0; i<A; i++)
            {
                if(auxLeg==legajos[i])
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);
                    flagEncontro = 1;
                    break;
                }

            }
            if(flagEncontro==0)
            {
                printf("Legajo inexistente");
            }
            break;
        case 4:
            acumNotas=0;
            c=0;
            for(i=0; i<A; i++)
            {
                if(legajos[i]!=-1)
                {
                    acumNotas+=notas[i];
                    c++;
                }

            }
            promedio = acumNotas/c;

            for(i=0; i<A; i++)
            {

                if(legajos[i]!=-1 && notas[i]>promedio)
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);
                }
            }

            break;
        case 5:

            flagEncontro = 0;

            printf("Ingrese un lgajo a buscar: "),
                   scanf("%d", &auxLeg);
            for(i=0; i<A; i++)
            {
                if(auxLeg==legajos[i])
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);
                    printf("Ingrese la nueva nota: ");
                    scanf("%f", &auxNota);
                    printf("Esta seguro de realizar la modificacion?: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        notas[i]=auxNota;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!!!");
                    }
                    flagEncontro = 1;
                    break;
                }

            }
            if(flagEncontro==0)
            {
                printf("Legajo inexistente");
            }

            break;

        case 6:
            printf("Legajo\tEdad\tNota\n");
            for(i=0; i<A; i++)
            {
                if(legajos[i]!=-1)
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);
            }
            break;
        case 7:
            flagEncontro = 0;

            printf("Ingrese un lgajo a buscar: "),
                   scanf("%d", &auxLeg);
            for(i=0; i<A; i++)
            {
                if(auxLeg==legajos[i])
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);

                    printf("Esta seguro de eliminar el alumno?: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        legajos[i]=-1;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!!!");
                    }
                    flagEncontro = 1;
                    break;
                }

            }
            if(flagEncontro==0)
            {
                printf("Legajo inexistente");
            }

            break;
        case 8:
            seguir='n';
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    //carga secuencial










    return 0;
}
/*
do
    {
        printf("Ingrese la posicion: ");
        scanf("%d", &posicion);

        printf("Ingrese un numero: ");
        scanf("%d", &numeros[posicion-1]);

        printf("Desea ingresar otro numero?: ");
        seguir = getche();

    }
    while(seguir=='s');*/


