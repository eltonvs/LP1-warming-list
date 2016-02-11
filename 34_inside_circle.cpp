/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Considerando a estrutura da questão 29 para representar um ponto em uma grade 2D,
 * implemente uma função que indique se um ponto p está localizado dentro ou fora de
 * um círculo. O círculo é definido por seu centro c e seu raio r. A função deve retornar 1
 * caso o ponto esteja localizado dentro ou na borda do círculo e 0 (zero) caso contrário.
 * Essa função deve obedecer o protótipo:
 *   int dentroCirc (const Ponto *c, int raio, const Ponto *p);
 */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

typedef struct _Dot {
    int x;
    int y;
} Dot;

int inside_circle(const Dot *c, int r, const Dot *p);
double distance_between_dots(const Dot *a, const Dot *b);

int main(int argc, char const *argv[]) {
    Dot c = {}, p = {};
    int r;

    // Get variables
    cout << "Enter the coordinates from the center of circle:" << endl;
    cout << "  X = ";
    cin >> c.x;
    cout << "  Y = ";
    cin >> c.y;
    cout << "Enter the circle radius: ";
    cin >> r;
    cout << "Enter the dot coordinates:" << endl;
    cout << "  X = ";
    cin >> p.x;
    cout << "  Y = ";
    cin >> p.y;

    // Output
    cout << "The dot is" << (inside_circle(&c, r, &p) ? "" : "n't") << " inside the circle"  << endl;

    return EXIT_SUCCESS;
}

double distance_between_dots(const Dot *a, const Dot *b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2.0));
}

int inside_circle(const Dot *c, int r, const Dot *p) {
    return distance_between_dots(c, p) <= r ? 1 : 0;
}
