#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Estacionamiento.h"
#include "validaciones.h"

#define TOTAL 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

int menu()
{
    char opcion[10];
    system("cls");
    printf("\n***ESTACIONAMIENTO***\n\n\n");
    printf("1- Alta Dueno\n");
    printf("2- Modificacion Dueno\n");
    printf("3- Ingreso Automovil\n");
    printf("4- Egreso Automovil\n");
    printf("5- Informes\n");
    printf("6- Salir\n");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    gets(opcion);

    while(validarNumero(opcion) == 0 || atoi(opcion) < 1 || atoi(opcion) > 6)
    {
        printf("Opcion incorrecta, debe ingresar valores del 1 al 6: ");
        fflush(stdin);
        gets(opcion);
    }

    return atoi(opcion);

}

/** \brief incializa el vector el 0
 *
 * \param duenos[] array a ser recorrido
 * \param tam tamaño del array
 * \return void
 *
 */
void inicializarVectorDuenos(eDueno duenos[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        duenos[i].estado = 0;
    }
}

/** \brief
 *
 * \param cars[] incializa el vector en 0
 * \param tam tamaño del array
 * \return void
 *
 */
void inicializarVectorCars(eCars cars[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cars[i].estado = 0;
    }
}

/** \brief devuelve el primero estado 0
 *
 * \param duenos[] array que se recorre
 * \param tam tamaño del array
 * \return devuelve el indice del lugar
 *
 */
int buscarDuenoLibre(eDueno duenos[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief busca el dueño en el array por id
 *
 * \param id id del deño a ser buscado
 * \param dueno[] array de dueños
 * \param tam tamaño del array
 * \return int devuelve el indice del dueño, -1 si no existe
 *
 */
int buscarDueno(int id, eDueno dueno[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (dueno[i].idDueno == id && dueno[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief agrega un dueno al array
 *
 * \param duenos[] array donde se ingresara el dueno
 * \param tam tamaño del array
 * \param bandera bandera para validacion del switch de main
 * \return void
 *
 */
void altaDueno(eDueno duenos[], int tam, int* bandera)
{
    eDueno nuevoDueno;
    int esta, id, lugar;
    char aux[100];
    char nombreAux[100];

    lugar = buscarDuenoLibre(duenos, tam);

    if (lugar == -1)
    {
        printf("No hay lugar en el sistema");
    }
    else
    {
        printf("\nIngrese el ID: ");
        fflush(stdin);
        gets(aux);

        if (validarNumero(aux) == 0)
        {
            printf("Debe ingresar solo numeros");
        }
        else
        {
            id = atoi(aux);

            esta = buscarDueno(id, duenos, tam);

            if (esta != -1)
            {
                printf("Ese dueno ya esta registrado");
            }
            else
            {
                nuevoDueno.idDueno = id;

                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombreAux);

                while (validarSoloLetras(nombreAux) == 0)
                {
                    printf("Ingrese solo letras: ");
                    fflush(stdin);
                    gets(nombreAux);
                }
                nombreAux[0] = toupper(nombreAux[0]);

                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(aux);

                while (validarSoloLetras(aux) == 0)
                {
                    printf("Ingrese solo letras: ");
                    fflush(stdin);
                    gets(aux);
                }
                aux[0] = toupper(aux[0]);

                strcat(nombreAux, " ");
                strcat(nombreAux, aux);
                strcpy(nuevoDueno.nombreYApellido, nombreAux);

                printf("Ingrese direccion: ");
                fflush(stdin);
                gets(nuevoDueno.direccion);

                while (strlen(nuevoDueno.direccion) > 30)
                {
                    printf("La dirreccion no debe contener mas de 30 caracteres: ");
                    fflush(stdin);
                    gets(nuevoDueno.direccion);
                }

                printf("Ingrese numero de tarjeta de credito: ");
                fflush(stdin);
                gets(aux);

                while (validarNumero(aux) == 0 || strlen(aux) > 16)
                {
                    printf("Ingrese solo un maximo de 16 numeros: ");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(nuevoDueno.numeroDeTarjetaDeCredito, aux);

                nuevoDueno.estado = 1;

                duenos[lugar] = nuevoDueno;

                *bandera = 1;
            }
        }


    }
}

/** \brief imprime los datos de todos los duenos por pantalla
 *
 * \param duenos[] array de duenos a ser mostrados
 * \param tam tamaño del array
 * \return void
 *
 */
void mostrarDuenos(eDueno duenos[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado != 0)
            printf("\n%d- %s \n", duenos[i].idDueno, duenos[i].nombreYApellido);
    }
}

/** \brief busca el primero indice 0 del array de autos
 *
 * \param cars[] array de autos
 * \param tam tamaño del array
 * \return int devuelve el indice del primero 0, devuele -1 si no existe
 *
 */
int buscarAutomovilLibre(eCars cars[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (cars[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief buscan un auto a partir de la patente
 *
 * \param patente[] patente del auto a ser modificado
 * \param cars[] array de autos donde se buscara el auto
 * \param tam tamaño del array
 * \return int devuelve el indice si lo encuentra, -1 si no existe
 *
 */
int buscarAtomovil(char patente[], eCars cars[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if (strcmp(cars[i].patente, patente) == 0 && cars[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief ingresa un auto en el estacionamiento si se puede
 *
 * \param duenos[] array de duenos para vincular con el auto
 * \param tamDuenos tamaño del array de duenos
 * \param cars[] array de autos para registrar el auto
 * \param tam tamaño del array de autos
 * \param bandera bandera para la validacion del switch en main
 * \return void
 *
 */
void ingresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam, int* bandera)
{
    eCars nuevoAutomovil;
    int esta, lugar;
    char patente[30];
    char aux[50];

    lugar = buscarAutomovilLibre(cars, tam);

    if (lugar == -1)
    {
        printf("No hay lugar en el estacionamiento");
    }
    else
    {
        printf("\nIngrese el la patente: ");
        fflush(stdin);
        gets(patente);

        while (strlen(patente) > 6)
        {
            printf("La patente debe estar conformada por 6 caracteres alfanuemricos. \nReingrese: ");
            fflush(stdin);
            gets(patente);
        }

        esta = buscarAtomovil(patente, cars, tam);

        if (esta != -1)
        {
            printf("Ese auto ya esta");
        }
        else
        {
            strcpy(nuevoAutomovil.patente, patente);

            printf("\n");
            printf("Ingrese marca \n 1- Alpha Romeo \n 2- Ferrari \n 3- Audi \n 4- Otro \n\n");
            fflush(stdin);
            gets(aux);

            while (validarNumero(aux) == 0 || atoi(aux) < 1 || atoi(aux) > 4)
            {
                printf("Debe ingresar los valores correspondientes a las marcas: ");
                fflush(stdin);
                gets(aux);
            }
            nuevoAutomovil.marca = atoi(aux);

            printf("\n");
            printf("Ingrese dueno por ID: \n");
            mostrarDuenos(duenos, tamDuenos);
            fflush(stdin);
            gets(aux);

            while (validarNumero(aux) == 0 || buscarDueno(atoi(aux), duenos, tamDuenos) == -1)
            {
                printf("El ID no es correcto o no existe: ");
                fflush(stdin);
                gets(aux);
            }
            nuevoAutomovil.dueno = atoi(aux);

            printf("\n");
            printf("Ingrese horario de entrada: ");
            fflush(stdin);
            gets(aux);

            while (validarNumero(aux) == 0 || atoi(aux) < 1 || atoi(aux) > 24)
            {
                printf("Ingrese una hora correcta (fomato de 24hs): ");
                fflush(stdin);
                gets(aux);
            }
            nuevoAutomovil.horarioDeEntrada = atoi(aux);

            nuevoAutomovil.estado = 1;

            cars[lugar] = nuevoAutomovil;

            *bandera = 1;
        }
    }
}

/** \brief imprime por pantalla todos los autos estacionados con los datos de sus duenos
 *
 * \param duenos[] array de  losd duenos para relacionar con los autos
 * \param tamDuenos tamaño del array de duenos
 * \param cars[] array de autos para imprimirlos
 * \param tam tamaño del array de autos
 * \return void
 *
 */
void mostrarAutomovilesEstacionados(eDueno duenos[], int tamDuenos, eCars cars[], int tam)
{
    int i;

    printf("Patente -- H. Entrada -- Marca -- Dueno  -- Direccion  --  N Tarjeta de C\n\n");

    for (i = 0; i < tam; i++)
    {
        mostrarAutomovilEstacionado(duenos, tamDuenos, cars[i]);
    }
}

/** \brief imprime un auto con los datos de su dueno
 *
 * \param duenos[] array de duenos para relacionarlo con el auto
 * \param tamDuenos tamano de array de auto
 * \param cars eCars estructura del auto
 * \return void
 *
 */
void mostrarAutomovilEstacionado(eDueno duenos[], int tamDuenos, eCars cars)
{
    int i;
    char marca[20];

    if (cars.marca == 1)
    {
        strcpy(marca, "Alpha Romeo");
    }
    else if (cars.marca == 2)
    {
        strcpy(marca, "Ferrari");
    }
    else if (cars.marca == 3)
    {
        strcpy(marca, "Audi");
    }
    else
    {
        strcpy(marca, "Otro");
    }

    if (cars.estado == 1)
    {
        printf("%s -- %dhs -- %s -- ", cars.patente, cars.horarioDeEntrada, marca);
        //recorro dueños
        for (i = 0; i < tamDuenos; i++)

        {
            if (duenos[i].estado == 1 && duenos[i].idDueno == cars.dueno)
            {
                printf("%s -- %s -- %s\n", duenos[i].nombreYApellido, duenos[i].direccion, duenos[i].numeroDeTarjetaDeCredito);
            }
        }
    }

}

/** \brief ordena el array de autos por hora de entrada y por patente
 *
 * \param cars[] array de los autos
 * \param tam tamaño del array
 * \return void
 *
 */
void ordenarAutomoviles(eCars cars[], int tam)
{
    int i, j;

    eCars aux;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (cars[i].horarioDeEntrada > cars[j].horarioDeEntrada)
            {
                aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }
            if (cars[i].horarioDeEntrada == cars[j].horarioDeEntrada)
                if (stricmp(cars[i].patente, cars[j].patente) > 0)
                {
                    aux = cars[i];
                    cars[i] = cars[j];
                    cars[j] = aux;
                }
        }
    }
}

/** \brief hardcodea 5 autos
 *
 * \param cars[] array a ser hardcodeado
 * \return void
 *
 */
void hardcodearCars(eCars cars[])
{
    char patente[][10] =  {"ABC123", "DFG456", "HIJ674", "JRD842", "KLM654"};
    int marca[] =  {AUDI, AUDI, 2, 4, 4};
    int dueno[] = {1, 2, 3, 4, 5};
    int horario[] = {10, 12, 12, 13, 13};

    int i;

    for (i = 0; i < 5; i++)
    {
        strcpy(cars[i].patente, patente[i]);
        cars[i].dueno = dueno[i];
        cars[i].marca = marca[i];
        cars[i].horarioDeEntrada = horario[i];
        cars[i].estado = 1;
    }

}

/** \brief muestra los duenos que poseen un auto de marca audi
 *
 * \param duenos[] array de los duenos
 * \param tamDuenos tamano de los duenos
 * \param cars[] array de los autos donde se buscara
 * \param tamCars tamano del array de autos
 * \return void
 *
 */
void mostrarPropietariosDeAudis(eDueno duenos[], int tamDuenos, eCars cars[], int tamCars)
{
    int i, j, bandera = 1;

    printf("Todos los propietarios de autos de marca Audi\n\n");

    for (i = 0; i < tamCars; i++)
    {
        if (cars[i].estado == 1 && cars[i].marca == AUDI)
        {
            for (j = 0; j < tamDuenos; j++)
            {
                if (duenos[j].estado == 1 && duenos[j].idDueno == cars[i].dueno)
                {
                    printf("%s -- %s -- %s\n", duenos[j].nombreYApellido, duenos[j].direccion, duenos[j].numeroDeTarjetaDeCredito);
                    bandera = 0;
                }
            }
        }


    }

    if (bandera)
        printf("Ningun cliente posee un auto de marca Audi");

}

/** \brief modifica el numero de tarjeta de credito de un dueno
 *
 * \param duenos[] array donde se buscara al dueno
 * \param tam tamano del array
 * \return void
 *
 */
void modificarDueno(eDueno duenos[], int tam)
{
    int i, id, bandera;
    char respuesta;
    char aux[50];

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    for (i = 0; i < tam; i++)
    {
        if (duenos[i].estado == 1 && duenos[i].idDueno == id)
        {
            printf("Seguro que desea modificar a ");
            printf("%s? ", duenos[i].nombreYApellido);
            printf("S/N\n");
            fflush(stdin);
            scanf("%c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta == 's')
            {
                printf("Numero actual de tarjeta de credito: %s\n", duenos[i].numeroDeTarjetaDeCredito);
                printf("Ingrese el nuevo numero de tarjeta de credito: ");
                fflush(stdin);
                gets(aux);

                while (validarNumero(aux) == 0 || strlen(aux) > 16)
                {
                    printf("Ingrese solo un maximo de 16 numeros: ");
                    fflush(stdin);
                    gets(aux);
                }

                printf("Modificacion exitosa");
                strcpy(duenos[i].numeroDeTarjetaDeCredito, aux);
            }
            else
            {
                printf("Accion cancelada");
            }
            bandera = 0;
            break;
        }

    }

    if (bandera)
        printf("El ID no existe");
}

/** \brief retira un automovil del estacionamiento
 *
 * \param duenos[] array de duenos para verificar
 * \param tamDuenos tamano del array de duenos
 * \param cars[] array de autos
 * \param tam int
 * \param arrayDeRecaudacion[] el array donde se guardara el valor de estadia
 * \return void
 *
 */
void egresoAutmovil(eDueno duenos[], int tamDuenos, eCars cars[], int tam, int arrayDeRecaudacion[])
{
    int esta, validar = 1, horaDeSalida, valorDeEstadia, id, estaDueno;
    char patente[30];
    char respuesta;
    char aux[30];


    printf("\nIngrese el ID: ");
    fflush(stdin);
    gets(aux);

    while (validarNumero(aux) == 0)
    {
        printf("\nIngrese un ID valido: ");
        fflush(stdin);
        gets(aux);
    }
    id = atoi(aux);

    estaDueno = buscarDueno(id, duenos, tamDuenos);

    if (estaDueno == -1)
    {
        printf("\nEl ID no existe");
    }
    else
    {
        printf("\nIngrese la patente: ");
        fflush(stdin);
        gets(patente);

        esta = buscarAtomovil(patente, cars, tam);

        if (esta == -1)
        {
            printf("\nLa patente no existe");
        }
        else
        {

            if (cars[esta].dueno == duenos[estaDueno].idDueno)
            {

                printf("\nDesea retirar el auto con patente \"%s\" del dueno \"%s\"? S/N \n",cars[esta].patente,duenos[estaDueno].nombreYApellido);
                fflush(stdin);
                scanf("%c", &respuesta);

                respuesta = tolower(respuesta);

                while(validar)
                {
                    if (respuesta == 's')
                    {
                        validar = 0;
                        printf("Ingrese la hora de salida (sabiendo que ingreso a la(s) %dhs): ", cars[esta].horarioDeEntrada);
                        fflush(stdin);
                        gets(aux);

                        while(validarNumero(aux) == 0 || atoi(aux) < cars[esta].horarioDeEntrada || atoi(aux) > 24)
                        {
                            printf("El auto ingreso a la(s) %dhs): ", cars[esta].horarioDeEntrada);
                            printf("y no puede permanecer de un dia para el otro, ingrese una hora correta: ");
                            fflush(stdin);
                            gets(aux);
                        }

                        horaDeSalida = atoi(aux);

                        valorDeEstadia = calcularRecaudacionDeAuto(cars[esta].horarioDeEntrada, horaDeSalida, cars[esta].marca, arrayDeRecaudacion);

                        generarTicket(cars[esta], duenos[estaDueno], valorDeEstadia, cars[esta].marca);

                        cars[esta].estado = 0;

                        break;

                    }
                    else if (respuesta == 'n')
                    {
                        validar = 0;
                        printf("Accion cancelada");
                        break;
                    }
                    printf("Ingrese S/N");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    respuesta = tolower(respuesta);
                }
            }
            else
            {
                printf("Los datos no coinciden.");
            }
        }
    }
}

/** \brief calcula el valor de la estacio segun hora de salida y marca
 *
 * \param horaDeEntrada la hora que ingreso el auto
 * \param horaDeSalida la hora que salio el auto
 * \param marca marca de auto
 * \param arrayDeRecaudacion[] array donde se guardara el valor de la estadia
 * \return int devuelve la recaudacion
 *
 */
int calcularRecaudacionDeAuto(int horaDeEntrada, int horaDeSalida, int marca, int arrayDeRecaudacion[])
{
    int costo;

    if (marca == ALPHA_ROMEO)
    {
        costo = (horaDeSalida - horaDeEntrada) * 150;
    }
    else if (marca == FERRARI)
    {
        costo = (horaDeSalida - horaDeEntrada) * 175;
    }
    else if (marca == AUDI)
    {
        costo = (horaDeSalida - horaDeEntrada) * 200;
    }
    else
    {
        costo = (horaDeSalida - horaDeEntrada) * 250;
    }

    recaudar(costo, marca, arrayDeRecaudacion);

    return costo;
}

/** \brief genera el ticket donde muestra el valor de la estadia de un auto
 *
 * \param car estructura del auto para mostrar datos
 * \param dueno estructura del dueno para mostrar datos
 * \param valorDeEstadia el valor de su estadia
 * \param marca marca del auto para mostrar
 * \return void
 *
 */
void generarTicket(eCars car, eDueno dueno, int valorDeEstadia, int marca)
{

    char marquita[20];

    printf("\n------------------------------------------------------------\n");

    printf("Nombre del dueno: %s\n", dueno.nombreYApellido);
    printf("Su patente: %s\n", car.patente);

    if (car.marca == ALPHA_ROMEO)
        strcpy(marquita, "Alpha Romeo");
    else if (car.marca == FERRARI)
        strcpy(marquita, "Ferrari");
    else if (car.marca == AUDI)
        strcpy(marquita, "Audi");
    else
        strcpy(marquita, "Otro");
    printf("La marca: %s\n", marquita);
    printf("Valor de la estadia: $%d", valorDeEstadia);

    printf("\n-------------------------------------------------------------------------\n");
}

/** \brief se encarga de guardar el valor de estadia segun marca en el array de recaudacion
 *
 * \param recaudacion el valor de la estadia de un auto
 * \param marca la marca del auto
 * \param arrayDeRecaudacion[] array donde se guardara el valor de la recaudacion
 * \return void
 *
 */
void recaudar(int recaudacion, int marca, int arrayDeRecaudacion[])
{
    if (marca == ALPHA_ROMEO)
    {
        arrayDeRecaudacion[ALPHA_ROMEO] = arrayDeRecaudacion[ALPHA_ROMEO] + recaudacion;
    }
    else if (marca == FERRARI)
    {
        arrayDeRecaudacion[FERRARI] = arrayDeRecaudacion[FERRARI] + recaudacion;
    }
    else if (marca == AUDI)
    {
        arrayDeRecaudacion[AUDI] = arrayDeRecaudacion[AUDI] + recaudacion;
    }
    else
    {
        arrayDeRecaudacion[OTRO] = arrayDeRecaudacion[OTRO] + recaudacion;
    }

    arrayDeRecaudacion[TOTAL] = arrayDeRecaudacion[TOTAL] + recaudacion;
}

/** \brief muestra las recaudaciones del array segun marca y totales
 *
 * \param arrayDeRecaudacion[] array donde se almacena todos los valores
 * \return void
 *
 */
void mostrarRecaudacion(int arrayDeRecaudacion[])
{
    printf("\n-------------------------------------------------------------------------\n");
    printf("Recaudacion Total: %d\n\n", arrayDeRecaudacion[TOTAL]);
    printf("Recaudacion por marca\n\n");
    printf("Alfa Romeo: %d\n", arrayDeRecaudacion[ALPHA_ROMEO]);
    printf("Ferrari: %d\n", arrayDeRecaudacion[FERRARI]);
    printf("Audi: %d\n", arrayDeRecaudacion[AUDI]);
    printf("Otro: %d", arrayDeRecaudacion[OTRO]);
    printf("\n-------------------------------------------------------------------------\n");
}











