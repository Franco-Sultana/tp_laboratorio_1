#include "arrayEmployees.h"

void initEmployees(eEmployee list[], int len)
{
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = FREE;
		}
	}
}

int EmployeeGetFreeIndex(eEmployee list[], int len)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == FREE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int findEmployeeById(eEmployee list[], int len, int ID)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].idEmployee == ID && list[i].isEmpty == OCCUPED)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

void showAnEmployee(eEmployee Employee)
{

	printf("%d\t%s\t\t%s\t\t%.2f%15d\t\n", Employee.idEmployee, Employee.nombre,
							Employee.apellido, Employee.salario, Employee.sector);
}

int printEmployees(eEmployee list[], int len)
{
	int i;
	int rtn = 0;
	int quantity = 0;

	if (list != NULL && len > 0)
	{
		printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == OCCUPED)
			{
				showAnEmployee(list[i]);
				quantity++;
			}
		}
	}
	if (quantity > 0)
	{
		rtn = 1;
	}
	return rtn;
}

eEmployee loadEmployeeData(void)
{
	eEmployee auxiliary;
	utn_getNombre(auxiliary.nombre, "Ingrese el nombre: ", "Nombre inválido. ", sizeof(auxiliary.nombre));
	utn_getNombre(auxiliary.apellido, "Ingrese el apellido: ", "Apellido inválido. ", sizeof(auxiliary.apellido));
	utn_getFlotantePrositivo(&auxiliary.salario, "Ingrese el salario: ", "(!)Error. ");
	utn_getEnteroPrositivo(&auxiliary.sector, "Ingrese el sector: ", "(!)Error. ");

	return auxiliary;
}

eEmployee modifyAnEmployee(eEmployee Employee)
{
	eEmployee auxiliary = Employee;
	int option;
	do
	{
		printf("\n\tMENU DE MODIFICACION\n -0 SALIR\n -1. Nombre\n -2. Apellido\n -3. Salario\n -4. Sector\n");
		utn_getEnteroSinReintentos(&option, "Ingrese una opcion: ", "opcion inválida. ", 0, 4);

		switch(option)
		{
			case 0:
				printf("Saliendo de modificar\n");
			break;
			case 1:
				utn_getNombre(auxiliary.nombre, "Ingrese el nombre a modificar: ", "Nombre inválido. ", sizeof(auxiliary.nombre));
			break;
			case 2:
				utn_getNombre(auxiliary.apellido, "Ingrese el apellido a modificar: ", "Apellido inválido. ", sizeof(auxiliary.apellido));
			break;
			case 3:
				utn_getFlotantePrositivo(&auxiliary.salario, "Ingrese el salario a modificar: ", "(!)Error. ");
			break;
			case 4:
				utn_getEnteroPrositivo(&auxiliary.sector, "Ingrese el sector a modificars: ", "(!)Error. ");
			break;
		}
	}while(option);
	return auxiliary;
}

int addEmployee(eEmployee list[], int len, int* id)
{
	int rtn = 0;
	char reply;
	eEmployee auxEmployee;
	int i;
	i = EmployeeGetFreeIndex(list, len);

	if (i != -1)
	{
		auxEmployee = loadEmployeeData();
		//auxEmployee.idEmployee = eEmployee_ObtenerID();
		auxEmployee.idEmployee = *id;
		*id = *id + 1;

		if(utn_getRespuestaSiNo(&reply, "¿Está seguro de dar de alta?", sizeof(reply)) == 1)
		{
			list[i] = auxEmployee;
			list[i].isEmpty = OCCUPED;
			rtn = 1;
		}
		else
		{
			rtn = -1;
		}
	}
	return rtn;
}

int removeEmployee(eEmployee list[], int len)
{
	int rtn = 0;
	int idEmployee;
	int i;
	char reply;

	printEmployees(list, len);

	for(i=0; i<len; i++)
	{
		if (list[i].isEmpty == OCCUPED)
		{
			utn_getEnteroPrositivo(&idEmployee, "Ingrese el id a dar de baja: ", "Error, ingrese un id válido. ");

			while (findEmployeeById(list, len, idEmployee) == -1)
			{
				printf("Ese id no existe.");
				utn_getEnteroPrositivo(&idEmployee, "Ingrese el id a dar de baja: ", "Error, ingrese un id válido. ");
			}
			i = findEmployeeById(list, len, idEmployee);

			if(utn_getRespuestaSiNo(&reply, "¿Está seguro de dar de baja?", sizeof(reply)) == 1)
			{
				list[i].isEmpty = REMUVED;
				rtn = 1;
				break;
			}
			else
			{
				rtn = -1;
			}
		}
	}
	return rtn;
}

int modifyEmployees(eEmployee list[], int len)
{
	int rtn = 0;
	int idEmployee;
	char reply;
	eEmployee auxiliary;
	int i;

	printEmployees(list, len);

	for(i=0; i<len; i++)
	{
		if (list[i].isEmpty == OCCUPED)
		{
			utn_getEnteroPrositivo(&idEmployee, "Ingrese el id para modificar: ", "Id inválido. ");
			while (findEmployeeById(list, len, idEmployee) == -1)
			{
				printf("Ese id no existe.");
				utn_getEnteroPrositivo(&idEmployee, "Ingrese el id para modificar: ", "Id inválido. ");
			}
			i = findEmployeeById(list, len, idEmployee);

			auxiliary = modifyAnEmployee(list[i]);

			if(utn_getRespuestaSiNo(&reply, "¿Está seguro?", sizeof(reply)) == 1)
			{
				list[i] = auxiliary;
				rtn = 1;
				break;
			}
			else
			{
				rtn = -1;
			}
		}
	}
	return rtn;
}

int sortEmployees(eEmployee list[], int len, int order)
{
	int rtn = 0;
	int i;
	int j;
	eEmployee aux;

	if (list != NULL && len > 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == OCCUPED
							&& list[j].isEmpty == OCCUPED)
					{
						if (strcmp(list[i].apellido, list[j].apellido) > 0 ||
								list[i].sector > list[j].sector)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 1;
		break;
		case 2:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == OCCUPED
							&& list[j].isEmpty == OCCUPED)
					{

						if (strcmp(list[i].apellido, list[j].apellido) < 0 ||
								list[i].sector < list[j].sector)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		}
	}
	return rtn;
}

float CalculateTotalAndAverageSalary(eEmployee listEmployee[], int len, float* acumulator)
{
	float average;
	int i;
	int counter = 0;

	for(i=0; i<len; i++)
	{
		if(listEmployee[i].isEmpty == OCCUPED)
		{
			*acumulator = *acumulator + listEmployee[i].salario;
			counter++;
		}
	}
	if(counter == 0)
	{
		average = -1;
	}
	else
	{
		average = *acumulator / counter;
	}

	return average;
}

int CalculateSalaryOverAverage(eEmployee listEmployee[], int len)
{
	float average;
	int i;
	int rtn = -1;
	int counterOverAverage = 0;
	float acumulator = 0;

	average =  CalculateTotalAndAverageSalary(listEmployee, len, &acumulator);

	for(i=0; i<len; i++)
	{
		if(listEmployee[i].salario > average && listEmployee[i].isEmpty == OCCUPED)
		{
			counterOverAverage++;
		}
	}
	if(counterOverAverage > 0)
	{
		rtn = counterOverAverage;
	}
	return rtn;
}

