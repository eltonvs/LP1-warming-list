/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Faça uma função em C++ chamada inverte_vetor que recebe um vetor de inteiros
 * como parâmetro e inverte a ordem dos seus elementos, alterando o vetor original pas-
 * sado como argumento. O parâmetro formal da função correspondente ao vetor a ser
 * invertido deve ser um ponteiro simples. Utilize aritmética de ponteiros ao invés de
 * indexação para percorrer o vetor. Implemente sua função de tal forma que não seja
 * necessário o uso de um vetor auxiliar e nem percorrer todos os elementos do vetor
 * original. A função inverteVetor deve obedecer o seguinte protótipo:
 *   void inverte_vetor(int *piVet, const int tam);
 * onde piVet é o ponteiro para o vetor a ser invertido e tam é o tamanho do mesmo.
 */

#include <iostream>

using std::cout;
using std::endl;

// Prototype
void invert_vector(int *p_v, const int size);

int main(int argc, char const *argv[]) {
    // Create example vector
    int v[] = {1, 2, 3, 4, 5, 6, 7};

    // Print Original vector
    for (int i : v)
        cout << i << endl;

    // Invert vector
    cout << "Inverting vector..." << endl;
    invert_vector(v, 7);

    // Print new (inverted) vector
    for (int i : v)
        cout << i << endl;

    return EXIT_SUCCESS;
}

void invert_vector(int *p_v, const int size) {
    for (int i = 0; i < size/2; i++)
        *(p_v+i) += *(p_v+size-i-1),
        *(p_v+size-i-1) = *(p_v+i) - *(p_v+size-i-1),
        *(p_v+i) -= *(p_v+size-i-1);
}
