/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Na teoria dos Sistemas define-se como elemento minimáx de uma matriz, o menor
 * elemento da linha em que se encontra o maior elemento da matriz. Implemente um
 * programa em C++ chamado minmax.cpp que lê uma matriz A[10][10] e determina
 * o elemento minimáx desta matriz, imprimindo a matriz A e a posição do elemento
 * minimáx.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

int main(int argc, char const *argv[]) {
    int *a, b, b_row;

    // Allocate memory to a
    try {
        a = new int[10*10];
    }catch (const bad_alloc & e) {
        cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
    }

    // Get matrix content
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> *(a+i*10+j);
            if (*(a+i*10+j) > b || (i == 0 && j == 0)) b = *(a+i*10+j), b_row = i;
        }

    // Create minimax var
    int minimax[] = {*(a+b_row*10), b_row, 0};

    // Get minimax
    for (int i = 0; i < 10; i++)
        if (*(a+b_row*10+i) < minimax[0]) minimax[0] = *(a+b_row*10+i), minimax[2] = i;

    // Print matrix
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cout << (j == 0 ? "| " : " ") << *(a+i*10+j) << (j == 9 ? " |\n" : " ");

    cout << "The minimax element is A[" << minimax[1] << "][" << minimax[2] << "]  = " << minimax[0] << endl;

    // Free memory
    delete[] a;

    return EXIT_SUCCESS;
}
