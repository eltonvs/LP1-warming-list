/*
 * Question
 * Faça uma função em C++ chamada intercalaVetores que recebe como parâmetro
 * dois vetores, vetA e vetB, de caracteres (possivelmente de tamanhos diferentes) e os
 * combina em um só vetor. Para gerar o vetor combinado deve-se intercalar elementos
 * dos dois vetores da seguinte forma: para o vetA deve-se iniciar com seu primeiro
 * elemento, avançando sequencialmente pelo vetor até o seu último elemento; para o
 * vetB deve-se iniciar pelo último elemento, retrocedendo sequencialmente pelo vetor
 * até o seu primeiro elemento.
 * Note que a função deve alocar dinamicamente uma quantidade de memória do tamanho
 * exato para conter a combinação resultante dos dois vetores. A função deve utilizar
 * aritmética de ponteiros para percorrer os dois vetores passados como argumento.
 * A função intercalaVetores deve obedecer o seguinte protótipo:
 *   char * intercalaVetores(const char * vetA, int tamA, const char * vetB, int tamB);
 * onde vetA é o ponteiro para o primeiro vetor e tamA seu tamanho; vetB é o ponteiro
 * para o segundo vetor e tamB seu tamanho. A função deve retornar um ponteiro para
 * o vetor contendo a combinação dos dois vetores passados como parâmetro.
 */

#include <iostream>

using namespace std;

char *merge_vector(const char *vetA, int sizeA, const char *vetB, int sizeB) {
	char *result_vector;
	try {
		result_vector = new char [sizeA+sizeB];
	}catch (const bad_alloc & e) {
		cerr << "[merge_vector()]: bad_alloc caught:" << e.what() << "\n";
	}

	for (int i = 0, j = 0; i < sizeA || i < sizeB; i++) {
		if (i < sizeA)
			*(result_vector+j++) = *(vetA+i);
		if (i < sizeB)
			*(result_vector+j++) = *(vetB+i);
	}

	return result_vector;
}

int main(int argc, char const *argv[]) {
	char *v1, *v2;
	int size_v1, size_v2;

	// Get size from the first vector
	cout << "Enter the size of the first vector: ";
	cin >> size_v1;

	// Get size from the second vector
	cout << "Enter the size of the second vector: ";
	cin >> size_v2;

	// Allocate memory (w/ try/catch)
	try {
		v1 = new char [size_v1];
	}catch (const bad_alloc & e) {
		cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
	}
	try {
		v2 = new char [size_v2];
	}catch (const bad_alloc & e) {
		cerr << "[main()]: bad_alloc caught:" << e.what() << "\n";
	}

	// Get values for the first vector
	cout << "Enter values:" << endl;
	for (int i = 0; i < size_v1; i++) {
		cout << "v1[" << i << "] = ";
		cin >> v1[i];
	}

	// Get values for the second vector
	cout << "Enter values:" << endl;
	for (int i = 0; i < size_v2; i++) {
		cout << "v1[" << i << "] = ";
		cin >> v2[i];
	}

	// Call function
	char *result = merge_vector(v1, size_v1, v2, size_v2);

	// Print result vector
	cout << "Result vector: [ ";
	for (int i = 0; i < size_v1 + size_v2; i++)
		cout << *(result+i) << (i < size_v1 + size_v2 - 1 ? ", " : " ");
	cout << "]" << endl;

	return EXIT_SUCCESS;
}