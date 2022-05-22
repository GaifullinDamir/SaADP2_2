#include <iostream>
#include "Sorting.h"
#include "Interface.h"
#include <cmath>

using namespace std;

int randomNumber() { return MinNumber + rand() % (MaxNumber - MinNumber + 1); }

void fillArray(int* currentArray, int size)
{
	for (int cell = 0; cell < size; cell++) { currentArray[cell] = randomNumber(); }
}

void duplicateArray(int* mainArray, int* auxArray, int size)
{
	for (int cell = 0; cell < size; cell++) { auxArray[cell] = mainArray[cell]; }
}

void bubbleSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int temporary;
	for (int i = 1; i < size; i++)
	{
		for (int j = size - 1; j >= i; j--)
		{
			if (auxArray[j - 1] > auxArray[j])
			{
				temporary = auxArray[j - 1];
				auxArray[j - 1] = auxArray[j];
				auxArray[j] = temporary;
				countExchanges++;
			}
			countCompares++;
		}
	}
}


void selectionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int min = 0;
	int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			countCompares++;
			if (auxArray[j] < auxArray[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = auxArray[i];
			auxArray[i] = auxArray[min];
			auxArray[min] = temp;
			countExchanges++;
		}
	}
}

void insertionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		while ((++countCompares) && j >= 0 && auxArray[i] < auxArray[j])
		{
			j = j - 1;
		}
		if (j + 1 != i)
		{
			int temporary = auxArray[i]; int l = i - 1;
			while (l >= j + 1)
			{
				auxArray[l + 1] = auxArray[l]; l--;
				countExchanges++;
			}
			auxArray[j + 1] = temporary;
		}
	}
}

void shellSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int steps = round(log2(size)) - 1; int copySteps = steps;
	int* stepsArray = new int[steps];
	for (int i = 0; copySteps > 0; i++, copySteps--) { stepsArray[i] = 2 * copySteps - 1; }
	int temporary, k, j;
	for (int m = 0; m < steps; m++)
	{
		k = stepsArray[m];
		for (int i = k; i < size; i++)
		{
			int j = i - k;
			while ((++countCompares) && j >= 0 && auxArray[i] < auxArray[j])
			{
				j = j - k;
			}
			if (j + k != i)
			{
				int temporary = auxArray[i]; int l = i - k;
				while (l >= j + k)
				{
					auxArray[l + k] = auxArray[l]; l = l - k;
					countExchanges++;
				}
				auxArray[j + k] = temporary;
			}
		}
	}
}

void quickSort(int* auxArray, int begin, int end, int& countCompares, int& countExchanges, int size)
{
	int temporary, middle, i = begin, j = end;
	middle = auxArray[(begin + end) / 2];
	do
	{
		while (auxArray[i] < middle)
		{
			i++;
			countCompares++;
		}
		while (auxArray[j] > middle)
		{
			j--;
			countCompares++;
		}
	
		if (i <= j)
		{
			temporary = auxArray[i]; auxArray[i] = auxArray[j]; auxArray[j] = temporary;
			i++; j--;
			countExchanges++;
		}
	} while (i <= j);

	if (begin < j) { quickSort(auxArray, begin, j, countCompares, countExchanges, size); }
	if (i < end) {  quickSort(auxArray, i, end, countCompares, countExchanges, size); }
}

void sieve(int* auxArray, int left, int right, int& countCompares, int& countExchanges)
{
	int i = left, j = 2 * left, x = auxArray[left];
	if (j < right && auxArray[j + 1] > auxArray[j])
	{
		j++;
	}
	countCompares++;
	while (j <= right && auxArray[j] > x)
	{
		countCompares++;
		auxArray[i] = auxArray[j]; i = j; j = 2 * j;

		if (j < right && auxArray[j + 1] > auxArray[j])
		{
			j++;
		}
		countCompares++;
	}
	auxArray[i] = x;
	countExchanges++;
}
void pyramidSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int temporary;
	int left = (size / 2) + 2; int right = size - 1;
	while (left > 0)
	{
		left--; sieve(auxArray, left, right, countCompares, countExchanges);
	}
	while (right > 0)
	{
		temporary = auxArray[0]; auxArray[0] = auxArray[right]; auxArray[right] = temporary;
		countExchanges++;
		right--; sieve(auxArray, left, right, countCompares, countExchanges);
	}
}
void show(int* currentArray, int size)
{
	for (int cell = 0; cell < size; cell++)
	{
		if (cell % 30 == 0) { cout << "\n"; }
		cout << currentArray[cell] << " ";
	}
}

void clearMemory(int* currentArray)
{
	delete[] currentArray;
	currentArray = nullptr;
}
