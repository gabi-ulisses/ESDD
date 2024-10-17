#include <stdio.h>
#include <time.h>
#include <string.h>
#include "biblioteca/metodos.c"
#include "casos.c"

#define MAX 1000000

void Sort(int vetor[], int tamanho);
void limparVetor(int vetor[], int tamanho);
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

// BubbleSort
copiaVetor(vetor, vetorCopia, size);
printf("Executando BubbleSort...\n");
BubbleSort(vetorCopia, size);

// InsertionSort
copiaVetor(vetor, vetorCopia, size);
printf("Executando InsertionSort...\n");
InsertionSort(vetorCopia, size);

// SelectionSort
copiaVetor(vetor, vetorCopia, size);
printf("Executando SelectionSort...\n");
SelectionSort(vetorCopia, size);

// MergeSort
copiaVetor(vetor, vetorCopia, size);
printf("Executando MergeSort...\n");
MergeSort(vetorCopia, 0, size - 1, size);

// QuickSort
copiaVetor(vetor, vetorCopia, size);
printf("Executando QuickSort...\n");
QuickSort(vetorCopia, 0, size - 1); // Ajustado para QuickSort
}

void limparVetor(int vetor[], int tamanho) {
    memset(vetor, 0, tamanho * sizeof(int));
}

void copiaVetor(int origem[], int destino[], int size) {
for (int i = 0; i < size; i++) {
destino[i] = origem[i];
}
}