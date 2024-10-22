#include "metodos.h"
#include <stdio.h>

Contagem BubbleSort(int vetor[], int size){

    Contagem contagem = {0, 0};  

    int i, aux;
    int continua = 1;

    do {
        continua = 0;

        for (i = 0; i < size - 1; i++) {

            contagem.comparacoes++; 

            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];    
                vetor[i] = vetor[i+1]; 
                vetor[i+1] = aux;  

                contagem.trocas++;
                continua = 1;
            }
        }

    }while (continua); 

    return contagem;
}

Contagem InsertionSort(int vetor[], int size) {

    Contagem contagem = {0, 0};      

    for (int i = 1; i < size; i++) {

        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            contagem.comparacoes++; 
            vetor[j + 1] = vetor[j];  
            j--;
            contagem.trocas++;  
        }
        contagem.comparacoes++;  

        vetor[j + 1] = chave; 
        if (j + 1 != i) {
            contagem.trocas++; 
        }
    }

    return contagem;
}

Contagem SelectionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  // Inicializa contagem

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            contagem.comparacoes++;  // Conta comparações
            if (vetor[j] < vetor[min_index]) {
                min_index = j; // Atualiza o índice do menor elemento
            }
        }

        // Efetuar a troca somente se houver alteração
        if (min_index != i) {
            int aux = vetor[min_index];
            vetor[min_index] = vetor[i];
            vetor[i] = aux;
            contagem.trocas++;  // Conta trocas
        }
    }

    return contagem; // Retorna a contagem
}


Contagem QuickSort(int vetor[], int inicio, int fim) {
    Contagem contagem_total = {0, 0};  

    if (inicio < fim) {
        Contagem contagem_particao = particao(vetor, inicio, fim);

        contagem_total.comparacoes += contagem_particao.comparacoes;
        contagem_total.trocas += contagem_particao.trocas;

        int j = inicio + contagem_particao.comparacoes; 

        Contagem contagem_esq = QuickSort(vetor, inicio, j - 1);
        Contagem contagem_dir = QuickSort(vetor, j + 1, fim);

        contagem_total.comparacoes += contagem_esq.comparacoes + contagem_dir.comparacoes;
        contagem_total.trocas += contagem_esq.trocas + contagem_dir.trocas;
    }

    return contagem_total; // Retorna contagem total
}

Contagem particao(int vetor[], int inicio, int fim) {
    Contagem contagem = {0, 0};  
    int pivot = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        contagem.comparacoes++;
        if (vetor[j] < pivot) {
            i++;
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            contagem.trocas++;
        }
    }

    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    contagem.trocas++;

    return contagem;
}

Contagem MergeSort(int vetor[], int inicio, int fim, int size) {
    Contagem contagem_total = {0, 0};  

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        Contagem contagem_esq = MergeSort(vetor, inicio, meio, size);
        Contagem contagem_dir = MergeSort(vetor, meio + 1, fim, size);
        Contagem contagem_inter = intercala(vetor, inicio, fim, meio, size);

        contagem_total.comparacoes = contagem_esq.comparacoes + contagem_dir.comparacoes + contagem_inter.comparacoes;
        contagem_total.trocas = contagem_esq.trocas + contagem_dir.trocas + contagem_inter.trocas;
    }

    return contagem_total;
}

Contagem intercala(int vetor[], int inicio, int fim, int meio, int size) {
    Contagem contagem = {0, 0};  
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

