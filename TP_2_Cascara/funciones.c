#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_LISTA 5

void inicializarEmpleados (EPersona* pLista, int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        (pLista+i)->estado = 0;
    }
}

int buscarLibre(EPersona* pLista, int tam)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if ((pLista+i)->estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void agregarPersona (EPersona* pLista, int tam)
{
    int index;
    EPersona nuevaPersona;
    EPersona* pNpersona;

    pNpersona = &nuevaPersona;

    system("cls");
    index = buscarLibre(pLista, MAX_LISTA);
    if (index == -1)
    {
        printf("No se pueden ingresar mas personas.\n\n");
        system("pause");
    }
    else
    {
        pNpersona->estado = 1;

        printf("--- ALTA PERSONA ---\n\n");
        printf("Nombre: ");
        fflush(stdin);
        gets(pNpersona->nombre);
        printf("Edad: ");
        scanf("%d", &pNpersona->edad);
        printf("DNI: ");
        scanf("%ld", &pNpersona->dni);
        (pLista+index) = *pNpersona;

        printf("\nSe ha agregado exitosamente.");
    }
    printf("\n\n");
}
