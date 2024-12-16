#include <stdlib.h>
#include <stdbool.h>

typedef struct stack* T_Stack;

typedef int T_Info; 

T_Stack init(int maxsize);

bool isFull(T_Stack stack);

bool isEmpty(T_Stack stack);

/*
* Insere o elemento no topo da pilha
*/
bool push(T_Stack stac, T_Info element);

/*
* Remove o elemento no topo da pilha
*/
bool pop(T_Stack stack, T_Info* element); // Recebe uma pilha e um ponteiro para retirar o elemento que está no topo e retorna true ou false

void destroy(T_Stack stack);