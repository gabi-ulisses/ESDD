#include "racional.h"

struct racional{
 int numerador;
 int denominador;
};

T_racional criarRacional(int numerador, int denominador){

    T_racional ptr;

    ptr = malloc(sizeof(struct racional));
    
    if(ptr != NULL){
       ptr->numerador = numerador;
       ptr->denominador = denominador;

       if (!ehValidoRacional(ptr)){
            ptr->numerador = 0; 
            ptr->denominador = 1;
       }
       
    }

    return ptr;
}

void destruirRacional(T_racional racionalPtr){
    free(racionalPtr);
}

T_racional somaRacional(T_racional racionalAPtr, T_racional racionalBPtr){

    T_racional soma;

    soma = criarRacional(0,1); // É necessário reservar o espaço na memória / inicializar a variável soma.

    soma->numerador = (racionalAPtr->numerador * racionalBPtr->denominador) + (racionalBPtr->numerador * racionalAPtr->denominador);

    soma->denominador = racionalAPtr->denominador * racionalBPtr->denominador;

    simplificaRacional(&soma);

    return soma;

}

T_racional multiplicaRacional(T_racional racionalAPtr, T_racional racionalBPtr){
    T_racional ptr;

    ptr = criarRacional(0,1);

    ptr->numerador = racionalAPtr->numerador * racionalBPtr->numerador;
    ptr->denominador = racionalAPtr->denominador * racionalBPtr->denominador;

    simplificaRacional(&ptr);

    return ptr;
}

void imprimeRacional(T_racional racionalPtr){

    printf("%d/%d", racionalPtr->numerador, racionalPtr->denominador);

}

T_racional entradaRacional(){
    int numerador, denominador;

    scanf("%d", &numerador);
    scanf("%d", &denominador);

    T_racional ptr = criarRacional(numerador, denominador);

    return ptr;
}

void simplificaRacional(T_racional* racionalPtr){

    int vMDC = mdc((*racionalPtr)->numerador,(*racionalPtr)->denominador); // Ponteiro para ponteiro = Endereço de memória de um endereço de memória

    (*racionalPtr)->numerador = (*racionalPtr)->numerador / vMDC;
    (*racionalPtr)->denominador = (*racionalPtr)->denominador / vMDC;
}

bool ehValidoRacional(T_racional racionalPtr){

    return racionalPtr->denominador != 0;
    
}

int mdc(int a, int b){

    int resto;

    do{
       resto = a % b;
       a = b;
       b = resto;
    } while (resto != 0);

    return a;
}