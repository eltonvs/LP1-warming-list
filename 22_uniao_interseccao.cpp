/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Faça uma função em C++ chamada uniaoIntersecao que recebe como parâmetro
 * dois vetores, vetA e vetB, de inteiros (possivelmente de tamanhos diferentes) e os
 * combina em dois vetores de saída, vetUni e vetInt. Para gerar o vetor vetUni a
 * função deve realizar a união entre os elementos de vetA e vetB. Para gerar o vetor
 * vetInt a função deve realizar a intersecção entre os elementos de vetA e vetB.
 * Note que a função deve alocar dinamicamente os dois vetores de saída, i.e., vetUni e
 * vetInt, de tal forma que os mesmos tenham o tamanho exato do resultado de suas
 * respectivas operações de combinação. A função deve utilizar aritmética de ponteiros
 * para percorrer os dois vetores de entrada, vetA e vetB, passados como argumento.
 * A função uniaoIntersecao poderia ter o seguinte protótipo:
 *   void uniaoIntersecao(int *vetA, int tamA, int *vetB, int tamB,
 *   int **vetUni, int *tamUni,
 *   int **vetInt, int *tamInt);
 * onde vetA e vetB são os vetores de entrada com seus respectivos tamanhos, tamA e
 * tamB; vetUni está associado ao vetor que conterá a união dos vetores de entrada, cujo
 * tamanho será indicado em tamUni; e vetInt está associado ao vetor que conterá a
 * intersecção dos vetores de entrada, cujo tamanho será indicado em tamInt. Modifique
 * o protótipo acima introduzindo o qualificador de tipo const de tal forma a restringir
 * ao máximo o acesso aos dados externos mas que ainda permita a função executar o
 * seu propósito original.
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::bad_alloc;

// Prototypes
bool has_in_array(const int x, const int arr_s, const int *arr);
void union_intersection(const int *vA, const int sA, const int *vB, const int sB, int **vU, int *sU, int **vI, int *sI);

int main(int argc, char const *argv[]) {
    int v1[5] = {1, 2, 20, 4, 5}, v2[3] = {1, 2, 3}, *vU, *vI, sU, sI;

    union_intersection(v1, 5, v2, 3, &vU, &sU, &vI, &sI);

    for (int i = 0; i < 5; i++)
        cout << "v1[" << i << "] = " << *(v1+i) << endl;
    cout << "v1 size = " << 5 << endl << endl;
    for (int i = 0; i < 3; i++)
        cout << "v2[" << i << "] = " << *(v2+i) << endl;
    cout << "v2 size = " << 3 << endl << endl;
    for (int i = 0; i < sU; i++)
        cout << "vU[" << i << "] = " << *(vU+i) << endl;
    cout << "Union vector size: " << sU << endl << endl;
    for (int i = 0; i < sI; i++)
        cout << "vI[" << i << "] = " << *(vI+i) << endl;
    cout << "Intersection vector size: " << sI << endl;

    // Free memory
    delete[] vU;
    delete[] vI;

    return EXIT_SUCCESS;
}

bool has_in_array(const int x, const int arr_s, const int *arr) {
    for (int i = 0; i < arr_s; i++)
        if (x == *(arr+i)) return true;
    return false;
}

void union_intersection(const int *vA, const int sA, const int *vB, const int sB, int **vU, int *sU, int **vI, int *sI) {
    int v1[sA < sB ? sA : sB], v2[sA+sB], p = 0;

    for (int i = 0; i < sA; i++)
        if (has_in_array(*(vA+i), sB, vB) && !has_in_array(*(vA+i), p, v1))
            *(v1+p++) = *(vA+i);
    *sI = p;
    try {
        *vI = new int[*sI];
    }catch (const bad_alloc & e) {
        cerr << "[union_intersection()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < p; i++)
        *(*vI+i) = *(v1+i);

    p = 0;

    for (int i = 0; i < sA; i++)
        if (!has_in_array(*(vA+i), p, v2))
            *(v2+p++) = *(vA+i);
    for (int i = 0; i < sB; i++)
        if (!has_in_array(*(vB+i), p, v2))
            *(v2+p++) = *(vB+i);

    *sU = p;
    try {
        *vU = new int[*sU];
    }catch (const bad_alloc & e) {
        cerr << "[union_intersection()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < p; i++)
        *(*vU+i) = *(v2+i);
}
