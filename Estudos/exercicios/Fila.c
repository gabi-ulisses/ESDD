#include <stdio.h>

struct fila {
    int pessoa;
    int posicao;
};

void init(struct fila *queue);
void enqueue(int pessoa, struct fila *queue);
void dequeue(int pessoa, struct fila *queue);
void mostrarFila(struct fila *queue);

int main() {
    int qtd_pessoas, pessoa, qtd_saidas;
    
    scanf("%d", &qtd_pessoas);
    
    struct fila queue[qtd_pessoas];
    init(queue);
    
    for (int i = 0; i < qtd_pessoas; i++) {
        scanf("%d", &pessoa);
        enqueue(pessoa, queue);
    }
    
    scanf("%d", &qtd_saidas);
    
    for (int i = 0; i < qtd_saidas; i++) {
        scanf("%d", &pessoa);
        dequeue(pessoa, queue);
    }
    
    mostrarFila(queue);
    
    return 0;
}

void init(struct fila *queue) {
    queue->posicao = 0;
}

void enqueue(int pessoa, struct fila *queue) {
    queue[queue->posicao].pessoa = pessoa;
    queue->posicao++;
}

void dequeue(int pessoa, struct fila *queue) {
    for (int i = 0; i < queue->posicao; i++) {
        if (pessoa == queue[i].pessoa) {
            for (int j = i; j < queue->posicao - 1; j++) {
                queue[j].pessoa = queue[j + 1].pessoa;
            }
            queue->posicao--;
            return;
        }
    }
}

void mostrarFila(struct fila *queue) {
    for (int i = 0; i < queue->posicao; i++) {
        if (i < queue->posicao - 1) {
            printf("%d ", queue[i].pessoa);
        } else {
            printf("%d\n", queue[i].pessoa);
        }
    }
}