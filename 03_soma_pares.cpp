/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado soma_pares.cpp que lê um número não
 * determinado de pares m, n, todos inteiros e positivos, um par de cada vez, calcula e
 * escreve a soma dos n primeiros inteiros consecutivos à partir de m (inclusive). Para
 * encerrar a entrada de dados você pode utilizar <Ctrl+d> ou assumir que quando
 * m = n = 0 o usuário deseja encerrar.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int m, n;
    cout << "Enter two integer numbers (Press Ctrl + D to exit):" << endl;

    while (cin >> m && cin >> n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += m + i + 1;  // +1 because i starts with 0
        cout << "The sum of " << n << " consecutive integers from " << m << " is " << sum << endl;
    }

    return EXIT_SUCCESS;
}
