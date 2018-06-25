#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_LISTA 10

int main()
{
    char seguir='s';

    EPersona lista[MAX_LISTA];

    inicializarEmpleados (lista, MAX_LISTA);

    while(seguir=='s')
    {
        switch(menu())
        {
            case 1:
                agregarPersona(lista, MAX_LISTA);
                system("Pause");
                break;
            case 2:
                borrarPersona(lista, MAX_LISTA);
                system("Pause");
                break;
            case 3:
                ordenarPorNombre(lista, MAX_LISTA);
                system("Pause");
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
