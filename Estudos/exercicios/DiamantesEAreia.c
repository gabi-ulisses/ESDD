#include <stdio.h>
#include <string.h>

int contar_diamantes(const char *elemento) {
    int abertura = 0, diamantes = 0;

    for (int i = 0; i < strlen(elemento); i++) {
        if (elemento[i] == '<') {
            abertura++;
        } else if (elemento[i] == '>' && abertura > 0) {
            abertura--;
            diamantes++;
        }
    }

    return diamantes;
}

int main() {
    int quantidadeCasos;
    char elemento[1001];

    scanf("%d", &quantidadeCasos);
    getchar(); 

    for (int i = 0; i < quantidadeCasos; i++) {
        fgets(elemento, 1001, stdin);
        elemento[strcspn(elemento, "\n")] = '\0'; 

        int resultado = contar_diamantes(elemento);
        printf("%d\n", resultado);
    }

    return 0;
}