#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


//LLENO = 0
int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int banderaCargadoTexto = 0;
    int banderaCargadoBin = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int confirmacion;
    do{

    	employee_menu(&option);
        switch(option)
        {
        	case 1:
        	system("cls");
			if(banderaCargadoTexto == 1)
			{
				if(utn_getRespuestaSiNo("(!)ATENCION(!) La lista ya fue cargada previamente, si continua se"
				"perderan todas las\nmodificaciones hechas al momento. Desea continuar?") == 1)
				{
					ll_clear(listaEmpleados);
					banderaCargadoTexto = 0;
				}
			}
        	if(banderaCargadoTexto == 0)
        	{

                switch(controller_loadFromText("data.csv",listaEmpleados))
                {
                case 1:
                	printf("\nLos datos se cargaron correctamente\n");
                	banderaCargadoTexto = 1;
                break;
                case -1:
                	printf("\n(X)Se cancelo la recarga de datos\n");
                break;
                case 0:
                	printf("\n(!)Hubo un error al intentar abrir el archivo\n");
                break;
                }

        	}
            break;
            case 2:
            	system("cls");
            	if(banderaCargadoBin == 1)
				{
					if(utn_getRespuestaSiNo("(!)ATENCION(!) La lista ya fue cargada previamente, si continua se"
					"perderan todas las\nmodificaciones hechas al momento. Desea continuar?") == 1)
					{
						ll_clear(listaEmpleados);
						banderaCargadoBin = 0;
					}
				}
				if(banderaCargadoBin == 0)
				{
					switch(controller_loadFromBinary("data.bin", listaEmpleados))
					{
					case 1:
						printf("\nLos datos se cargaron correctamente\n");
						banderaCargadoBin = 1;
					break;
					case -1:
						printf("\n(!)Hubo un error al intentar abrir el archivo. Asegurese de haber guardado los\n "
								"cambios en el archivo binario primero\n");
					break;
					}

				}
            break;
            case 3:
            	system("cls");
            	switch(controller_addEmployee(listaEmpleados))
            	{
            	case 1:
            		printf("\nSe cargo correctamente\n");
            	break;
            	case -1:
            		printf("\n(!)Ocurrio un error inesperado\n");
            	break;
            	case 0:
            		printf("\n(X)Se cancelo el alta\n");
            	break;
            	}
            break;
            case 4:
            	system("cls");
            	switch(controller_editEmployee(listaEmpleados))
            	{
            	case 2:
            		printf("\n(X)Se cancelo la modificacion\n");
            	break;
            	case 1:
            		printf("\nEl empleado se modifico correctamente\n");
            	break;
            	case 0:
            		printf("\n(-)El id no fue encontrado\n");
            	break;
            	case -1:
            		printf("\n(0)Aun no hay una lista cargada\n");
            	break;
            	case -2:
            		printf("\n(!!)Ocurrio un error inesperado\n");
            	break;
            	}
            break;
            case 5:
            	system("cls");
            	switch(controller_removeEmployee(listaEmpleados))
            	{
            	case 2:
					printf("\n(X)Se cancelo la baja\n");
				break;
				case 1:
					printf("\nEl empleado se dio de baja correctamente\n");
				break;
				case 0:
					printf("\n(-)El id no fue encontrado\n");
				break;
				case -1:
					printf("\n(0)Aun no hay una lista cargada\n");
				break;
				case -2:
					printf("\n(!!)Ocurrio un error inesperado\n");
				break;
            	}
            break;
            case 6:
            	system("cls");
            	switch(controller_ListEmployee(listaEmpleados))
            	{
            	case -2:
            		printf("\n(!!)Ocurrio un error inesperado\n");
            	break;
            	case -1:
            		printf("\n(0)Aun no hay una lista cargada\n");
            	break;
            	case 0:
            		printf("\n(!)Ocurrio un error al mostrar\n");
            	break;
            	}
            break;
            case 7:
            	system("cls");
            	switch(controller_sortEmployee(listaEmpleados))
            	{
            	case -1:
            		printf("\n(!!)Ocurrio um error inesperado\n");
            	break;
            	case 0:
            		printf("\n(0)Aun no hay una lista cargada\n");
            	break;
            	}
            break;
            case 8:
            	system("cls");
            	confirmacion = 1;
				if(banderaCargadoBin == 0 && banderaCargadoTexto == 0)
				{
					if(utn_getRespuestaSiNo("\n(!!)ATENCION(!!) La lista no fue cargada desde el archivo, si continua se perdera\n"
										"una gran cantidad de informacion. Desea continuar?") != 1)
					{
						confirmacion = 0;
						printf("\nSe cancelo la recarga de datos\n");
					}
				}
				if(confirmacion == 1)
				{
					{
            			switch(controller_saveAsText("data.csv", listaEmpleados))
						{
						case -2:
							printf("\n(!!)Ocurrio un error inesperado\n");
						break;
						case -1:
							printf("\n(X)Se cancelo el guardado de dado\n");
						break;
						case 0:
							printf("\n(!)Hubo un error al abrir el archivo\n");
						break;
						case 1:
							printf("\nLos datos se guardaron con exito\n");
						break;
						case 2:
							printf("\n(0)No se realizaron modificaciones a la lista\n");
						break;
						}
					}


            	}
            break;
            case 9:
            	system("cls");
            	confirmacion = 1;
            	if(banderaCargadoBin == 0 && banderaCargadoTexto == 0)
            	{
					if(utn_getRespuestaSiNo("\n(!!)ATENCION(!!) La lista no fue cargada desde el archivo, si continua se perdera\n"
										"una gran cantidad de informacion. Desea continuar?") != 1)
					{
						confirmacion = 0;
						printf("\nSe cancelo la recarga de datos\n");
					}
            	}
            	if(confirmacion == 1)
            	{
					switch(controller_saveAsBinary("data.bin", listaEmpleados))
					{

					case -2:
						printf("\n(!!)Ocurrio un error inesperado\n");
					break;
					case -1:
						printf("\n(0)No se realizaron modificaciones a la lista\n");
					break;
					case 0:
						printf("\n(!)Ocurrio un error al abrir el archivo\n");
					break;
					case 1:
						printf("\nLos datos se guardaron con exito\n");
					break;
					case 2:
						printf("\n(X)Se cancelo el guardado de datos\n");
					break;
					}
            	}
            break;
            case 10:
            	system("cls");
            	ll_deleteLinkedList(listaEmpleados);
            	printf("\nSaliendo");

            break;

        }

    }while(option != 10);
    return 0;
}

