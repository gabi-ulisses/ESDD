#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int n = 10, count = 0, numero;
    
    // Aloca o vetor inicial com 10 elementos
    vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }
    
    // Lê os números até o usuário digitar 0
    printf("Digite números inteiros. Digite 0 para encerrar.\n");
    while (1) {
        printf("Digite um número: ");
        scanf("%d", &numero);
        
        if (numero == 0) {
            break;
        }
        
        if (count == n) {
            n += 10;  // Expande o vetor para mais 10 elementos
            vetor = (int *)realloc(vetor, n * sizeof(int));
            if (vetor == NULL) {
                printf("Erro de alocação de memória.\n");
                return 1;
            }
        }
        
        vetor[count++] = numero;  // Armazena o número no vetor
    }
    
    // Imprime o vetor
    printf("Vetor lido: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Libera a memória alocada
    free(vetor);
    
    return 0;
}
