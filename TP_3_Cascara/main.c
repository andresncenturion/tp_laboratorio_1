#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define PATH "archivo.dat"

int main()
{
    char seguir = 's';
    eMovie* arrayMovies;
    int tam = 100;
    int* pTam;

    pTam = &tam;
    arrayMovies = newArrayMovies(pTam);

    while (seguir == 's')
    {
        fileToArray(PATH, arrayMovies, pTam);
        switch (menu())
        {
        case 1:
            agregarPelicula(PATH, arrayMovies, pTam);
            break;
        case 2:
            borrarPelicula(arrayMovies, pTam);
            break;
        case 3:
            modificarPelicula(arrayMovies, pTam);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida.\n\n");
            break;
        }
        arrayToFile(PATH, arrayMovies, pTam);
    }
    free(arrayMovies);
    return 0;
}
