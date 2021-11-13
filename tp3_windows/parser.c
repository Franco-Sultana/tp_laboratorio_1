#include "parser.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmpleado;
	char id[30];
	char nombre[30];
	char horas[30];
	char sueldo[30];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);
			auxEmpleado = employee_newParametros(id, nombre, horas, sueldo);
			if(auxEmpleado != NULL)
			{
				retorno = 1;
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}
	}
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmpleado;
	int id;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		while(!feof(pFile))
		{
			auxEmpleado = employee_new();
			fread(auxEmpleado, sizeof(Employee), 1, pFile);
			employee_getId(auxEmpleado, &id);
			if(auxEmpleado != NULL && id != 0)
			{
				retorno = 1;
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}
	}


    return retorno;
}
