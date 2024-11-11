#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5}; // Exemplo de vetor em ordem crescente
    int tamanho = 5;
    int ordenado = 1; // Vamos assumir que está ordenado

    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            ordenado = 0; // Não está em ordem
            break;
        }
    }

    if (ordenado == 1) {
        printf("ORDENADO\n");
    } else {
        printf("NÃO ORDENADO\n");
    }

    return 0;
}
