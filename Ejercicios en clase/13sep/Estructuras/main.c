#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia, mes, anio;
}eFecha;

typedef struct
{
    int dni;
    char nombre[40];
    float peso;
    eFecha fNac;

}ePersona;

int cargarInt(char []);
void cargarCadena(char [], char []);
float cargarFloat(char []);
void mostraPersona(ePersona);
void mostrarPersonas(ePersona[], int );

int main()
{
    int i;

    //ePersona unaPersona;

    //ePersona otraPersona;

    ePersona listaPersonas[3];



    //unaPersona = {40.000, "Fede", 80};

    /*
    unaPersona.dni = 40000;
    strcpy(unaPersona.nombre, "Fede");
    unaPersona.peso = 80;
    */

    /*printf("Ingrese DNI...\n");
    scanf("%d", &unaPersona.dni);*/


    /*
    unaPersona.dni = cargarInt("Ingrese DNI...\n");

    cargarCadena("Ingrese nombre...\n", unaPersona.nombre);

    unaPersona.peso = cargarFloat("Ingrese Peso...\n");

    printf("\n\n");

    mostraPersona(unaPersona);

    printf("\n------------------------\n");

    otraPersona = unaPersona ;

    mostraPersona(otraPersona);

    printf("\n\n");
    */


    for (i = 0; i < 3; i++)
    {
       listaPersonas[i].dni = cargarInt("Ingrese DNI...\n");
       cargarCadena("Ingrese nombre...\n", listaPersonas[i].nombre);
       listaPersonas[i].peso = cargarInt("Ingrese peso...\n");
       listaPersonas[i].fNac.dia = cargarInt("Ingrese dia de nacimiento...\n");
       listaPersonas[i].fNac.mes = cargarInt("Ingrese mes de nacimiento...\n");
       listaPersonas[i].fNac.anio = cargarInt("Ingrese anio de nacimiento...\n");
    }

    mostrarPersonas(listaPersonas, 3);

    return 0;
}






int cargarInt(char msj[])
{
    int num;
    printf("%s", msj);
    scanf("%d", &num);

    return num;
}

void cargarCadena(char msj[], char cad[])
{
    printf("%s", msj);
    fflush(stdin);
    gets(cad);
}

float cargarFloat(char msj[])
{
    float num;

    printf("%s", msj);
    scanf("%f", &num);

    return num;
}

void mostraPersona(ePersona p1)
{
    printf("%d\t %s\t %.2f\t %.02d/%.02d/%d", p1.dni, p1.nombre, p1.peso, p1.fNac.dia, p1.fNac.mes, p1.fNac.anio);
}

void mostrarPersonas(ePersona p1[], int num)
{
    int i;
    printf("\nDNI\t NOMBRE\t PESO\t FECHA DE NACIMIENTO\n");
     for (i = 0; i < num; i++)
    {
        mostraPersona(p1[i]);
        printf("\n");
    }
}

