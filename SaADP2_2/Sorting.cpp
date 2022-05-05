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

void quickSort(int* auxArray, int& countCompares, int& countExchanges, int size)
{
	int left = 0; int right = size - 1;
	int middle = auxArray[size / 2];
	int temporary;
	do {
		while (auxArray[left] < middle) { countCompares++; left++; }
		while (auxArray[right] > middle) { countCompares++; right--; }
		countCompares += 2;
		if(left <= right) 
		{
			temporary = auxArray[left];
			auxArray[left] = auxArray[right];
			auxArray[right] = temporary;
			left++; right--; 
			countExchanges++;
		}
	} while (left <= right);

	if (right > 0) { quickSort(auxArray, countCompares, countExchanges, right + 1); }
	if (left < size) { quickSort(auxArray, countCompares, countExchanges, size - left); }

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
