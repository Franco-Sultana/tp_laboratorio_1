/*
 ============================================================================
		Franco Sultana		TP1

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */


#include <stdlib.h>
#include "biblioteca.h"


int main(void)
{
	setbuf(stdout, NULL);
	int numeroA;
	int numeroB;
	int resSuma;
	int resResta;
	float resDivision;
	int resMultiplicacion;
	int resFactorialA;
	int resFactorialB;

	printf("Ingrese un número (A): ");
	scanf("%d", &numeroA);
	printf("Ingrese otro número (B): ");
	scanf("%d", &numeroB);

	resSuma= Sumar(numeroA, numeroB);
	resResta= Restar(numeroA, numeroB);
	resDivision= Dividir(numeroA, numeroB);
	resMultiplicacion= Multiplicar(numeroA, numeroB);
	resFactorialA= FactorialA(numeroA);
	resFactorialB= FactorialB(numeroB);

	printf("A=%d\n", numeroA);
	printf("B=%d\n", numeroB);
	printf("El resultado de A+B es: %d\n", resSuma);
	printf("El resultado de A-B es: %d\n", resResta);
	if(numeroB!=0)
	{
		printf("El resultado de A/B es: %.2f\n", resDivision);
	}
	else
	{
		printf("ERROR, no se puede dividir por cero\n");
	}
	printf("El resultado de A*B es: %d\n", resMultiplicacion);
	printf("El factorial de A es: %d y el factorial de B es: %d", resFactorialA, resFactorialB);
	return EXIT_SUCCESS;
}


