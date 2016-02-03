/*
 * Question:
 * Escreva um programa em C/C++ chamado intervalos.cpp que lê um número não
 * conhecido de valores, um de cada vez, e conta quantos deles estão em cada um dos
 * intervalos [0, 25), [25, 50), [50, 75) e [75, 100].
 */


#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int x;
	auto tot(0);
	auto int1(0);
	auto int2(0);
	auto int3(0);
	auto int4(0);

	cout << "Enter integer numbers (Press Ctrl + D to exit):" << endl;

	while (cin >> x) {
		if (x >= 0 && x < 25) int1++;
		else if (x >= 25 && x < 50) int2++;
		else if (x >= 50 && x < 75) int3++;
		else if (x >= 75 && x <= 100) int4++;
		tot++;
	}

	cout << static_cast<float>(int1)/tot*100 << '%' << " on interval [0, 25)" << endl;
	cout << static_cast<float>(int2)/tot*100 << '%' << " on interval [25, 50)" << endl;
	cout << static_cast<float>(int3)/tot*100 << '%' << " on interval [50, 75)" << endl;
	cout << static_cast<float>(int4)/tot*100 << '%' << " on interval [75, 100]" << endl;

	return EXIT_SUCCESS;
}