/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado compacta_vet.cpp que lê 20 inteiros,
 * os armazena em um arranjo unidimensional (vetor) C e o imprime na tela. A seguir, o
 * programa deve compactar o vetor C, retirando dele todos os valores nulos ou negativos
 * e imprimir o vetor modificado.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    auto size(20);
    int c[size];

    // Get vector data
    for (int i = 0; i < size; i++)
        cin >> c[i];

    // Print vector
    for (int i = 0; i < size; i++)
        cout << "c[" << i << "] = " << c[i] << endl;

    // Remove negative/null values from vector
    for (int i = 0; i < size; i++)
        if (c[i] <= 0) c[i] = c[--size], i--;

    // Print new vector
    for (int i = 0; i < size; i++)
        cout << "c[" << i << "] = " << c[i] << endl;

    return EXIT_SUCCESS;
}
