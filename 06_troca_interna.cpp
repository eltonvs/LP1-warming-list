/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado troca_interna.cpp que lê 20 inteiros, os
 * armazena em um arranjo unidimensional (vetor) A e o imprime na tela. A seguir, o
 * programa deve trocar o conteúdo do último elemento de A com o 1º , do penúltimo
 * com o 2º, do ante-penúltimo com o 3º e assim pode diante até que todos os elementos
 * tenham sido trocados de lugar apenas uma vez. Por fim, o programa deve imprimir o
 * vetor modificado.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int a[20];

    // Read vector values
    for (int i = 0; i < 20; i++)
        cin >> a[i];

    // Display vector values
    for (int i = 0; i < 20; i++)
        cout << "a[" << i << "] = " << a[i] << endl;

    cout << "Changing values..." << endl;

    // Change values
    for (int i = 0, t; i < 20/2; i++)
        t = a[i], a[i] = a[20-i-1], a[20-i-1] = t;

    // Display vector values
    for (int i = 0; i < 20; i++)
        cout << "a[" << i << "] = " << a[i] << endl;

    return EXIT_SUCCESS;
}
