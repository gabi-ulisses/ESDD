#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elementos;
    int topo;
    int capacidade;
} Pilha;

void inicializarPilha(Pilha* pilha, int capacidade) {
    pilha->elementos = (int*)malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

int vazia(Pilha* pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha* pilha, int valor) {
    pilha->elementos[++pilha->topo] = valor;
}

int desempilhar(Pilha* pilha) {
    if (vazia(pilha)) return -1;
    return pilha->elementos[pilha->topo--];
}

int topo(Pilha* pilha) {
    if (vazia(pilha)) return -1;
    return pilha->elementos[pilha->topo];
}

void destruirPilha(Pilha* pilha) {
    free(pilha->elementos);
}

int podeRemover(Pilha* pilha1, Pilha* pilha2, Pilha* pilha3) {
    if (topo(pilha1) % 3 == 0 || topo(pilha2) % 3 == 0 || topo(pilha3) % 3 == 0) {
        return 1;
    }
    if ((topo(pilha1) + topo(pilha2)) % 3 == 0 || (topo(pilha2) + topo(pilha3)) % 3 == 0) {
        return 1;
    }
    if ((topo(pilha1) + topo(pilha2) + topo(pilha3)) % 3 == 0) {
        return 1;
    }
    return 0;
}

int jogoVencido(Pilha* pilha1, Pilha* pilha2, Pilha* pilha3, int N) {
    while (N > 0) {
        if (podeRemover(pilha1, pilha2, pilha3)) {
            if (topo(pilha1) % 3 == 0) desempilhar(pilha1);
            else if (topo(pilha2) % 3 == 0) desempilhar(pilha2);
            else if (topo(pilha3) % 3 == 0) desempilhar(pilha3);
            else if ((topo(pilha1) + topo(pilha2)) % 3 == 0) {
                desempilhar(pilha1);
                desempilhar(pilha2);
            }
            else if ((topo(pilha2) + topo(pilha3)) % 3 == 0) {
                desempilhar(pilha2);
                desempilhar(pilha3);
            }
            else if ((topo(pilha1) + topo(pilha2) + topo(pilha3)) % 3 == 0) {
                desempilhar(pilha1);
                desempilhar(pilha2);
                desempilhar(pilha3);
            }
            N--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF && N != 0) {
        Pilha pilha1, pilha2, pilha3;
        inicializarPilha(&pilha1, N);
        inicializarPilha(&pilha2, N);
        inicializarPilha(&pilha3, N);
        
        for (int i = 0; i < N; i++) {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            empilhar(&pilha1, A);
            empilhar(&pilha2, B);
            empilhar(&pilha3, C);
        }
        
        if (jogoVencido(&pilha1, &pilha2, &pilha3, N)) {
            printf("1\n");
        } else {
            printf("0\n");
        }

        destruirPilha(&pilha1);
        destruirPilha(&pilha2);
        destruirPilha(&pilha3);
    }

    return 0;
}