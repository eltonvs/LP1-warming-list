/*
 * Question:
 * Escreva um programa em C++ que lê uma matriz M[6][6], calcula as somas das
 * pares hachuriadas, imprime o conteúdo da matriz M e as somas calculadas.
 *   a)  | 0  1  1  1  1  1 |
 *       | 0  0  1  1  1  1 |
 *       | 0  0  0  1  1  1 |
 *       | 0  0  0  0  1  1 |
 *       | 0  0  0  0  0  1 |
 *       | 0  0  0  0  0  0 |
 *
 *   b)  | 1  1  1  1  1  0 |
 *       | 1  1  1  1  0  0 |
 *       | 1  1  1  0  0  0 |
 *       | 1  1  0  0  0  0 |
 *       | 1  0  0  0  0  0 |
 *       | 0  0  0  0  0  0 |
 *
 *   c)  | 0  1  1  1  1  0 |
 *       | 0  0  1  1  0  0 |
 *       | 0  0  0  0  0  0 |
 *       | 0  0  0  0  0  0 |
 *       | 0  0  0  0  0  0 |
 *       | 0  0  0  0  0  0 |
 *
 *   d)  | 0  0  0  0  0  0 |
 *       | 1  0  0  0  0  0 |
 *       | 1  1  0  0  0  0 |
 *       | 1  1  0  0  0  0 |
 *       | 1  0  0  0  0  0 |
 *       | 0  0  0  0  0  0 |
 */

#include <iostream>

using namespace std;

int sum_top_right(const int m[6][6]);
int sum_top_left(const int m[6][6]);
int sum_top_triangle(const int m[6][6]);
int sum_left_triangle(const int m[6][6]);

int main(int argc, char const *argv[]) {
	int matrix[6][6];

	// Fill matrix
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			cout << "m[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}

	// Show sum results
	cout << sum_top_right(matrix) << endl;
	cout << sum_top_left(matrix) << endl;
	cout << sum_top_triangle(matrix) << endl;
	cout << sum_left_triangle(matrix) << endl;

	return EXIT_SUCCESS;
}

int sum_top_right(const int m[6][6]) {
	auto sum(0);

	for (int i = 0; i < 6; i++)
		for (int j = i+1; j < 6; j++)
			sum += m[i][j];
	return sum;
}

int sum_top_left(const int m[6][6]) {
	auto sum(0);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5-i; j++)
			sum += m[i][j];
	return sum;
}

int sum_top_triangle(const int m[6][6]) {
	auto sum(0);

	for (int i = 0; i < 3; i++)
		for (int j = i+1; j < 5-i; j++)
			sum += m[i][j];

	return sum;
}

int sum_left_triangle(const int m[6][6]) {
	auto sum(0);

	for (int i = 0; i < 3; i++)
		for (int j = i+1; j < 5-i; j++)
			sum += m[j][i];

	return sum;
}