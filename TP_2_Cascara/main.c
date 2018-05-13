#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 50

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    long int dni;
}EPersona;

void inicializarEmpleados (EPersona[], int);
void agregarPersona (EPersona[], int);
int buscarLibre(EPersona[], int);
int buscarPersona (EPersona[], int, long int);
void borrarPersona (EPersona[], int);
void ordenarPorNombre(EPersona[], int);
void mostrarPersonas(EPersona[], int);
void mostrarPersona (EPersona[], int, int);
void imprimirGrafico (EPersona[], int);

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona lista[MAX_LISTA];

    inicializarEmpleados (lista, MAX_LISTA);

    while(seguir=='s')
    {
        system ("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista, MAX_LISTA);
                system("pause");
                break;
            case 2:
                borrarPersona(lista, MAX_LISTA);
                system("pause");
                break;
            case 3:
                ordenarPorNombre(lista, MAX_LISTA);
                system("pause");
                break;
            case 4:
                imprimirGrafico(lista, MAX_LISTA);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta.");
                break;
        }
    }

    return 0;
}

void inicializarEmpleados (EPersona lista[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        lista[i].estado = 0;
    }
}

int buscarLibre(EPersona lista[], int tam)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void agregarPersona (EPersona lista[], int tam)
{
    int index;
    EPersona nuevaPersona;

    system("cls");
    index = buscarLibre(lista, MAX_LISTA);
    if (index == -1)
    {
        printf("No se pueden ingresar mas personas.\n\n");
        system("pause");
    }
    else
    {
        nuevaPersona.estado = 1;

        printf("--- ALTA PERSONA ---\n\n");
        printf("Nombre: ");
        fflush(stdin);
        gets(nuevaPersona.nombre);
        printf("Edad: ");
        scanf("%d", &nuevaPersona.edad);
        printf("DNI: ");
        scanf("%ld", &nuevaPersona.dni);
        lista[index] = nuevaPersona;

        printf("\nSe ha agregado exitosamente.");
    }
    printf("\n\n");
}


int buscarPersona (EPersona lista[], int tam, long int auxDni)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].dni == auxDni && lista[i].estado == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void borrarPersona (EPersona lista[], int tam)
{
    long int dni;
    int existe;
    char confirma;

    system("cls");
    printf("--- BORRAR PERSONA ---\n\n");
    printf("DNI: ");
    scanf("%ld", &dni);
    existe = buscarPersona(lista, tam, dni);
    if (existe == -1)
    {
        printf("\nEl DNI ingresado no existe");
    }
    else
    {
        mostrarPersona(lista, tam, existe);
        printf("\nConfirma borrar?[s/n]: ");
        fflush(stdin);
        scanf( "%c", &confirma);
        while ((confirma != 's') && (confirma != 'n'))
        {
            printf("ERROR. Ingrese nuevamente.\n");
            printf("\nConfirma borrar?[s/n]: ");
            fflush(stdin);
            scanf( "%c", &confirma);
        }
        if (confirma == 's')
        {
            printf("\nConfirma borrado.");
            lista[existe].estado = 0;
            printf("\nBorrado exitoso.");
        }
        else
        {
            printf("\nCancela borrado.");
        }
    }
    printf("\n\n");
}

void mostrarPersona (EPersona lista[], int tam, int index)
{
    printf("NOMBRE \tEDAD \tDNI\n");
    printf("\n%s \t%d \t%ld", lista[index].nombre, lista[index].edad, lista[index].dni);
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;

    system("cls");
    printf("NOMBRE \tEDAD \tDNI\n");
    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("\n%s \t%d \t%ld", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }
}

void ordenarPorNombre(EPersona lista[], int tam)
{
    int i;
    int j;
    EPersona auxPersona;

    system("cls");
    printf("--- LISTA ORDENADA POR NOMBRES ---\n\n");
    for (i=0 ; i<tam-1 ; i++)
    {
        for (j=i+1 ; i<tam ; i++)
        {
            if (strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                    auxPersona = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxPersona;
            }
        }
    }
    mostrarPersonas(lista, tam);
    printf("\n\n");
}

void imprimirGrafico (EPersona lista[], int tam)
{
    int i;
    int contadores[3];
    int hasta18 = 0;
    int de19a35 = 0;
    int mayor35 = 0;
    int maximo;
    int flag = 0;

    system ("cls");
    printf("--- GRAFICO POR EDADES ---\n\n");

    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 1)
        {
            if (lista[i].edad < 19)
            {
                hasta18++;
            }
            if ((lista[i].edad > 19) && (lista[i].edad < 36))
            {
                de19a35++;
            }
            if (lista[i].edad > 35)
            {
                mayor35++;
            }
        }
    }
    contadores[0] = hasta18;
    contadores[1] = de19a35;
    contadores[2] = mayor35;

    for(i=0 ; i<3 ; i++)
    {
        if ((contadores[i] > maximo) || (flag == 0))
        {
            flag = 1;
            maximo = contadores [i];
        }
    }

    for(i=maximo ; i>0 ; i--)
        {
            if (i >= hasta18)
            {
                printf("*");
            }
            if (i >= de19a35)
            {
                printf("\t*");
            }
            if (i >= mayor35)
            {
                printf("\t\t*");
            }
            printf("\n");
        }

    printf("\n<=18 \t19-35 \t>35");
    printf("\n\n");
}
