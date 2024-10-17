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

    printf("\n\nTrocas: %lld | ", troca);
    printf("Comparações: %lld | ", comparacoes);
	printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

}


void InsertionSort(int vetor[], int size) {

    long long int comparacoes_insertion = 0;
    long long int trocas_insertion = 0;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    inicio = clock();

    for (int i = 1; i < size; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Contabilizando comparações
        while (j >= 0 && vetor[j] > chave) {
            comparacoes_insertion++;
            vetor[j + 1] = vetor[j]; // Aqui estamos "trocando"
            j--;
            trocas_insertion++;
        }

        comparacoes_insertion++; // Comparação que falhou no while

        vetor[j + 1] = chave; // Troca final da chave

        if (j + 1 != i) { // Se houve troca de fato
            trocas_insertion++;
        }
    }
    
    fim = clock(); 

    tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;


    printf("\n\nTrocas: %lld | ", trocas_insertion);
    printf("Comparações: %lld | ", comparacoes_insertion);
    printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);

}



void SelectionSort(int vetor[], int size) {

    long long int comparacoes_selection = 0;
    long long int trocas_selection = 0;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    inicio = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            comparacoes_selection++;
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }

        // Efetuar a troca somente se houver alteração
        if (min_index != i) {
            int temp = vetor[min_index];
            vetor[min_index] = vetor[i];
            vetor[i] = temp;
            trocas_selection++;
        }
    }
    
    fim = clock(); 

    tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    printf("\n\nTrocas: %lld | ", trocas_selection);
    printf("Comparações: %lld | ", comparacoes_selection);
    printf("Tempo de execução: %.5f segundos\n\n", tempo_gasto);
    
}



int partition(int vetor[], int low, int high) {

    long long int comparacoes_quick = 0;
    long long int trocas_quick = 0;

    int pivot = vetor[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparacoes_quick++;

        if (vetor[j] < pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            trocas_quick++;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[high];
    vetor[high] = temp;
    trocas_quick++;

    return (i + 1);
}

void QuickSort(int vetor[], int low, int high) {
    if (low < high) {
        int pi = partition(vetor, low, high);
        QuickSort(vetor, low, pi - 1);
        QuickSort(vetor, pi + 1, high);
    }
}

int comparacoes_merge = 0;
int trocas_merge = 0;

void MergeSort(int vetor[], int inicio, int fim, int size) {
    
    if (inicio < fim) {
        comparacoes_merge++;
        int meio = (inicio + fim) / 2;
        MergeSort(vetor, inicio, meio, size);
        MergeSort(vetor, meio + 1, fim, size);
        intercala(vetor, inicio, fim, meio, size);
    }   
}

void intercala(int vetor[], int inicio, int fim, int meio, int size) {

    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = vetor[inicio + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {

        comparacoes_merge++;

        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
            trocas_merge++;
        }

        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
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