/*
 * Question:
 * Implemente um programa em C/C++ chamado fib01.cpp que recebe um valor inteiro
 * positivo L e imprime os termos da série de Fibonacci inferiores a L.
 * A sequência de Fibonacci define-se como tendo os dois primeiros termos iguais a 1
 * e cada termo seguinte é a soma dos dois termos imediatamente anteriores. Desta
 * forma se fosse fornecido ao programa uma entrada L = 15 o mesmo deveria produzir
 * a seguinte sequência de termos da série: 1 1 2 3 5 8 13.
 */


#include <iostream>

using namespace std;

int fib(int n) {
	return (n == 0 || n == 1) ? 1 : fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[]) {
	int l;

	cout << "Enter a number: ";
	cin >> l;

	for (int i = 0; fib(i) < l; i++)
		cout << fib(i) << " ";

	cout << endl;

	return EXIT_SUCCESS;
}