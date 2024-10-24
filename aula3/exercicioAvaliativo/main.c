#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000

void Sort(int vetor[], int tamanho, int opcaoOrdenacao);
void copiaVetor(int origem[], int destino[], int size);

// Métodos:

typedef struct {
    long long int comparacoes;
    long long int trocas;
} Contagem;

Contagem BubbleSort(int vetor[], int size);
Contagem InsertionSort(int vetor[], int size);
Contagem SelectionSort(int vetor[], int size);
Contagem MergeSort(int v[], int left, int right);
Contagem intercala(int v[], int left, int right);
Contagem QuickSort(int vetor[], int low, int high);
void troca(int* a, int* b);
int particiona(int vetor[], int low, int high, Contagem* contagem);

// Casos:

void preencherMelhorCaso(int vetor[], int size);
void preencherCasoMedio(int vetor[], int size);
void preencherPiorCaso(int vetor[], int size);

int main(){

    int *vetor;  // Ponteiro para o vetor
    int tamanho[] = {1000, 100000, 1000000};
    int opcaoTamanho = 0, opcaoOrdenacao = 0, size;

    printf("Vamos testar alguns métodos de classificação!\n");
    printf("Escolha o tamanho do vetor desejado: \n\n");
    printf("1 - Vetor com 1.000 elementos: \n");
    printf("2 - Vetor com 100.000 elementos: \n");
    printf("3 - Vetor com 1.000.000 elementos: \n");

    printf("\nOpção escolhida: ");
    scanf("%d", &opcaoTamanho);

    if (opcaoTamanho < 1 || opcaoTamanho > 3) {
        printf("Opção inválida!\n");
        return 1;
    }

    size = tamanho[opcaoTamanho - 1];
    vetor = (int *)malloc(size * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("\nEscolha o algoritmo de ordenação:\n");
    printf("1 - BubbleSort\n");
    printf("2 - InsertionSort\n");
    printf("3 - SelectionSort\n");
    printf("4 - MergeSort\n");
    printf("5 - QuickSort\n");

    printf("\nOpção escolhida: ");
    scanf("%d", &opcaoOrdenacao);

    if (opcaoOrdenacao < 1 || opcaoOrdenacao > 5) {
        printf("Opção de algoritmo inválida!\n");
        free(vetor);
        return 1;
    }

    printf("\nMelhor caso:\n\n");
    preencherMelhorCaso(vetor, size);
    Sort(vetor, size, opcaoOrdenacao);

    printf("\nCaso médio:\n\n");
    preencherCasoMedio(vetor, size);
    Sort(vetor, size, opcaoOrdenacao);

    printf("\nPior caso:\n\n");
    preencherPiorCaso(vetor, size);
    Sort(vetor, size, opcaoOrdenacao);

    free(vetor);  // Liberar a memória

    return 0;
}

void Sort(int vetor[], int size, int opcaoOrdenacao) {
    int vetorCopia[size];
    Contagem resultado;
    clock_t inicio, fim;
    double tempo_gasto;

    copiaVetor(vetor, vetorCopia, size);

    switch(opcaoOrdenacao) {
        case 1:
            printf("Executando BubbleSort...\n\n");
            inicio = clock();
            resultado = BubbleSort(vetorCopia, size);
            fim = clock();
            break;
        case 2:
            printf("Executando InsertionSort...\n\n");
            inicio = clock();
            resultado = InsertionSort(vetorCopia, size);
            fim = clock();
            break;
        case 3:
            printf("Executando SelectionSort...\n\n");
            inicio = clock();
            resultado = SelectionSort(vetorCopia, size);
            fim = clock();
            break;
        case 4:
            printf("Executando MergeSort...\n\n");
            inicio = clock();
            resultado = MergeSort(vetorCopia, 0, size - 1);
            fim = clock();
            break;
        case 5:
            printf("Executando QuickSort...\n\n");
            inicio = clock();
            resultado = QuickSort(vetorCopia, 0, size - 1);
            fim = clock();
            break;
        default:
            printf("Opção de algoritmo inválida!\n");
            return;
    }

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Comparações: %lld | Trocas: %lld | Tempo de execução: %.5f segundos\n\n", 
           resultado.comparacoes, resultado.trocas, tempo_gasto);
}

void copiaVetor(int origem[], int destino[], int size) {
    for (int i = 0; i < size; i++) {
        destino[i] = origem[i];
    }
}

// Casos

void preencherMelhorCaso(int vetor[], int size){
    for (int i = 0; i < size; i++){
        vetor[i] = i; 
    }
}

void preencherCasoMedio(int vetor[], int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        vetor[i] = rand() % size; 
    }
}

void preencherPiorCaso(int vetor[], int size){
    for (int i = 0; i < size; i++){
        vetor[i] = size - i - 1;
    }
}

// Métodos de ordenação

Contagem BubbleSort(int vetor[], int size) {
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
    Contagem contagem = {0, 0};  // Inicializa as contagens de comparações e trocas

    for (int i = 1; i < size; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Compara a chave com os elementos anteriores
        while (j >= 0) {
            contagem.comparacoes++;  // Contagem de comparações dentro do while
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];  // Move o elemento para a direita
                contagem.trocas++;  // Conta a movimentação do elemento
                j--;
            } else {
                break;  // Não precisa mais continuar comparando
            }
        }
        // Insere a chave na posição correta
        vetor[j + 1] = chave;
        // Troca da chave não deve ser contada novamente
    }

    return contagem;
}


Contagem SelectionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            contagem.comparacoes++;  
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int aux = vetor[min_index];
            vetor[min_index] = vetor[i];
            vetor[i] = aux;
            contagem.trocas++;  
        }
    }

    return contagem;  
}

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int low, int high, Contagem* contagem) {
    int random_pivot_index = low + rand() % (high - low + 1);
    troca(&vetor[random_pivot_index], &vetor[high]);  

    int pivot = vetor[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        contagem->comparacoes++;
        if (vetor[j] < pivot) {
            i++;
            troca(&vetor[i], &vetor[j]);
            contagem->trocas++;
        }
    }
    troca(&vetor[i + 1], &vetor[high]);
    contagem->trocas++;
    return (i + 1);
}

Contagem QuickSort(int vetor[], int low, int high) {
    Contagem contagem = {0, 0};

    if (low < high) {
        int pi = particiona(vetor, low, high, &contagem);  
        Contagem contagem_esq = QuickSort(vetor, low, pi - 1);  
        Contagem contagem_dir = QuickSort(vetor, pi + 1, high);  

        contagem.comparacoes += contagem_esq.comparacoes + contagem_dir.comparacoes;
        contagem.trocas += contagem_esq.trocas + contagem_dir.trocas;
    }
    return contagem;
}

Contagem intercala(int v[], int left, int right){
    Contagem contagem = {0, 0};

    int meio = (left + right) / 2;
    int i = left;
    int j = meio + 1;
    int k = 0;
    int temp[right - left + 1];

    while (i <= meio && j <= right) {
        contagem.comparacoes++;
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
        contagem.trocas++;
    }

    while (i <= meio) {
        temp[k++] = v[i++];
        contagem.trocas++;
    }

    while (j <= right) {
        temp[k++] = v[j++];
        contagem.trocas++;
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        v[i] = temp[k];
        contagem.trocas++;
    }

    return contagem;
}

Contagem MergeSort(int v[], int left, int right) {
    Contagem contagem = {0, 0};

    if (left < right) {
        int meio = (left + right) / 2;
        Contagem contagem_esq = MergeSort(v, left, meio); 
        Contagem contagem_dir = MergeSort(v, meio + 1, right);
        Contagem contagem_merge = intercala(v, left, right);

        contagem.comparacoes = contagem_esq.comparacoes + contagem_dir.comparacoes + contagem_merge.comparacoes;
        contagem.trocas = contagem_esq.trocas + contagem_dir.trocas + contagem_merge.trocas;
    }

    return contagem;
}