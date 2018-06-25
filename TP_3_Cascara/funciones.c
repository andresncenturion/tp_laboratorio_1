#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define PATH "archivo"

eMovie* newArrayMovies (int* pTam)
{
    eMovie* arrayMovies;

    arrayMovies = (eMovie*) malloc (sizeof(eMovie)*(*pTam));

    if (arrayMovies == NULL)
    {
        printf("ERROR. No se encontro espacio en memoria para el array de peliculas.\n\n");
        exit(1);
    }
    return arrayMovies;
}

void inicializarArray (eMovie* arrayMovies, int* pTam)
{
    int i;

    if (arrayMovies != NULL && (*pTam) > 0)
    {
        for (i=0 ; i<*pTam ; i++)
        {
            (arrayMovies+i)->estado = 0;
        }
    }
}

void fileToArray (char* path, eMovie* arrayMovies, int* pTam)
{
    int cant;
    FILE* f;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        f = fopen(path, "wb");
    }
    while (!feof(f))
    {
        cant = fread(arrayMovies, sizeof(eMovie), *pTam, f);
        if (cant != *pTam)
        {
            if (feof(f))
            {
                break;
            }
            else
            {
                printf("Error de lectura.\n\n");
                break;
            }
        }
    }
    fclose(f);
    *pTam = cant;
    printf("Cantidad de elementos leidos desde archivo: %d", cant);
    system("Pause");
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

void mostrarPelicula (eMovie* movie)
{
    printf("%s  %s  %d  %s  %d  %s  %d\n", movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkDeImagen, movie->estado);
}

void mostrarPeliculas (eMovie* arrayMovies, int* pTam)
{
    int i = 0;

    for (i=0 ; i<*pTam ; i++)
    {
        if ((arrayMovies+i)->estado == 1)
        {
            mostrarPelicula(arrayMovies+i);
        }
    }
    printf("\n\n");
}

eMovie* new_movie()
{
    eMovie* nuevaMovie;

    nuevaMovie = (eMovie*) malloc (sizeof(eMovie));
    if (nuevaMovie != NULL)
    {
        printf("--- AGREGAR PELICULA ---\n\n");
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

int buscarLibre (eMovie* arrayMovies, int* pTam)
{
    int i;
    int index = -1;

    for (i=0 ; i<*pTam ; i++)
    {
        if ((arrayMovies+i)->estado == 0)
            {
                index = i;
                break;
            }
    }
    return index;
}

eMovie* resizeArray (eMovie* arrayMovies, int* pTam)
{
    eMovie* auxArray = NULL;

    if (arrayMovies != NULL)
    {
        *pTam = (*pTam + 5);
        auxArray = (eMovie*) realloc(arrayMovies, sizeof(eMovie)*(*pTam));
        if (auxArray != NULL)
        {
            arrayMovies = auxArray;
        }
    }
    free(auxArray);
    return arrayMovies;
}

void arrayToFile (char* path, eMovie* arrayMovies, int* pTam)
{
    FILE* f;
    int cant;

    f = fopen(path, "wb");
    if (f == NULL)
    {
        printf("Error al crear archivo.\n\n");
        exit(-1);
    }
    cant = fwrite(arrayMovies, sizeof(eMovie), *pTam, f);
    if (cant != *pTam);
    {
        printf("Error al escribir el archivo.\n\n");
        exit(1);
    }
    fclose(f);
}

void agregarPelicula(char* path, eMovie* arrayMovies, int* pTam)
{
    int index;
    eMovie* nuevaMovie;

    index = buscarLibre(arrayMovies, pTam);
    if (index == -1)
    {
        arrayMovies = resizeArray (arrayMovies, pTam);
        index = buscarLibre(arrayMovies, pTam);
    }
    nuevaMovie = new_movie();
    *(arrayMovies+index) = *nuevaMovie;
    printf("Pelicula cargada con exito.\n\n");
}

void borrarPelicula(eMovie* arrayMovies, int* pTam)
{
    char auxTitulo[20];
    int i;

    printf("--- BORRAR PELICULA ---");
    mostrarPeliculas(arrayMovies, pTam);
    printf("Ingrese el titulo de la pelicula a borrar: ");
    fflush(stdin);
    gets(auxTitulo);

    for (i=0 ; i<*pTam ; i++)
    {
        if (strcmp(auxTitulo, (arrayMovies+i)->titulo) == 0)
        {
            (arrayMovies+i)->estado = 0;
            printf("Pelicula borrada.\n\n");
        }
    }
}

void modificarPelicula(eMovie* arrayMovies, int* pTam)
{
    printf("--- MODIFICAR PELICULA ---\n\n");
    mostrarPeliculas(arrayMovies, pTam);
    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    int opcion;

    for (i=0 ; i<*pTam ; i++)
    {
        if (strcmp(auxTitulo, (arrayMovies+i)->titulo) == 0)
        {
            printf("Seleccione campo a modificar:\n");
            printf("1. Titulo\n");
            printf("2. Genero\n");
            printf("3. Duracion\n");
            printf("4. Descripcion\n");
            printf("5. Puntaje\n");
            printf("6. Link de Imagen\n\n");
            scanf("%d", opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese nuevo titulo: ");
                gets((arrayMovies+i)->titulo);
            }
        }
    }
}

