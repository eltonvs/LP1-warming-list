/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa em C++ chamado dist pts.cpp que calcula e imprime a
 * distância Euclidiana entre dois pontos do R² , P1 = (x1, y1) e P2 = (x2 , y2),
 * determinados por suas coordenadas Cartesianas. Para tanto o programa deverá
 * ler as coordenadas x e y de cada um dos dois pontos. A fórmula para o cálculo da
 * distância d entre dois pontos P1 e P2 é dada por: d(P1, P2) = (x2 − x1)² + (y2 − y1)².
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

typedef struct _Dot {
    double x, y;
} Dot;

// Prototype
double euclidean_distance(Dot P1, Dot P2);

int main(int argc, char const *argv[]) {
    Dot P1 = {}, P2 = {};

    // Set float numbers precision
    cout << fixed;
    cout << setprecision(2);

    // Scan P1
    cout << "Insert the coordinates of P1:" << endl;
    cout << "X = ";
    cin >> P1.x;
    cout << "Y = ";
    cin >> P1.y;
    // Scan P2
    cout << "Insert the coordinates of P2:" << endl;
    cout << "X = ";
    cin >> P2.x;
    cout << "Y = ";
    cin >> P2.y;

    // Show Euclidean distance
    cout << "The Euclidean Distance is " << euclidean_distance(P1, P2) << endl;

    return EXIT_SUCCESS;
}

double euclidean_distance(Dot P1, Dot P2) {
    return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}
