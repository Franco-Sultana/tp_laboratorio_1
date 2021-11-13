/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: F2019
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile puntero a direccion de memoria donde apunta el archivo
 * \param pArrayListEmployee LinkedList* puntero a deireccion de memoria donde apunta la linkedList
 * \return int 0 si alguno de los parametros vino en NULL || -1 si el empleado vino en NULL || 1 si pudo parsear
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param FILE* pFile puntero a direccion de memoria donde apunta el archivo
 * \param pArrayListEmployee LinkedList* puntero a deireccion de memoria donde apunta la linkedList
 * \return int 0 si alguno de los parametros vino en NULL || -1 si el empleado vino en NULL || 1 si pudo parsear
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
