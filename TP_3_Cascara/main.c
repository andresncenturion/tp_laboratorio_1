#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define PATH "archivo"
#define TAM 5

int main()
{
    char seguir = 's';
    eMovie* arrayMovies;

    arrayMovies = newArrayMovies(TAM);

    if (arrayMovies == (NULL))
    {
        printf("No se pudo reservar espacio en memoria\n\n");
        exit(1);
    }

    inicializarArray(arrayMovies, TAM);
    while (seguir == 's')
    {
        switch (menu())
        {
        case 1:
            agregarPelicula(arrayMovies, TAM);
            system("Pause");
            break;
        case 2:
            borrarPelicula(arrayMovies, TAM, PATH);
            system("Pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida.\n\n");
            break;
        }
    }
    //free ();

    return 0;
}
