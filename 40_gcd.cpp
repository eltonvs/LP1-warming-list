/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Cálculo recursivo do Máximo Divisor Comum (MDC).
 * i.   Dados dois números inteiros não nulos m e n, calcule seu MDC através da imple-
 *      mentação da seguinte equação de recorrência:
 *      MDC(m, n) =
 *       | MDC(m, m − n), se m > n
 *       | MDC(n − m, m), se m < n
 *       | m, em caso contrário
 *      (Este procedimento é estendido e otimizado no algoritmo abaixo.)
 * ii.  Algoritmo de Euclides (cerca de 300 A.C.). Dados dois números naturais não-
 *      nulos m e n, tais que 0 ≤ n < m, calcule seu MDC através da implementação da
 *      seguinte equação de recorrência:
 *      MDC(m, n) =
 *       | m, se n = 0
 *       | MDC(n, m resto n), em caso contrário
 * iii. Dois números naturais positivos são ditos co-primos ou primos entre si caso eles
 *      não possuam fatores comuns para além da unidade. Use o módulo determinado
 *      por algum dos algoritmos acima para determinar se dois números a e b são primos
 *      entre si. Compare o número de chamadas recursivas efetuadas caso seja utilizado
 *      o módulo (i) com o número de chamadas geradas pelo módulo (ii).
 */

#include <iostream>

using std::cout;
using std::endl;

int mdc(unsigned int m, unsigned int n);
bool coprime(unsigned int m, unsigned int n);

int main(int argc, char const *argv[]) {
    cout << mdc(20, 2) << endl;
    cout << coprime(3, 2) << endl;

    return EXIT_SUCCESS;
}

int mdc(unsigned int m, unsigned int n) {
    return n ? mdc(n, m%n) : m;
}

bool coprime(unsigned int m, unsigned int n) {
    return (mdc(m, n) == 1) ? true : false;
}
