/*

Um número a é dito permutação de um número b se os dígitos de a 
formam uma permutação dos dígitos de b.

(a) Faça uma função conta_digitos que dados um inteiro n e um inteiro d, 
0 < d <= 9, devolve quantas vezes o dígito d aparece em n.

*/

#include <stdio.h>

int conta_digitos(int d, int n);

int main(){
    int d = 3, n = 4331;
    int resultado;

    resultado = conta_digitos(d, n);
    printf("O dígito %d aparece %d vezes em %d.\n", d, resultado, n);

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
