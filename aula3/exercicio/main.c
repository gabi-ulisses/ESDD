#include <stdio.h>
#include <time.h>
#include <string.h>
#include "biblioteca/metodos.c"
#include "casos.c"

#define MAX 1000000

void Sort(int vetor[], int tamanho);
void limparVetor(int vetor[], int tamanho);

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

        preencherMelhorCaso(vetor, tamanho[0]);
        size = tamanho[0];
        printf("\nMelhor caso ");
        Sort(vetor, size);

        preencherCasoMedio(vetor, tamanho[0]);
        size = tamanho[0];
        printf("\nCaso médio ");
        Sort(vetor, size);

        preencherPiorCaso(vetor, tamanho[0]);
        size = tamanho[0];
        printf("\nPior caso ");
        Sort(vetor, size);

        break;

        case 2:
    
    // Com 100.000 elementos:

        preencherMelhorCaso(vetor, tamanho[1]);
        size = tamanho[1];
        printf("\nMelhor caso ");
        Sort(vetor, size);

        preencherCasoMedio(vetor, tamanho[1]);
        size = tamanho[1];
        printf("\nCaso médio ");
        Sort(vetor, size);

        preencherPiorCaso(vetor, tamanho[1]);
        size = tamanho[1];
        printf("\nPior caso ");
        Sort(vetor, size);

        break;

        case 3:


    // Com 1.000.000 elementos:

        preencherMelhorCaso(vetor, tamanho[2]);
        size = tamanho[2];
        Sort(vetor, size);

        preencherCasoMedio(vetor, tamanho[2]);
        size = tamanho[2];
        printf("\nCaso médio ");
        Sort(vetor, size);

        preencherPiorCaso(vetor, tamanho[2]);
        size = tamanho[2];
        printf("\nPior caso ");
        Sort(vetor, size);

        break;
    
        default:
            printf("Opção inválida!");
        break;
    }
}


void Sort(int vetor[], int tamanho){

    BubbleSort(vetor, tamanho);

   /* InsertionSort(vetor, tamanho);

    MergeSort(vetor, tamanho);

    QuickSort(vetor, tamanho);

    SelectionSort(vetor, tamanho);*/
}

void limparVetor(int vetor[], int tamanho) {
    memset(vetor, 0, tamanho * sizeof(int));
}