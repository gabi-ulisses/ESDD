/*

    "BubbleSort" ou "Ordenação por Bolha":
        Compara pares de elementos adjacentes e os troca de lugar
        se estiverem na ordem errada.
        Esse processo se repete até que mais nenhuma troca seja 
        necessária (elementos já ordenados).

    "Performance"
        Melhor caso: O(n), ou seja, dados já ordenados.
        Pior caso: O(n²), necessário todas as iterações para ordenar.

    * Não recomendado para grandes conjuntos de dados, listas muito grande.

*/


#include <stdio.h>
#define TAM 10

void preencherVetor(int vetor[]);
void bubbleSort(int vetor[]);
void imprimeVetor(int vetor[]);


int main() {
    int vetor[TAM];

    preencherVetor(vetor);

    printf("\nVetor original: ");
    imprimeVetor(vetor);

    bubbleSort(vetor);

    printf("\nVetor ordenado: ");
    imprimeVetor(vetor);

    return 0; 
}

void preencherVetor(int vetor[]){
    int i;

    printf("\nVamos ordenar um vetor!");
    printf("\nInforme um número para...\n\n");

    for ( i = 0; i < TAM; i++){
        printf("Posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void imprimeVetor(int vetor[]){
    
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]); 
    }
    printf("\n"); 

}

void bubbleSort(int vetor[]) {
   
    int i, continua, aux;
    
    continua = 1;

    do {
        continua = 0; 
        
        for (i = 0; i < TAM - 1; i++) {
            if (vetor[i] > vetor[i+1]) { // Se o elemento atual for maior que o próximo, faz a troca.

                aux = vetor[i];    // Salva o valor de vetor[i] em 'aux' temporariamente.
                vetor[i] = vetor[i+1]; // Coloca o valor de vetor[i+1] em vetor[i].
                vetor[i+1] = aux;  // Coloca o valor de 'aux' (antigo vetor[i]) em vetor[i+1].
                
                continua = 1;
            }
        }
    } while (continua); // O loop continua até que não haja mais trocas (continua == 1).
}