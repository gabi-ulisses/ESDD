#include <stdio.h>

void inserir_ordenado(int vetor[], int tamanho, int valor) {
    int i;

    // Desloca os elementos maiores que o valor para a direita
    for (i = tamanho - 1; (i >= 0 && vetor[i] > valor); i--) {
        vetor[i + 1] = vetor[i];
    }

    // Insere o novo valor na posição correta
    vetor[i + 1] = valor;
}

int main() {
    int vetor[10] = {1, 3, 5, 7, 9}; // Vetor ordenado
    int tamanho = 5; // Número de elementos no vetor atualmente
    int valor = 4; // Novo valor a ser inserido

    // Chama a função para inserir o valor, mantendo a ordenação
    inserir_ordenado(vetor, tamanho, valor);

    // Atualiza o tamanho do vetor após a inserção
    tamanho++;

    // Imprime o vetor resultante
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
