/*
 * Question:
 * Escreva um programa em C++ chamado vet5.cpp que recebe um conjunto de 30
 * valores inteiros e os coloca em 2 vetores, A e B, conforme forem pares ou ímpares. Os
 * vetores A e B deverão ter 5 posições de armazenamento. Quando um dos dois vetores
 * fica cheio, o programa deve imprimi-lo. Terminada a entrada de dados, o programa
 * deve imprimir o conteúdo dos dois vetores. Note que cada vetor pode ser preenchido
 * tantas vezes quantas forem necessárias.
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int a[5], b[5], i = 0, j = 0, input;

	// Info message
	cout << "Enter integer numbers (Press Ctrl + D to exit):" << endl;

	// Read numbers
	while (cin >> input) {
		// Input is odd
		if (input%2) {
			b[i] = input, i++;
			// Vector is full
			if (i == 5) {
				cout << "Odds:" << endl;
				// Print vector elements
				for (int n: b)
					cout << n << endl;
				i = 0;
			}
		// Input is even
		}else {
			a[j] = input, j++;
			// Vector is full
			if (j == 5) {
				cout << "Evens:" << endl;
				// Print vector elements
				for (int n: a)
					cout << n << endl;
				j = 0;
			}
		}
	}

	if (i > 0) {
		cout << "Odds:" << endl;
		for (int n = 0; n < i; n++)
			cout << b[n] << endl;
	}
	if (j > 0) {
		cout << "Evens:" << endl;
		for (int n = 0; n < j; n++)
			cout << a[n] << endl;
	}

	return EXIT_SUCCESS;
}