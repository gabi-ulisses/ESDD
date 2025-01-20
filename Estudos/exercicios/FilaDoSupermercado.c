#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tempo_livre;
    int id;
} Caixa;

void troca(Caixa *a, Caixa *b) {
    Caixa temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int vi[N]; 
    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }

    int cj[M];
    for (int j = 0; j < M; j++) {
        scanf("%d", &cj[j]);
    }

    Caixa caixas[N]; 
    for (int i = 0; i < N; i++) {
        caixas[i].tempo_livre = 0;
        caixas[i].id = i;
    }

    for (int j = 0; j < M; j++) {
        int menor_id = 0;
        for (int i = 1; i < N; i++) {
            if (caixas[i].tempo_livre < caixas[menor_id].tempo_livre || 
                (caixas[i].tempo_livre == caixas[menor_id].tempo_livre && caixas[i].id < caixas[menor_id].id)) {
                menor_id = i;
            }
        }

        caixas[menor_id].tempo_livre += vi[caixas[menor_id].id] * cj[j];
    }

    int tempo_total = 0;
    for (int i = 0; i < N; i++) {
        if (caixas[i].tempo_livre > tempo_total) {
            tempo_total = caixas[i].tempo_livre;
        }
    }

    printf("%d\n", tempo_total);
    return 0;
}