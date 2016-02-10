/*
 * Question:
 * Considerando a estrutura (com typedef)
 *   typedef struct _Vetor {
 *       float x;
 *       float y;
 *       float z;
 *   } Vetor;
 * para representar um vetor no ponto no R³, implemente uma função que calcule a soma
 * de dois vetores. Essa função deve obedecer o protótipo:
 *   void soma (const Vetor *v1, const Vetor *v2, Vetor **res);
 * onde v1 e v2 são ponteiros para os vetores a serem somados pela função, e o parâmetro
 * res é um ponteiro para um ponteiro para uma estrutura vetor onde o resultado da
 * operação deve ser armazenado. Para tanto é necessário alocar dinamicamente a estru-
 * tura para receber o resultado da soma.
 * Além da função mencionada acima, implemente uma outra versão da soma que deve
 * seguir o protótipo:
 *   Vetor soma2 (const Vetor *v1, const Vetor *v2);
 * onde v1 e v2 são ponteiros para os vetores a serem somados pela função, e a função
 * retorna uma estrutura do tipo Vetor que foi alocada dinamicamente pela função e
 * contém o resultado da soma.
 */

#include <iostream>

using namespace std;

typedef struct _Vector {
	float x, y, z;
} Vector;

// Prototypes
void sum(const Vector *v1, const Vector *v2, Vector **res);
Vector sum2(const Vector *v1, const Vector *v2);

int main(int argc, char const *argv[]) {
	Vector v1 = {1.2, 2.5, 3.7}, v2 = {3.3, 4.7, 5.1}, r, *p_r = &r;

	// Call sum()
	sum(&v1, &v2, &p_r);

	// Show sum() results
	cout << "Sum():" << endl;
	cout << "\tX = " << r.x << endl;
	cout << "\tY = " << r.y << endl;
	cout << "\tZ = " << r.z << endl;

	// Call sum2()
	r = sum2(&v1, &v2);

	// Show sum2() results
	cout << "Sum2():" << endl;
	cout << "\tX = " << r.x << endl;
	cout << "\tY = " << r.y << endl;
	cout << "\tZ = " << r.z << endl;

	return EXIT_SUCCESS;
}

void sum(const Vector *v1, const Vector *v2, Vector **r) {
	(*r)->x = v1->x + v2->x, (*r)->y = v1->y + v2->y, (*r)->z = v1->z + v2->z;
}

Vector sum2(const Vector *v1, const Vector *v2) {
	return {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
}
