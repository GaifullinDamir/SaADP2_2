#include <iostream>
#include <string>
#include "Interface.h"
#include "Sorting.h"

using namespace std;

void printMenu()
{
	cout << endl;
	cout
		<< "\n1. Bubble sort."
		<< "\n2. Selection sort."
		<< "\n3. Insertion sort."
		<< "\n4. Shell sort."
		<< "\n5. Quick sort."
		<< "\n6. Exit."
		<< endl;
}

int input()
{
	int option = 0; bool check = true; string optionInput;
	while (check)
	{
		try { cin >> optionInput; option = stoi(optionInput); check = false; }
		catch (const std::exception&) { cout << "   Wrong input.\n\n"; check = true; }
	}
	return option;
}

void interface(int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size)
{

	bool stop = false; printMenu();

	while (!stop)
	{
		cout << "   Choice: ";
		switch (input())
		{
		case ShowMenu:		{ printMenu(); break; }
		case BubbleSort:    { caseSort(bubbleSort, mainArray, auxArray, countCompares, countExchanges, size); break; }
		case SelectionSort: { caseSort(selectionSort, mainArray, auxArray, countCompares, countExchanges, size); break; }
		case InsertionSort: { caseSort(insertionSort, mainArray, auxArray, countCompares, countExchanges, size); break; }
		case ShellSort:     { caseSort(shellSort, mainArray, auxArray, countCompares, countExchanges, size); break; }
		case QuickSort:     { caseSort(quickSort, mainArray, auxArray, countCompares, countExchanges, size); break; }
		case Exit:          { stop = true; break; }
		default:              cout << "   There is no such menu item.\n\n"; break;
		}
		cout << "   (0) - show menu.\n";
	}
}

int getSize()
{
	int size = 0;
	while (size < MinSize || size > MaxSize) { cout << "   Enter the size (1 - 10000): "; size = input(); }
	return size;
}

void showInfo(int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size)
{
	cout << "\n   Before sorting:\n   ";
	show(mainArray, size);
	cout << "\n\n   After sorting:\n   ";
	show(auxArray, size);
	cout << "\n   Number of comparisons: " << countCompares << "\n\n   Number of exchanges: " << countExchanges << "\n\n";
}

void caseSort(void(*pSort)(int*, int&, int&, int), int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size)
{
	countCompares = countExchanges = 0;
	duplicateArray(mainArray, auxArray, size);
	pSort(auxArray, countCompares, countExchanges, size);
	showInfo(mainArray, auxArray, countCompares, countExchanges, size);
}