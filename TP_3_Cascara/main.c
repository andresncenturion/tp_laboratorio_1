#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define PATH "archivo"

int main()
{
    char seguir = 's';
    eMovie* arrayMovies;

    arrayMovies = newArrayMovies();

    while (seguir == 's')
    {
        switch (menu())
        {
        case 1:
            agregarPelicula(PATH, arrayMovies);
            system("Pause");
            break;
        case 2:
            borrarPelicula(PATH, arrayMovies);
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida.\n\n");
            break;
        }
    }
    free(arrayMovies);
    return 0;
}
