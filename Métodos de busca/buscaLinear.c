#include <stdio.h>


int buscaLinear(int arr[], int tamanho, int elemento){
  for (int i = 0; i < tamanho; i++){
      if (arr[i] == elemento){
          return i;
      }
  }
  return -1;
}


int main(){
  int lista[] = {10, 20, 30, 40, 50};
  int tamanho = sizeof(lista) / sizeof(lista[0]);
  int elementoProcurado = 30;


  int resultado = buscaLinear(lista, tamanho, elementoProcurado);


  if (resultado != -1) {
      printf("O elemento foi encontrado na posição %d\n", resultado);
  }else{
      printf("O elemento não foi encontrado na lista.\n");
  }
  return 0;
}