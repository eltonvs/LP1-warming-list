/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa em C++ chamado preenche_matriz.cpp que lê um inteiro
 * positivo n e cria uma matriz quadrada n x n que deverá ser preenchida automaticamente
 * com inteiros positivos de 1 até n², dando prioridade a linhas ao invés de colunas
 * (row-major). Por exemplo, uma matriz 3 x 3 deverá ser preenchida da seguinte forma:
 *   | 1 2 3 |
 *   | 4 5 6 |
 *   | 7 8 9 |
 *   Faça o seu programa imprimir na tela a matriz assim preenchida.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

int main(int argc, char const *argv[]) {
    int n, *m;

    // Get matrix size
    cout << "Enter the matrix size (n): ";
    cin >> n;

    // Create matrix
    try {
        m = new int[n*n];
    }catch (const bad_alloc & e) {
        cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
    }

    // Populate matrix
    for (int i = 0; i < n*n; i++)
        *(m+i) = i+1;

    // Print populated matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << (!j ? "| " : " ") << *(m+i*n+j) << (j == n-1 ? " |\n" : " ");

    delete[] m;

    return EXIT_SUCCESS;
}
