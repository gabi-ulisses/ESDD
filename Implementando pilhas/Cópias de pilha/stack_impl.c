#include "stack.h"

struct stack {
    int top;
    int maxsize;
    T_Info* elements; 
};

Pilha init(int maxsize){
    Pilha stack = NULL;
    if(maxsize > 0){
        stack = malloc(sizeof(struct stack)); 
        if (stack != NULL){ 
            stack->top = -1; 
            stack->maxsize = maxsize;
            stack->elements = malloc(sizeof(T_Info) * maxsize); // Declarando o vetor
            if (stack->elements == NULL){ 
                free(stack);
                stack = NULL;
            }
        }
    }
    return stack;
}

bool isFull(Pilha stack){
    if (stack == NULL){
        return false;
    }
    
    return stack->top == stack->maxsize - 1; // Se o topo for igual ao tamanho da pilha -1...a pilha está cheia
}

bool isEmpty(Pilha stack){
   if (stack != NULL){
        return stack->top == -1; //  Se o topo for -1 a pilha está vazia (pois -1 é a nossa posição inicial)...
   }
   return false;
}

bool push(Pilha stack, T_Info element){
    if (stack != NULL){
        if (!isFull(stack)){ // Se a stack NÃO estiver cheia...
           stack->top += 1;
           stack->elements[stack->top] = element;
           return true;
        }
    }
    return false;
}

bool pop(Pilha stack, T_Info* element){
    if (stack != NULL){
        if (!isEmpty(stack)){ // Se a stack NÃO estiver vazia...
            *element = stack->elements[stack->top];
            stack->top -= 1; 
            return true;
        }
    }
    return false;
}

void destroy(Pilha stack) {
    free(stack->elements);
    free(stack);
}
