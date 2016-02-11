/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Uma matriz que tem aproximadamente 2/3 de seus elementos iguais a zero é denominada
 * de matriz esparsa. Implemente um programa em C++ chamado esparsa.cpp que lê uma
 * matriz esparsa de inteiros M[10][10] e forma uma matriz condensada, de apenas
 * 3 colunas com os elementos não nulos da matriz M, de forma que:
 *   a) a primeira coluna contém o valor não nulo de M.
 *   b) a segunda coluna contém a linha de M onde foi encontrado o valor.
 *   c) a terceira coluna contém a coluna de M onde foi encontrado o valor.
 * A seguir, imprima a matriz lida e a matriz condensada.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

int main(int argc, char const *argv[]) {
    int *m, *condensed, c_size = 0;

    // Allocate memory to matrix
    try {
        m = new int[10*10];
    }catch (const bad_alloc & e) {
        cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
    }

    // Get matrix content
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> *(m+i*10+j);
            if (*(m+i*10+j) != 0) c_size++;
        }

    // Allocate memory to condensed matrix
    try {
        condensed = new int[c_size*3];
    }catch (const bad_alloc & e) {
        cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
    }

    // Insert data on condensed matrix
    for (int i = 0, c = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (*(m+i*10+j) != 0)
                *(condensed+c*c_size+0) = *(m+i*10+j),
                *(condensed+c*c_size+1) = i,
                *(condensed+c*c_size+2) = j,
                c++;

    // Print matrix
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cout << (j == 0 ? "| " : " ") << *(m+i*10+j) << (j == 9 ? " |\n" : " ");

    cout << endl;

    // Print condensed matrix
    for (int i = 0; i < c_size; i++)
        for (int j = 0; j < 3; j++)
            cout << (j == 0 ? "| " : " ") << *(condensed+i*c_size+j) << (j == 2 ? " |\n" : " ");

    delete[] m;
    delete[] condensed;

    return EXIT_SUCCESS;
}
