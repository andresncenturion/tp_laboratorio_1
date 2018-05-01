#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTA 50

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
}EPersona;

void inicializarEmpleados (EPersona[], int);
void agregarPersona (EPersona[], int);
int buscarLibre(EPersona[], int);
//void borrarPersona (EPersona lista[], int tam);
void ordenarPorNombre(EPersona[], int);
void mostrarPersonas(EPersona[], int);

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona lista[MAX_LISTA];

    inicializarEmpleados (lista, MAX_LISTA);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista, MAX_LISTA);
                break;
            case 2:
                /*borrarPersona(lista[], MAX_LISTA);
                break;*/
            case 3:
                ordenarPorNombre(lista, MAX_LISTA);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void inicializarEmpleados (EPersona lista[], int tam)
{
    int i;

    for (i=0 ; i<tam ; i++)
    {
        lista[i].estado = 0;
    }
}

void agregarPersona (EPersona lista[], int tam)
{
    int index;
    EPersona nuevaPersona;

    system("cls");
    index = buscarLibre(lista, MAX_LISTA);
    if (index == -1)
    {
        printf("No se pueden ingresar mas personas.\n\n");
        system("pause");
    }
    else
    {
        nuevaPersona.estado = 1;

        printf("NOMBRE: ");
        fflush(stdin);
        gets(nuevaPersona.nombre);
        printf("EDAD: ");
        scanf("%d", &nuevaPersona.edad);
        lista[index] = nuevaPersona;

        printf("\nSe ha agregado exitosamente.");
    }
    printf("\n\n");
}

int buscarLibre(EPersona lista[], int tam)
{
    int i;
    int index = -1;

    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

/*void borrarPersona (EPersona lista[], int tam)
{

}*/

void ordenarPorNombre(EPersona lista[], int tam)
{
    int i;
    int j;
    EPersona auxPersona;

    for (i=0 ; i<tam-1 ; i++)
    {
        for (j=i+1 ; i<tam ; i++)
        {
            if (strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                    auxPersona = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxPersona;
            }
        }
    }
    mostrarPersonas(lista, tam);
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;

    system("cls");
    printf("NOMBRE \tEDAD\n\n");
    for (i=0 ; i<tam ; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("%s \t%d", lista[i].nombre, lista[i].edad);
        }
    }
}
