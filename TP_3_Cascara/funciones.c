#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define PATH "archivo"
#define TAM 5

eMovie* newArrayMovies (int tam)
{
    eMovie* arrayMovies;

    if (tam<0)
    {
        arrayMovies = (eMovie*) malloc(tam*sizeof(eMovie));
        if (arrayMovies != NULL)
        {
            printf("Error al inicializar.\n\n");
            exit(1);
        }
    }
    return arrayMovies;
}

void mostrarPelicula (eMovie* movie)
{
    printf("%s  %s  %d  %s  %d  %s  %d\n", movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkDeImagen, movie->estado);
}

void mostrarPeliculas (char* path, eMovie* arrayMovies, int tam)
{
    int i = 0;

    fileToArray(path, arrayMovies);
    for (i=0 ; i<tam ; i++)
    {
        if ((arrayMovies+i)->estado == 1)
        {
            mostrarPelicula(arrayMovies+i);
        }
    }
    printf("\n\n");
}

void inicializarArray (eMovie* arrayMovies, int tam)
{
    int i;

    if (arrayMovies != NULL && tam>0)
    {
        for (i=0 ; i<tam ; i++)
        {
            (arrayMovies+i)->estado = 0;
        }
    }
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
    int i = -1;
    int index;

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

void agregarPelicula(char* path, eMovie* arrayMovies, int tam)
{
    eMovie* nuevaMovie;
    eMovie* auxArray;
    int index;
    int aumento;

    fileToArray(path, arrayMovies);
    index = buscarLibre(arrayMovies, tam);
    nuevaMovie = new_movie();
    if (index != -1)
    {
        *(arrayMovies+index) = *nuevaMovie;
    }
    else
    {
        aumento = tam+5;
        auxArray = (eMovie*) realloc(arrayMovies, sizeof(eMovie)+aumento);
        if (auxArray != NULL)
        {
            arrayMovies = auxArray;
        }
        else
        {
            printf("Error al redimensionar memoria.\n\n");
        }
    }
    arrayToFile(path, arrayMovies, index);
}

void fileToArray (char* path, eMovie* arrayMovies)
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
}

void arrayToFile (char* path, eMovie* arrayMovies, int index)
{
    FILE* f;
    int cant;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        f = fopen(path, "wb");
    }
    else
    {
        f = fopen(path, "ab");
    }

    cant = fwrite((arrayMovies+index), sizeof(eMovie), 1, f);
    if (cant != 1)
    {
        printf("Error al escribir el archivo.\n\n");
    }
    fclose(f);
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

void borrarPelicula(char* path, eMovie* arrayMovies, int tam)
{
    char auxTitulo[20];
    int i;

    fileToArray(path, arrayMovies);

    printf("--- BORRAR PELICULA ---\n\n");
    mostrarPeliculas(path, arrayMovies, tam);
    printf("Ingrese nombre de pelicula a borrar: ");
    fflush(stdin);
    gets(auxTitulo);

    for (i=0 ; i<tam ; i++)
    {
        if (stricmp(auxTitulo, (arrayMovies+i)->titulo) == 0)
        {
            (arrayMovies+i)->estado = 0;
            printf("La pelicula se ha borrado exitosamente.\n\n");
        }
    }
    arrayToFile2(path, arrayMovies, tam);
}

