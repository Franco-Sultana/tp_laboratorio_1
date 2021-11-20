

#include "Employee.h"

Employee* employee_new()
{
	Employee* auxEmpleado;
	auxEmpleado = (Employee*)calloc(1, sizeof(Employee));
	return auxEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* auxEmpleado;
	auxEmpleado = malloc(sizeof(Employee));
	if(auxEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr && sueldoStr != NULL)
	{
		employee_setId(auxEmpleado, atoi(idStr));
		employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadasStr));
		employee_setNombre(auxEmpleado, nombreStr);
		employee_setSueldo(auxEmpleado, atoi(sueldoStr));
	}

	return auxEmpleado;
}

void employee_menu(int* opcion)
{
	printf("\n------------------------------ MENU PRINCIPAL ------------------------------\n"
			" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
		    " 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
		    " 3. Alta de empleado\n"
		    " 4. Modificar datos de empleado\n"
		    " 5. Baja de empleado\n"
		    " 6. Listar empleados\n"
		    " 7. Ordenar empleados\n"
		    " 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
		    " 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
		   " 10. Salir\n"
		   "------------------------------------------------------------------------------\n");

	utn_getEntero(opcion, "Ingrese una opcion: ", "(!)Opcion invalida. ", 0, 10);
}

void employee_titulo()
{
	printf("\n%5s %30s %10s %10s\n", "ID", "NOMBRE", "HORAS", "SUELDO");
}

void employee_mostrarUno(Employee* empleado)
{
	int id;
	char nombre[30];
	int sueldo;
	int horas;
	employee_obtenerDatos(empleado, &id, nombre, &horas, &sueldo);
	printf("%5d %30s %10d %10d\n", id, nombre, horas, sueldo);
}

int employee_obtenerDatos(Employee* empleado, int* id, char* nombre, int* horas, int* sueldo)
{
	int retorno = 0;
	if(empleado != NULL && id != NULL && nombre != NULL && horas != NULL && sueldo != NULL)
	{
		retorno = 1;
		employee_getId(empleado, id);
		employee_getHorasTrabajadas(empleado, horas);
		employee_getSueldo(empleado, sueldo);
		employee_getNombre(empleado, nombre);
	}
	return retorno;
}


Employee* employee_cargarDatos(char nombre[], char sueldo[], char horas[], int tamNombre, int tamHoras, int tamSueldo)
{
	Employee* auxEmpleado;
	auxEmpleado = employee_new();

	utn_getNombre(nombre, "Ingrese el nombre del empleado: ", "(!)Nombre invalido. ", tamNombre);
	utn_getTextoEnteros(horas, "Ingrese la cantidad de horas trabajadas: ",
										 "(!)Cantidad invalida. ", tamHoras);
	utn_getTextoEnteros(sueldo, "Ingrese el sueldo: ", "(!)Sueldo invalido. ", tamSueldo);



	return auxEmpleado;
}

void employee_delete(Employee* empleado)
{
	if(empleado != NULL)
	{
		free(empleado);
	}
}

Employee* employee_modificarDatos(Employee* empleado)
{
	Employee* empleadoModificado;
	empleadoModificado =  empleado;
	int opcion;
	int id;
	char nombre[30];
	int horasTrabajadas;
	int sueldo;
	char idStrModificado[30];
	char nombreModificado[30];
	char horasTrabajadasModificado[30];
	char sueldoModificado[30];

	employee_obtenerDatos(empleado, &id, nombre, &horasTrabajadas, &sueldo);

	sprintf(idStrModificado, "%d", id);
	sprintf(horasTrabajadasModificado, "%d", horasTrabajadas);
	sprintf(sueldoModificado, "%d", sueldo);
	strcpy(nombreModificado, nombre);
	do
	{
		printf("\n------ MENU MODIFICAR ------\n"
				" 0. Salir del menu modificar\n"
				" 1. Nombre\n"
				" 2. Horas trabajadas\n"
				" 3. Sueldo\n"
				"----------------------------\n");

		utn_getEntero(&opcion, "Ingrese una opcion: ", "(!)Opcion invalida. ", 0, 3);
		switch(opcion)
		{
		case 1:
			utn_getNombre(nombreModificado, "Ingrese el nombre del empleado: ", "(!)Nombre invalido. ", sizeof(nombreModificado));
			break;
		case 2:
			utn_getTextoEnteros(horasTrabajadasModificado, "Ingrese la cantidad de horas trabajadas: ",
											 "(!)Cantidad invalida. ", sizeof(horasTrabajadasModificado));
			break;
		case 3:
			utn_getTextoEnteros(sueldoModificado, "Ingrese el sueldo: ", "(!)Sueldo invalido. ", sizeof(sueldoModificado));
			break;
		}
		empleadoModificado = employee_newParametros(idStrModificado, nombreModificado,
													horasTrabajadasModificado, sueldoModificado);
	}while(opcion != 0);
	return empleadoModificado;
}

int employee_buscarPorID(Employee* empleado, int idBuscar)
{
	int retorno = 0;

	int id;
	employee_getId(empleado, &id);
	if(idBuscar == id)
	{
		retorno = 1;
	}
	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas >0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo >0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_compararNombre(void* valor1, void* valor2)
{

	char nombre1[30];
	char nombre2[30];
	int comparacion;
	Employee* empleado1 = (Employee*)valor1;
	Employee* empleado2 = (Employee*)valor2;
	if(empleado1 != NULL && empleado2 != NULL)
	{
		employee_getNombre(empleado1, nombre1);
		employee_getNombre(empleado2, nombre2);

		comparacion = strcmp(nombre1, nombre2);
	}
	return comparacion;
}

int employee_compararSueldo(void* valor1, void* valor2)
{
	int sueldo1;
	int sueldo2;
	int comparacion = 0;
	Employee* empleado1 = (Employee*)valor1;
	Employee* empleado2 = (Employee*)valor2;
	if(empleado1 != NULL && empleado2 != NULL)
	{
		employee_getSueldo(empleado1, &sueldo1);
		employee_getSueldo(empleado2, &sueldo2);
		if(sueldo1 > sueldo2)
		{
			comparacion = 1;
		}
		else
		{
			if(sueldo1 < sueldo2)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

int employee_compararHoras(void* valor1, void* valor2)
{
	int horas1;
	int horas2;
	int comparacion = 0;
	Employee* empleado1 = (Employee*)valor1;
	Employee* empleado2 = (Employee*)valor2;
	if(empleado1 != NULL && empleado2 != NULL)
	{
		employee_getHorasTrabajadas(empleado1, &horas1);
		employee_getHorasTrabajadas(empleado2, &horas2);
		if(horas1 > horas2)
		{
			comparacion = 1;
		}
		else
		{
			if(horas1 < horas2)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

int employee_compararId(void* valor1, void* valor2)
{
	int id1;
	int id2;
	int comparacion = 0;
	Employee* empleado1 = (Employee*)valor1;
	Employee* empleado2 = (Employee*)valor2;
	if(empleado1 != NULL && empleado2 != NULL)
	{
		employee_getId(empleado1, &id1);
		employee_getId(empleado2, &id2);
		if(id1 > id2)
		{
			comparacion = 1;
		}
		else
		{
			if(id1 < id2)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}
