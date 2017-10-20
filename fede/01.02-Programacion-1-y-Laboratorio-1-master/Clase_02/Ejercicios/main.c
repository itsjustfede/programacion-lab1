#include <stdio.h>
#include <stdlib.h>

int main()
{
	//variables
	char pregunta;
	int suma=0;
	int unidad=1;
	int numero;
	int numeroMinimo=0;
	int numeroMaximo=0;
    int numeroMinimoImpar=0;
	int numeroMaximoImpar=0;

	int promedio;


	//contadores
	int contador=0;
	int contadorNumeroPar=0;
	int contadorNumeroImpar=0;
	int contador_3_15=0;
	int contador_16_29=0;
	int contador_30_mas=0;


	//acumuladores
	int acumuladorGeneral=0;
	int acumuladorNumeroPar=0;
	int acumuladorNumeroImpar=0;
	int sumatoriaImpar=0;



	do
    {
       printf("ingrese un numero: ");
       scanf("%i" , &numero);
       while(numero<=0)
       {
          printf("Error, ingrese un numero mayor a cero: ");
          scanf("%i" , &numero);
       }

       acumuladorGeneral=acumuladorGeneral+numero;

       contador++;

       printf("Desea cargar otro valor [s/n]:");
       scanf(" %c",&pregunta);

       if (contador==1)
       {
          numeroMaximo=numero;
          numeroMinimo=numero;
       }
       else
       {
          if (numero>numeroMaximo)
          {
            numeroMaximo=numero;
          }
          else
          {
             if (numeroMinimo>numero)
             {
               numeroMinimo=numero;
             }
          }
       }

       // condicional par o impar
       if(numero%2==0)
       {
         contadorNumeroPar++;
       }
       else
       {
         contadorNumeroImpar++;
         acumuladorNumeroImpar=acumuladorNumeroImpar+numero;

         if (contadorNumeroImpar==1)
         {
            numeroMaximoImpar=numero;
            numeroMinimoImpar=numero;
         }
         else
         {
            if (numero>numeroMaximoImpar)
            {
               numeroMaximoImpar=numero;
            }
            else
            {
              if (numeroMinimoImpar>numero)
              {
               numeroMinimoImpar=numero;
              }
            }
         }

       }

       //condicional rango de numero
       if(numero>=30)
       {
        contador_30_mas++;
       }
       else
       {
          if(numero>=3 && numero<=15 )
          {
            contador_3_15++;
          }
          else
          {
            if(numero>=16 && numero<=29)
            {
              contador_16_29++;
            }
          }
       }


    }while(pregunta=='s');




    //ejercicio 1
    printf("1) Cantidad de numeros par: %i \n", contadorNumeroPar);

    //ejercicio 2
    printf("2) Cantidad de numeros impar: %i \n", contadorNumeroImpar);

    //ejercicio 3
    printf("3) Sumatoria numero impar: %i \n", acumuladorNumeroImpar);

    //ejercicio 4
    promedio=acumuladorGeneral/contador;
    printf("4) Promedio de todos los numeros: %i \n", promedio);

    //ejercicio 5
    printf("5) El Numero mayor ingresado: %i \n", numeroMaximo);

    //ejercicio 6
    printf("6) El Numero menor impar ingresado: %i \n", numeroMinimoImpar);

    //ejercicio 7
    printf("7) Rango(3-15): %i \n Rango(16-29): %i \n Rango(29-en adelante): %i \n", contador_3_15, contador_16_29, contador_30_mas );

    //ejercicio 8
    //printf("8)\n");

    //a
    //  printf("a) Sumatoria de numeros que lo anteceden-impar- : %i \n", );

    //b
     //printf("b) Numeros que lo anteceden, hasta sumatoria de n impar: : %i \n", );


    return 0;

}
