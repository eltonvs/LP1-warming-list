/*
 * Implemente um programa em C++ chamado preenche_matriz.cpp que lê um inteiro
 * positivo n e cria uma matriz quadrada n x n que deverá ser preenchida automaticamente
 * com inteiros positivos de 1 até n², dando prioridade a linhas ao invés de colunas
 * (row-major). Por exemplo, uma matriz 3 x 3 deverá ser preenchida da seguinte forma:
 *   | 1 2 3 |
 *   | 4 5 6 |
 *   | 7 8 9 |
 *   Faça o seu programa imprimir na tela a matriz assim preenchida.
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;

	// Get matrix size
	cout << "Enter the matrix size (n): ";
	cin >> n;

	// Create matrix
	int m[n][n];

	// Populate matrix
	for (int i = 0; i < n*n; i++)
		*(*m+i) = i+1;

	// Print populated matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << (j == 0 ? "| " : " ") << m[i][j] << (j == n - 1 ? " |\n" : " ");

	return EXIT_SUCCESS;
}