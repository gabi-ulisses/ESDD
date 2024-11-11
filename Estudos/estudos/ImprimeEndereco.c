#include <stdio.h>

int main() {
    float vetor[10];
    
    // Lê os valores do vetor
    for (int i = 0; i < 10; i++) {
        printf("Digite o valor para o vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
    }
    
    // Imprime os endereços de memória de cada posição
    for (int i = 0; i < 10; i++) {
        printf("Endereço de vetor[%d]: %p\n", i, &vetor[i]);
    }
    
    return 0;
}
