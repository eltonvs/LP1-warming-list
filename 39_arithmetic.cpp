/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Aritmética sobre os números naturais.
 * i.   Defina um módulo que implementa recursivamente o cálculo da multiplicação
 *      MultSoma(m,n) de dois números não-negativos m e n em termos de adições sucessivas.
 *        Dica: faça uso da equação de recorrência
 *          MultSoma(m, n) =
 *           | 0, se n = 0
 *           | MultSoma(m, n − 1) + m, em caso contrário
 * ii.  Defina um módulo que implementa recursivamente o cálculo da exponencial ExpoMult(m,n)
 *      de dois números não-negativos m e n em termos de multiplicações sucessivas. Qual
 *      é, neste caso, a equação de recorrência adequada para esta tarefa?
 * iii. Faça uso dos dois módulos anteriores para definir o módulo ExpoSoma, que im-
 *      plementa o cálculo da exponencial de dois números não-negativos em termos de
 *      adições sucessivas.
 * iv.  Supondo a existência de um módulo que calcula a função Sucessor, que recebe
 *      um número natural e devolve o número que o segue segundo a ordem usual dos
 *      naturais, utilize tal módulo para implementar a função binária Soma sobre pares
 *      de naturais.
 */

#include <iostream>

using std::cout;
using std::endl;

int mult_sum(unsigned int m, unsigned int n);
int expo_mult(unsigned int m, unsigned int n);
int expo_sum(unsigned int m, unsigned int n);
int bin_sum(unsigned int m, unsigned int n);
int sucessor(int n);

int main(int argc, char const *argv[]) {
    cout << mult_sum(32, 6) << endl;    // Expected: 32*6 = 192
    cout << bin_sum(325, 152) << endl;  // Expected: 325+152 = 477
    cout << expo_mult(2, 7) << endl;    // Expected: 2⁷ = 128
    cout << expo_sum(2, 7) << endl;     // Expected: 2⁷ = 128

    return EXIT_SUCCESS;
}

int mult_sum(unsigned int m, unsigned int n) {
    return n ? mult_sum(m, --n) + m : 0;
}

int expo_mult(unsigned int m, unsigned int n) {
    return n ? expo_mult(m, --n) * m : 1;
}

int expo_sum(unsigned int m, unsigned int n) {
    return n ? mult_sum(expo_mult(m, --n), m) : 1;
}

int bin_sum(unsigned int m, unsigned int n) {
    return n ? sucessor(bin_sum(m, --n)) : m;
}

int sucessor(int n) {
    return ++n;
}
