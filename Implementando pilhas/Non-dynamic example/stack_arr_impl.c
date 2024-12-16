#include "stack_arr.h"
#define MAXSIZE 100

/*
* Struct não dinâmico
*/
struct stack {
    int top;
    int maxsize;
    T_Info elements[MAXSIZE]; 
};

T_Stack init(int maxsize){
    T_Stack stack = NULL;
    if(maxsize > 0){
        stack = malloc(sizeof(struct stack)); 
        if (stack != NULL){ 
            stack->top = -1; 
            if (maxsize > MAXSIZE){
                stack->maxsize = MAXSIZE;
            }else{
                stack->maxsize = maxsize;
            }
        }
    }
    return stack;
}

bool isFull(T_Stack stack){
    if (stack == NULL){
        return false;
    }
    
    return stack->top == stack->maxsize - 1; // Se o topo for igual ao tamanho da pilha -1...a pilha está cheia
}

bool isEmpty(T_Stack stack){
   if (stack != NULL){
        return stack->top == -1; //  Se o topo for -1 a pilha está vazia (pois -1 é a nossa posição inicial)...
   }
   return false;
}

bool push(T_Stack stack, T_Info element){
    if (stack != NULL){
        if (!isFull(stack)){ // Se a stack NÃO estiver cheia...
           stack->top += 1;
           stack->elements[stack->top] = element;
           return true;
        }
    }
    return false;
}

bool pop(T_Stack stack, T_Info* element){
    if (stack != NULL){
        if (!isEmpty(stack)){ // Se a stack NÃO estiver vazia...
            *element = stack->elements[stack->top];
            stack->top -= 1; 
        }
    }
    return false;
}

void destroy(T_Stack stack) {
    if (stack != NULL){
        free(stack);
        stack = NULL; // Evitar acessos a ponteiros de memória liberada
    }
}
