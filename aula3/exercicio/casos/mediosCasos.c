#include <stdlib.h>

void preencherCasoMedio(int vetor[], int size){

    int i;

    for (i = 0; i < size; i++){
        vetor[i] = rand() % size; 
    }

}