/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2021
 *      Author: F2019
 *
 *      Franco Sultana Div "B"
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>

/**
 * @fn float Sumar(float, float)
 * @brief Realiza la suma de los dos números (A+B)
 *
 * @param numeroA
 * @param numeroB
 * @return Resultado de la suma
 */
float Sumar(float, float);

/**
 * @fn float Restar(float, float)
 * @brief Realiza la resta de los dos números (A-B)
 *
 * @param numeroA
 * @param numeroB
 * @return Resultado de la resta
 */
float Restar(float, float);

/**
 * @fn float Dividir(float, float)
 * @brief Realiza la división de los dos números (A/B)
 *
 * @param numeroA
 * @param numeroB
 * @return Resultado de la división
 */
float Dividir(float, float);

/**
 * @fn float Multiplicar(float, float)
 * @brief Realiza la multiplicación de los números (A*B)
 *
 * @param numeroA
 * @param numeroB
 * @return Resultado de la multiplicación
 */
float Multiplicar(float, float);

/**
 * @fn float FactorialA(float)
 * @brief Realiza la factorización del número A (A!)
 *
 * @param numeroA
 * @return Resultado de la factorización
 */
float FactorialA(float);

/**
 * @fn float FactorialB(float)
 * @brief Realiza la factorizacion del numero B (B!)
 *
 * @param numeroB
 * @return Resultado de la factorización
 */
float FactorialB(float);

/**
 * @fn int ComprobarDecimalEnteroA(float)
 * @brief Comprueba si el numero A (primer numero) es decimal o entero, para mostrar en el factorial de A
 *
 * @param numeroA
 * @return 1 si es decimal 	/	0 si es entero
 */
int ComprobarDecimalEnteroA(float);

/**
 * @fn int ComprobarDecimalEnteroB(float)
 * @brief Comprueba si el numero B (segundo numero) es decimal o entero, para mostrar en el factorial de B
 *
 * @param numeroB
 * @return 1 si es decimal	/	0 si es entero
 */
int ComprobarDecimalEnteroB(float);


#endif /* BIBLIOTECA_H_ */
