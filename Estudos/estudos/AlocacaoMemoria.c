#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int n, par = 0, impar = 0;
    
    // Lê o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    // Aloca dinamicamente o vetor
    vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }
    
    // Lê os valores do vetor
    for (int i = 0; i < n; i++) {
        printf("Digite o valor para o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    // Imprime os valores e conta os pares e ímpares
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
        if (vetor[i] % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }
    
    printf("Quantidade de pares: %d\n", par);
    printf("Quantidade de ímpares: %d\n", impar);
    
    // Libera a memória alocada
    free(vetor);
    
    return 0;
}
