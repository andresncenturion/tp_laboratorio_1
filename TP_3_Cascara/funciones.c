#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define PATH "archivo"
#define M_INITIAL_VALUE 2

void inicializarArray (eMovie* arrayMovies, int tam)
{
    int i;

    if (arrayMovies != NULL && tam > 0)
    {
        for (i=0 ; i<tam ; i++)
        {
            (arrayMovies+i)->estado = 0;
        }
    }
}

eMovie* newArrayMovies ()
{
    eMovie* arrayMovies;


    arrayMovies = (eMovie*) malloc (sizeof(eMovie)*);

    if (arrayMovies == NULL)
    {
        printf("Error al inicializar.\n\n");
        exit(1);
    }

    inicializarArray(arrayMovies, tam);

    return arrayMovies;
}

void mostrarPelicula (eMovie* movie)
{
    printf("%s  %s  %d  %s  %d  %s  %d\n", movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkDeImagen, movie->estado);
}

void mostrarPeliculas (eMovie* arrayMovies, int tam)
{
    int i = 0;

    for (i=0 ; i<tam ; i++)
    {
        if ((arrayMovies+i)->estado == 1)
        {
            mostrarPelicula(arrayMovies+i);
        }
    }
    printf("\n\n");
}

int menu(void)
{
    int opcion;

    system ("cls");
    printf("--- SELECCIONE OPCION DESEADA ---\n\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

eMovie* new_movie()
{
    eMovie* nuevaMovie;

    nuevaMovie = (eMovie*) malloc (sizeof(eMovie));
    if (nuevaMovie != NULL)
    {
        printf("Titulo: ");
        fflush(stdin);
        gets(nuevaMovie->titulo);
        printf("Genero: ");
        fflush(stdin);
        gets(nuevaMovie->genero);
        printf("Duracion: ");
        scanf("%d", &nuevaMovie->duracion);
        printf("Descripcion: ");
        fflush(stdin);
        gets(nuevaMovie->descripcion);
        printf("Puntaje: ");
        scanf("%d", &nuevaMovie->puntaje);
        printf("Link de imagen: ");
        fflush(stdin);
        gets(nuevaMovie->linkDeImagen);
        nuevaMovie->estado = 1;
    }
    return nuevaMovie;
}

int buscarLibre (eMovie* arrayMovies, int tam)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if ((arrayMovies+i)->estado == 0)
            {
                index = i;
                break;
            }
    }
    return index;
}

eMovie* resizeArray (eMovie* arrayMovies, int tam)
{
    eMovie* auxArray = NULL;

    if (arrayMovies != NULL)
    {
        auxArray = (eMovie*) realloc(arrayMovies, sizeof(eMovie)*(tam+5));
        if (auxArray != NULL)
        {
            arrayMovies = auxArray;
        }
    }
    free(auxArray);
    return arrayMovies;
}
int fileToArray (char* path, eMovie* arrayMovies)
{
    FILE* f;
    int cant;
    int i=0;

    f = fopen(path, "rb");
    if (f != NULL)
    {
        while (!feof(f))
        {
            cant = fread((arrayMovies+i), sizeof(eMovie), 1, f);
            i++;
            if (cant != 1)
            {
                if (feof(f))
                {
                    break;
                }
                else
                {
                    printf("Error al leer el archivo.\n\n");
                    break;
                }
            }
        }
        fclose(f);
    }
    return i;
}

int arrayToFile (char* path, eMovie* arrayMovies)
{
    FILE* f;
    int cant;
    int i=0;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        f = fopen(path, "wb");
    }
    else
    {
        f = fopen(path, "ab");
    }

    cant = fwrite((arrayMovies+i), sizeof(eMovie), 1, f);
    i++;
    if (cant != 1)
    {
        printf("Error al escribir el archivo.\n\n");
    }
    fclose(f);
    return i;
}

void agregarPelicula(char* path, eMovie* arrayMovies)
{
    eMovie* nuevaMovie;
    int index = 0;
    int tam = 0;

    tam = fileToArray(path, arrayMovies);
    index = buscarLibre(arrayMovies, tam);
    nuevaMovie = new_movie();
    if (index == -1)
    {
        arrayMovies = resizeArray (arrayMovies, tam);
        index = tam+1;
    }
    *(arrayMovies+index) = *nuevaMovie;
    arrayToFile(path, arrayMovies);
    printf("Pelicula cargada con exito.\n\n");
}

void arrayToFile2(char* path, eMovie* arrayMovies, int tam)
{
    FILE* f;
    int cant;
    int i;

    f = fopen(path, "rb");
    if (f != NULL)
    {
        fclose(f);
        f = fopen(path, "wb");
        for (i=0 ; i<tam ; i++)
        {
            if ((arrayMovies+i)->estado == 1)
            {
                cant = fwrite((arrayMovies+i), sizeof(eMovie), 1, f);
                if (cant != 1)
                {
                    printf("Error al escribir el archivo.\n\n");
                }
            }
        }
    }
}

void borrarPelicula(char* path, eMovie* arrayMovies)
{
    int cant;

    cant = fileToArray(path, arrayMovies);
    mostrarPeliculas(arrayMovies, cant);
}

