/*
 ============================================================================
			Franco Sultana
 ============================================================================
 */
 #include "arrayEmployees.h"
#define LEN_EMPLOYEE 1000

int main(void)
{
	setbuf(stdout, NULL);

	int id = 0;
	int option;
	int order;
	int listOption;
	float totalSalary;
	float avergeSalary;
	int overAverage;
	char reply;

	eEmployee Employee[LEN_EMPLOYEE];

	initEmployees(Employee, LEN_EMPLOYEE);
	do
	{

		printf("\n\tMENÚ PRINCIPAL\n");
		printf("0. Salir\n");
		printf("1. Alta empleado\n");
		printf("2. Modificar empleado\n");
		printf("3. Baja empleado\n");
		printf("4. Mostrar empleados\n");

		utn_getEnteroSinReintentos(&option, "Ingrese una opción: ", "(!)Opción inválida. ",0, 4);
		switch (option)
		{
		case 0:
			if(utn_getRespuestaSiNo(&reply, "¿Está seguro de salir?", sizeof(reply)) == 1)
			{
				printf("\n\n\tSaliendo");
				option = -1;
			}
		break;
		case 1:
			switch(addEmployee(Employee, LEN_EMPLOYEE, &id))
			{
				case 1:
					printf("Empleado ingresado con éxito\n");
				break;
				case -1:
					printf("X Alta cancelada\n");
				break;
				case 0:
					printf("No hay espacio para cargar mas empleados\n");
				break;
			}
		break;
		case 2:
	switch(modifyEmployees(Employee, LEN_EMPLOYEE))
		{
			case 1:
				printf("Empleado modificado  con éxito\n");
			break;
			case -1:
				printf("X Modificacion cancelada\n");
			break;
			case 0:
				printf("Aun no hay empleado dados de alta, no se puede realizar una modificacion\n");
			break;
		}
	break;
		case 3:
			switch(removeEmployee(Employee, LEN_EMPLOYEE))
			{
				case 1:
					printf("Empleado dado de baja con éxito\n");
				break;
				case -1:
					printf("X Baja cancelada\n");
				break;
				case 0:
					printf("Aun no hay empleado dados de alta, no se puede realizar una baja\n");
				break;
			}
		break;
		case 4:
			printf("\n\tMENU MOSTRAR\n 1. Lista empleados\n 2. Total y salario promedio\n");
			utn_getEnteroSinReintentos(&listOption, "Ingrese una opcion: ", "(!)Opción inválida. ", 1, 2);
			switch(listOption)
			{
				case 1:
					printf("\tLISTA\n  1. Lista ordenada de menor a mayor\n  2. Lista ordenada de menor a mayor\n");
					utn_getEnteroSinReintentos(&order, "Ingrese una opción: ", "(!)Opción inválida. ", 1, 2);
					sortEmployees(Employee, LEN_EMPLOYEE, order);
					if(printEmployees(Employee, LEN_EMPLOYEE) != 1)
					{
						printf("Asegurese de haber ingresado al menos un empleado\n");
					}
				break;
				case 2:
					avergeSalary = CalculateTotalAndAverageSalary(Employee, LEN_EMPLOYEE, &totalSalary);
					if(avergeSalary == -1)
					{
						printf("No hay empleados dados de alta. No se puede calcular el promedio\n");
					}
					else
					{
						printf("Salario promedio: %.2f   -   Salario total: %.2f\n", avergeSalary, totalSalary);
					}
					overAverage = CalculateSalaryOverAverage(Employee, LEN_EMPLOYEE);
					if(overAverage != -1)
					{
						printf("Cantidad de empleados que superan el promedio: %d\n", overAverage);
					}
					else
					{
						printf("No hay empleados que superen el promedio\n");
					}

				break;
			}

		break;

		}
	} while (option != -1);
	system("cls");
	return 0;
}
