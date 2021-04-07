/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2021
 *      Author: F2019
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>

/**
 * @fn int Sumar(int, int)
 * @brief Realiza la suma de los dos números (A+B)
 *
 * @param Numero A
 * @param Numero B
 * @return Resultado de la suma
 */
int Sumar(int, int);

/**
 * @fn int Restar(int, int)
 * @brief Realiza la resta de los dos números (A-B)
 *
 * @param Numero A
 * @param Numero B
 * @return Resultado de la resta
 */
int Restar(int, int);

/**
 * @fn float Dividir(int, int)
 * @brief Realiza la división de los dos números (A/B)
 *
 * @param Numero A
 * @param Numero B
 * @return Resultado de la división
 */
float Dividir(int, int);

/**
 * @fn int Multiplicar(int, int)
 * @brief Realiza la multiplicación de los números (A*B)
 *
 * @param Numero A
 * @param Numero B
 * @return Resultado de la multiplicación
 */
int Multiplicar(int, int);

/**
 * @fn int FactorialA(int)
 * @brief Realiza la factorización del número A (A!)
 *
 * @param Numero A
 * @return Resultado de la factorización
 */
int FactorialA(int);

/**
 * @fn int FactorialB(int)
 * @brief Realiza la factorizacion del numero B (B!)
 *
 * @param Numero B
 * @return Resultado de la factorización
 */
int FactorialB(int);


#endif /* BIBLIOTECA_H_ */
