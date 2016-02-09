/*
Implemente uma função que indique se uma matriz quadrada de números inteiros é
uma matriz triangular superior ou não. A função deve retornar 1 se a matriz for uma
matriz triangular superior, e 0 caso contrário. A função recebe como parâmetros a
matriz de inteiros, usando a representação de matrizes através de ponteiro simples,
e um inteiro n, indicando a dimensão da matriz. Essa função deve obedecer o protótipo:
  int ehTrianguloSuperior (const int * mat, int n);
 */

#include <iostream>

using namespace std;

// Prototype
int is_upper_triangular(const int *m, int n);

int main(int argc, char const *argv[]) {
	int triangular_matrix[3][3] = {{1, 2, 3}, {0, 5, 6}, {0, 0, 0}};
	int not_triangular_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	cout << is_upper_triangular(*triangular_matrix, 3) << endl;
	cout << is_upper_triangular(*not_triangular_matrix, 3) << endl;

	return EXIT_SUCCESS;
}

int is_upper_triangular(const int *m, int n) {
	auto z(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++, z++)
			if (i > j && *(m+z) != 0)
				return 0;
	return 1;
}