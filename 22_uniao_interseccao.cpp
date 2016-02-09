/*
 * Faça uma função em C++ chamada uniaoIntersecao que recebe como parâmetro
 * dois vetores, vetA e vetB, de inteiros (possivelmente de tamanhos diferentes) e os
 * combina em dois vetores de saída, vetUni e vetInt. Para gerar o vetor vetUni a
 * função deve realizar a união entre os elementos de vetA e vetB. Para gerar o vetor
 * vetInt a função deve realizar a intersecção entre os elementos de vetA e vetB.
 * Note que a função deve alocar dinamicamente os dois vetores de saída, i.e., vetUni e
 * vetInt, de tal forma que os mesmos tenham o tamanho exato do resultado de suas
 * respectivas operações de combinação. A função deve utilizar aritmética de ponteiros
 * para percorrer os dois vetores de entrada, vetA e vetB, passados como argumento.
 * A função uniaoIntersecao poderia ter o seguinte protótipo:
 *   void uniaoIntersecao(int *vetA, int tamA, int *vetB, int tamB,
 *   int **vetUni, int *tamUni,
 *   int **vetInt, int *tamInt);
 * onde vetA e vetB são os vetores de entrada com seus respectivos tamanhos, tamA e
 * tamB; vetUni está associado ao vetor que conterá a união dos vetores de entrada, cujo
 * tamanho será indicado em tamUni; e vetInt está associado ao vetor que conterá a
 * intersecção dos vetores de entrada, cujo tamanho será indicado em tamInt. Modifique
 * o protótipo acima introduzindo o qualificador de tipo const de tal forma a restringir
 * ao máximo o acesso aos dados externos mas que ainda permita a função executar o
 * seu propósito original.
 */

#include <iostream>

using namespace std;

bool has_in_array(int x, int arr_s, int *arr) {
	for (int i = 0; i < arr_s; i++)
		if (x == *(arr+i)) return true;
	return false;
}

void union_intersection(const int *v_A, const int s_A, int *v_B, const int s_B, int *v_Uni, int *s_Uni, int *v_Int, int *s_Int) {
	int v1[s_A < s_B ? s_A : s_B], v2[s_A+s_B], p = 0;

	for (int i = 0; i < s_A; i++)
		if (has_in_array(*(v_A+i), s_B, v_B) && !has_in_array(*(v_A+i), p, v1))
			*(v1+p++) = *(v_A+i);
	*s_Int = p;
	v_Int = new int [p];

	for (int i = 0; i < p; i++)
		*(v_Int+i) = *(v1+i);

	p = 0;

	for (int i = 0; i < s_A; i++)
		if (!has_in_array(*(v_A+i), p, v2))
			*(v2+p++) = *(v_A+i);
	for (int i = 0; i < s_B; i++)
		if (!has_in_array(*(v_B+i), p, v2))
			*(v2+p++) = *(v_B+i);

	*s_Uni = p;
	v_Uni = new int [*s_Uni];

	for (int i = 0; i < *s_Uni; i++)
		*(v_Uni+i) = *(v2+i);
}

int main(int argc, char const *argv[]) {
	int v1[5]={1, 2, 2, 4, 5},
		v2[3]={1, 2, 3},
		*v_uni,
		*v_int,
		s_uni,
		s_int;

	union_intersection(v1, 5, v2, 3, v_uni, &s_uni, v_int, &s_int);

	for (int i = 0; i < 5; i++)
		cout << ">> " << *(v1+i) << endl;
	cout << "s_v1 = " << 5 << endl;
	for (int i = 0; i < 3; i++)
		cout << ">> " << *(v2+i) << endl;
	cout << "s_v2 = " << 3 << endl;
	for (int i = 0; i < s_uni; i++)
		cout << ">> " << *(v_uni+i) << endl;
	cout << "s_vuni = " << s_uni << endl;
	for (int i = 0; i < s_int; i++)
		cout << ">> " << *(v_int+i) << endl;
	cout << "s_vint = " << s_int << endl;

	return EXIT_SUCCESS;
}