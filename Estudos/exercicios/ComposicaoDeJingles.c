#include <stdio.h>
#include <string.h>

double calcularDuracao(char simbolo) {
    double valor = 0.0;

    switch (simbolo) {
        case 'W': 
            valor = 1.0; 
            break;

        case 'H': 
            valor = 0.5; 
            break;

        case 'Q': 
            valor = 0.25; 
            break;

        case 'E': 
            valor = 0.125; 
            break;

        case 'S': 
            valor = 0.0625; 
            break;

        case 'T': 
            valor = 0.03125; 
            break;

        case 'X': 
            valor = 0.015625; 
            break;

        default: 
            valor = 0.0; 
            break; // Para evitar valores inválidos
    }

    return valor;
}

int main() {
    char partitura[1000];
    int contador;
    double somaDuracao;

    while (scanf("%[^\n]\n", partitura) != EOF) {
        if (strcmp(partitura, "*") == 0)
            break;

        contador = 0;
        somaDuracao = 0.0;

        for (int i = 0; i < strlen(partitura); ++i) {
            if (partitura[i] == '/') {
                if (somaDuracao == 1.0)
                    ++contador;
                somaDuracao = 0.0;
            } else {
                somaDuracao += calcularDuracao(partitura[i]);
            }
        }

        printf("%d\n", contador);
    }

    return 0;
}