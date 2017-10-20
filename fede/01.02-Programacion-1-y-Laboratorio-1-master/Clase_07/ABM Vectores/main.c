#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarAlumnos(int[], char[][50], int[], float[], int[], int);
int buscarLibre(int[], int);
int altaAlumno(int[], char[][50], int[], float[], int[], int);



#define A 3

int main()
{
    int legajos[A], edades[A], estados[A]= {0}, maxEdad, flagMax = 0, opcion, auxLeg, flagEncontro, flagIngreso=0,auxInt;
    float notas[A], promedio, acumNotas, auxNota;
    int i, j,c;
    char nombres[A][50], seguir='s', respuesta, auxString[50];
    int posicion;

    do
    {
        printf("1.Cargar datos\n2.Mostrar Maximo\n3. Buscar por legajo \n4.promedio\n5.modificar \n6.Listar todo\n7.Bajas\n8. Salir\n9. Ordenar por nombre\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            flagEncontro=0;

            flagEncontro = altaAlumno(legajos, nombres, edades, notas, estados, A);
            if(flagEncontro==-1)
            {
                printf("No hay espacio disponible");
            }
            else
            {
                printf("Carga exitosa!!!");
            }

            flagIngreso=1;
            break;
        case 2:
            if(flagIngreso==1)
            {
                for(i=0; i<A; i++)
                {
                    if(estados[i]!=0)
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

                    if(estados[i]!=0 && edades[i]==maxEdad)
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
                if(estados[i]!=0 && auxLeg==legajos[i])
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

                if(estados[i]!=0 && notas[i]>promedio)
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
                if(estados[i]!=0 && auxLeg==legajos[i])
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
            mostrarAlumnos(legajos, nombres, edades, notas, estados, A);
            break;
        case 7:
            flagEncontro = 0;

            printf("Ingrese un lgajo a buscar: "),
                   scanf("%d", &auxLeg);
            for(i=0; i<A; i++)
            {
                if(estados[i]!=0 && auxLeg==legajos[i])
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], notas[i]);

                    printf("Esta seguro de eliminar el alumno?: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        estados[i] = 0;
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
        case 9:

            for(i=0; i<A-1; i++)
            {
                for(j=i+1; j<A; j++)
                {
                    if(strcmp(nombres[i], nombres[j])>0)
                    {
                        strcpy(auxString,nombres[i]);
                        strcpy(nombres[i], nombres[j]);
                        strcpy(nombres[j],auxString);
                        //legajos, notas, edades, estados

                        auxInt = legajos[i];
                        legajos[i] = legajos[j];
                        legajos[j] = auxInt;

                        auxNota = notas[i];
                        notas[i] = notas[j];
                        notas[j] = auxNota;

                        auxInt = edades[i];
                        edades[i] = edades[j];
                        edades[j] = auxInt;

                        auxInt = estados[i];
                        estados[i] = estados[j];
                        estados[j] = auxInt;
                    }
                    else
                    {
                        if(strcmp(nombres[i], nombres[j])==0)
                        {
                            if(legajos[i]>legajos[j])
                            {
                                auxInt = legajos[i];
                                legajos[i] = legajos[j];
                                legajos[j] = auxInt;

                                auxNota = notas[i];
                                notas[i] = notas[j];
                                notas[j] = auxNota;

                                auxInt = edades[i];
                                edades[i] = edades[j];
                                edades[j] = auxInt;

                                auxInt = estados[i];
                                estados[i] = estados[j];
                                estados[j] = auxInt;
                            }

                        }
                    }


                }
            }

            mostrarAlumnos(legajos, nombres, edades, notas, estados, A);

            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');
    //carga secuencial










    return 0;
}


void mostrarAlumnos(int leg[], char nom[][50], int ed[], float not[], int est[], int tam)
{
    int i;
    printf("Legajo\tnombre\tEdad\tNota\n");
    for(i=0; i<tam; i++)
    {
        if(est[i]!=0)
            printf("%d\t%s\t%d\t%f\n", leg[i], nom[i], ed[i], not[i]);
    }
}

int buscarLibre(int estados[], int  tam)
{
    int i;
    int encontro=-1;
    for(i=0; i<tam; i++)
    {
        if(estados[i]==0)
        {
            encontro=i;
            break;
        }
    }

    return encontro;
}

int altaAlumno(int legajos[], char nombres[][50], int edades[], float notas[], int estados[], int tam)
{
    int posicion;


    posicion = buscarLibre(estados,A);
    if(posicion!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[posicion]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[posicion]);
        printf("Ingrese edad: ");
        scanf("%d", &edades[posicion]);
        printf("Ingrese nota: ");
        scanf("%f", &notas[posicion]);

        estados[posicion] = 1;

    }
    return posicion;
}
