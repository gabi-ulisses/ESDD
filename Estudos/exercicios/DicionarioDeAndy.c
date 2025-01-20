#include <stdio.h>
#include <string.h>
#include <ctype.h>

void processarString(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[j] = tolower(str[i]);
            j++;
        } else {
            str[j] = ' ';
            j++;
        }
    }
    str[j] = '\0';
}

void ordenarPalavras(char palavras[][50], int quantidade) {
    char temp[50];
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (strcmp(palavras[i], palavras[j]) > 0) {
                strcpy(temp, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], temp);
            }
        }
    }
}

int main() {
    char entrada[10005];
    char palavras[1000][50];
    int quantidadePalavras = 0;

    while (scanf("%s", entrada) == 1) {
        processarString(entrada);

        char *token = strtok(entrada, " ");
        while (token != NULL) {
            int encontrada = 0;

            for (int i = 0; i < quantidadePalavras; i++) {
                if (strcmp(palavras[i], token) == 0) {
                    encontrada = 1;
                    break;
                }
            }

            if (encontrada == 0) {
                if (quantidadePalavras < 1000) {
                    strcpy(palavras[quantidadePalavras], token);
                    quantidadePalavras++;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    ordenarPalavras(palavras, quantidadePalavras);

    for (int i = 0; i < quantidadePalavras; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}