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
    }
    fclose(f);
    *pTam = cant;
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
    printf("%s  %s  %d  %s  %d  %s\n", movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkDeImagen);
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

    f = fopen (path, "rb+");
    if (f == NULL)
    {
        f = fopen(path, "wb");
        if (f == NULL)
        {
            printf("Error al crear archivo.\n\n");
            exit(-1);
        }
    }
    fwrite(arrayMovies, sizeof(eMovie), *pTam, f);
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

    printf("--- BORRAR PELICULA ---\n\n");
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
    char auxTitulo[20];
    int i;
    int index = -1;
    char seguir = 's';
    int opcion;

    printf("--- MODIFICAR PELICULA ---\n\n");
    mostrarPeliculas(arrayMovies, pTam);
    printf("\nIngrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTitulo);
    int flag = 0;

    for (i=0 ; i<*pTam ; i++)
    {
        if (strcmp(auxTitulo, (arrayMovies+i)->titulo) == 0)
        {
            index = i;
            break;
        }
    }
    while (seguir == 's' && flag == 0)
    {
        if (index > -1)
        {
            flag = 1;
            printf("Seleccione campo a modificar:\n");
            printf("1. Titulo\n");
            printf("2. Genero\n");
            printf("3. Duracion\n");
            printf("4. Descripcion\n");
            printf("5. Puntaje\n");
            printf("6. Link de Imagen\n");
            printf("7. Cancelar\n\n");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese nuevo titulo: ");
                fflush(stdin);
                gets((arrayMovies+index)->titulo);
                break;
            case 2:
                printf("Ingrese nuevo genero: ");
                fflush(stdin);
                gets((arrayMovies+index)->genero);
                break;
            case 3:
                printf("Ingrese nueva duracion: ");
                scanf("%d", &((arrayMovies+index)->duracion));
                break;
            case 4:
                printf("Ingrese nueva descripcion: ");
                fflush(stdin);
                gets((arrayMovies+index)->descripcion);
                break;
            case 5:
                printf("Ingrese nuevo puntaje: ");
                scanf("%d", &((arrayMovies+index)->puntaje));
                break;
            case 6:
                printf("Ingrese nuevo link de imagen: ");
                fflush(stdin);
                gets((arrayMovies+index)->linkDeImagen);
                break;
            case 7:
                seguir = 'n';
                break;
            }
        }
        else
        {
            printf("No se han encontrado peliculas con ese nombre.\n\n");
            break;
        }
    }
}

