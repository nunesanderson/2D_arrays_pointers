// 2DArraysPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{

	time_t start, end;
	int n = 2000;

	////////////////////////////////////////////////////
	// Creating the arrays
	////////////////////////////////////////////////////

	printf("Creating the arrays");
	
	double** arrA;
	double** arrB;
	double** arrC;

	arrA = new double*[n];
	arrB = new double*[n];
	arrC = new double*[n];

	for (int x = 0; x<n; x++)
	{
		arrA[x] = new double[n];
		arrB[x] = new double[n];
		arrC[x] = new double[n];


	}
	printf("\rCreating the arrays - Done!\n");
	
	////////////////////////////////////////////////////
	//Populating the arrays
	////////////////////////////////////////////////////

	printf("Populating the arrays");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arrA[i][j] = 1;
			arrB[i][j] = 1;
			arrC[i][j] = 1;
		}
	}
	printf("\rPopulating the arrays - Done\n");

	////////////////////////////////////////////////////
	//Multiplicating the arrays (indices)
	////////////////////////////////////////////////////
	printf("Multiplying the arrays (indices)");
	time(&start);
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<n; ++j)
			for (int k = 0; k<n; ++k)
			{
				arrC[i][j] += arrA[i][k] * arrB[k][j];
			}

	time(&end);
	double dif = difftime(end, start);
	printf("\rMultiplying the arrays (indices) - Done in %.2lf seconds\n",dif);

	////////////////////////////////////////////////////
	//Multiplicating the arrays (pointers)
	////////////////////////////////////////////////////
	printf("Multiplying the arrays (pointers)");
	time(&start);
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<n; ++j)
			for (int k = 0; k<n; ++k)
			{
				*(*(arrC + i) + j) += *(*(arrA + i) + j)*(*(*(arrB + k) + j));
			}

	time(&end);
	dif = 0.0;
	dif = difftime(end, start);
	printf("\rMultiplying the arrays (pointers) - Done in %.2lf seconds\n", dif);

	////////////////////////////////////////////////////
	//Destroying the arrays
	////////////////////////////////////////////////////

	printf("Destroying the arrays");
	for (int x = 0; x < n; x++)
	{
		delete[] arrA[x];
		delete[] arrB[x];
		delete[] arrC[x];

	}
	delete[]arrA;
	delete[]arrB;
	delete[]arrC;

	printf("\rDestroying the arrays - Done\n");
	printf("Done!");

	getchar();

	return 0;
}

