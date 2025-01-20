#include <stdlib.h>
#include <stdio.h>

int comparar(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int buscarBinario(int *V, int n, int valor) {
    int inicio = 0, fim = n;

    while (inicio < fim) {
        int meio = (inicio + fim) / 2;

        if (V[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    return (inicio < n && V[inicio] == valor) ? inicio + 1 : -1;
}

int main() {
    int *marmores;
    int caso = 0, N, Q, consulta, resultado;

    scanf("%d %d", &N, &Q);

    while (N != 0 || Q != 0) {
        marmores = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, N, sizeof(int), comparar);

        printf("CASO %d:\n", ++caso);
        for (int i = 0; i < Q; i++) {
            scanf("%d", &consulta);

            resultado = buscarBinario(marmores, N, consulta);
            if (resultado == -1) {
                printf("%d nao encontrado\n", consulta);
            } else {
                printf("%d encontrado na posicao %d\n", consulta, resultado);
            }
        }

        free(marmores);
        scanf("%d %d", &N, &Q);
    }

    return 0;
}