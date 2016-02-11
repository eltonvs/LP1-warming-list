/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Faça uma função denominada PontoEmEsfera que verifica se um ponto P especificado
 * por suas coordenadas Cartesianas P = (x, y, z) está dentro está dentro, na superfície
 * ou fora de uma esfera de raio r e centro em C = (Xc, Yc, Zc).
 * Faça um programa chamado de verifica_esferas.cpp que lê, de um arquivo texto,
 * uma sequência de definições de ponto e esfera (um conjunto por linha) e imprime a
 * classificação do ponto (dentro, superfície ou fora) na saída padrão e em um arquivo
 * denominado saida_esferas.txt. Segue abaixo um exemplo de formato de arquivo.
 *   1.5 2.5 1.0 3.0 3.0 3.0 4.0
 *   ...
 *   x y z Xc Yc Zc r
 * A fórmula da distância Euclidiana entre dois pontos P1 e P2 é:
 *   d(P1, P2)² = (X2 − X1)² + (Y2 − Y1)² + (Z2 − Z1)²
 * A equação Cartesiana da esfera com centro (Xc, Yc, Zc) e raio r é dada por:
 *   (X − Xc)² + (Y − Yc)² + (Z − Zc)² = r²
 * Observação: Pense como seria a solução do mesmo problema considerando uma caixa
 * ao invés de uma esfera. Neste caso a caixa teria seus planos paralelos aos planos
 * Cartesianos, mas seus comprimentos (altura, largura, profundidade) poderiam ser de
 * tamanhos distintos. Um caixa pode ser especificada por apenas 2 vértices em faces
 * opostas de forma a constituirem uma diagonal principal da caixa: canto inferior es-
 * querdo na face da frente e canto superior direito na face de trás.
 */

#include <iostream>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

typedef struct _Dot {
    double x, y, z;
} Dot;

int inside_sphere(const Dot *c, double r, const Dot *p);
double distance_between_dots(const Dot *a, const Dot *b);

int main(int argc, char const *argv[]) {
    Dot p = {}, c = {};
    double r;

    // Files
    ifstream file_in;
    ofstream file_out;

    // Open Files
    file_in.open("35_spheres_in.txt");
    file_out.open("35_spheres_out.txt");

    // Verify if the files are opened
    if (!file_in.is_open() || !file_out.is_open()) {
        cout << "Error at the file opening" << endl;
        return EXIT_FAILURE;
    }

    // Read file_in and write results in file_out
    while (file_in >> p.x >> p.y >> p.z >> c.x >> c.y >> c.z >> r)
        if (inside_sphere(&c, r, &p) == 1) {
            file_out << "Inside" << endl;
            cout << "Inside" << endl;
        } else if (inside_sphere(&c, r, &p) == -1) {
            file_out << "Surface" << endl;
            cout << "Surface" << endl;
        } else {
            file_out << "Outside" << endl;
            cout << "Outside" << endl;
        }

    // Close files
    file_in.close();
    file_out.close();

    return EXIT_SUCCESS;
}

double distance_between_dots(const Dot *a, const Dot *b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}

int inside_sphere(const Dot *c, double r, const Dot *p) {
    return distance_between_dots(c, p) < r ? 1 : distance_between_dots(c, p) == r ? -1 : 0;
}
