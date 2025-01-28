#include <stdio.h>
#include "lista.h"

int main(){
    List lista = create();

    insert(lista, "Matheus");
    insert(lista, "Gabrielle");
    insert(lista, "Gabriel");
    insertAtBeggining(lista, "Eduardo");

    for (int i = 0; i < size(lista); i++){
        printf("%s \n", getIntoAt(lista, i));
    }
    

    return 0;
}
