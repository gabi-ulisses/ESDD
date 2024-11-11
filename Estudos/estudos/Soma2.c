#include <stdio.h>

// Função que soma A e B, armazenando o resultado em A
void somaEmA(int *a, int *b) {
    *a = *a + *b;  // A recebe a soma de A e B
}

int main() {
    int A, B;
    
    // Lê os valores de A e B
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    
    // Chama a função para somar e modificar A
    somaEmA(&A, &B);
    
    // Exibe os valores de A e B
    printf("Resultado: A = %d, B = %d\n", A, B);
    
    return 0;
}
