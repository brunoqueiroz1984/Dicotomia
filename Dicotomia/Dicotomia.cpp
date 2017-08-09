// Dicotomia.cpp : Calcula a raiz de uma fórmula com dicotomia.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stdafx.h"

//exemplo: 1x^3+4x^2-10     int=1 e 2         erro=0,03

float calc(int *eq, int grau, float inta, float intb); //função q calcula se a função é valida
void dic(int *eq, int grau, float inta, float intb, float erro);//função q calcula a dicotomia

int main()
{
	float inta, intb, erro;
	int eq[10], grau, i, f;

	printf("\nDigite o grau da funcao (min2-max6): ");
	scanf("%i", &grau);

	for (i = 0; i <= grau; i++)
	{
		printf("\nDigite o termo Cx^%i: ", i);
		scanf("%i", &eq[i]);
	}

	printf("\nDigite o erro: ");
	scanf("%f", &erro);
	printf("\nDigite o intervalo 1: ");
	scanf("%f", &inta);
	printf("\nDigite o intervalo 2: ");
	scanf("%f", &intb);

	f = calc(eq, grau, inta, intb);
	if (f == 1)
	{
		printf("\n\nA funcao eh valida!!\n\n");
		dic(eq, grau, inta, intb, erro);
	}
	else
		printf("\n\nA funcao nao eh valida!!\n\n");

	printf("Programa finalizado!\n");
	system("PAUSE");
	return 0;
}


float calc(int *eq, int grau, float inta, float intb)
{
	int i;
	float re1 = 0, re2 = 0, aux;

	for (i = 0; i <= grau; i++, eq++)//fors para substituir os intervalos na funções
	{
		aux = *eq*(pow(inta, i));
		re1 += aux;

	}

	for (i = 0; i <= grau; i++, eq++)
	{
		aux = *eq*(pow(intb, i));
		re2 += aux;

	}
	if (re1*re2<0) //multiplicação dos resultados
		return 1;
	else
		return 0;

}

void dic(int *eq, int grau, float inta, float intb, float erro)
{
	int i;
	float m, fm, aux, er;

	er = (intb - inta) / 2;
	do
	{

		m = (inta + intb) / 2;
		fm = 0;
		for (i = 0; i <= grau; i++, eq++)
		{
			aux = *eq*pow(m, i);
			fm += aux;
		}
		eq -= 4;
		if (fm>0)
			intb = m;
		if (fm<0)
			inta = m;
		er = (intb - inta) / 2;
	} while (er>erro);

	printf("\nA raiz eh: %f +/- %f", m, er);
}

