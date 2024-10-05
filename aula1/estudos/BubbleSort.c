/*

    "BubbleSort" ou "Ordenação por Bolha":
        Compara pares de elementos adjacentes e os troca de lugar
        se estiverem na ordem errada.
        Esse processo se repete até que mais nenhuma troca seja 
        necessária (elementos já ordenados).

    "Performance"
        Melhor caso: O(n), ou seja, dados já ordenados.
        Pior caso: O(n²), necessário todas as iterações para ordenar.

    * Não recomendado para grandes conjuntos de dados.

*/


#include <stdio.h>

void bubbleSort(int V[], int N);

int main() {
    int V[] = {64, 34, 25, 12, 22, 11, 90};
    
    int N = sizeof(V) / sizeof(V[0]);

    bubbleSort(V, N);

    printf("Vetor ordenado: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", V[i]); 
    }

    return 0; 
}


void bubbleSort(int V[], int N) {
   
    int i, continua, aux, fim = N;
    
    // O loop do-while vai repetir enquanto houver trocas de elementos.
    do {
        continua = 0; // Reinicializa 'continua' a cada passagem pelo vetor.
        
        // Loop para percorrer o vetor até a posição 'fim-1'.
        for (i = 0; i < fim - 1; i++) {
            // Compara os elementos adjacentes.
            if (V[i] > V[i+1]) {
                // Se o elemento atual for maior que o próximo, faz a troca.
                aux = V[i];    // Salva o valor de V[i] em 'aux' temporariamente.
                V[i] = V[i+1]; // Coloca o valor de V[i+1] em V[i].
                V[i+1] = aux;  // Coloca o valor de 'aux' (antigo V[i]) em V[i+1].
                
                // Atualiza 'continua' com o índice da última troca.
                // Isso indica que ainda há elementos para ordenar.
                continua = i;
            }
        }
        fim--; // Diminui o limite superior do vetor, pois os últimos elementos já estão ordenados.
        
    } while (continua != 0); // O loop continua até que não haja mais trocas (continua == 0).
}