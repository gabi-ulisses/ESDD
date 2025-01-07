# Estrutura de Dados: Lista

Uma lista é uma **coleção de elementos organizados em uma sequência linear**. Isso significa que cada elemento possui uma posição específica e segue uma ordem determinada. As listas são altamente versáteis e permitem o armazenamento e manipulação eficiente de conjuntos de dados.

## Tipos de Listas

1. **Lista Estática**: 
   - Representada por um vetor, utilizando endereços imediatos de memória.
   - **Vantagens**: Acesso rápido aos elementos usando índices.
   - **Desvantagens**: Redimensionamento custoso e requer memória imediata.

2. **Lista Dinâmica (ou Encadeada)**: 

    Representada por elementos que possuem um ponteiro para o próximo elemento (_sabem quem vem depois mas, não sabem quem vem antes_), espaço que guarda informação e um espaço que guarda ponteiro;listas dinâmicas podem ser:
    
    * **Simplesmente encadeadas**: encadeada lienarmente, sempre aponta para o próximo (ou o anterior de acordo com o contexto);
        * **Não ordenada**: fora de ordem;
        * **Ordenada:** ordem alfabética, por exemplo.

    **Vantagens**: Flexibilidade na alocação de memória; fácil inserção e remoção de elementos.
    **Desvantagens**: Acesso aos elementos é mais lento devido ao uso de ponteiros; maior consumo de memória para armazenar os ponteiros.

## Tipos de Listas Dinâmicas

1. **Listas Simplesmente Encadeadas**: Cada elemento (nó) aponta para o próximo, formando uma sequência.
2. **Listas Duplamente Encadeadas**: Cada elemento aponta tanto para o próximo quanto para o anterior, permitindo a navegação bidirecional.
3. **Listas Circulares**: A última posição da lista aponta para o primeiro elemento, formando um ciclo.

## Operações Básicas

1. **Inserir**: Adiciona um elemento em uma posição específica da lista.
   - Complexidade: O(1) no melhor caso para listas dinâmicas, O(n) no pior caso.
2. **Remover**: Remove um elemento de uma posição específica da lista.
   - Complexidade: O(1) no melhor caso para listas dinâmicas, O(n) no pior caso.
3. **Pesquisar**: Procura por um elemento específico na lista e retorna sua posição.
   - Complexidade: O(n) em listas estáticas e dinâmicas.
4. **Acessar**: Retorna o elemento em uma posição específica da lista.
   - Complexidade: O(1) para listas estáticas, O(n) para listas dinâmicas.
5. **isEmpty**: Verifica se a lista está vazia.
   - Complexidade: O(1)

## Conclusão

As listas são fundamentais em ciência da computação por sua capacidade de armazenar e organizar dados de forma eficiente. Conhecer os diferentes tipos de listas e suas operações é essencial para escolher a estrutura de dados adequada para cada situação.
