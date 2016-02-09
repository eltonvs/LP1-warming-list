/*
 * Question:
 * Implemente um programa em C++ chamado busca_palindromo.cpp que lê uma string do
 * usuário e verifica se a mesma é um palíndromo. Um palíndromo é uma palavra, frase,
 * número ou qualquer outra sequência de unidades (como uma cadeia de ADN) que tenha
 * a propriedade de poder ser lida tanto da direita para a esquerda como da esquerda
 * para a direita (o ajustamento de espaços entre letras é geralmente permitido).
 * Exemplos de palavras: anilina, arara, mirim, radar, rotor, osso, ovo, iriri, mussum.
 * Exemplos de frases: “A rara arara”, “Socorram-me, subi no ônibus em Marrocos”, “A
 * mala nada na lama”.
 * Identificar palíndromos em palavras é relativamente fácil. A maior dificuldade será
 * identificar frases que são palíndromos. Para tanto o programa deverá eliminar todos
 * os espaços em brancos e separadores como hífen, vírgulas, ponto-e-vírgula, etc.
 *   Obs.: Considere que serão fornecidas apenas strings sem acentos gráficos como á ou é;
 *         crie funções para eliminar os espaços em brancos e separadores de forma a
 *         facilitar a busca de palíndromos.
 */

#include <iostream>
#include <cstring>

using namespace std;

char *escaped_string(char *str);
bool is_palidrome(char const *str);

int main(int argc, char const *argv[]) {
	cout << is_palidrome("arara") << endl;
	cout << is_palidrome("anilina") << endl;
	cout << is_palidrome("mirim") << endl;
	cout << is_palidrome("radar") << endl;
	cout << is_palidrome("rotor") << endl;
	cout << is_palidrome("osso") << endl;
	cout << is_palidrome("ovo") << endl;
	cout << is_palidrome("iriri") << endl;
	cout << is_palidrome("mussum") << endl;
	cout << is_palidrome("A rara arara") << endl;
	cout << is_palidrome("Socorram-me, subi no onibus em Marrocos") << endl;
	cout << is_palidrome("A mala nada na lama") << endl;

	return EXIT_SUCCESS;
}

char *escaped_string(char const *str) {
	int str_size = strlen(str);
	char *new_str;
	try {
		new_str = new char [str_size];
	}catch (const bad_alloc & e) {
		cerr << "[escape_string()]: bad_alloc caught:" << e.what() << "\n";
	}

	for (int i = 0, j = 0; i < str_size; i++)
		if (*(str+i) >= 32 && *(str+i) <= 63)
			continue;
		else
			*(new_str+j++) = tolower(*(str+i));

	return new_str;
}

bool is_palidrome(char const *str) {
	char *escaped_str = escaped_string(str);
	int str_size = strlen(escaped_str);

	for (int i = 0; i < str_size/2; i++)
		if (*(escaped_str+i) != *(escaped_str+str_size-i-1))
			return false;

	return true;
}
