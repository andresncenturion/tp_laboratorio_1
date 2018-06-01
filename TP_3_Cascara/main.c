#include <stdio.h>
#include <stdlib.h>

#define PATH "archivo.dat"
#define TAM 5

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkDeImagen[50];
    int estado;
}eMovie;

void generarArchivo (FILE*);
void inicializarArray(eMovie*, int);
eMovie* newArray (int);
int menu (void);
void agregarPelicula(eMovie*, eMovie*, int);
int buscarLibre (eMovie*, int);
void guardarPeliculas(eMovie*, int, char*);

int main()
{
    char seguir = 's';

    while (seguir != 'n')
    {
        eMovie* pelicula;
        eMovie* cartelera;

        cartelera = newArray(TAM);

        if (cartelera == NULL)
        {
            printf ("No se pudo reservar memoria.\n\n");
            exit(1);
        }

        system("cls");
        switch (menu())
        {
        case 1:
            agregarPelicula(pelicula, cartelera, TAM);
            guardarPeliculas(cartelera, TAM, PATH);
            system("pause");
            break;
        /*case 2:
            borrarPelicula();
            break;
        case 3:
            modificarPelicula();
            break;
        case 4:
            paginaWeb();
            break;*/
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida. Intente nuevamente.\n\n");
            system("pause");
            break;
        }
    }
    return 0;
}

void generarArchivo (FILE* pArch)
{
    pArch = fopen(PATH, "rb");
    if (pArch == NULL)
    {
        pArch = fopen(PATH, "wb");
        if (pArch == NULL)
        {
            printf ("No se puede abrir el archivo.\n\n");
            exit(1);
        }
        printf("El archivo se abrio exitosamente.\n\n");
        fclose(pArch);
    }
}

void inicializarArray(eMovie* cartelera, int tam)
{
    int i;

    if ((cartelera != NULL)&&(tam>0))
    {
        for (i=0 ; i<tam ; i++)
        {
            (cartelera+i)->estado = 0;
        }
    }
}

eMovie* newArray (int tam)
{
    eMovie* cartelera;

    if (tam>0)
    {
        cartelera = (eMovie*) malloc(tam*sizeof(eMovie));
        if (cartelera != NULL)
        {
            inicializarArray(cartelera, tam);
        }
        else
        {
            printf("No se puede crear una nueva cartelera\n\n");
        }
    }
    else
    {
        printf("ERROR. Tamanio de cartelera invalido.\n\n");
    }
    return cartelera;
}

int menu (void)
{
    int opcion;

    system ("cls");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

int buscarLibre (eMovie* cartelera, int tam)
{
    int index = -1;
    int i;

    for (i=0 ; i<TAM ; i++)
    {
        if((cartelera+i)->estado == 0)
        {
            index = i;
        }
    }
    return index;
}

void agregarPelicula(eMovie* pelicula, eMovie* cartelera, int tam)
{
    int index;

    pelicula = (eMovie*) malloc(sizeof(eMovie));
    if (pelicula != NULL)
    {
        printf("--- AGREGAR PELICULA ---\n\n");
        printf("Titulo: ");
        fflush(stdin);
        scanf("%s", pelicula->titulo);
        printf("Genero: ");
        fflush(stdin);
        scanf("%s", pelicula->genero);
        printf("Duracion: ");
        scanf("%d", pelicula->duracion);
        printf("Descripcion: ");
        fflush(stdin);
        scanf("%s", pelicula->descripcion);
        printf("Puntaje: ");
        scanf("%d", pelicula->puntaje);
        printf("Link de imagen: ");
        fflush(stdin);
        scanf("%s", pelicula->linkDeImagen);
        pelicula->estado = 1;

        index = buscarLibre (cartelera, TAM);
        if (index != -1)
        {
            *(cartelera+index) = *pelicula;
        }
    }
}

void guardarPeliculas(eMovie* cartelera, int tam, char* path)
{
    FILE* arch;
    int i;

    arch = fopen (path, "wb");

    if (arch != NULL)
    {
        for (i=0 ; i<tam ; i++)
        {
            if ((cartelera+i)->estado == 1)
            {
                fwrite((cartelera+i), sizeof(eMovie), 1, arch);
            }
        }
        fclose(arch);
        printf("\nEmpleados guardados con exito\n\n");
    }
}
