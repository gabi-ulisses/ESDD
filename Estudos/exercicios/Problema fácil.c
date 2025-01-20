#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

typedef struct {
    int *itens;
    int tamanho;
    int capacidade;
} Vetor;

void inicializarVetor(Vetor *v) {
    v->itens = NULL;
    v->tamanho = 0;
    v->capacidade = 0;
}

void adicionarElemento(Vetor *v, int valor) {
    if (v->tamanho == v->capacidade) {
        v->capacidade = (v->capacidade == 0) ? 1 : v->capacidade * 2;
        v->itens = realloc(v->itens, v->capacidade * sizeof(int));
    }
    v->itens[v->tamanho++] = valor;
}

void limparVetor(Vetor *v) {
    free(v->itens);
    v->itens = NULL;
    v->tamanho = 0;
    v->capacidade = 0;
}

Vetor T[MAX];

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < MAX; i++) {
            inicializarVetor(&T[i]);
        }

        for (int i = 1; i <= n; i++) {
            int temp;
            scanf("%d", &temp);
            adicionarElemento(&T[temp], i);
        }

        while (m--) {
            int k, v;
            scanf("%d %d", &k, &v);
            k--;
            if (k < T[v].tamanho) {
                printf("%d\n", T[v].itens[k]);
            } else {
                printf("0\n");
            }
        }

        for (int i = 0; i < MAX; i++) {
            limparVetor(&T[i]);
        }
    }

    return 0;
}