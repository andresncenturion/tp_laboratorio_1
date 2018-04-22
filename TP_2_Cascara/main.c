#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * param lista: el array se pasa como parametro.
 */
int ObtenerEspacioLibre(EPersona lista[]);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * param lista: el array se pasa como parametro. dni: el dni a ser buscado en el array.
 */
int BuscarPorDni(EPersona lista[], int dni);

int main()
{
    char seguir='s';
    int opcion=0;

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
                break;
            case 2:
                break;
            case 3:
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
