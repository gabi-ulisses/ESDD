#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verificarSubsequencia(char *subString, char *stringPrincipal);

int main() {

    int i, j;
    char stringPrincipal[100060];
    char subString[1100];
    int quantidadeCasos, quantidadeStrings;

    scanf("%d", &quantidadeCasos);
    scanf("%s", stringPrincipal);

    for (i = 0; i < quantidadeCasos; ++i) {

        scanf("%d", &quantidadeStrings);

        for (j = 0; j < quantidadeStrings; ++j) {

            scanf("%s", subString);

            if (verificarSubsequencia(subString, stringPrincipal)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

        scanf("%s", stringPrincipal);
    }

    return 0;
}

bool verificarSubsequencia(char *subString, char *stringPrincipal) {

    int i, j;
    int tamSubString, tamStringPrincipal;

    tamSubString = strlen(subString);
    tamStringPrincipal = strlen(stringPrincipal);

    for (i = 0, j = 0; i < tamStringPrincipal && j < tamSubString; i++) {
        if (subString[j] == stringPrincipal[i]) {
            j++;
        }
    }

    return (j == tamSubString);
}