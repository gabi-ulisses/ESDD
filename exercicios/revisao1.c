/*

Um número a é dito permutação de um número b se os dígitos de a 
formam uma permutação dos dígitos de b.

(a) Faça uma função conta_digitos que dados um inteiro n e um inteiro d, 
0 < d <= 9, devolve quantas vezes o dígito d aparece em n.

(b) Usando a função do item anterior, faça um programa que lê dois 
inteiros positivos a e b e responda se a é p

*/

#include <stdio.h>

int conta_digitos(int d, int n);

int main(){
    int d = 3, n = 4331;

    conta_digitos(d, n);
}

int conta_digitos(int d, int n){

    int resto;
    int conta;

   while (n > 10){
        resto = n % 10;
        if (resto == d){
            conta++;
        }
   }

   return conta ++;
    
}
