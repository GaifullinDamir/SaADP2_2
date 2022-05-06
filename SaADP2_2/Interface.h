#pragma once
#include "Sorting.h"

enum interface
{
	ShowMenu, BubbleSort, SelectionSort, InsertionSort, ShellSort, QuickSort, PyramidSort, Exit,
	BaseLevel = 1,
};

void printMenu();

int input();

void interface(int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size);

int getSize();

void showInfo(int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size);

void caseSort(void(*pSort)(int*, int&, int&, int), int* mainArray, int* auxArray,
	int& countCompares, int& countExchanges, int size);

void caseQuickSort(int* mainArray, int* auxArray, int& countCompares, int& countExchanges, int size);