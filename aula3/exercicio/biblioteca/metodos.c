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

    printf("Método BubbleSort -");
    printf("Trocas: %lld | ", troca);
    printf("Comparações: %lld | ", comparacoes);
	printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

}

void InsertionSort(int vetor[], int size){

	int i, j, aux;
	long long int troca = 0; //
	long long int comparacoes = 0;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

	inicio = clock();

	for(i = 1; i < size; i++){
		aux = vetor[i];
		
		for(j = i - 1; j >= 0 && vetor[j] > aux; j--){
			vetor[j+1] = vetor[j];
			troca++;
		}
		vetor[j+1] = aux;
		comparacoes++;
	}
	fim = clock(); 

	tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    printf("Método Insertion Sort - ");
    printf("Trocas: %lld | ", troca);
    printf("Comparações: %lld | ", comparacoes);
	printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

}

void SelectionSort(int vetor[], int size){

    int i, j, pos_menor, aux;
	long long int troca = 0; //
	long long int comparacoes = 0;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

	inicio = clock();
	
	for(i=0; i < size; i++){
		pos_menor = i;
		for(j=i+1; j < size; j++){
			if(vetor[j] < vetor[pos_menor]){
				pos_menor = j;
				troca++;
			}
		comparacoes++;
		}
		aux = vetor[i];
		vetor[i] = vetor[pos_menor];
		vetor[pos_menor] = aux;
	}

	fim = clock(); 

	tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    printf("Método Selection Sort - ");
    printf("Trocas: %lld | ", troca);
    printf("Comparações: %lld | ", comparacoes);
	printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

}

/*
void MergeSort(int vetor[], int inicio, int fim, int size){
	int meio;
	long long	int meio;

	if(inicio < fim){
		comparacoes++;
		meio = (inicio + fim) / 2;
		MergeSort(vetor, inicio, meio, size);
		MergeSort(vetor, meio+1, fim, size);
		intercala(vetor, inicio, fim, meio, size);
	}
}

void intercala(int vetor[], int inicio, int fim, int meio, int size){

	int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
	int arquivo_aux[size];
	int troca = 0;

	inicio_arquivo1 = inicio;
	inicio_arquivo2 = meio + 1;
	pos_livre = inicio;

	while(inicio_arquivo1 <= meio && inicio_arquivo2 <= fim){
		if(vetor[inicio_arquivo1] <= vetor[inicio_arquivo2]){
			arquivo_aux[pos_livre] = vetor[inicio_arquivo1];
			inicio_arquivo1 += 1;
		} 
		else
		{
			arquivo_aux[pos_livre] = vetor[inicio_arquivo2];
			inicio_arquivo2 += 1;
		}
		pos_livre += 1;
	}
	for(i=inicio_arquivo1; i<= meio; i++, pos_livre++){
		arquivo_aux[pos_livre] = vetor[i];
	}
	for(i=inicio_arquivo2; i<= fim; i++, pos_livre++){
		arquivo_aux[pos_livre] = vetor[i];
	}
	for(i=inicio; i <= fim; i++){
		vetor[i] = arquivo_aux[i];
	}

	return troca++;
}


void QuickSort(int vetor[], int size){

}
*/