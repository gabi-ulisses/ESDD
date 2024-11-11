#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Conjunto;

// Função para criar um conjunto vazio
Conjunto criarConjunto() {
    Conjunto c;
    c.dados = (int *)malloc(10 * sizeof(int));  // Capacidade inicial de 10 elementos
    c.tamanho = 0;
    c.capacidade = 10;
    return c;
}

// Função para insere um elemento no conjunto
void insereElemento(Conjunto *c, int elemento) {
    // Verifica se há espaço no vetor
    if (c->tamanho == c->capacidade) {
        c->capacidade *= 2;  // Dobra a capacidade
        c->dados = (int *)realloc(c->dados, c->capacidade * sizeof(int));
    }
    c->dados[c->tamanho++] = elemento;
}

// Função para remover um elemento do conjunto
void removeElemento(Conjunto *c, int elemento) {
    for (int i = 0; i < c->tamanho; i++) {
        if (c->dados[i] == elemento) {
            // Move os elementos à direita do elemento encontrado
            for (int j = i; j < c->tamanho - 1; j++) {
                c->dados[j] = c->dados[j + 1];
            }
            c->tamanho--;
            return;
        }
    }
    printf("Elemento %d não encontrado no conjunto.\n", elemento);
}

// Função para verificar se um elemento pertence ao conjunto
int pertence(Conjunto *c, int elemento) {
    for (int i = 0; i < c->tamanho; i++) {
        if (c->dados[i] == elemento) {
            return 1;  // Pertence ao conjunto
        }
    }
    return 0;  // Não pertence
}

// Função para calcular a união de dois conjuntos
Conjunto uniao(Conjunto *c1, Conjunto *c2) {
    Conjunto uniaoConjunto = criarConjunto();
    
    // Adiciona todos os elementos de c1 no conjunto união
    for (int i = 0; i < c1->tamanho; i++) {
        insereElemento(&uniaoConjunto, c1->dados[i]);
    }
    
    // Adiciona todos os elementos de c2 que não estão em c1
    for (int i = 0; i < c2->tamanho; i++) {
        if (!pertence(&uniaoConjunto, c2->dados[i])) {
            insereElemento(&uniaoConjunto, c2->dados[i]);
        }
    }
    
    return uniaoConjunto;
}

// Função para calcular a intersecção de dois conjuntos
Conjunto intersecao(Conjunto *c1, Conjunto *c2) {
    Conjunto intersecaoConjunto = criarConjunto();
    
    // Adiciona os elementos que estão em ambos os conjuntos
    for (int i = 0; i < c1->tamanho; i++) {
        if (pertence(c2, c1->dados[i])) {
            insereElemento(&intersecaoConjunto, c1->dados[i]);
        }
    }
    
    return intersecaoConjunto;
}

// Função para calcular a diferença entre dois conjuntos
Conjunto diferenca(Conjunto *c1, Conjunto *c2) {
    Conjunto diferencaConjunto = criarConjunto();
    
    // Adiciona os elementos de c1 que não estão em c2
    for (int i = 0; i < c1->tamanho; i++) {
        if (!pertence(c2, c1->dados[i])) {
            insereElemento(&diferencaConjunto, c1->dados[i]);
        }
    }
    
    return diferencaConjunto;
}

// Função para testar se dois conjuntos são iguais
int saoIguais(Conjunto *c1, Conjunto *c2) {
    if (c1->tamanho != c2->tamanho) {
        return 0;  // Os conjuntos têm tamanhos diferentes
    }
    
    for (int i = 0; i < c1->tamanho; i++) {
        if (!pertence(c2, c1->dados[i])) {
            return 0;  // Se algum elemento de c1 não pertence a c2
        }
    }
    
    return 1;  // Os conjuntos são iguais
}

// Função para retornar o tamanho do conjunto
int tamanho(Conjunto *c) {
    return c->tamanho;
}

// Função para verificar se o conjunto está vazio
int estaVazio(Conjunto *c) {
    return c->tamanho == 0;
}

// Função para imprimir os elementos de um conjunto
void imprimeConjunto(Conjunto *c) {
    printf("{ ");
    for (int i = 0; i < c->tamanho; i++) {
        printf("%d ", c->dados[i]);
    }
    printf("}\n");
}

// Função para liberar a memória alocada pelo conjunto
void liberarConjunto(Conjunto *c) {
    free(c->dados);
}

int main() {
    Conjunto c1 = criarConjunto();
    Conjunto c2 = criarConjunto();
    
    // Insere elementos no primeiro conjunto
    insereElemento(&c1, 1);
    insereElemento(&c1, 2);
    insereElemento(&c1, 3);
    insereElemento(&c1, 4);
    
    // Insere elementos no segundo conjunto
    insereElemento(&c2, 3);
    insereElemento(&c2, 4);
    insereElemento(&c2, 5);
    insereElemento(&c2, 6);
    
    // Imprime os conjuntos
    printf("Conjunto 1: ");
    imprimeConjunto(&c1);
    
    printf("Conjunto 2: ");
    imprimeConjunto(&c2);
    
    // Calcula a união
    Conjunto cUniao = uniao(&c1, &c2);
    printf("União: ");
    imprimeConjunto(&cUniao);
    
    // Calcula a intersecção
    Conjunto cIntersecao = intersecao(&c1, &c2);
    printf("Interseção: ");
    imprimeConjunto(&cIntersecao);
    
    // Calcula a diferença
    Conjunto cDiferenca = diferenca(&c1, &c2);
    printf("Diferença (C1 - C2): ");
    imprimeConjunto(&cDiferenca);
    
    // Testa se os conjuntos são iguais
    if (saoIguais(&c1, &c2)) {
        printf("Os conjuntos são iguais.\n");
    } else {
        printf("Os conjuntos não são iguais.\n");
    }
    
    // Testa se o conjunto está vazio
    printf("O conjunto 1 está vazio? %s\n", estaVazio(&c1) ? "Sim" : "Não");
    
    // Mostra o tamanho do conjunto
    printf("O tamanho do conjunto 1 é: %d\n", tamanho(&c1));
    
    // Libera a memória dos conjuntos
    liberarConjunto(&c1);
    liberarConjunto(&c2);
    liberarConjunto(&cUniao);
    liberarConjunto(&cIntersecao);
    liberarConjunto(&cDiferenca);
    
    return 0;
}
