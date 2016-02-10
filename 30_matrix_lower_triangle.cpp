/*
 * Question:
 * Implemente uma função que retorne a soma dos elementos abaixo da diagonal de uma
 * matriz quadrada de números de ponto flutuante (float), isto é, a soma de todos os
 * elementos a(i, j) onde i > j. A função recebe como parâmetros a matriz de números de
 * ponto flutuante, usando a representação de matrizes através de ponteiro duplo, e
 * um inteiro n, indicando a dimensão da matriz. Essa função deve obedecer o protótipo:
 *   float somaTrianguloInferior (const float ** mat, int n);
 */

#include <iostream>

using namespace std;

float sum_lower_triangle(float **m, int n);

int main(int argc, char const *argv[]) {
	float *m;
	int n;

	// Get matrix size
	cout << "Enter the matrix size: ";
	cin >> n;

	// Allocate memory
	try {
		m = new float [n];
	}catch (const bad_alloc & e) {
		cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
	}

	for (int i = 0; i < n*n; i++) {
		cout << "Enter the " << i+1 << "º number: ";
		cin >> *(m+i);
	}

	cout << "The sum of matrix lower triangle is " << sum_lower_triangle(&m, n) << endl;

	return EXIT_SUCCESS;
}

float sum_lower_triangle(float **m, int n) {
	auto sum(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i > j)
				sum += *(*m+i*n+j);

	return sum;
}
