#include <stdio.h>

void merge(int array[], int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int esquerda[tamanhoEsquerda], direita[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++) {
        esquerda[i] = array[inicio + i];
    }
    for (int j = 0; j < tamanhoDireita; j++) {
        direita[j] = array[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] >= direita[j]) {
            array[k] = esquerda[i];
            i++;
        } else {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        array[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);

        merge(array, inicio, meio, fim);
    }
}

int main() {
    int n, k, vetor[1000000];
    const int MODULO = 1000000007;

    while (scanf("%d %d", &n, &k) != EOF && k > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i]);
        }

        mergeSort(vetor, 0, n - 1);

        int soma = 0;
        for (int i = 0; i < k; i++) {
            soma = (soma + vetor[i]) % MODULO;
        }

        printf("%d\n", soma);
    }

    return 0;
}