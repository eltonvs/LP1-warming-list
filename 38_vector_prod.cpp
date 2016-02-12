/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Considerando a estrutura da questão 32 para representar um vetor no R³, implemente
 * uma função que calcule o produto escalar de dois vetores. Essa função deve obedecer
 * o protótipo:
 *   float dot(const Vetor *v1, const Vetor *v2);
 * onde v1 e v2 são ponteiros para os vetores a serem multiplicados, e o resultado da
 * operação v1 · v2 deve ser retornado.
 * O produto escalar entre dois vetores X = {X1, X2, ..., Xn} e Y = {Y1, Y2, ..., Yn} é
 * X · Y = sum(XiYi, i = 1, n) = X1Y1 + ··· + XnYn.
 */

#include <iostream>

using std::cout;
using std::endl;

typedef struct _Vector {
    float x, y, z;
} Vector;

float prod(const Vector *v1, const Vector *v2);

int main(int argc, char const *argv[]) {
    Vector v1 = {1.2, 2.5, 3.7}, v2 = {3.3, 4.7, 5.1};

    // Call prod()
    float r = prod(&v1, &v2);

    // Show prod() result
    cout << "prod() = " << r << endl;

    return EXIT_SUCCESS;
}

float prod(const Vector *v1, const Vector *v2) {
    return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
}
