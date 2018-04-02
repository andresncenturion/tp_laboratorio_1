#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int num1 = 0;
    int num2 = 0;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    //float factorial;

    int pedirEntero(void);
    int sumarEnteros(int,int);
    int restarEnteros(int,int);
    int multiplicarEnteros(int,int);
    float dividirEnteros(int,int);
    //float factorialEntero(int);

    while(seguir == 's')
    {
        printf("1- Ingresar 1er operando (A = %d)\n", num1);
        printf("2- Ingresar 2do operando (B = %d)\n", num2);
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
                break;
            case 2:
                num2 = pedirEntero();
                break;
            case 3:
                suma = sumarEnteros(num1,num2);
                printf("La suma es: %d", suma);
                break;
            case 4:
                resta = restarEnteros(num1,num2);
                printf("La resta es: %d", resta);
                break;
            case 5:
                if (num2 != 0)
                {
                    division = dividirEnteros(num1,num2);
                    printf("La division es: %.2f", division);
                }
                else
                {
                    printf("No es posible dividir por 0");
                }
                break;
            case 6:
                multiplicacion = multiplicarEnteros(num1,num2);
                printf("La multiplicacion es: %d", multiplicacion);
                break;
            /*case 7:
                factorial = factorialEntero(num1);
                printf("El factorial es: %f", factorial);
                break;*/
            case 8:
                suma = sumarEnteros(num1,num2);
                printf("La suma es: %d", suma);
                resta = restarEnteros(num1,num2);
                printf("La resta es: %d", resta);
                if (num2 != 0)
                {
                    division = dividirEnteros(num1,num2);
                    printf("La division es: %f", division);
                }
                else
                {
                    printf("No es posible dividir por 0");
                }
                multiplicacion = multiplicarEnteros(num1,num2);
                printf("La multiplicacion es: %d", multiplicacion);
                /*factorial = factorialEntero(num1);
                printf("El factorial es: %f", factorial);*/
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
