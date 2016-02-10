/*
 * Question:
 * Uma matriz que tem aproximadamente 2/3 de seus elementos iguais a zero é denominada
 * de matriz esparsa. Implemente um programa em C++ chamado esparsa.cpp que lê uma
 * matriz esparsa de inteiros M[10][10] e forma uma matriz condensada, de apenas
 * 3 colunas com os elementos não nulos da matriz M, de forma que:
 *   a) a primeira coluna contém o valor não nulo de M.
 *   b) a segunda coluna contém a linha de M onde foi encontrado o valor.
 *   c) a terceira coluna contém a coluna de M onde foi encontrado o valor.
 * A seguir, imprima a matriz lida e a matriz condensada.
 */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int *m, *condensed, c_size = 0;

	// Allocate memory to matrix
	m = new int [10*10];

	// Get matrix content
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cout << "M[" << i << "][" << j << "] = ";
			cin >> *(m+i*10+j);
			if (*(m+i*10+j) != 0) c_size++;
		}

	// Allocate memory to condensed matrix
	condensed = new int [c_size*3];

	// Insert data on condensed matrix
	for (int i = 0, c = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (*(m+i*10+j) != 0)
				*(condensed+c*c_size+0) = *(m+i*10+j),
				*(condensed+c*c_size+1) = i,
				*(condensed+c*c_size+2) = j,
				c++;

	// Print matrix
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cout << (j == 0 ? "| " : " ") << *(m+i*10+j) << (j == 9 ? " |\n" : " ");

	cout << endl;

	// Print condensed matrix
	for (int i = 0; i < c_size; i++)
		for (int j = 0; j < 3; j++)
			cout << (j == 0 ? "| " : " ") << *(condensed+i*c_size+j) << (j == 2 ? " |\n" : " ");

	return EXIT_SUCCESS;
}