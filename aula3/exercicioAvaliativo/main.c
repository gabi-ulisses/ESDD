#include <stdio.h>
#include <time.h>
#include <string.h>
#include "biblioteca/metodos.h"
#include "casos.c"

#define MAX 1000000

void Sort(int vetor[], int tamanho);
void copiaVetor(int origem[], int destino[], int size);

int main(){
    
    int vetor[MAX];
    int tamanho[] = {1000, 100000, 1000000};
    int opcao = 0, size;

    printf("Vamos testar alguns métodos de classificação!\n");
    printf("Escolha a opção desejada: \n\n");
    printf("1 - Vetor com 1.000 elementos: \n");
    printf("2 - Vetor com 100.000 elementos: \n");
    printf("3 - Vetor com 1.000.000 elementos: \n");

    printf("\nOpção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao){
        case 1:

        // Com 1.000 elementos:

            size = tamanho[0];

            printf("\nMelhor caso:\n\n");
            preencherMelhorCaso(vetor, size);
            Sort(vetor, size);

            printf("\nCaso médio:\n\n");
            preencherCasoMedio(vetor, size);
            Sort(vetor, size);

            printf("\nPior caso:\n\n");
            preencherPiorCaso(vetor, size);
            Sort(vetor, size);

        break;

        case 2:
    
        // Com 100.000 elementos:

            size = tamanho[1];

            printf("\nMelhor caso\n\n");
            preencherMelhorCaso(vetor, size);
            Sort(vetor, size);

            printf("\nCaso médio\n\n");
            preencherCasoMedio(vetor, size);
            Sort(vetor, size);

            printf("\nPior caso\n\n");
            preencherPiorCaso(vetor, size);
            Sort(vetor, size);

        break;

        case 3:

        // Com 1.000.000 elementos:
            size = tamanho[2];

            printf("\nMelhor caso\n\n");
            preencherMelhorCaso(vetor, size);
            Sort(vetor, size);

            printf("\nCaso médio\n\n");
            preencherCasoMedio(vetor, size);
            Sort(vetor, size);
            
            printf("\nPior caso\n\n");
            preencherPiorCaso(vetor, size);
            Sort(vetor, size);

        break;
    
        default:
            printf("Opção inválida!");
        break;
    }
}


void Sort(int vetor[], int size) {
    int vetorCopia[size];
    Contagem resultado;
    clock_t inicio, fim;
    double tempo_gasto;

    // BubbleSort
    copiaVetor(vetor, vetorCopia, size);
    printf("Executando BubbleSort...\n");
    inicio = clock();  // Começa a contar o tempo
    resultado = BubbleSort(vetorCopia, size);
    fim = clock();  // Termina a contagem do tempo
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("BubbleSort - Trocas: %d | Comparações: %d | Tempo de execução: %.5f segundos\n\n", 
           resultado.trocas, resultado.comparacoes, tempo_gasto);

    // InsertionSort
    copiaVetor(vetor, vetorCopia, size);
    printf("Executando InsertionSort...\n");
    inicio = clock();
    resultado = InsertionSort(vetorCopia, size);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("InsertionSort - Trocas: %d | Comparações: %d | Tempo de execução: %.5f segundos\n\n", 
           resultado.trocas, resultado.comparacoes, tempo_gasto);

    // SelectionSort
    copiaVetor(vetor, vetorCopia, size);
    printf("Executando SelectionSort...\n");
    inicio = clock();
    resultado = SelectionSort(vetorCopia, size);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("SelectionSort - Trocas: %d | Comparações: %d | Tempo de execução: %.5f segundos\n\n", 
           resultado.trocas, resultado.comparacoes, tempo_gasto);

    // MergeSort
    copiaVetor(vetor, vetorCopia, size);
    printf("Executando MergeSort...\n");
    inicio = clock();
    resultado = MergeSort(vetorCopia, 0, size - 1, size);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("MergeSort - Trocas: %d | Comparações: %d | Tempo de execução: %.5f segundos\n\n", 
           resultado.trocas, resultado.comparacoes, tempo_gasto);

    // QuickSort
    copiaVetor(vetor, vetorCopia, size);
    printf("Executando QuickSort...\n");
    inicio = clock();
    resultado = QuickSort(vetorCopia, 0, size - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("QuickSort - Trocas: %d | Comparações: %d | Tempo de execução: %.5f segundos\n\n", 
           resultado.trocas, resultado.comparacoes, tempo_gasto);
}



void copiaVetor(int origem[], int destino[], int size) {
for (int i = 0; i < size; i++) {
destino[i] = origem[i];
}
}