/*

Passagem por referência: 

Passagem por valor:

*/

#include <stdio.h>
#include <time.h>
#include "biblioteca/metodos.h"

#include "casos/melhoresCasos.c"
#include "casos/mediosCasos.c"
#include "casos/pioresCasos.c"

#define MAX 1000000

void Sort(int vetor[], int tamanho);

int main(){
    
    int vetor[MAX];
    int tamanho[] = {1000, 100000, 1000000};
    int opcao;

    printf("Vamos testar alguns métodos de classificação!\n");
    printf("Escolha a opção desejada: \n");
    printf("1 - Vetor com 1.000 elementos: \n");
    printf("2 - Vetor com 100.000 elementos: \n");
    printf("3 - Vetor com 1.000.000 elementos: \n");

    switch (opcao){
        case 1:

    // Com 1.000 elementos:
        
        preencherCasoMedio(vetor, tamanho[0]);
        Sort(vetor, tamanho[0]);

        preencherPiorCaso(vetor, tamanho[0]);
        Sort(vetor, tamanho[0]);

        preencherMelhorCaso(vetor, tamanho[0]);
        Sort(vetor, tamanho[0]);

        break;

        case 2:
    
    // Com 100.000 elementos:

        preencherCasoMedio(vetor, tamanho[1]);
        Sort(vetor, tamanho[1]);


        preencherPiorCaso(vetor, tamanho[1]);
        Sort(vetor, tamanho[1]);


        preencherMelhorCaso(vetor, tamanho[1]);
        Sort(vetor, tamanho[1]);

        break;

        case 3:


    // Com 1.000.000 elementos:

        preencherCasoMedio(vetor, tamanho[2]);
        Sort(vetor, tamanho[2]);


        preencherPiorCaso(vetor, tamanho[2]);
        Sort(vetor, tamanho[2]);


        preencherMelhorCaso(vetor, tamanho[2]);
        Sort(vetor, tamanho[2]);

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