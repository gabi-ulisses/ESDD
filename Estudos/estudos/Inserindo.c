#include <stdio.h>

void insertion_sort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
    int tamanho = 10;

    insertion_sort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
