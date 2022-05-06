#include <iostream>
#include "Sorting.h"
#include "Interface.h"

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
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (auxArray[j] > auxArray[j + 1])
			{
				temporary = auxArray[j];
				auxArray[j] = auxArray[j + 1];
				auxArray[j + 1] = temporary;
				countExchanges++;
			}
			countCompares++;
		}
	}
}

void selectionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int temporary;
	for (int startIndex = 0; startIndex < size - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; currentIndex++)
		{
			if (auxArray[currentIndex] < auxArray[smallestIndex]) { smallestIndex = currentIndex; }
			countCompares++;
		}
		temporary = auxArray[startIndex];
		auxArray[startIndex] = auxArray[smallestIndex];
		auxArray[smallestIndex] = temporary;
		countExchanges++;
	}
}

void insertionSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int temporary;
	for (int i = 1; i < size; i++)
	{
		temporary = auxArray[i]; int j = i - 1;
		while (j >= 0 && temporary < auxArray[j])
		{
			auxArray[j + 1] = auxArray[j];
			j--;
			countCompares++;
			countExchanges++;
		}
		auxArray[j + 1] = temporary;
		countCompares++;
	}
}

void shellSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int steps = (int)log2(size) - 1; int copySteps = steps;
	int* stepsArray = new int[steps];
	for (int i = 0; copySteps > 0; i++, copySteps--){ stepsArray[i] = 2 * copySteps - 1; }
	int temporary, stepLength, j;
	for (int m = 0; m < steps; m++)
	{
		stepLength = stepsArray[m];
		for (int i = stepLength; i < size; i++)
		{
			temporary = auxArray[i]; j = i - stepLength;
			while (j >= 0 && temporary < auxArray[j])
			{
				countCompares++;
				auxArray[j + stepLength] = auxArray[j]; j = j - stepLength;
				countExchanges++;
			}
			countCompares++;
			auxArray[j + stepLength] = temporary;
		}
	}
	clearMemory(stepsArray);
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
		countCompares += 2;
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
		countExchanges++;
		if (j < right && auxArray[j + 1] > auxArray[j])
		{
			j++;
		}
		countCompares++;
	}
	countCompares++;
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
