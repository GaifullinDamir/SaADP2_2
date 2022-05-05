#pragma once

enum sorting
{
	MinNumber = 0, MaxNumber = 250,
	MinSize = 1, MaxSize = 10000
};

void fillArray(int* currentArray, int size);

void duplicateArray(int* mainArray, int* auxArray, int size);

void bubbleSort(int* auxArray, int& countCompares, int& countExchanges, int size);

void selectionSort(int* auxArray, int& countCompares, int& countExchanges, int size);

void insertionSort(int* auxArray, int& countCompares, int& countExchanges, int size);

void show(int* currentArray, int size);

void clearMemory(int* currentArray);
