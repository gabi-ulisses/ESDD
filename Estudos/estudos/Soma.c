#include <stdio.h>

// Função que retorna a soma do dobro dos dois números
int somaDobro(int *a, int *b) {
    *a = *a * 2;  // Armazena o dobro de A em A
    *b = *b * 2;  // Armazena o dobro de B em B
    return *a + *b;  // Retorna a soma dos dois
}

int main() {
    int A, B;
    
    // Lê os valores de A e B
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    
    // Chama a função e imprime o resultado
    int resultado = somaDobro(&A, &B);
    printf("O resultado da soma do dobro é: %d\n", resultado);
    printf("Novo valor de A: %d, Novo valor de B: %d\n", A, B);
    
    return 0;
}
