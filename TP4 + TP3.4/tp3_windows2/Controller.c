
#include "controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		retorno = 1;
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
		{
			ll_sort(pArrayListEmployee, employee_compararId, 1);
			fclose(pFile);
		}
	}

    return retorno;
}



int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFileBin;
	pFileBin = fopen(path, "rb");

	if(pFileBin != NULL)
	{
		retorno = 1;
		if(parser_EmployeeFromBinary(pFileBin, pArrayListEmployee) == 1)
		{
			fclose(pFileBin);
		}
	}


	return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmpleado;
	FILE* pFileId;
	int id;
	char idStr[30];
	char nombre[30];
	char horasTrabajadas[30];
	char sueldo[30];

	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		auxEmpleado = employee_cargarDatos(nombre, horasTrabajadas, sueldo, sizeof(nombre), sizeof(horasTrabajadas), sizeof(sueldo));
		if(utn_getRespuestaSiNo("Desea dar de alta el empleado?") == 1)
		{

			pFileId = fopen("id.csv" ,"r");
			fscanf(pFileId, "%d", &id);
			fclose(pFileId);
			pFileId = fopen("id.csv" ,"w");
			fprintf(pFileId, "%d",id+1);
			fclose(pFileId);
			sprintf(idStr, "%d", id);
			retorno = 1;
			auxEmpleado = employee_newParametros(idStr, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, auxEmpleado);

		}
	}

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -2;
	Employee* empleado;
	Employee* empleadoModificado;
	int idIngresado;
	int id;
	int encontro = 0;
	int index;
	int len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		retorno = -1;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = 0;
			utn_getEntero(&idIngresado, "Ingrese id del empleado a modificar: ", "(!)Id invalido. ", 1, INT_MAX);
			for(int i = 0; i<len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(empleado, &id);
				if(employee_buscarPorID(empleado, idIngresado) == 1)
				{
					encontro = 1;
					break;
				}
			}
			if(encontro == 1)
			{
				retorno = 2;
				index = ll_indexOf(pArrayListEmployee, empleado);
				empleadoModificado = employee_modificarDatos(empleado);
				employee_titulo();
				employee_mostrarUno(empleadoModificado);
				if(utn_getRespuestaSiNo("Desea confirmar la modificacion?") == 1)
				{
					retorno = 1;
					ll_set(pArrayListEmployee, index, empleadoModificado);
					employee_delete(empleado);
				}
			}
		}
	}
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -2;
	Employee* empleado;
	int idIngresado;
	int id;
	int encontro = 0;
	int index;
	int len;

	if(pArrayListEmployee != NULL)
	{
		retorno = -1;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = 0;
			len = ll_len(pArrayListEmployee);
			utn_getEntero(&idIngresado, "Ingrese id del empleado a dar de baja: ", "(!)Id invalido. ", 1, INT_MAX);
			for(int i = 0; i<len; i++)
			{
				empleado = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(empleado, &id);
				if(employee_buscarPorID(empleado, idIngresado) == 1)
				{
					encontro = 1;
					break;
				}
			}
		}
		if(encontro == 1)
		{
			retorno = 2;
			index = ll_indexOf(pArrayListEmployee, empleado);
			if(utn_getRespuestaSiNo("Desea dar de baja el empleado?") == 1)
			{
				retorno = 1;
				ll_remove(pArrayListEmployee, index);
				employee_delete(empleado);
			}
		}
	}
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -2;
	int len;
	Employee* auxEmpleado;
	if(pArrayListEmployee != NULL)
	{
		retorno = -1;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = 0;


			len = ll_len(pArrayListEmployee);
			employee_titulo();
			for(int i=0; i<len; i++)
			{
				auxEmpleado = ll_get(pArrayListEmployee, i);
				if(auxEmpleado != NULL)
				{
					employee_mostrarUno(auxEmpleado);
					retorno = 1;
				}
			}
		}
	}


    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int opcionOrden;
	int orden;
	LinkedList* listaOrdenada = ll_newLinkedList();
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = 1;
			listaOrdenada = ll_clone(pArrayListEmployee);
			printf("\n---- MENU ORDENAR ----\n"
					" 1. Nombre\n"
					" 2. Id\n"
					" 3. Sueldo\n"
					" 4. Horas trabajadas\n"
					"----------------------\n");
			utn_getEntero(&opcion, "Ingrese una opcion: ", "(!)Opcion invalida. ", 1, 4);
			if(opcion != 1)
			{
				printf("\n------ ORDEN ------\n"
						" 1. Menor a mayor\n"
						" 2. Mayor a menor\n"
						"-------------------\n");
			}
			else
			{
				printf(" 1. A - Z\n 2. Z - A\n");
			}
			utn_getEntero(&opcionOrden, "Ingrese el orden: ", "(!)Opcion invalida. ", 1, 2);
			printf("\nEstamos ordenando los empleados, tenga paciencia...\n");
			switch(opcionOrden)
			{
			case 1:
				orden = 1;
			break;
			case 2:
				orden = 0;
			break;
			}
			switch(opcion)
			{
				case 1:
					ll_sort(listaOrdenada, employee_compararNombre, orden);
					break;
				case 2:
					ll_sort(listaOrdenada, employee_compararId, orden);
					break;
				case 3:
					ll_sort(listaOrdenada, employee_compararSueldo, orden);
					break;
				case 4:
					ll_sort(listaOrdenada, employee_compararHoras, orden);
				break;
			}
			controller_ListEmployee(listaOrdenada);
			ll_deleteLinkedList(listaOrdenada);
		}
	}


    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -2;
	FILE* pFile;
	int len = ll_len(pArrayListEmployee);
	Employee* auxEmpleado;
	int id;
	char nombre[30];
	int sueldo;
	int horas;

	char idStr[30];
	char sueldoStr[30];
	char horasStr[30];

	if(pArrayListEmployee != NULL && path != NULL)
	{
		retorno = 2;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = -1;
			if(utn_getRespuestaSiNo("Desea guardar los cambios?") == 1)
			{
				retorno = 0;
				pFile = fopen(path, "w");
				if(pFile != NULL)
				{
					fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
					for(int i = 0; i<len; i++)
					{
						retorno = 1;
						auxEmpleado = ll_get(pArrayListEmployee, i);
						employee_obtenerDatos(auxEmpleado, &id, nombre, &horas, &sueldo);

						sprintf(idStr, "%d", id);
						sprintf(sueldoStr, "%d", sueldo);
						sprintf(horasStr, "%d", sueldo);
						fprintf(pFile, "%s,%s,%s,%s\n",idStr, nombre, horasStr, sueldoStr);
					}
					pclose(pFile);
				}
			}
		}
	}
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -2;
	Employee* auxEmplelado;
	FILE* pFileBin;
	int len;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = -1;
		if(ll_isEmpty(pArrayListEmployee) != 1)
		{
			retorno = 0;
			len = ll_len(pArrayListEmployee);
			pFileBin = fopen(path, "wb");
			if(pFileBin != NULL)
			{
				retorno = 2;
				if(utn_getRespuestaSiNo("Desea guardar los cambios?"))
				{
					for(int i = 0; i<len; i++)
					{
						auxEmplelado = ll_get(pArrayListEmployee, i);
						fwrite(auxEmplelado, sizeof(Employee), 1, pFileBin);
						retorno = 1;

					}
				}
			fclose(pFileBin);
			}
		}
	}
    return retorno;
}
