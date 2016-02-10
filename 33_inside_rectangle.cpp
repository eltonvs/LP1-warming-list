/*
 * Question:
 * Considerando a estrutura
 *   typedef struct _Ponto {
 *       int x;
 *       int y;
 *   } Ponto;
 * para representar um ponto em uma grade 2D, implemente uma função que indique se
 * um ponto p está localizado dentro ou fora de um retângulo. O retângulo é definido
 * por seus vértices inferior esquerdo v1 e superior direito v2. A função deve retornar
 * 1 caso o ponto esteja localizado dentro do retângulo e 0 caso contrário. Essa função
 * deve obedecer o protótipo:
 * int dentroRet (const Ponto* v1, const Ponto* v2, const Ponto* p);
 * ou alternativamente use o seguinte protótipo:
 * int dentroRet (const Ponto &v1, const Ponto &v2, const Ponto &p);
 *   Obs.: Repare que os pontos v1, v2 e p são passados como referência constante
 *         de forma que seus valores não podem ser alterados dentro da função. Isso é uma
 *         boa prática de programação, uma vez que para calcular se p está dentro do retângulo
 *         definido por v1 e v2 não é necessário modificar seus valores.
 */

#include <iostream>

using namespace std;

typedef struct _Dot {
	int x;
	int y;
} Dot;

int inside_rectangle(const Dot *v1, const Dot *v2, const Dot *p);

int main(int argc, char const *argv[]) {
	Dot v1, v2, p;

	// Get variables
	cout << "Enter the rectangle bottom-left vertice:" << endl;
	cout << "  X = ";
	cin >> v1.x;
	cout << "  Y = ";
	cin >> v1.y;
	cout << "Enter the rectangle top-right vertice:" << endl;
	cout << "  X = ";
	cin >> v2.x;
	cout << "  Y = ";
	cin >> v2.y;
	cout << "Enter the dot coordinates:" << endl;
	cout << "  X = ";
	cin >> p.x;
	cout << "  Y = ";
	cin >> p.y;

	// Output
	cout << "The dot " << (inside_rectangle(&v1, &v2, &p) ? "is" : "isn't") << " inside the rectangle"  << endl;

	return EXIT_SUCCESS;
}

int inside_rectangle(const Dot *v1, const Dot *v2, const Dot *p) {
	return ((*p).x < (*v2).x && (*p).y < (*v2).y && (*p).x > (*v1).x && (*p).y > (*v1).y) ? 1 : 0;
}