#include "stack.h"
#include <stdio.h>

int main(){
    T_Stack pilha;

    pilha = init(5);

    for(int i = 0; i < 12; i++){
        if (push(pilha, i)){
            printf("Empilhado: %d\n", i);
        }else{
            printf("Pilha cheia\n");
        }
    }

    T_Info dado;

    while (!isEmpty(pilha)){
        if(pop(pilha, &dado)){
            printf("> %d\n", dado);
        }
    }
    

    return 0;
}