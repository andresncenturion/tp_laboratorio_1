#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide al usuario que ingrese un valor entero
 *
 * \param No recibe ningun parametro
 * \return Retorna el valor entero ingresado por el usuario
 *
 */
int pedirEntero(void);

/** \brief Suma dos valores enteros
 *
 * \param Recibe un valor entero correspondiente al primer operando
 * \param Recibe un valor entero correspondiente al segundo operando
 * \return Retorna el resultado de la suma entre los valores recibidos
 *
 */
int sumarEnteros(int num1,int num2);

/** \brief Resta dos valores enteros
 *
 * \param Recibe un valor entero correspondiente al primer operando
 * \param Recibe un valor entero correspondiente al segundo operando
 * \return Retorna el resultado de la resta entre los valores recibidos
 *
 */
int restarEnteros(int num1,int num2);

/** \brief Realiza una division entre dos valores enteros.
 *
 * \param Recibe un valor entero correspondiente al divisor
 * \param Recibe un valor entero correspondiente al dividendo (debe ser distinto de 0).
 * \return Retorna un valor del tipo float correspondiente al resultado de la division.
 *
 */
float dividirEnteros(int num1, int num2);

/** \brief Realiza una multiplicacion entre dos valores enteros.
 *
 * \param Recibe un valor entero correspondiente al primer operando.
 * \param Recibe un valor entero correspondiente al segundo operando.
 * \return Retorna un valor entero correspondiente al resultado de la multiplicacion
 *
 */
int multiplicarEnteros(int num1,int num2);

/** \brief Calcula el factorial de un valor entero
 *
 * \param Recibe un valor entero
 * \return Retorna el resultado del calculo factorial del valor recibido.
 *
 */
int factorialEntero(int num1);




#endif // FUNCIONES_H_INCLUDED
