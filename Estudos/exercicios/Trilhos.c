#include <stdlib.h>
#include <stdio.h>

typedef struct NoPilha {
    int valor;
    struct NoPilha* abaixo;
} NoPilha;

typedef struct Pilha {
    int tamanho;
    NoPilha* topo;
} Pilha;

void empilhar(Pilha* pilha, int valor) {
    pilha->tamanho++;
    NoPilha* novoTopo = (NoPilha*) malloc(sizeof(NoPilha));
    novoTopo->valor = valor;
    novoTopo->abaixo = pilha->topo;
    pilha->topo = novoTopo;
}

void desempilhar(Pilha* pilha) {
    if (pilha->tamanho > 0) {
        pilha->tamanho--;
        NoPilha* topoAntigo = pilha->topo;
        pilha->topo = pilha->topo->abaixo;
        free(topoAntigo);
    }
}

int topo(Pilha* pilha) {
    return pilha->topo->valor;
}

int tamanho(Pilha* pilha) {
    return pilha->tamanho;
}

int vazia(Pilha* pilha) {
    return pilha->tamanho == 0;
}

void inicializar(Pilha* pilha) {
    pilha->tamanho = 0;
    pilha->topo = NULL;
}

void destruir(Pilha* pilha) {
    while (!vazia(pilha)) {
        desempilhar(pilha);
    }
}

int main() {
    int numeroVagoes, vagao;
    Pilha entrada, estacao, saida;

    while (scanf("%d", &numeroVagoes) != EOF) {
        if (numeroVagoes == 0) break;

        while (scanf("%d", &vagao)) {
            if (vagao == 0) {
                printf("\n");
                break;
            }

            inicializar(&entrada);
            inicializar(&estacao);
            inicializar(&saida);

            empilhar(&entrada, vagao);
            empilhar(&saida, 1);
            for (int i = 2; i <= numeroVagoes; ++i) {
                scanf("%d", &vagao);
                empilhar(&entrada, vagao);
                empilhar(&saida, i);
            }

            while (!vazia(&entrada) || !vazia(&estacao) || !vazia(&saida)) {
                if (!vazia(&entrada) && !vazia(&saida) && topo(&entrada) == topo(&saida)) {
                    desempilhar(&entrada);
                    desempilhar(&saida);
                } else if (!vazia(&estacao) && !vazia(&saida) && topo(&estacao) == topo(&saida)) {
                    desempilhar(&estacao);
                    desempilhar(&saida);
                } else if (!vazia(&entrada)) {
                    empilhar(&estacao, topo(&entrada));
                    desempilhar(&entrada);
                } else {
                    break;
                }
            }

            if (vazia(&entrada) && vazia(&estacao) && vazia(&saida)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            destruir(&entrada);
            destruir(&estacao);
            destruir(&saida);
        }
    }

    return 0;
}