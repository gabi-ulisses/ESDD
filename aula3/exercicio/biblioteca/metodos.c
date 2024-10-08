#include "metodos.h"

void BubbleSort(int vetor[], int size){
   
    int i, continua, aux, troca;
    
    continua = 1;

    do {
        continua = 0; 
        
        for (i = 0; i < size - 1; i++) {

            if (vetor[i] > vetor[i+1]) { 

                aux = vetor[i];    
                vetor[i] = vetor[i+1]; 
                vetor[i+1] = aux;  
                
                continua = 1;

                troca++;

            }
        }

    } while (continua); 

    printf("Trocas: %d", troca);
    printf("Comparações: %d", i);

}
/*
void InsertSort(int vetor[], int size){

	int i, j, continua, aux;

	for(i = 1; i < size; i++){
		aux = vetor[i];
		
		for(j = i - 1; j >= 0 && vetor[j] > aux; j--){
			vetor[j+1] = vetor[j];
		}
		vetor[j+1] = aux;
	}

}

void SelectionSort(int vetor[], int size){

    int i, j, pos_menor, aux;
	
	for(i=0; i < size; i++){
		pos_menor = i;
		for(j=i+1; j < size; j++){
			if(vetor[j] < vetor[pos_menor]){
				pos_menor = j;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[pos_menor];
		vetor[pos_menor] = aux;
	}

}

void MergeSort(int vetor[], int size){

}

void QuickSort(int vetor[], int size){

}
*/