#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *dados;
    int *minimos;
    int topo;
    int capacidade;
} Pilha;

Pilha* inicializar(int capacidadeMaxima) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->dados = (int*)malloc(sizeof(int) * capacidadeMaxima);
    pilha->minimos = (int*)malloc(sizeof(int) * capacidadeMaxima);
    pilha->topo = -1;
    pilha->capacidade = capacidadeMaxima;
    return pilha;
}

void adicionar(Pilha* pilha, int valor) {
    if (pilha->topo + 1 < pilha->capacidade) {
        pilha->dados[++pilha->topo] = valor;
        if (pilha->topo == 0) {
            pilha->minimos[pilha->topo] = valor;
        } else {
            pilha->minimos[pilha->topo] = valor < pilha->minimos[pilha->topo - 1] 
                                          ? valor 
                                          : pilha->minimos[pilha->topo - 1];
        }
    }
}

void remover(Pilha* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
    }
}

int obterMenor(Pilha* pilha) {
    if (pilha->topo >= 0) {
        return pilha->minimos[pilha->topo];
    }
    return -1;
}

bool estaVazia(Pilha* pilha) {
    return pilha->topo < 0;
}

void liberar(Pilha* pilha) {
    free(pilha->dados);
    free(pilha->minimos);
    free(pilha);
}

int main() {
    int n;
    scanf("%d", &n);

    Pilha* pilha = inicializar(n);

    for (int i = 0; i < n; i++) {
        char comando[10];
        scanf("%s", comando);

        if (strcmp(comando, "PUSH") == 0) {
            int valor;
            scanf("%d", &valor);
            adicionar(pilha, valor);
        } else if (strcmp(comando, "POP") == 0) {
            if (estaVazia(pilha)) {
                printf("EMPTY\n");
            } else {
                remover(pilha);
            }
        } else if (strcmp(comando, "MIN") == 0) {
            if (estaVazia(pilha)) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", obterMenor(pilha));
            }
        }
    }

    liberar(pilha);
    return 0;
}