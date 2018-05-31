#include <stdio.h>
#include <stdlib.h>
//#include "funciones.h"

#define MAX_MOVIES 5

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}EMovie;

int menu (void);
FILE* abrirArchivo (void);
void inicializarCartelera (EMovie*, int);
void agregarPelicula(EMovie*, EMovie*, int);

int main()
{
    char seguir='s';

    while(seguir=='s')
    {
        EMovie* movie;
        EMovie* cartelera;
        FILE* pArch;

        pArch = abrirArchivo();
        inicializarCartelera(cartelera, MAX_MOVIES);

        switch(menu())
        {
            case 1:
                agregarPelicula(movie, cartelera, MAX_MOVIES);
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

int menu (void)
{
    int opcion;

    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Generar pagina web\n");
    printf("4- Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

FILE* abrirArchivo (void)
{
    FILE* pArch;

    if (pArch = (fopen("archivo", "rb") == NULL))
    {
        if (pArch = ((fopen("archivo", "wb") == NULL)))
        {
            printf("ERROR. No se pudo abrir el archivo.\n\n");
            exit(1);
        }
        fclose(pArch);
    }
    return pArch;
}

void inicializarCartelera (EMovie* cartelera, int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        (cartelera+i)->estado = 0;
    }
}

void agregarPelicula(EMovie* movie, EMovie* cartelera, int tam)
{
    int i;

    printf("Titulo: ");
    scanf("%s", movie->titulo);
    printf("Genero: ");
    scanf("%s", movie->genero);
    printf("Duracion: ");
    scanf("%d", &movie->duracion);
    printf("Descripcion: ");
    scanf("%s", movie->descripcion);
    printf("Puntaje: ");
    scanf("%d", &movie->puntaje);
    printf("Link Imagen: ");
    scanf("%s", movie->linkImagen);
    movie->estado = 1;

    for (i=0 ; i<tam ; i++)
    {
        if ((cartelera+i)->estado == 0)
        {
            *(cartelera+i) = *movie;
        }
    }
}
