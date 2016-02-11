/*
 * Copyright 2016 - Elton Viana
 *
 * Question:
 * Implemente um programa denominado equacao.cpp que invoca a função raizes, que
 * por sua vez calcula as raízes de uma equação do segundo grau, do tipo ax²+bx+c = 0.
 * Essa função deve obedecer o protótipo
 * int raizes (float a, float b, float c, float * x1, float * x2);
 * onde a, b e c representam os coeficientes da equação, e x1 e x2 são ponteiros para as
 * variáveis onde devem ser guardadas as raízes da equação. A função deve retornar o
 * número de raízes reais que a equação possui.
 * Vale salientar que:
 * 1. Se a equação possuir raízes reais e distintas, x1 deve armazenar a raiz menor e x2
 *    a outra raiz. Neste caso a função deve retornar o valor 2, indicando que existem
 *    duas raízes.
 * 2. Se a equação possuir possuir raízes reais e iguais x1 = x2 e a função deve retornar 1.
 * 3. Se a equação não possuir raízes reais então a função deve fazer x1 = 0 e x2 = 0
 *    e o retorno da função deve ser 0.
 * 4. A função sqrt definida na biblioteca padrão da linguagem deve ser usada para calcular
 *    a raiz quadrada de números. Para tanto basta incluir a biblioteca <cmath>
 *    onde está declarado o protótipo da função: double sqrt(double n)
 */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int roots(float a, float b, float c, float *x1, float *x2) {
    *x1 = 0, *x2 = 0;
    if ((a > 0 && c > 0) || (a < 0 && c < 0)) {
        return 0;
    } else if (c == 0) {
        *x1 = -b/a;
        return 1;
    } else {
        float delta = pow(b, 2) - 4*a*c;
        *x1 = (-b + sqrt(delta))/2, *x2 = -(b + sqrt(delta))/2;
        if (*x1 < *x2) *x1 += *x2, *x2 = *x1 - *x2, *x1 -= *x2;
        return 2;
    }
}

int main(int argc, char const *argv[]) {
    float a, b, c, x1, x2;

    // Receive values
    cout << "Enter the function coefficients" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    // Print Results
    cout << "This function have " << roots(a, b, c, &x1, &x2) << " root(s)" << endl;
    cout << "x' = " << x1 << endl;
    cout << "x'' = " << x2 << endl;

    return EXIT_SUCCESS;
}
