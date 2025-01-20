#include <stdio.h>
#include <string.h>

void ordenaPorValidade(int validade[], char carne[][21], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (validade[j] > validade[j + 1]) {
                int tempValidade = validade[j];
                validade[j] = validade[j + 1];
                validade[j + 1] = tempValidade;

                char tempCarne[21];
                strcpy(tempCarne, carne[j]);
                strcpy(carne[j], carne[j + 1]);
                strcpy(carne[j + 1], tempCarne);
            }
        }
    }
}

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        if (N == 0) {
            continue;
        }

        int validade[N];
        char carne[N][21];

        for (int i = 0; i < N; i++) {
            scanf("%s", carne[i]);
            scanf("%d", &validade[i]);
        }

        ordenaPorValidade(validade, carne, N);

        for (int i = 0; i < N; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%s", carne[i]);
        }
        printf("\n");
    }

    return 0;
}