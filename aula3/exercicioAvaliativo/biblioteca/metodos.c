#include "metodos.h"
#include <stdio.h>
#include <time.h>

Contagem BubbleSort(int vetor[], int size){
    Contagem contagem = {0, 0};  // Inicializa comparações e trocas

    int i, continua, aux;
    continua = 1;

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    inicio = clock();

    do {
        continua = 0;

        for (i = 0; i < size - 1; i++) {
            contagem.comparacoes++;  // Incrementa o contador de comparações

            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];    
                vetor[i] = vetor[i+1]; 
                vetor[i+1] = aux;  

                continua = 1;
                contagem.trocas++;  // Incrementa o contador de trocas
            }
        }

    } while (continua); 

    fim = clock();
    tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    return contagem;
}

Contagem InsertionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  // Inicializa comparações e trocas

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    inicio = clock();

    for (int i = 1; i < size; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            contagem.comparacoes++;  // Comparação dentro do while
            vetor[j + 1] = vetor[j];  // Desloca o valor maior
            j--;
            contagem.trocas++;  // Troca (deslocamento)
        }
        contagem.comparacoes++;  // Comparação que falhou no while

        vetor[j + 1] = chave;  // Posiciona a chave
        if (j + 1 != i) {
            contagem.trocas++;  // Conta a troca final
        }
    }

    fim = clock();
    tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    return contagem;
}

Contagem SelectionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  // Inicializa comparações e trocas

    // Inicializa a contagem de tempo
    clock_t inicio = 0, fim = 0;
    double tempo_gasto;

    inicio = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            contagem.comparacoes++;  // Conta comparações
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }

        // Efetuar a troca somente se houver alteração
        if (min_index != i) {
            int temp = vetor[min_index];
            vetor[min_index] = vetor[i];
            vetor[i] = temp;
            contagem.trocas++;  // Conta trocas
        }
    }

    fim = clock();
    tempo_gasto = ((double)(fim - inicio))/CLOCKS_PER_SEC;

    return contagem;
}

Contagem partition(int vetor[], int low, int high) {
    Contagem contagem = {0, 0};  // Inicializa comparações e trocas
    int pivot = vetor[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        contagem.comparacoes++;
        if (vetor[j] < pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            contagem.trocas++;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[high];
    vetor[high] = temp;
    contagem.trocas++;

    return contagem;
}

Contagem QuickSort(int vetor[], int low, int high) {
    Contagem contagem_total = {0, 0};  // Inicializa comparações e trocas

    if (low < high) {
        // Chama partition e recebe a contagem
        Contagem contagem_partition = partition(vetor, low, high);
        contagem_total.comparacoes += contagem_partition.comparacoes;
        contagem_total.trocas += contagem_partition.trocas;

        // Calcula o índice do pivot
        int pi = low + contagem_partition.comparacoes; // Corrigido para usar a contagem

        // Chama recursivamente para as duas metades
        Contagem contagem_esq = QuickSort(vetor, low, pi - 1);
        Contagem contagem_dir = QuickSort(vetor, pi + 1, high);

        // Acumula as contagens das chamadas recursivas
        contagem_total.comparacoes += contagem_esq.comparacoes + contagem_dir.comparacoes;
        contagem_total.trocas += contagem_esq.trocas + contagem_dir.trocas;
    }

    return contagem_total; // Retorna contagem total
}

Contagem intercala(int vetor[], int inicio, int fim, int meio, int size) {
    Contagem contagem = {0, 0};  // Inicializa comparações e trocas
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Vetores temporários
    int L[n1], R[n2];

    // Copiando dados para os vetores temporários
    for (i = 0; i < n1; i++) {
        L[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    // Mesclando os vetores temporários de volta no vetor principal
    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        contagem.comparacoes++;
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        contagem.trocas++;
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
        contagem.trocas++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
        contagem.trocas++;
    }

    return contagem;
}

Contagem MergeSort(int vetor[], int inicio, int fim, int size) {
    Contagem contagem_total = {0, 0};  // Inicializa comparações e trocas

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Chamada recursiva para as duas metades
        Contagem contagem_esq = MergeSort(vetor, inicio, meio, size);
        Contagem contagem_dir = MergeSort(vetor, meio + 1, fim, size);
        Contagem contagem_inter = intercala(vetor, inicio, fim, meio, size);

        // Soma as contagens de comparações e trocas
        contagem_total.comparacoes = contagem_esq.comparacoes + contagem_dir.comparacoes + contagem_inter.comparacoes;
        contagem_total.trocas = contagem_esq.trocas + contagem_dir.trocas + contagem_inter.trocas;
    }

    return contagem_total;
}