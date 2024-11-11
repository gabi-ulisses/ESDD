/*

Escreva o vetor resultante (teste de mesa) ao aplicar o algoritmo de particionamento em duas partes
(partition) no vetor seguinte: 26 65 45 73 10 18 78 93 70 49 23 22.


Vetor original: 26 65 45 73 10 18 78 93 70 49 23 22
Escolha do pivô: 22

Passos:
1. Comparando 26 com 22 → sem troca.
2. Comparando 65 com 22 → sem troca.
3. Comparando 45 com 22 → sem troca.
4. Comparando 73 com 22 → sem troca.
5. Comparando 10 com 22 → troca com 26: 10 65 45 73 26 18 78 93 70 49 23 22.
6. Comparando 18 com 22 → troca com 65: 10 18 45 73 26 65 78 93 70 49 23 22.
7. Comparando 78 com 22 → sem troca.
8. Comparando 93 com 22 → sem troca.
9. Comparando 70 com 22 → sem troca.
10. Comparando 49 com 22 → sem troca.
11. Comparando 23 com 22 → sem troca.
12. Comparando 22 com 22 → troca com 65: 10 18 22 73 26 65 78 93 70 49 23 45.


*/