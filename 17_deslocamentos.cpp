/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Faça um programa chamado deslocamentos.cpp que recebe quatro números inteiros,
 * n1, n2, n3 e n4, e um certo número de deslocamentos, d, que esses números devem
 * sofrer em relação a sequência original de entrada de dados. Se d=0 a sequêcia de saída
 * é a mesma da entrada; se d > 0 você deve deslocar os números para a ‘direita’ d vezes,
 * imaginando que os números formam um círculo (i.e. após o n-ésimo termo segue-se o 1º);
 * se d<0 o deslocamento deve ser feito para a ‘esquerda’.
 * Por exemplo, se a entrada for n1 = 5, n2 = −2, n3 = 7, n4 = 45 e d = 3 o resultado
 * final seria (−2, 7, 45, 5), ou seja, os números foram deslocados para a direita três vezes:
 * (5, −2, 7, 45) → (45, 5, −2, 7) → (7, 45, 5, −2) → (-2,7,45,5).
 * Utilize uma função denominada ShiftN(n1,n2,n3,n4,d) que recebe os números como
 * parâmetros por referência e aplica o deslocamento d sobre eles. Tente fazer esta função
 * de forma mais otimizado possível, evitando deslocamentos desnecessários (dica: utilize
 * o operador resto ou % em C++).
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void shift_n(int *n1, int *n2, int *n3, int *n4, int d) {
    d %= 4;
    if (d > 0) {
        for (int i = 0; i < d; i++) {
            int aux = *n4;
            *n4 = *n3, *n3 = *n2, *n2 = *n1, *n1 = aux;
        }
    } else {
        for (int i = 0; i > d; i--) {
            int aux = *n1;
            *n1 = *n2, *n2 = *n3, *n3 = *n4, *n4 = aux;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n1, n2, n3, n4, d;

    // Get values
    cout << "n1 = ";
    cin >> n1;
    cout << "n2 = ";
    cin >> n2;
    cout << "n3 = ";
    cin >> n3;
    cout << "n4 = ";
    cin >> n4;
    cout << "d = ";
    cin >> d;

    // Call function
    shift_n(&n1, &n2, &n3, &n4, d);

    // Print values
    cout << "(" << n1 << ", ";
    cout << n2 << ", ";
    cout << n3 << ", ";
    cout << n4 << ")" << endl;

    return EXIT_SUCCESS;
}
