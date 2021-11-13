#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @brief Constructor por defecto de empleado
 * @return direccion de memoria del nuevo empleado
 */
Employee* employee_new();

/**
 * @brief constructor parametrizado de empleado
 * @param idStr id del empleado
 * @param nombreStr nombre del empleado
 * @param horasTrabajadasStr horas trabajadas del empleado
 * @param sueldoStr sueldo del empleado
 * @return direccion de memoria del nuevo empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @brief Muestra al usuario el menu de opciones
 * @param opcion direccion de memoria a la que apunta la opcion elegida por el usuario
 */
void employee_menu(int* opcion);

/**
 * @brief Cabecera de los datos de empleado al mostrarse
 */
void employee_titulo();

/**
 * @brief Muestra un empleado
 * @param empleado direccion de memoria a la que apunta el empleado a mostrarse
 */
void employee_mostrarUno(Employee* empleado);

/**
 * @brief Funcion que junta todos los getters
 * @param empleado  direccion de memoria a la que apunta el empleado a mostrarse
 * @param id direccion de memoria a donde va a apuntar el id del empleado
 * @param nombre direccion de memoria a donde va a apuntar el nombre del empleado
 * @param horas direccion de memoria a donde va a apuntar las horas  del empleado
 * @param sueldo direccion de memoria a donde va a apuntar el sueldo del empleado
 * @return
 */
int employee_obtenerDatos(Employee* empleado, int* id, char* nombre, int* horas, int* sueldo);

/**
 * @brief elimina un empleado de memoria
 * @param empleado  direccion de memoria a donde va a apuntar el empleado que se va a eliminar
 */
void employee_delete(Employee* empleado);

/**
 * @brief carga los datos de empleado
 * @return direccion de memoria del empleado con todos los datos cargados
 */
Employee* employee_cargarDatos(char* nombre, char* sueldo, char* horas, int tamNombre, int tamHoras, int tamSueldo);

/**
 * @brief modifica los datos de los empleados
 * @return direccion de memoria del empleado con los datos modificados
 */
Employee* employee_modificarDatos();

/**
 * @brief busca por id
 * @param auxEmpleado direccion de memoria a la que apunta el empleado a buscar
 * @param idBuscar id que debe ser igual al de alguno de los empleados
 * @return 0 si no encontro el id || 1 si encontro
 */
int employee_buscarPorID(Employee* auxEmpleado, int idBuscar);

/**
 * @brief setter de id
 * @param this direccion de memoria a la que apunta el empleado a settear
 * @param id id que va a setearse en el empleado
 * @return 0 si no pudo settear || 1 si pudo
 */
int employee_setId(Employee* this,int id);

/**
 * @brief getter de id
 * @param this direccion de memoria a la que apunta el empleado a obtener el id
 * @param id puntero a direccion de memoria donde apunta el id que va a obtener el dato
 * @return 0 si no pudo obtener || 1 si pudo
 */
int employee_getId(Employee* this,int* id);

/**
 * @brief setter de nombre
 * @param this direccion de memoria a la que apunta el empleado a settear
 * @param nombre nombre que va a setearse en el empleado
 * @return 0 si no pudo settear || 1 si pudo
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @brief getter de nombre
 * @param this direccion de memoria a la que apunta el empleado a obtener el nombre
 * @param nombre puntero a direccion de memoria donde apunta el nombre que va a obtener el dato
 * @return 0 si no pudo obtener || 1 si pudo
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @brief setter de HorasTrabajadas
 * @param this direccion de memoria a la que apunta el empleado a settear
 * @param HorasTrabajadas HorasTrabajadas que va a setearse en el empleado
 * @return 0 si no pudo settear || 1 si pudo
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @brief getter de horas trabajadas
 * @param this direccion de memoria a la que apunta el empleado a obtener las horas
 * @param horasTrabajadas puntero a direccion de memoria donde apunta las horasTrabajadas que va a obtener el dato
 * @return 0 si no pudo obtener || 1 si pudo
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief setter de suedlo
 * @param this direccion de memoria a la que apunta el empleado a settear
 * @param sueldo sueldo que va a setearse en el empleado
 * @return 0 si no pudo settear || 1 si pudo
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @brief getter de sueldo
 * @param this direccion de memoria a la que apunta el empleado a obtener las sueldo
 * @param sueldo puntero a direccion de memoria donde apunta el sueldo que va a obtener el dato
 * @return 0 si no pudo obtener || 1 si pudo
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @brief compara por nombre, de menor a mayor o viceversa
 * @param valor1 primer valor
 * @param valor2 segundo valor
 * @return 0 si los nombres son iguales || 1 si el nombre de valor 1 es mayor al segundo ||
 *  		-1 si el nombre de valor 2 es mayor al primero
 */
int employee_compararNombre(void* valor1, void* valor2);

/**
 * @brief compara por sueldo, de menor a mayor o viceversa
 * @param valor1 primer valor
 * @param valor2 segundo valor
 * @return 0 si los sueldo son iguales || 1 si el sueldo de valor 1 es mayor al segundo ||
 *  		-1 si el nombre de valor 2 es mayor al primero
 */
int employee_compararSueldo(void* valor1, void* valor2);


/**
 * @brief compara por id, de menor a mayor o viceversa
 * @param valor1 primer valor
 * @param valor2 segundo valor
 * @return 0 si los nombres son iguales || 1 si el id de valor 1 es mayor al segundo ||
 *  		-1 si el id de valor 2 es mayor al primero
 */
int employee_compararId(void* valor1, void* valor2);

/**
 * @brief compara por horas, de menor a mayor o viceversa
 * @param valor1 primer valor
 * @param valor2 segundo valor
 * @return 0 si las horas son iguales || 1 si las horas de valor 1 es mayor al segundo ||
 *  		-1 si las horas de valor 2 es mayor al primero
 */
int employee_compararHoras(void* valor1, void* valor2);
#endif // employee_H_INCLUDED
