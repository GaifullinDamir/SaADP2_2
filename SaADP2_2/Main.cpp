#include <iostream>
#include "Sorting.h"
#include "Interface.h"

using namespace std;

int main()
{
	int countCompares{ 0 }, countExchanges{ 0 };
	int size = getSize();
	//int* mainArray = new int[size];
	int* auxArray = new int[size];

	int mainArray[6] = { 15, 33, 42, 07, 12, 19 };
	//fillArray(mainArray, size);

	/*interface(mainArray, auxArray, countCompares, countExchanges, size);*/
	interface(mainArray, auxArray, countCompares, countExchanges, 6);
	clearMemory(mainArray);
	clearMemory(auxArray);
}