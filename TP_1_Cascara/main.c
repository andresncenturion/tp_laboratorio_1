#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int num1;
    int num2;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int factorial;
    int flagCarga1 = 0;
    int flagCarga2 = 0;
    int pedirEntero(void);
    int sumarEnteros(int,int);
    int restarEnteros(int,int);
    int multiplicarEnteros(int,int);
    int factorialEntero(int);
    float dividirEnteros(int,int);

    while(seguir == 's')
    {
        if (flagCarga1 == 1)
        {
            printf("1- Ingresar 1er operando (A = %d)\n", num1);
        }
        else
        {
            printf("1- Ingresar 1er operando (A = x)\n");
        }
        if (flagCarga2 == 1)
        {
            printf("2- Ingresar 2do operando (B = %d)\n", num2);
        }
        else
        {
            printf("2- Ingresar 2do operando (B = y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                num1 = pedirEntero();
                flagCarga1 = 1;
                system("cls");
                break;
            case 2:
                num2 = pedirEntero();
                flagCarga2 = 1;
                system("cls");
                break;
            case 3:
                suma = sumarEnteros(num1,num2);
                system("cls");
                printf("La suma es: %d\n", suma);
                break;
            case 4:
                resta = restarEnteros(num1,num2);
                system("cls");
                printf("La resta es: %d\n", resta);
                break;
            case 5:
                if (num2 != 0)
                {
                    division = dividirEnteros(num1,num2);
                    system("cls");
                    printf("La division es: %.2f\n", division);
                }
                else
                {
                    printf("No es posible dividir por 0\n");
                }
                break;
            case 6:
                multiplicacion = multiplicarEnteros(num1,num2);
                system("cls");
                printf("La multiplicacion es: %d\n", multiplicacion);
                break;
            case 7:
                factorial = factorialEntero(num1);
                system("cls");
                printf("El factorial es: %d\n", factorial);
                break;
            case 8:
                suma = sumarEnteros(num1,num2);
                printf("La suma es: %d\n", suma);
                resta = restarEnteros(num1,num2);
                printf("La resta es: %d\n", resta);
                if (num2 != 0)
                {
                    division = dividirEnteros(num1,num2);
                    printf("La division es: %f\n", division);
                }
                else
                {
                    printf("No es posible dividir por 0");
                }
                multiplicacion = multiplicarEnteros(num1,num2);
                printf("La multiplicacion es: %d\n", multiplicacion);
                factorial = factorialEntero(num1);
                printf("El factorial es: %d\n", factorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
