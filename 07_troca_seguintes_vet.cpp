/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado troca_seguintes_vet.cpp que lê 20 inteiros,
 * os armazena em um arranjo unidimensional (vetor) B e o imprime na tela. A seguir,
 * o programa deve trocar o conteúdo dos elementos de B de ordem ímpar com os
 * de ordem par imediatamente seguintes e imprimir o vetor modificado.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int b[20];

    // Read vector values
    for (int i = 0; i < 20; i++)
        cin >> b[i];

    // Print vector
    for (int i = 0; i < 20; i++)
        cout << "b[" << i << "] = " << b[i] << endl;

    cout << "Changing positions (odd <-> even)..." << endl;

    // Change positions (odd <-> even)
    for (int i = 0, t; i < 20 - 1; i += 2)
        t = b[i], b[i] = b[i+1], b[i+1] = t;

    // Print new vector
    for (int i = 0; i < 20; i++)
        cout << "b[" << i << "] = " << b[i] << endl;

    return EXIT_SUCCESS;
}
