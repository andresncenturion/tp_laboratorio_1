int pedirEntero(void)
{
    int num1;

    printf("Ingrese operando: ");
    scanf("%d", &num1);
    return num1;
}

int sumarEnteros(int num1,int num2)
{
    int resultado;

    resultado = num1 + num2;
    return resultado;
}

int restarEnteros(int num1,int num2)
{
    int resultado;

    resultado = num1 - num2;
    return resultado;
}

float dividirEnteros(int num1, int num2)
{
    float resultado;

    resultado = (float) num1 / num2;
    return resultado;
}

int multiplicarEnteros(int num1,int num2)
{
    int resultado;

    resultado = num1 * num2;
    return resultado;
}

/*float factorialEntero(int num1)
{
    float resultado;

    if (num1 == 1)
    {
        resultado = 1;
    }
    resultado= num1 * factorialEntero(num1-1);
    return resultado;
}*/
