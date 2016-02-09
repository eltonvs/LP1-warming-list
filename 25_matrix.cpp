/*
 * Question:
 * Escreva um programa que lê valores reais para uma matriz M[5][5] e calcula e imprime
 * as seguintes somas:
 *   a) da linha 4 de M
 *   b) da coluna 2 de M
 *   c) da diagonal principal de M
 *   d) da diagonal secundária de M
 *   e) de todos os elementos da matriz
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	double m[5][5];

	// Get values
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "M[" << i << "][" << j << "] = ";
			cin >> m[i][j];
		}
	}

	// Line 4 sum
	double line4_sum = 0;
	for (int i = 0; i < 5; i++)
		line4_sum += m[3][i];
	cout << "The line 4 sum is: " << line4_sum << endl;

	// Column 2 sum
	double column2_sum = 0;
	for (int i = 0; i < 5; i++)
		column2_sum += m[i][1];
	cout << "The column 2 sum is: " << column2_sum << endl;

	// Main diagonal
	double main_diagonal_sum = 0;
	for (int i = 0; i < 5; i++)
		main_diagonal_sum += m[i][i];
	cout << "The main diagonal sum is: " << main_diagonal_sum << endl;

	// Secondary diagonal
	double secondary_diagonal_sum = 0;
	for (int i = 0; i < 5; i++)
		secondary_diagonal_sum += m[i][4-i];
	cout << "The secondary diagonal sum is: " << secondary_diagonal_sum << endl;

	// All elements
	double total_sum = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			total_sum += m[i][j];
	cout << "The sum of all elements is: " << total_sum << endl;

	return EXIT_SUCCESS;
}