# Estrutura de Dados: Pilha

## Introdução

Uma pilha é uma estrutura de dados abstrata que segue o princípio `LIFO (Last In, First Out)`. Isso significa que o último elemento adicionado à pilha será o primeiro a ser removido. É como uma pilha de pratos: você coloca novos pratos no topo e remove primeiro o prato que está no topo.

## Operações Básicas

As operações fundamentais em uma pilha são:

1. **Push**: Adiciona um item ao topo da pilha.
2. **Pop**: Remove e retorna o item do topo da pilha.
3. **isEmpty**: Verifica se a pilha está vazia.
4. **isFull**: Verifica se a pilha está cheia (em caso de implementação com capacidade limitada).
5. **Destroy**: Libera a memória alocada pela pilha, garantindo que não haja vazamento de memória.


_Embora `destroy` não esteja diretamente envolvido na manipulação dos dados armazenados na pilha, ela é crucial para o gerenciamento eficiente de recursos, especialmente em programas de longa duração ou que manipulam muitas pilhas._