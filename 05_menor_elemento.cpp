/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado menor_elemento.cpp que lê 20 números
 * reais, os armazena em um arranjo unidimensional (vetor) Vet e o imprime na tela. A
 * seguir, o programa deve encontrar o menor elemento e a sua posição no vetor Vet e
 * escrever na saída padrão qual é o menor elemento e que posição ele ocupa no vetor.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    float vet[20], smaller_num;
    int smaller_p;

    // Read vector values
    for (int i = 0; i < 20; i++)
        cin >> vet[i];

    // Print vector
    for (int i = 0; i < 20; i++)
        cout << "vet[" << i << "] = " << vet[i] << endl;

    // Find the smaller number on vector
    for (int i = 0; i < 20; i++)
        if (i == 0) smaller_num = vet[0], smaller_p = 0;
        else if (vet[i] < smaller_num) smaller_num = vet[i], smaller_p = i;

    cout << "The smaller number on given vector is " << smaller_num << " and is on position " << smaller_p << endl;

    return EXIT_SUCCESS;
}
