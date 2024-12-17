#include <stdlib.h>
#include <stdbool.h>

typedef struct stack* Pilha;

typedef int T_Info; 

Pilha init(int maxsize);

bool isFull(Pilha stack);

bool isEmpty(Pilha stack);

/*
* Insere o elemento no topo da pilha
*/
bool push(Pilha stack, T_Info element);

/*
* Remove o elemento no topo da pilha
*/
bool pop(Pilha stack, T_Info* element); // Recebe uma pilha e um ponteiro para retirar o elemento que está no topo e retorna true ou false

void destroy(Pilha stack);

void duplicar_pilha(Pilha p1, Pilha p2, T_Info qtd);

int max_stack(Pilha p1, Pilha p2, T_Info qtd);

void inverter(Pilha p1, T_Info qtd);

bool iguais(Pilha p1, Pilha p2, T_Info qtd);