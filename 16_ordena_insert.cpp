/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa em C++ denominado ordena_insert.cpp que lê, para um vetor V
 * de 30 posições, vinte valores inteiros que ocuparão as 20 primeiras posições de V.
 * Ordene, a seguir, os elementos de V em ordem não decrescente. Leia, a seguir, 10
 * valores inteiros, um por vez, e insira-os nas posições adequadas de V, de forma que V
 * continue ordenado em ordem não decrescente. Ao final imprima o conteúdo de V.
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Prototypes
void swap(int *a, int *b);
void sort(int *v, int s);
void insert_sort(int *v, int s, int n);

int main(int argc, char const *argv[]) {
    int v[30];

    // Get values from the first 20 numbers
    for (int i = 0; i < 20; i++) {
        cout << "Enter the " << i+1 << "º number: ";
        cin >> v[i];
    }

    // Sort the first 20 numbers
    cout << "Sorting..." << endl;
    sort(v, 20);

    // Enter the next 10 numbers
    for (int i = 20; i < 30; i++) {
        int num;
        cout << "Enter the " << i+1 << "º number: ";
        cin >> num;
        insert_sort(v, i, num);
    }

    for (int i : v)
        cout << i << endl;

    return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    *a += *b, *b = *a - *b, *a -= *b;
}

void sort(int *v, int s) {
    for (int i = 0; i < s - 1; i++)
        if (v[i] > v[i+1]) {
            swap(&v[i], &v[i+1]);
            i = 0;
        }
}

void insert_sort(int *v, int s, int n) {
    if (n > v[s-1]) {
        v[s] = n;
        return;
    }

    for (int i = 0; i < s; i++)
        if (n < v[i]) {
            for (int j = s; j > i; j--)
                v[j] = v[j-1];
            v[i] = n;
            return;
        }
}
