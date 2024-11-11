#include <stdio.h>

void counting_sort(int X[], int n) {
    // 1. Encontrar o maior valor no vetor X para definir o tamanho do vetor count
    int max = X[0];
    for (int i = 1; i < n; i++) {
        if (X[i] > max) {
            max = X[i];
        }
    }

    // 2. Criar o vetor count com tamanho adequado
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // 3. Preencher o vetor count, contando as ocorrências de cada valor em X
    for (int i = 0; i < n; i++) {
        count[X[i]]++;
    }

    // 4. Modificar o vetor count para armazenar a quantidade de elementos menores que cada valor
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 5. Criar o vetor de saída
    int output[n];
    
    // 6. Colocar os elementos no vetor de saída, garantindo a estabilidade
    for (int i = n - 1; i >= 0; i--) {
        output[count[X[i]] - 1] = X[i];
        count[X[i]]--;  // Decrementar para o próximo valor igual
    }

    // 7. Copiar o vetor de saída de volta para o vetor X
    for (int i = 0; i < n; i++) {
        X[i] = output[i];
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int X[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    int n = sizeof(X) / sizeof(X[0]);

    printf("Vetor original: ");
    print_array(X, n);

    counting_sort(X, n);

    printf("Vetor ordenado: ");
    print_array(X, n);

    return 0;
}
