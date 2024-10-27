    /*
    
    "Ordenação" é a tarefa de colocar um conjunto de 
    dados em uma determinada ordem, permitindo acesso mais eficiente aos dados.

    "Algoritmo de ordenação" é o algoritmo que coloca 
    os elementos de uma sequência em uma certa ordem.
    
    Tipos de ordenação mais comuns:

        Numérica;
        Lexicográfica (ordem alfabética);
    
    Independente do tipo a ordem pode ser: crescente ou decrescente.

    Os métodos de ordenação são classificados em:

        Ordenação interna: o conjunto de dados que será ordenado cabe na memória principal, com
        isso, qualquer registro pode ser imediatamente acessado.

        Ordenação externa:  o conjunto de dados que será ordenado não cabe na memória principal, com
        isso, os registros são acessados sequencialmente ou em grandes blocos.
    
    Existem:
        Métodos básicos: que possibilitam uma fácil implementação e auxiliam o entendimento dos 
        algoritmos complexos. Essa complexidade é representada por O(n²), ou seja, se 
        existem n elementos a serem ordenados, o algoritmo gasta n² operações para ordená-los.
        
        Métodos sofisticados: que têm, em geral, um melhor desempenho. Sua complexidade pode ser
        definida por O(n log n), ou seja, se existem existem n elementos a serem ordenados, 
        o algoritmo gasta n log de n operações para ordená-los.
    */

#include <stdio.h>
#include <stdlib.h>

void ordenar(int vetor[], int n);

void imprimirVetor(int vetor[], int n);

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    
    printf("\nVetor original: \n");
    imprimirVetor(vetor, n);
    
    // Chama a função de ordenação
    ordenar(vetor, n);
    
    printf("\nVetor ordenado: \n");
    imprimirVetor(vetor, n);

    return 0;
}

// Implementação da função de ordenação (Bubble Sort como exemplo)
void ordenar(int vetor[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n-1; i++) {
    // O loop externo controla a quantidade de passagens pelo vetor.
    // Cada iteração coloca o maior elemento restante na sua posição correta.
    // Começamos com i=0 e vamos até n-2 (n-1 é o último elemento, que será ordenado automaticamente).

    for (j = 0; j < n-i-1; j++) {
        // O loop interno percorre os elementos não ordenados do vetor.
        // Ele compara cada elemento com o próximo (vetor[j] > vetor[j+1]).
        // O tamanho do loop interno diminui à medida que 'i' aumenta, porque os últimos elementos já estarão ordenados.
        
        if (vetor[j] > vetor[j+1]) {
            // Compara o elemento atual (vetor[j]) com o próximo (vetor[j+1]).
            // Se o atual for maior que o próximo, eles precisam ser trocados para manter a ordem crescente.

            temp = vetor[j];
            // Salva o valor de vetor[j] temporariamente para realizar a troca.

            vetor[j] = vetor[j+1];
            // Move o valor de vetor[j+1] para vetor[j], efetivamente realizando a troca.

            vetor[j+1] = temp;
            // Atribui o valor temporário (vetor[j] original) para vetor[j+1].
            // Agora os elementos estão trocados, com o menor valor à esquerda e o maior à direita.
        }
    }
    // Ao final de cada iteração do loop interno, o maior valor da parte não ordenada do vetor
    // será "empurrado" para o final do vetor.
}

}

// Implementação da função para imprimir o vetor
void imprimirVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}