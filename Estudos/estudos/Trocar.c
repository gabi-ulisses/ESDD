#include <stdio.h>

// Função que troca os valores de duas variáveis
void trocarValores(int *a, int *b) {
    int temp = *a;  // Armazena o valor de 'a' em uma variável temporária
    *a = *b;        // Atribui o valor de 'b' a 'a'
    *b = temp;      // Atribui o valor de 'temp' (antigo 'a') a 'b'
}

int main() {
    int A, B;
    
    // Lê os dois valores inteiros
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    
    // Exibe os valores antes da troca
    printf("Antes da troca: A = %d, B = %d\n", A, B);
    
    // Chama a função para trocar os valores
    trocarValores(&A, &B);  // Passa os endereços de A e B para a função
    
    // Exibe os valores após a troca
    printf("Após a troca: A = %d, B = %d\n", A, B);
    
    return 0;
}
