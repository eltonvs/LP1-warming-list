/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado negativo5.cpp que lê 5 valores inteiros,
 * um de cada vez, conta quantos destes valores são negativos e imprime esta informação.
 */


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    auto a(0), n(0);

    for (int i = 0; i < 5; i++) {
        cout << "Enter the " << i+1 << "º number: ";
        cin >> a;
        if (a < 0) n++;
    }

    cout << n << " negative numbers " << (n > 1 ? "were" : "was") << " entered" << endl;

    return EXIT_SUCCESS;
}
