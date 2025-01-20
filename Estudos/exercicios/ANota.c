#include <stdio.h>
#define MODULO 1000000007

void combinar(int array[], int inicio, int meio, int fim) {
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

void ordenar(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        ordenar(array, inicio, meio);
        ordenar(array, meio + 1, fim);

        combinar(array, inicio, meio, fim);
    }
}

int main() {
    int quantidadeNumeros, somaMaxima;
    int numeros[1000000];

    while (scanf("%d%d", &quantidadeNumeros, &somaMaxima) != EOF && somaMaxima > 0) {
        for (int i = 0; i < quantidadeNumeros; i++) {
            scanf("%d", &numeros[i]);
        }

        ordenar(numeros, 0, quantidadeNumeros - 1);

        int somaFinal = 0;
        for (int i = 0; i < somaMaxima; i++) {
            somaFinal = (somaFinal + numeros[i]) % MODULO;
        }

        printf("%d\n", somaFinal);
    }

    return 0;
}