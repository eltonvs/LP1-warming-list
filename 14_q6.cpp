/*
 * Question:
 * Implemente um programa denominado q6.cpp que cria um vetor de inteiros (pode ser
 * estático ou fornecido pelo usuário) e invoca a função maiores. Esta função recebe como
 * parâmetro o vetor de números inteiros (vet) de tamanho n e um valor x. A função deve
 * retornar quantos números maiores do que x existem nesse vetor. O protótipo da função é:
 *   int maiores (const int* const vet, const int n, const int x);
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int maiores(const int* const vet, const int n, const int x) {
	// Set return variable
	auto tot(0);

	for (int i = 0; i < n; i++)
		if (vet[i] > x) tot++;

	return tot;
}

int main(int argc, char const *argv[]) {
	int n, x;

	// Get n value
	cout << "Enter the vector size: ";
	cin >> n;

	// Create the vector (size = n)
	int vet[n];

	// Fills vector randomically
	for (int i = 0; i < n; i++) {
		srand(time(0)+i);
		vet[i] = rand()%100;
	}

	// Get x value
	cout << "Enter x value: ";
	cin >> x;

	// Print the function result
	cout << "The total number(s) greater than " << x << " on vector is " << maiores(vet, n, x) << endl;

	return EXIT_SUCCESS;
}