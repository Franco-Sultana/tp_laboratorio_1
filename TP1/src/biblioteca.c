/*
 * biblioteca.c
 *
 *  Created on: 30 mar. 2021
 *      Author: F2019
 *
 *      Franco Sultana div "B"
 */

#include "biblioteca.h"

float Sumar(float numeroA, float numeroB)
{
	float suma;
	suma=numeroA+numeroB;
	return suma;
}

float Restar(float numeroA, float numeroB)
{
	float resta;
	resta=numeroA-numeroB;
	return resta;
}

float Dividir(float numeroA, float numeroB)
{
	float division;
	division=numeroA/numeroB;
	return division;
}

float Multiplicar(float numeroA, float numeroB)
{
	float multiplicacion;
	multiplicacion=numeroA*numeroB;
	return multiplicacion;
}

float FactorialA(float numeroA)
{
	int i;
	float factorialA;
	factorialA=1;
	i=0;

	for(i=numeroA; i>1; i--)
	{
		factorialA=factorialA*i;
	}
	return factorialA;
}

float FactorialB(float numeroB)
{
	int i;
	float factorialB;
	factorialB=1;
	i=0;

	for(i=numeroB; i>1; i--)
	{
		factorialB=factorialB*i;
	}
	return factorialB;
}

int ComprobarDecimalEnteroA(float a)
{
	int entero;
	int decimalEnteroA;
	entero=a;

	if(a-entero)
	{
		decimalEnteroA=1;
	}
	else
	{
		decimalEnteroA=0;
	}
	return decimalEnteroA;
}

int ComprobarDecimalEnteroB(float b)
{
	int entero;
	int decimalEnteroB;
	entero=b;

	if(b-entero)
	{
		decimalEnteroB=1;
	}
	else
	{
		decimalEnteroB=0;
	}
	return decimalEnteroB;
}
