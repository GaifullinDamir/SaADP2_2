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
