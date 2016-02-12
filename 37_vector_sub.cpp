/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Considerando a estrutura da questão 36 para representar um vetor no R³, implemente
 * uma função que calcule a subtração de dois vetores. Essa função deve obedecer o
 * protótipo:
 *   void sub (const Vetor *v1, const Vetor *v2, Vetor **res);
 * onde v1 e v2 são ponteiros para os vetores a serem subtraídos pela função, e o parâmetro
 * res deve ser alocado dinamicamente dentro da função e receber o resultado da operação
 * de subtração (v1 − v2).
 */

#include <iostream>

using std::cout;
using std::endl;

typedef struct _Vector {
    float x, y, z;
} Vector;

void sub(const Vector *v1, const Vector *v2, Vector **r);

int main(int argc, char const *argv[]) {
    Vector v1 = {1.2, 2.5, 3.7}, v2 = {3.3, 4.7, 5.1}, r, *p_r = &r;

    // Call sub()
    sub(&v1, &v2, &p_r);

    // Show sub() results
    cout << "Sub():" << endl;
    cout << "\tX = " << r.x << endl;
    cout << "\tY = " << r.y << endl;
    cout << "\tZ = " << r.z << endl;

    return EXIT_SUCCESS;
}

void sub(const Vector *v1, const Vector *v2, Vector **r) {
    (*r)->x = v1->x - v2->x, (*r)->y = v1->y - v2->y, (*r)->z = v1->z - v2->z;
}
