#include "metodos.h"
#include <time.h>  

void BubbleSort(int vetor[], int size){
   
    int i, continua, aux;
	long long int troca = 0; //
	long long int comparacoes = 0;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    continua = 1;

	inicio = clock();

    do {
        continua = 0; 
        
        for (i = 0; i < size - 1; i++) {

			comparacoes++;

            if (vetor[i] > vetor[i+1]) { 

                aux = vetor[i];    
                vetor[i] = vetor[i+1]; 
                vetor[i+1] = aux;  
                
                continua = 1;

                troca++;
            }
        }

    } while (continua); 

	fim = clock(); 

	tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    printf("- Método BubbleSort\n\n");
    printf("Trocas: %lld | ", troca);
    printf("Comparações: %lld | ", comparacoes);
	printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

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