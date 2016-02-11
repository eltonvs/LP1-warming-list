/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Desenvolva funções para implementar as seguintes ações:
 * 1. Swap: Trocar o conteúdo de duas variáveis passadas por referência.
 * 2. Ordena3: Recebe como parâmetros três números inteiros e um flag ordem, e os
 *    coloca em ordem crescente se ordem = V, ou em ordem decrescente se ordem = F
 *    (usar passagem de parâmetro por referência e a função Swap()).
 * 3. EhPrimo: Verifica se um número recebido como parâmetro é primo.
 * 4. EhPar: Retorna verdadeiro (V) se um número recebido como parâmetro é par,
 *    retornando falso (F) caso contrário.
 * 5. EhAmigo: Retorna verdadeiro (V) se os dois números recebidos como parâmetros
 *    são amigos, falso (F) caso contrário.
 * 6. mdc: Retorna o Máximo Divisor Comum de 3 números recebidos como parâmetros.
 * 7. mmc: Retorna o Mínimo Múltiplo Comum de 3 números recebidos como parâmetros.
 * 8. Fatorial: Retorna o fatorial do número recebido como parâmetro.
 */

#include <iostream>
#include <cmath>

// Helpers
int mdc2(int a, int b) {
    return a%b ? mdc2(b, a%b) : b;
}

int mmc2(int a, int b) {
    return a*b/mdc2(a, b);
}

// Functions
void swap(int *a, int *b) {
    *a += *b, *b = *a - *b, *a -= *b;
}

void ordena3(int *a, int *b, int *c, bool order) {
    if (*a > *b && *a > *c) {
        if (*b < *c)
            swap(b, c);
    } else if (*b > *a && *b > *c) {
        if (*a > *c) {
            swap(a, b);
        } else {
            swap(a, b);
            swap(b, c);
        }
    } else {
        if (*a > *b) {
            swap(b, c);
            swap(a, b);
        } else {
            swap(a, c);
        }
    }

    if (order)
        swap(a, c);
}

bool eh_primo(int n) {
    for (int i = 2; i < sqrt(n); i++)
        if (n%i == 0)
            return false;
    return true;
}

bool eh_par(int n) {
    return n&1 ? false : true;
}

bool eh_amigo(int a, int b) {
    auto s_d1(0), s_d2(0);

    for (int i = 1; i < a; i++)
        if (a%i == 0) s_d1 += i;

    for (int i = 1; i < b; i++)
        if (b%i == 0) s_d2 += i;

    return (s_d1 == b && s_d2 == a) ? true : false;
}

int mdc(int a, int b, int c) {
    return mdc2(mdc2(a, b), c);
}

int mmc(int a, int b, int c) {
    return mmc2(mmc2(a, b), c);
}

int fatorial(int n) {
    return (n == 0) ? 1 : n*fatorial(n-1);
}

int main(int argc, char const *argv[]) {
    // Your code here

    return EXIT_SUCCESS;
}
