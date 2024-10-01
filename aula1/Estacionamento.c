/*

Considere um estacionamento no centro da cidade. O 
estacionamento foi implementado em um terreno estreito que 
permite apenas que os carros sejam estacionados em fila, ou 
seja, um atrás do outro. 

Além disso, o estacionamento possui acesso a duas ruas, ou 
seja, é possível atravessar de uma rua a outra por dentro do 
estacionamento. Assim, o proprietário definiu que a entrada do 
estacionamento se dá por uma rua e a saída por outra. 

*/


#include <stdio.h>
#include <stdlib.h>
#define NROVAGAS 3

// Declaração de variável heterogênea
struct estacionamento{ 
    int vetor[NROVAGAS];
    int qtdade;
};

struct estacionamento criaEstacionamento();

int estaCheio(struct estacionamento variavel);

void mostraEstacionamento(struct estacionamento garage);

struct estacionamento entraCarro(struct estacionamento garage, int placa);

struct estacionamento saiCarro(struct estacionamento garage);

int main(){

    struct estacionamento garagem;

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

struct estacionamento criaEstacionamento(){
    struct estacionamento variavel;
    variavel.qtdade = -1; // Estacionamento vazio
    return variavel;
}

int estaCheio(struct estacionamento variavel){
    return variavel.qtdade == NROVAGAS - 1 ? 1 : 0; // Se a quantidade for igual a 2, Estacionamento = Cheio
}

void mostraEstacionamento(struct estacionamento garage){
    int i;
    printf("\nCarros estacionados: ");
    if (!(garage.qtdade < 0))
    {
        for (i = 0; i < garage.qtdade; i++)
        {
            printf("%d - ", garage.vetor[i]);
        }
        printf("%d", garage.vetor[i]);
    }
}

struct estacionamento entraCarro(struct estacionamento garage, int placa){

    if (!estaCheio(garage)){
        garage.qtdade++;
        garage.vetor[garage.qtdade] = placa;
        printf("\nEntrou: %d", placa);
    }else{
        printf("\nEstacionamento cheio!");
    }
    
    mostraEstacionamento(garage);
    return garage;
    
}

struct estacionamento saiCarro(struct estacionamento garage){
    int i;
    if ( garage.qtdade > -1){
        printf("\nSaiu: %d", garage.vetor[0]);
        for ( i = 0; i < NROVAGAS-1; i++){
            garage.vetor[i] =  garage.vetor[i+1];
        }
        garage.qtdade -= 1;
    }else{
        printf("\nEstacionamento vazio!");
    }

    mostraEstacionamento(garage);
    return garage;
}