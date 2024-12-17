#include "stack.h"
#include <stdio.h>

int main(){
    int a;
    Pilha p1, p2;
    T_Info qtd;

    printf("\nNúmero de elementos da pilha: ");
    scanf("%d", &qtd);

    p1 = init(qtd);

    for (int i = 0; i < qtd; i++){
        printf("\nPosição %d: ", i);
        scanf("%d", &a);
        push(p1, a);
        printf("Elemento %d empilhado com sucesso!\n", a);
    }

    p2 = init(qtd);

    duplicar_pilha(p1, p2, qtd);

    int resultado = max_stack(p1, p2, qtd);

    if (resultado == 0) {
        printf("As pilhas têm o mesmo tamanho.\n");
    } else if (resultado > 0) {
        printf("A primeira pilha é maior.\n");
    } else {
        printf("A segunda pilha é maior.\n");
    }

    T_Info element;

    while (!isEmpty(p1)){
        if(pop(p1, &element)){
            printf("> %d\n", element);
        }
    }
    
    inverter(p1, qtd);

    while (!isEmpty(p1)){
        if(pop(p1, &element)){
            printf("> %d\n", element);
        }
    }
    
    printf("Pilha 1 invertida!");

    if (iguais(p1, p2, qtd)){
        printf("\nAs pilhas são iguais!\n");
    }else{
        printf("\nAs pilhas não são iguais!\n");
    }
    
    return 0;
}


void duplicar_pilha(Pilha p1, Pilha p2, T_Info qtd) {
    T_Info element;
    Pilha temp = init(qtd);
    int cont = 0;

    while (!isEmpty(p1)) {
        pop(p1, &element);
        push(temp, element);
    }

    while (!isEmpty(temp)) {
        pop(temp, &element);
        push(p1, element);
        push(p2, element);
    }

    destroy(temp);
}

int max_stack(Pilha p1, Pilha p2, T_Info qtd){
    int cont1 = 0;
    int cont2 = 0;
    T_Info element;
    Pilha temp1 = init(qtd);
    Pilha temp2 = init(qtd);

    while (!isEmpty(p1)){
        pop(p1, &element);
        push(temp1, element);
        cont1++;
    }

    while (!isEmpty(p2)){
        pop(p2, &element);
        push(temp2, element);
        cont2++;
    }

    while (!isEmpty(temp1)){
        pop(temp1, &element);
        push(p1, element);
    }
    while (!isEmpty(temp2)){
        pop(temp2, &element);
        push(p2, element);
    }

    destroy(temp1);
    destroy(temp2);

    if (cont1 == cont2) {
        return 0;
    } else if (cont1 > cont2) {
        return 1;
    } else {
        return -1;
    }
}

void inverter(Pilha p1, T_Info qtd){

    T_Info element;
    Pilha temp = init(qtd);

    while (!isEmpty(p1)){
        pop(p1, &element);
        push(temp, element);
    }

    while (!isEmpty(temp)){
        pop(temp, &element);
        push(p1, element);
    }

    destroy(temp);
}

bool iguais(Pilha p1, Pilha p2, T_Info qtd) {

    T_Info element1, element2;
    Pilha temp = init(qtd); 
    bool saoIguais = true;

    while (!isEmpty(p1) && !isEmpty(p2)) {
        pop(p1, &element1);
        pop(p2, &element2);

        if (element1 != element2) {
            saoIguais = false;
        }

        push(temp, element1);
        push(temp, element2);
    }

    if (!isEmpty(p1) || !isEmpty(p2)) {
        saoIguais = false;
    }

    while (!isEmpty(temp)) {
        pop(temp, &element2);
        push(p2, element2);
        pop(temp, &element1);
        push(p1, element1);
    }

    destroy(temp);

    return saoIguais;
}
