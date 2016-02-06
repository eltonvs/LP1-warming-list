/*
 * Implemente um programa em C++ chamado ponto em retangulo.cpp que verifica se
 * um ponto P = (Xp, Yp), determinado por suas coordenadas Cartesianas, está localizado
 * dentro, na borda ou fora de um retângulo definido por dois pontos (também determinados
 * por suas coordenadas Cartesianas): o canto inferior esquerdo IE = (Xie, Yie) e o
 * canto superior direito SD = (Xsd, Ysd).
 * O programa deve receber três pares de valores X e Y. Os dois primeiros pares
 * correspondentes aos dois pontos, R1 e R2, que definem um retângulo; enquanto
 * que o último par define o ponto de teste P. Note que R1 e R2 podem não corresponder
 * diretamente ao canto inferior esquerdo e canto superior direito nesta ordem, podendo
 * seus valores estarem trocados. Portanto o programa deve, primeiramente, assegurar-se
 * de que R1 corresponda a IE e R2 corresponda a SD, trocando os valores de suas coordenadas
 * se for o caso. Além disso, o programa também deve assegurar-se de que R1 e R2 de
 * fato definem um retângulo válido (isto é, R1 != R2). A seguir o programa deve realizar
 * testes e indicar se o ponto P está dentro, na borda ou fora do retângulo, imprimindo
 * uma mensagem para cada situação.
*/

#include <iostream>

using namespace std;

struct Dot {
	double x, y;
};

int main(int argc, char const *argv[]) {
	Dot P, IE, SD;

	// Get R1 coord
	cout << "Enter R1:" << endl;
	cout << "\tX = ";
	cin >> IE.x;
	cout << "\tY = ";
	cin >> IE.y;
	// Get R2 coord
	cout << "Enter R2:" << endl;
	cout << "\tX = ";
	cin >> SD.x;
	cout << "\tY = ";
	cin >> SD.y;
	// Get P coord
	cout << "Enter P:" << endl;
	cout << "\tX = ";
	cin >> P.x;
	cout << "\tY = ";
	cin >> P.y;

	// Verify if the rectangle is valid
	if (SD.x == IE.x && SD.y == IE.y) {
		cout << "This rectangle is invalid" << endl;
		return EXIT_SUCCESS;
	// Verify if SD is the bottom-left dot and IE is the top-right dot
	}else if (SD.x < IE.x && SD.y < IE.y) {
		SD.x += IE.x, IE.x = SD.x - IE.x, SD.x -= IE.x;
		SD.y += IE.y, IE.y = SD.y - IE.y, SD.y -= IE.y;
	}

	// Verify if P is inside the rectangle
	if (P.x < SD.x && P.y < SD.y && P.x > IE.x && P.y > IE.y)
		cout << "The P dot is inside the rectangle" << endl;
	// P is on top border of the rectangle
	else if (P.y == SD.y && P.x < SD.x && P.x > IE.x)
		cout << "The P dot is on the top border of the rectangle" << endl;
	// P is on bottom border of the rectangle
	else if (P.y == IE.y && P.x < SD.x && P.x > IE.x)
		cout << "The P dot is on the bottom border of the rectangle" << endl;
	// P is on right border of the rectangle
	else if (P.x == SD.y && P.y < SD.y && P.y > IE.y)
		cout << "The P dot is on the right border of the rectangle" << endl;
	// P is on left border of the rectangle
	else if (P.x == IE.y && P.y < SD.y && P.y > IE.y)
		cout << "The P dot is on the left border of the rectangle" << endl;
	// P is outside the rectangle
	else
		cout << "The P dot is outside the rectangle" << endl;

	return EXIT_SUCCESS;
}