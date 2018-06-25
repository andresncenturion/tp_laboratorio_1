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
    int cant = *pTam;
    FILE* f;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        f = fopen(path, "wb");
    }
    else
    {
        while (!feof(f))
        {
            cant = fread(arrayMovies, sizeof(eMovie), *pTam, f);
        }
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

void generarPaginaWeb(eMovie* arrayMovies, int* pTam)
{
    FILE* f;
    int i;

    f = fopen("C:/Users/andre/Documents/GitHub/tp_laboratorio_1/TP_3_Cascara/template/index.html", "wb");
    if(f == NULL)
    {
        printf("El archivo no pudo ser creado.");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
        for(i=0; i<*pTam; i++)
        {
            if((arrayMovies+i)->estado == 1)
            {
                fprintf(f,"<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt='%s'></a><h3><a href='#'>", (arrayMovies+i)->linkDeImagen, (arrayMovies+i)->titulo);
                fprintf(f,"<h3 style='color:#2196f3'>%s</h3>\n",(arrayMovies+i)->titulo);
                fprintf(f,"<ul><li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d minutos</li></ul>\n",(arrayMovies+i)->genero,(arrayMovies+i)->puntaje,(arrayMovies+i)->duracion);
                fprintf(f,"<p>%s</p></article>",(arrayMovies+i)->descripcion);
            }
        }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    printf("Archivo generado.\n\n");
    system("Pause");
    fclose(f);
}
