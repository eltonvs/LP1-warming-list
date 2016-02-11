/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa chamado avalia_poli.cpp que recebe como entrada de
 * dados inteiros correspondente a um polinômio e um valor real para o qual o polinômio
 * deve ser avaliado. O polinômio poderá ter, no máximo, 4 termos ou monômios.
 * Por exemplo, a seguinte entrada de dados:
 *   4 2 -2 1 5 0 0 0 5.0
 * corresponde ao polinômio de grau 2, 4x² − 2x + 5, o qual deve ser avaliado para o valor
 * x = 5.0, resultando 4(5.0)² − 2(5.0) + 5 = 95.0.
 * Após a leitura de um polinômio e de um valor a ser avaliado o programa deve invocar a
 * função avalia que deve receber os 4 termos do polinômio e o valor a ser avaliado como
 * parâmetros e retornar o valor da avaliação. O resultado da função deve ser exibido na
 * tela, juntamente com uma representação do polinômio, da seguinte forma:
 *   f(x)=4x^2 - 2x + 5, f(5.0) = 95.0
 * Nesta representação deve haver apenas um e apenas um espaço em branco ' ' antes e
 * depois dos sinais '-' e '+'.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main(int argc, char const *argv[]) {
    int coefficients[4], exponent[4];
    double x, r = 0;

    // Set float/double numbers precision
    cout << fixed;
    cout << setprecision(1);

    // Get the equation
    cout << "Enter the equation:" << endl;
    for (int i = 0; i < 4; i++)
        cin >> coefficients[i] >> exponent[i];

    // Get x value
    cin >> x;

    // Get the equation result
    for (int i = 0; i < 4; i++)
        r += coefficients[i] * pow(x, exponent[i]);

    // Echo final result
    cout << "f(x) =";
    for (int i = 0; i < 4; i++)
        if (coefficients[i] != 0) {
            cout << (coefficients[i] < 0 ? " - " : (i ? " + " : " ")) << abs(coefficients[i]) << "x";
            if (exponent[i] != 0)
                cout << "^" << exponent[i];
        }
    cout << ", f(" << x << ") = " << r << endl;

    return EXIT_SUCCESS;
}
