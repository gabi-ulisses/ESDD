#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct racional * T_racional;

T_racional criarRacional(int numerador, int denominador);

void destruirRacional(T_racional racionalPtr);

T_racional somaRacional(T_racional racionalAPtr, T_racional racionalBPtr);

T_racional multiplicaRacional(T_racional racionalAPtr, T_racional racionalBPtr);

void imprimeRacional(T_racional racionalPtr);

T_racional entradaRacional();

void simplificaRacional(T_racional* racionalPtr);

bool ehValidoRacional(T_racional racionalPtr);

int mdc(int a, int b);
