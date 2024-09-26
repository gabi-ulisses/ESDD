/*

(b) Usando a função do item anterior - ContaDigitos.c - faça um programa que lê dois 
inteiros positivos a e b e responda se a é p.

*/

#include <stdio.h>

int conta_digitos(int d, int n);

int verifica_permutacao(int a, int b);

int main() {

    int a, b;

    printf("Digite dois números positivos para verificar se há permutação...\n");
    printf("\nPrimeiro número: ");
    scanf("%d", &a);
    printf("\nSegundo número: ");
    scanf("%d", &b);


    if (verifica_permutacao(a, b)) {
        printf("\n%d é uma permutação de %d.\n", a, b);
    } else {
        printf("\n%d não é uma permutação de %d.\n", a, b);
    }

    return 0;
}

int conta_digitos(int d, int n){

    int resto;
    int conta = 0;

   while (n > 0){
        resto = n % 10;
        if (resto == d){
            conta++;
        }
    n = n / 10;
   }

   return conta;
    
}

int verifica_permutacao(int a, int b) {

    for (int d = 0; d <= 9; d++) {
        // Verifica se a contagem do dígito d em a é igual à contagem em b
        if (conta_digitos(d, a) != conta_digitos(d, b)) {
            return 0;  // Se algum dígito não tiver a mesma contagem, não são permutações
        }
    }
    return 1;  // Se todas as contagens forem iguais, são permutações
}