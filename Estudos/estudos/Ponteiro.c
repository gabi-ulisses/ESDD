#include <stdio.h>

int main() {
    int var1, var2;
    
    // Lê as duas variáveis inteiras
    printf("Digite o valor de var1: ");
    scanf("%d", &var1);
    
    printf("Digite o valor de var2: ");
    scanf("%d", &var2);
    
    // Ponteiros para as variáveis
    int *ptr1 = &var1;
    int *ptr2 = &var2;
    
    // Exibe os endereços de memória
    printf("Endereço de memória de var1: %p\n", &ptr1);
    printf("Endereço de memória de var2: %p\n", &ptr2);
    
    // Compara os valores e exibe o maior
    if (*ptr1 > *ptr2) {
        printf("A variável var1 tem o maior valor (%d) e o endereço %p\n", *ptr1, &ptr1);
    } else if (*ptr2 > *ptr1) {
        printf("A variável var2 tem o maior valor (%d) e o endereço %p\n", *ptr2, &ptr2);
    } else {
        printf("As duas variáveis possuem o mesmo valor (%d).\n", *ptr1);
    }
    
    return 0;
}
