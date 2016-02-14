/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Estudo de uma função.
 * Sejam X = [X1 , ... , Xn] e Y = [Y1 , ... , Yn] dois vetores tais que f(Xi) = Yi, para alguma
 * função f . Assuma que o vetor X está ordenado.
 * i.  Defina a função Máximo que calcula o máximo da função f.
 * ii. Defina a função Monotonia que devolve 1 se a função f é crescente, −1 se a função
 *     f é decrescente, e 0 caso contrário.
 * ii. Defina a função TVM que calcula a Taxa de Variação Média de f em cada intervalo.
 *     Esta função deverá devolver um vetor de comprimento n − 1 em que na i-ésima
 *     posição do vetor ocorre a TVM de f no intervalo [Xi , Xi+1].
 */

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

int maximum(int *x, int *f, int size);
int monotony(int *f, int size);
int *get_arc(int *f, int size);

int main(int argc, char const *argv[]) {
    // Example: f(x) = x² | Domain: [-3, 3]
    int x[] = {-3, -2, -1, 0, 1, 2, 3}, y[] = {9, 4, 1, 0, 1, 4, 9}, size = 7;

    cout << maximum(x, y, size) << endl;
    cout << monotony(y, size) << endl;

    int *arc = get_arc(y, size);
    for (int i = 0; i < size - 1; i++)
        cout << "arc[" << x[i] << ", " << x[i+1] << "] = " << *(arc+i) << endl;

    // Free memory
    delete[] arc;

    return EXIT_SUCCESS;
}

int maximum(int *x, int *f, int size) {
    int m[] = {0, *f};
    for (int i = 1; i < size; i++)
        if (*(f+i) >= *(m+1)) *m = i, *(m+1) = *(f+i);
    return *(x+*m);
}

int monotony(int *f, int size) {
    int s = 0;
    for (int i = 1; i < size; i++)
        if ((*(f+i) < *(f+i-1) && s == 1) ||
            (*(f+i) > *(f+i-1) && s == -1) ||
            (*(f+i) == *(f+i-1)))
            return 0;
        else if (*(f+i) < *(f+i-1))
            s = -1;
        else
            s = 1;
    return s;
}

int *get_arc(int *f, int size) {
    int *arc;

    try {
        arc = new int[size-1];
    }catch(const bad_alloc & e) {
        cerr << "[get_arc()]: bad_alloc caught:" << e.what() << "\n";
    }

    // Fill vector with average rate of change
    for (int i = 0; i < size - 1; i++)
        *(arc+i) = *(f+i+1) - *(f+i);

    return arc;
}
