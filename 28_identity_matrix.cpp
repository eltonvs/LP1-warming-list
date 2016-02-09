/*
 * Question:
 * Implemente uma função que indique se uma matriz quadrada de números inteiros é
 * uma matriz identidade ou não. A função deve retornar 1 se a matriz for uma matriz
 * identidade, e 0 caso contrário (matriz identidade é aquela em que a diagonal principal
 * contém apenas 1s e o resto da matriz contém zeros). A função recebe como parâmetro
 * a matriz de inteiros, usando a representação de matrizes através de ponteiro simples,
 * e um inteiro n, indicando a dimensão da matriz. Essa função deve obedecer o protótipo:
 *   int ehMatrizIdentidade(const int * mat, int n);
 */

#include <iostream>

using namespace std;

// Prototype
int is_identity_matrix(const int *m, int n);

int main(int argc, char const *argv[]) {
	int id_matrix[2][2] = {{1, 0}, {0, 1}};
	int not_id_matrix[2][2] = {{1, -1}, {-1, 1}};

	cout << is_identity_matrix(*id_matrix, 2) << endl;
	cout << is_identity_matrix(*not_id_matrix, 2) << endl;

	return EXIT_SUCCESS;
}

int is_identity_matrix(const int *m, int n) {
	for (int i = 0, j = 0; i < n*n; i++)
		if (i == n*j+j) {
			if (*(m+i) != 1)
				return 0;
			j++;
		}else if (*(m+i) != 0)
			return 0;

	return 1;
}
