#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Racional;

Racional adicionar(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional subtrair(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional multiplicar(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional dividir(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador;
    resultado.denominador = r1.denominador * r2.numerador;
    return resultado;
}

int obterMDC(int a, int b) {
    return b == 0 ? a : obterMDC(b, a % b);
}

Racional reduzir(Racional r) {
    int mdc = (r.numerador < 0) ? obterMDC(-r.numerador, r.denominador) : obterMDC(r.numerador, r.denominador);
    r.numerador /= mdc;
    r.denominador /= mdc;
    return r;
}

int main() {
    int qtdOperacoes;
    char operador;
    Racional r1, r2, resultado;

    scanf("%d", &qtdOperacoes);

    for (int i = 0; i < qtdOperacoes; ++i) {
        scanf("%d / %d %c %d / %d", &r1.numerador, &r1.denominador, &operador, &r2.numerador, &r2.denominador);

        switch (operador) {
            case '+':
                resultado = adicionar(r1, r2);
                break;
            case '-':
                resultado = subtrair(r1, r2);
                break;
            case '*':
                resultado = multiplicar(r1, r2);
                break;
            case '/':
                resultado = dividir(r1, r2);
                break;
        }

        printf("%d/%d = ", resultado.numerador, resultado.denominador);
        resultado = reduzir(resultado);
        printf("%d/%d\n", resultado.numerador, resultado.denominador);
    }

    return 0;
}