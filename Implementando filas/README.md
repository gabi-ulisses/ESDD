# Estrutura de Dados: Fila

## Introdução

Uma fila é uma estrutura de dados abstrata que segue o princípio `FIFO (First In, First Out)`. Isso significa que o primeiro elemento adicionado à fila será o primeiro a ser removido. É como uma fila de pessoas esperando para entrar em um evento: a primeira pessoa na fila é a primeira a ser atendida.

## Operações Básicas

As operações fundamentais em uma fila são:

1. **Enqueue**: Adiciona um item ao final da fila.
2. **Dequeue**: Remove e retorna o item da frente da fila.
3. **isEmpty**: Verifica se a fila está vazia.
4. **isFull**: Verifica se a fila está cheia (em caso de implementação com capacidade limitada).
5. **Destroy**: Libera a memória alocada pela fila, garantindo que não haja vazamento de memória.

_Embora `destroy` não esteja diretamente envolvido na manipulação dos dados armazenados na fila, ela é crucial para o gerenciamento eficiente de recursos, especialmente em programas de longa duração ou que manipulam muitas filas._
