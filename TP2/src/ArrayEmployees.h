#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

#ifndef EEmployee_H_
#define EEmployee_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define FREE 0
#define OCCUPED 1
#define REMUVED -1

//*** ESTRUCTURA
typedef struct {
	int idEmployee;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} eEmployee;
//***

/** INICIO CABECERAS DE FUNCION*/
/**
 * @fn void initEmployees(eEmployee[], int)
 * @brief inicializa el campo is empty en 0 (VACIO)
 *
 * @param list list de Employee a inicializar
 * @param len lenaño del list
 */
void initEmployees(eEmployee list[], int len);

/**
 * @fn int eEmployee_ObtenerID(void)
 * @brief Obtiene el id automaticamente
 *
 * @return id
 */
int eEmployee_ObtenerID(void);

/**
 * @fn int EmployeeGetFreeIndex(eEmployee[], int)
 * @brief Busca espacio FREE, y si lo encuentra devuelve el index
 *
 * @param list array de Employee
 * @param len tamaño del array
 * @return index de la posicion del list que está disponible
 */
int EmployeeGetFreeIndex(eEmployee list[], int len);

/**
 * @fn int findEmployeeById(eEmployee[], int, int)
 * @brief Busca con el id dentro del list. Si lo encuentra, devuelve la posicion donde está
 *
 * @param list array de Employee
 * @param len tamaño del array
 * @param ID id que el usuario ingresó
 * @return retorna i (la posicion en la que está ese list)
 */
int findEmployeeById(eEmployee list[], int len, int ID);

/**
 * @fn void showAnEmployee(eEmployee)
 * @brief Muestra 1 Employee, con todos sus datos
 *
 * @param Employee El empleado de tipo eEmployee
 */
void showAnEmployee(eEmployee Employee);

/**
 * @fn int eEmployee_MostrarTodos(eEmployee[], int)
 * @brief muestra una lista de todos los Employee
 *
 * @param list	 array de Employee
 * @param len tamaño del array
 * @return 1 si pudo mostrar al menos 1 Employee, 0 si no
 */
int printEmployees(eEmployee list[], int len);

/**
 * @fn int sortEmployees(eEmployee[], int, int)
 * @brief
 *
 * @param list array de Employee
 * @param len tamaño del array
 * @param order permite al usuario mostrar la lista en distinto orden
 * @return 1 si pudo mostrar la lista, 0 si no
 */
int sortEmployees(eEmployee list[], int len, int order);


/**
 * @fn eEmployee modifyAnEmployee(eEmployee)
 * @brief Pide el ingreso de un id al usuario para modificar datos
 *
 * @param Employee auxiliar de tipo eEmployee con cada dato modificado
 * @return retorna el Employee si la modificacion es correcta, y -1 si no
 */
eEmployee modifyAnEmployee(eEmployee Employee);
/**
 * @fn int removeEmployee(eEmployee[], int, int)
 * @brief Pide un id al usuario para darlo de baja
 *
 * @param list array de Employee
 * @param len tamaño de array
 * @param id se le pide al usuario para buscar ese id
 * @return 0 si no se cargó ningún dato / 1 si pudo dar de baja / -1 si el usuario cancela la baja
 */

int removeEmployee(eEmployee list[], int len, int id);

/**
 * @fn int eEmployee_Modificacion(eEmployee[], int)
 * @brief Pide un id al usuario para modificar algun campo del list Employee
 *
 * @param list list de Employee
 * @param len lenaño de Employee
 * @return 0 si no se cargó ningún dato, 1 si pudo modificar y -1 si el usuario cancela la modificacion
 */
int modifyEmployees(eEmployee list[], int len);

/**
 * @fn float CalculateTotalAndAverageSalary(eEmployee[], int, float*)
 * @brief calcula el promedio de los sueldos
 *
 * @param listEmployee array de employee
 * @param len tamaño de employee
 * @param acumulator puntero a direccion de memoria donde se va a copiar el acumulaoor, que cuenta el total de salary
 * @return el promedio si pudo calcularlo, -1 si no
 */
float CalculateTotalAndAverageSalary(eEmployee listEmployee[], int len, float* acumulator);

/**
 * @fn int CalculateSalaryOverAverage(eEmployee[], int)
 * @brief Cuenta los trabajadores que sobrepasan el sueldo promedio
 *
 * @param listEmployee array de employee
 * @param len tamaño de array
 * @return el contador de trabadores por encima del salario si pudo calcularlo. -1 si no.
 */
int CalculateSalaryOverAverage(eEmployee listEmployee[], int len);



/**
 * @fn int addEmployee(eEmployee[], int, int*, char[], char[], float, int)
 * @brief Da de alta un trabajador
 *
 * @param list array de employeee
 * @param len tamaño del array
 * @param id puntero a direccion de memoria donde se va a copiar el id incremental
 * @param name nombre del trabajador
 * @param lastName apellido del trabajador
 * @param salary salario
 * @param sector sector donde trabaja
 * @return 0 si no hay espacio en el array / 1 si pudo cargar los datos / -1 si el usuario cancela la modificacion
 */
int addEmployees(eEmployee list[], int len, int* id, char name[], char lastName[], float salary, int sector);

#endif
