#include <stdio.h>

int busca(int val, int lista[14]) {
    int inicio = 0;
    int fim = 13;  // Tamanho do array - 1
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        printf("Visitando o elemento: %d\n", lista[meio]);

        if (lista[meio] == val) {
            return meio;  // Valor encontrado
        } else if (lista[meio] < val) {
            inicio = meio + 1;  // Procurar na metade direita
        } else {
            fim = meio - 1;  // Procurar na metade esquerda
        }
    }

    return -1;  // Valor não encontrado
}

int main() {
    int lista[14] = {5, 18, 27, 33, 44, 49, 54, 67, 69, 72, 79, 86, 87, 92};
    int resultado = busca(79, lista);

    if (resultado != -1) {
        printf("Valor encontrado no índice: %d\n", resultado);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
