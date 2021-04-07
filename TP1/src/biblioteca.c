/*
 * biblioteca.c
 *
 *  Created on: 30 mar. 2021
 *      Author: F2019
 */

#include "biblioteca.h"

int Sumar(int numeroA, int numeroB)
{
	int suma;
	suma=numeroA+numeroB;
	return suma;
}

int Restar(int numeroA, int numeroB)
{
	int resta;
	resta=numeroA-numeroB;
	return resta;
}

float Dividir(int numeroA, int numeroB)
{
	float division;
	division=(float)numeroA/numeroB;
	return division;
}

int Multiplicar(int numeroA, int numeroB)
{
	int multiplicacion;
	multiplicacion=numeroA*numeroB;
	return multiplicacion;
}

int FactorialA(int numeroA)
{
	int i;
	int factorialA;
	factorialA=1;
	i=0;

	for(i=numeroA; i>1; i--)
	{
		factorialA=factorialA*i;
	}
	return factorialA;
}

int FactorialB(int numeroB)
{
	int i;
	int factorialB;
	factorialB=1;
	i=0;

	for(i=numeroB; i>1; i--)
	{
		factorialB=factorialB*i;
	}
	return factorialB;
}

