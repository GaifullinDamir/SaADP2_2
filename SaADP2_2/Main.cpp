#include <iostream>
#include "Sorting.h"
#include "Interface.h"

using namespace std;

int main()
{
	int countCompares{ 0 }, countExchanges{ 0 };
	int size = getSize();
	int* mainArray = new int[size];
	int* auxArray = new int[size];

	fillArray(mainArray, size);

	interface(mainArray, auxArray, countCompares, countExchanges, size);

	clearMemory(mainArray);
	clearMemory(auxArray);
}