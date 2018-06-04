#include <stdio.h>
#include <stdlib.h>
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
    printf("%d.  %s  %s  %d  %s  %d  %s", movie->idMovie, movie->titulo, movie->genero, movie->duracion, movie->descripcion, movie->puntaje, movie->linkDeImagen);
    printf("\n");
}

void mostrarPeliculas (eMovie* arrayMovies, int tam)
{
    int i;

    if (arrayMovies != NULL && tam>0)
    {
        for (i=0; i<tam ; i++)
        {
            if ((arrayMovies+i)->estado == 1)
            {
                mostrarPelicula(arrayMovies+i);
            }
        }
    }
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

void guardarMovies (eMovie* arrayMovies, int tam, char* path)
{
    FILE* f;
    int i;

    f = fopen(path, "wb");
    if (f != NULL)
    {
        for (i=0 ; i<tam ; i++)
        {
            if ((arrayMovies+i)->estado == 1)
            {
                fwrite((arrayMovies+i), sizeof(eMovie), 1, f);
            }
        }
    }
    fclose(f);
    printf("\nPelicula guardada con exito\n\n");
}

void agregarPelicula(eMovie* arrayMovies, int tam)
{
    eMovie* nuevaMovie;
    int index;

    nuevaMovie = new_movie();
    index = buscarLibre(arrayMovies, tam);
    if (index != -1)
    {
        *(arrayMovies+index) = *nuevaMovie;
        (arrayMovies+index)->idMovie = index+1;
    }
    else
    {
        printf("No se pueden agregar mas peliculas.\n\n");
    }
    guardarMovies(arrayMovies, tam, PATH);
}

void leerMovies(eMovie* arrayMovies, int tam, char* path)
{
    FILE* f;
    int cant;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    while (!feof(f))
    {
        cant = fread(arrayMovies, sizeof(eMovie), tam, f);
        if (cant != tam)
        {
            if (feof(f))
            {
                break;
            }
            else
            {
                printf("Error. No leyo el ultimo registro.\n\n");
                break;
            }
        }
    }
    fclose(f);
}

void borrarPelicula(eMovie* arrayMovies, int tam, char* path)
{
    int id;

    leerMovies(arrayMovies, tam, path);
    mostrarPeliculas(arrayMovies, tam);
    printf("Seleccione pelicula a borrar: ");
    scanf("%d", &id);

    (arrayMovies+(id-1))->estado = 0;
    printf("Pelicula borrada con exito.\n\n");
}

