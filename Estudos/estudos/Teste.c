/*

Sequência de entrada: 2, 4, 6, 8, 10, 12

1. Bubble Sort
O Bubble Sort trabalha trocando elementos adjacentes se estiverem fora de ordem, e repete esse processo até que a lista esteja ordenada.

Passo a Passo:

Entrada: [2, 4, 6, 8, 10, 12]

Primeira Passada:
Compare 2 e 4 → 2 < 4, nada troca.
Compare 4 e 6 → 4 < 6, nada troca.
Compare 6 e 8 → 6 < 8, nada troca.
Compare 8 e 10 → 8 < 10, nada troca.
Compare 10 e 12 → 10 < 12, nada troca.
Após a primeira passada, a lista já está ordenada. Resultado final: [2, 4, 6, 8, 10, 12].

2. Insertion Sort
O Insertion Sort pega um elemento de cada vez e o insere na posição correta em uma parte já ordenada da lista.

Passo a Passo:

Entrada: [2, 4, 6, 8, 10, 12]

O primeiro elemento (2) já está na posição correta.
O segundo (4) já está na posição correta.
O terceiro (6) já está na posição correta.
O quarto (8) já está na posição correta.
O quinto (10) já está na posição correta.
O sexto (12) já está na posição correta.
Resultado final: [2, 4, 6, 8, 10, 12].

3. Selection Sort
O Selection Sort encontra o menor (ou maior) elemento e o coloca na posição correta, repetindo esse processo até que toda a lista esteja ordenada.

Passo a Passo:

Entrada: [2, 4, 6, 8, 10, 12]

Encontre o menor valor na lista: 2, já está na posição correta.
Encontre o menor valor no restante da lista: 4, já está na posição correta.
Encontre o menor valor no restante da lista: 6, já está na posição correta.
Encontre o menor valor no restante da lista: 8, já está na posição correta.
Encontre o menor valor no restante da lista: 10, já está na posição correta.
Encontre o menor valor no restante da lista: 12, já está na posição correta.
Resultado final: [2, 4, 6, 8, 10, 12].

4. Merge Sort
O Merge Sort divide o vetor recursivamente em metades até que as metades sejam de tamanho 1, e depois as junta de forma ordenada.

Passo a Passo:

Entrada: [2, 4, 6, 8, 10, 12]

Divida a lista em duas metades: [2, 4, 6] e [8, 10, 12].
Divida essas metades ainda mais:
[2, 4, 6] se divide em [2] e [4, 6] (já ordenado).
[8, 10, 12] se divide em [8] e [10, 12] (já ordenado).
Combine as metades ordenadas:
[4, 6] e [2] se tornam [2, 4, 6].
[10, 12] e [8] se tornam [8, 10, 12].
Combine tudo novamente: [2, 4, 6] e [8, 10, 12] se tornam [2, 4, 6, 8, 10, 12].
Resultado final: [2, 4, 6, 8, 10, 12].

5. Quick Sort
O Quick Sort escolhe um pivô e organiza a lista em torno dele, colocando todos os menores que o pivô à esquerda e os maiores à direita. Em seguida, aplica-se o mesmo processo recursivamente.

Passo a Passo:

Entrada: [2, 4, 6, 8, 10, 12]

Escolha o pivô (por exemplo, 12).
Organize em torno do pivô: [2, 4, 6, 8, 10] | 12.
Recursivamente, repita o processo para o subvetor [2, 4, 6, 8, 10].
O pivô para o subvetor [2, 4, 6, 8, 10] é 10, organize: [2, 4, 6, 8] | 10.
Repita o processo para os subvetores [2, 4, 6, 8], [2, 4, 6], etc., até que todos os elementos estejam ordenados.
Resultado final: [2, 4, 6, 8, 10, 12].


---------

Sequência de entrada: 11, 9, 7, 5, 3, 1
1. Bubble Sort
O Bubble Sort realiza comparações e trocas entre elementos adjacentes. O processo continua até que o vetor esteja completamente ordenado.

Passo a Passo:

Entrada: [11, 9, 7, 5, 3, 1]

Primeira Passada:

Compare 11 e 9 → 11 > 9 → troque → [9, 11, 7, 5, 3, 1]
Compare 11 e 7 → 11 > 7 → troque → [9, 7, 11, 5, 3, 1]
Compare 11 e 5 → 11 > 5 → troque → [9, 7, 5, 11, 3, 1]
Compare 11 e 3 → 11 > 3 → troque → [9, 7, 5, 3, 11, 1]
Compare 11 e 1 → 11 > 1 → troque → [9, 7, 5, 3, 1, 11]
Depois da primeira passada, o maior valor (11) está na posição correta.

Segunda Passada:

Compare 9 e 7 → 9 > 7 → troque → [7, 9, 5, 3, 1, 11]
Compare 9 e 5 → 9 > 5 → troque → [7, 5, 9, 3, 1, 11]
Compare 9 e 3 → 9 > 3 → troque → [7, 5, 3, 9, 1, 11]
Compare 9 e 1 → 9 > 1 → troque → [7, 5, 3, 1, 9, 11]
Terceira Passada:

Compare 7 e 5 → 7 > 5 → troque → [5, 7, 3, 1, 9, 11]
Compare 7 e 3 → 7 > 3 → troque → [5, 3, 7, 1, 9, 11]
Compare 7 e 1 → 7 > 1 → troque → [5, 3, 1, 7, 9, 11]
Quarta Passada:

Compare 5 e 3 → 5 > 3 → troque → [3, 5, 1, 7, 9, 11]
Compare 5 e 1 → 5 > 1 → troque → [3, 1, 5, 7, 9, 11]
Quinta Passada:

Compare 3 e 1 → 3 > 1 → troque → [1, 3, 5, 7, 9, 11]
Resultado final: [1, 3, 5, 7, 9, 11].

2. Insertion Sort
Passo a Passo:

Entrada: [11, 9, 7, 5, 3, 1]

O primeiro elemento (11) já está na posição correta.
O segundo (9) é inserido na posição correta: [9, 11, 7, 5, 3, 1].
O terceiro (7) é inserido na posição correta: [7, 9, 11, 5, 3, 1].
O quarto (5) é inserido na posição correta: [5, 7, 9, 11, 3, 1].
O quinto (3) é inserido na posição correta: [3, 5, 7, 9, 11, 1].
O sexto (1) é inserido na posição correta: [1, 3, 5, 7, 9, 11].
Resultado final: [1, 3, 5, 7, 9, 11].

3. Selection Sort
Passo a Passo:

Entrada: [11, 9, 7, 5, 3, 1]

Encontre o menor valor (1) e troque com o primeiro: [1, 9, 7, 5, 3, 11].
Encontre o menor valor no restante da lista (3) e troque com o segundo: [1, 3, 7, 5, 9, 11].
Encontre o menor valor no restante da lista (5) e troque com o terceiro: [1, 3, 5, 7, 9, 11].
Encontre o menor valor no restante da lista (7) e troque com o quarto: [1, 3, 5, 7, 9, 11].
O vetor já está ordenado.
Resultado final: [1, 3, 5, 7, 9, 11].

4. Merge Sort
Passo a Passo:

Entrada: [11, 9, 7, 5, 3, 1]

Divida a lista em duas metades: [11, 9, 7] e [5, 3, 1].
Divida ainda mais:
[11, 9, 7] → [11] e [9, 7] → [9], [7].
[5, 3, 1] → [5], [3, 1] → [3], [1].
Combine e ordene:
[9] e [7] → [7, 9].
[5] e [3] → [3, 5], depois combine com [1] → [1, 3, 5].
Combine as metades ordenadas:
[7, 9] e [11] → [7, 9, 11].
[1, 3, 5] → [1, 3, 5].
Combine tudo novamente → [1, 3, 5, 7, 9, 11].
Resultado final: [1, 3, 5, 7, 9, 11].

5. Quick Sort
Passo a Passo:

Entrada: [11, 9, 7, 5, 3, 1]

Escolha o pivô (por exemplo, 1) e organize em torno dele: [1 | 9, 7, 5, 3, 11].
Recursivamente, faça o mesmo com o subvetor [9, 7, 5, 3, 11].
Escolha o pivô (por exemplo, 11) → [9, 7, 5, 3] | 11.
Continue o processo até que todos os elementos estejam ordenados.
Resultado final: [1, 3, 5, 7, 9, 11].

*/