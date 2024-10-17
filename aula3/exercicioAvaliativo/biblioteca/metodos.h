#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int vetor[], int size);

void InsertionSort(int vetor[], int size);

void SelectionSort(int vetor[], int size);

void MergeSort(int vetor[], int inicio, int fim, int size);
void intercala(int vetor[], int inicio, int fim, int meio, int size);

int partition(int vetor[], int low, int high);
void QuickSort(int vetor[], int low, int high);