/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Desenvolva duas funções, NesimoFib(n) e FibMenorL(L), que imprimem, respectiva-
 * mente, a sequência de Fibonacci até seu n-ésimo termo e os m primeiros termos da
 * série de Fibonacci que são menores que L. Lembre-se que a série de Fibonacci é dada
 * por {1, 1, 2, 3, 5, 8, 13, 21, ...}, ou seja, os primeiros dois termos da série são 1 e os
 * próximos termos são calculados como a soma dos dois termos precedentes imediatos.
 * Desenvolva também uma função denominada de PiramideFib(h) que recebe como
 * parâmetro h indicando a altura da pirâmide de Fibonacci e a imprime da tela (utilize
 * as funções anteriores). A pirâmide de Fibonacci para h = 7 deve corresponder a:
 *
 *                1
 *              1 1
 *            2 1 1
 *          3 2 1 1
 *        5 3 2 1 1
 *      8 5 3 2 1 1
 *   13 8 5 3 2 1 1
 *      8 5 3 2 1 1
 *        5 3 2 1 1
 *          3 2 1 1
 *            2 1 1
 *              1 1
 *                1
 *
 *   * Note que a pirâmide esta “deitada” para a esquerda.
 */

#include <iostream>

using std::cout;
using std::endl;

int nth_fib(int n) {
    return (n == 0 || n == 1) ? 1 : nth_fib(n-1) + nth_fib(n-2);
}

int smaller_fib(int n) {
    int i = 0;
    while (nth_fib(i) < n) i++;
    return i;
}

void pyramid_fib(int h) {
    for (int i = 0; i < h*2-1; i++) {
        for (int j = 1; j <= h; j++) {
            if (abs(i-h+1) < j)
                cout << nth_fib(abs(h-j)) << "\t";
            else
                cout << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    pyramid_fib(7);

    return EXIT_SUCCESS;
}
