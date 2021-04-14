/*
 ============================================================================
		Franco Sultana	Div "B"	TP1

Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
 ============================================================================
 */
#include <stdlib.h>
#include "biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);
	float numeroA;
	float numeroB;
	int opcion;
	int banderaNumeroA;
	int banderaNumeroB;
	int banderaResolverOperaciones;
	int resComprobarDecimalEnteroA;
	int resComprobarDecimalEnteroB;

	float resSumar;
	float resRestar;
	float resDividir;
	float resMultiplicar;
	float resFactorialA;
	float resFactorialB;

	banderaNumeroA=0;
	banderaNumeroB=0;
	banderaResolverOperaciones=0;

	printf("�BIENVENIDO!\n");
	while(opcion!=5)
	{
		printf("	==================");
		printf("\nMEN� DE OPCIONES");
		printf("\n  -'1' para ingresar el primer n�mero\n");
		printf("  -'2' para ingresar el segundo n�mero\n");
		printf("  -'3' para calcular las operaciones\n");
		printf("  -'4' para ver los resultados\n");
		printf("  -'5' para salir\n");
		printf("Ingrese un numero para elegir una opci�n: ");
		scanf("%d", &opcion);
		printf("\nINGRES� '%d':\n", opcion);

		switch(opcion)
		{
		case 1:
			printf("Ingrese el primer n�mero (A): ");
			scanf("%f", &numeroA);
			printf("A=%.2f\n", numeroA);
			banderaNumeroA=1;
		break;
		case 2:
			printf("Ingrese el segundo n�mero (B): ");
			scanf("%f", &numeroB);
			printf("B=%.2f\n", numeroB);
			banderaNumeroB=1;
		break;
		case 3:
			if(banderaNumeroA==0 || banderaNumeroB==0)
			{
				printf("(!) ERROR, aseg�rese de haber ingresado todos los n�meros\n");
			}
			else
			{
				resSumar=Sumar(numeroA, numeroB);
				resRestar=Restar(numeroA, numeroB);
				resDividir=Dividir(numeroA, numeroB);
				resMultiplicar=Multiplicar(numeroA, numeroB);
				resFactorialA=FactorialA(numeroA);
				resFactorialB=FactorialB(numeroB);
				resComprobarDecimalEnteroA=ComprobarDecimalEnteroA(numeroA);
				resComprobarDecimalEnteroB=ComprobarDecimalEnteroB(numeroB);

				printf("�Ya resolvimos las operaciones!\n");
				banderaResolverOperaciones=1;
			}
		break;
		case 4:
			if(banderaResolverOperaciones==0)
			{
				printf("(!) ERROR, aseg�rese de haber calculado las operaciones (opcion 3)\n");
			}
			else
			{
				printf("A=%.2f\nB=%.2f\n", numeroA, numeroB);
				printf("El resultado de A+B es: %.2f\n", resSumar);
				printf("El resultado de A-B es: %.2f\n", resRestar);
				if(numeroB==0)
				{
					printf("(!) ERROR, no se puede dividir por cero");
				}
				else
				{
					printf("El resultado de A/B es: %.2f\n", resDividir);
				}
				printf("El resultado de A*B es: %.2f\n", resMultiplicar);

				if(resComprobarDecimalEnteroA==1 || numeroA<0)
				{
					printf("El fatorial de A es: ERROR(factorial con decimales o negativos) ");
				}
				else
				{
					if(resComprobarDecimalEnteroA==0 || numeroA>0)
					{
						printf("El factorial de A es: %.2f ", resFactorialA);
					}
				}
				if(resComprobarDecimalEnteroB==1 || numeroB<0)
				{
					printf("y el factorial de B es: ERROR(factorial con decimales o negativos)\n");
				}
				else
				{
					if(resComprobarDecimalEnteroB==0 || numeroB>0)
					{
						printf("y el factorial de B es: %.2f\n", resFactorialB);
					}
				}
			}
		break;
		case 5:
			printf("�Gracias por usar esta calculadora!");
		break;
		default:
			printf("(!) ERROR, elija una opci�n entre 1 y 5\n");
		break;
		}
	}
	return EXIT_SUCCESS;
}




