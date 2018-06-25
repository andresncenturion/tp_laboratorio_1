#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEmpleados (EPersona lista[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        lista[i].estado = 0;
    }
}

int menu (void)
{
    int opcion;

    system("cls");

    printf("--- SELECCIONE LA OPCION DESEADA ---\n\n");

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n\n");

    scanf("%d",&opcion);

    return opcion;
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

    index = buscarLibre(lista, tam);
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

void borrarPersona (EPersona lista[], int tam)
{
    long int auxDni;
    int index;
    char confirma;

    printf("--- BORRAR PERSONA ---\n\n");
    mostrarPersonas(lista, tam);
    printf("DNI: ");
    scanf("%ld", &auxDni);
    index = buscarPersona(lista, tam, auxDni);
    if (index == -1)
    {
        printf("\nEl DNI ingresado no existe");
    }
    else
    {
        mostrarPersona(lista, index);
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
            lista[index].estado = 0;
            printf("\nBorrado exitoso.");
        }
        else
        {
            printf("\nCancela borrado.");
        }
    }
    printf("\n\n");
}

void mostrarPersona (EPersona lista[], int index)
{
    printf("\n%s \t%d \t%ld", lista[index].nombre, lista[index].edad, lista[index].dni);
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;

    printf("NOMBRE \tEDAD \tDNI\n");
    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 1)
        {
            mostrarPersona(lista, i);
        }
    }
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

void ordenarPorNombre(EPersona lista[], int tam)
{
    EPersona auxPersona;
    int i,j;

    printf("--- LISTA ORDENADA POR NOMBRE ---\n\n");

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1 ; j<tam ; j++)
        {

            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }
    }

    mostrarPersonas(lista, tam);
}

void imprimirGrafico (EPersona lista[], int tam)
{
    int flag=0;
    int i;
    int menor18=0;
    int entre19y35=0;
    int mayor35=0;
    int contTotal;

    printf("--- GRAFICO POR EDADES ---\n\n");

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad < 18)
            {
                menor18++;
            }
            else
            {
                if(lista[i].edad >= 18 && lista[i].edad <= 35)
                {
                    entre19y35++;
                }
                if(lista[i].edad > 35)
                {
                    mayor35++;
                }
            }
        }
    }
    contTotal = menor18 + entre19y35 + mayor35;
    for(i=contTotal ; i>0 ; i--)
    {
        if(menor18 == i)
        {
            printf("*");
            menor18--;
        }

        printf("\t");

        if(entre19y35 == i)
        {
            printf("*");
            entre19y35--;
        }
        printf("\t");

        if(mayor35==i)
        {
            printf("*");
            mayor35 --;
        }
        printf("\n");
        flag = 1;
    }
    if(flag != 1)
    {
        printf("No se han ingresado datos\n");
    }
    printf("-----------------\n");
    printf("<=18\t19-35\t>=35\n");
}
