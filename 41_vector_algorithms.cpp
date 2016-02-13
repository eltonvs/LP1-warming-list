/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente cada um dos seguintes algoritmos de forma imperativa e de forma recursiva:
 * i.   Defina o módulo MembroQ que recebe um número N e um vetor V de números e
 *      devolve verdadeiro se N pertence a V e falso caso contrário.
 * ii.  Defina o módulo Ocorrencias que recebe um número N e um vetor V e conta
 *      quantas vezes N ocorre em V.
 * iii. Defina um módulo que recebe um vetor V e um número N e devolve uma tripla
 *      [A,B,C] tal que A é o número de elementos de V maiores que N, B é o número de
 *      elementos de V iguais a N, e C é o número de elementos menores que N.
 * iv.  Defina um módulo Prefixo que recebe como argumento dois vetores U e V e
 *      devolve verdadeiro se U é prefixo de V e falso caso contrário.
 * v.   Defina uma sub-rotina ProdEscalar que recebe como argumento um vetor V e um
 *      escalar X e calcula o produto escalar de V por X, alterando diretamente o vetor V.
 *   Dica. Acrescente a cada módulo alguns parâmetros de entrada convenientes para a
 *   realização da tarefa correspondente, tais como dim para a dimensão do vetor e pos para
 *   a posição do elemento em foco numa determinada execução do módulo em questão.
 */

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::bad_alloc;

bool memberq(int n, const int *v, int size);
int occurrences(int n, const int *v, int size);
int *triple(int n, const int *v, int size);
// bool prefix(const int *u, int size_u, const int *v, int size_v);
// I did not understand it
void scalar_product(int x, int *v, int size);

int main(int argc, char const *argv[]) {
    int v1[] = {1, 2, 3, 3, 5};
    // int v2[] = {8, 7, 6};

    // Print Vector
    for (int i = 0; i < 5; i++)
        cout << *(v1+i) << (i == 4 ? "\n" : ", ");

    cout << memberq(3, v1, 5) << endl;
    cout << memberq(4, v1, 5) << endl;

    cout << occurrences(3, v1, 5) << endl;

    int *t = triple(3, v1, 5);
    cout << "A = " << *t << " B = " << *(t+1) << " C = " << *(t+1) << endl;
    delete[] t;

    // cout << prefix(v1, 5, v2, 3) << endl;

    scalar_product(3, v1, 5);
    for (int i = 0; i < 5; i++)
        cout << *(v1+i) << (i == 4 ? "\n" : ", ");

    return EXIT_SUCCESS;
}

bool memberq(int n, const int *v, int size) {
    for (int i = 0; i < size; i++)
        if (*(v+i) == n)
            return true;
    return false;
}

int occurrences(int n, const int *v, int size) {
    auto r(0);
    for (int i = 0; i < size; i++)
        if (*(v+i) == n) r++;
    return r;
}

int *triple(int n, const int *v, int size) {
    int *r;
    try {
        r = new int[3];
    }catch (const bad_alloc & e) {
        cerr << "[triple()]: bad_alloc caught:" << e.what() << "\n";
    }

    for (int i = 0; i < size; i++)
        if (*(v+i) > n)
            (*r)++;
        else if (*(v+i) == n)
            (*(r+1))++;
        else
            (*(r+2))++;

    return r;
}

/*
bool prefix(const int *u, int size_u, const int *v, int size_v) {
}
*/

void scalar_product(int x, int *v, int size) {
    for (int i = 0; i < size; i++)
        *(v+i) *= x;
}
