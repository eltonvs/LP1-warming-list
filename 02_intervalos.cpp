/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Escreva um programa em C/C++ chamado intervalos.cpp que lê um número não
 * conhecido de valores, um de cada vez, e conta quantos deles estão em cada um dos
 * intervalos [0, 25), [25, 50), [50, 75) e [75, 100].
 */


#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int x;
    auto tot(0), int1(0), int2(0), int3(0), int4(0);

    cout << "Enter integer numbers (Press Ctrl + D to exit):" << endl;

    while (cin >> x) {
        if (x >= 0 && x < 25) int1++;
        else if (x >= 25 && x < 50) int2++;
        else if (x >= 50 && x < 75) int3++;
        else if (x >= 75 && x <= 100) int4++;
        tot++;
    }

    cout << int1*100.0/tot << '%' << " on interval [0, 25)" << endl;
    cout << int2*100.0/tot << '%' << " on interval [25, 50)" << endl;
    cout << int3*100.0/tot << '%' << " on interval [50, 75)" << endl;
    cout << int4*100.0/tot << '%' << " on interval [75, 100]" << endl;

    return EXIT_SUCCESS;
}
