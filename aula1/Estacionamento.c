#include <stdio.h>
#include <stdlib.h>
#define NROVAGAS 3

typedef struct{
    int vetor[NROVAGAS];
    int qtdade;
}Estacionamento;

Estacionamento criaEstacionamento(){
    Estacionamento variavel;
    variavel.qtdade = -1;
    return variavel;
};

int estaCheio (Estacionamento variavel){
    return variavel.qtdade == NROVAGAS-1?1:0;
}

void mostraEstacionamento(Estacionamento garage){
    int i;
    printf("\nCarros estacionados: ");
    if(!(garage.qtdade < 0)){
        for (i=0; i<garage.qtdade;i++){
            printf("%d - ", garage.vetor[i]);
        }
        printf("%d", garage.vetor[i]);
    }
}

int main(){
    Estacionamento garagem;

    garagem = criaEstacionamento();
    garagem = saiCarro(garagem);
    garagem = entraCarro(garagem, 1234);
    garagem = entraCarro(garagem, 2345);
    garagem = entraCarro(garagem, 3456);
    garagem = entraCarro(garagem, 4567);
    garagem = saiCarro(garagem);
    garagem = entraCarro(garagem, 9876);
    garagem = entraCarro(garagem, 8765);
    garagem = saiCarro(garagem);
    garagem = saiCarro(garagem);

    return 0;
}


Estacionamento entraCarro(Estacionamento garage, int placa){

}

Estacionamento saiCarro(Estacionamento garage){

}