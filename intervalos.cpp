#include <iostream>

using namespace std;

int is_on_int_1(int n) {
	return (n >= 0 && n < 25) ? 1 : 0;
}
int is_on_int_2(int n) {
	return (n >= 25 && n < 50) ? 1 : 0;
}
int is_on_int_3(int n) {
	return (n >= 50 && n < 75) ? 1 : 0;
}
int is_on_int_4(int n) {
	return (n >= 75 && n <= 100) ? 1 : 0;
}

int main(int argc, char const *argv[]) {
	int x;
	auto tot(0);
	auto int1(0);
	auto int2(0);
	auto int3(0);
	auto int4(0);

	std::cout << "Entre com valores inteiros ( Ctrl + d p / encerrar ): " << endl;

	while (cin >> x) {
		if (is_on_int_1(x)) int1++;
		if (is_on_int_2(x)) int2++;
		if (is_on_int_3(x)) int3++;
		if (is_on_int_4(x)) int4++;
		tot++;
	}

	std::cout << static_cast<float>(int1)/tot*100 << '%' << " on interval [0, 25)" << endl;
	std::cout << static_cast<float>(int2)/tot*100 << '%' << " on interval [25, 50)" << endl;
	std::cout << static_cast<float>(int3)/tot*100 << '%' << " on interval [50, 75)" << endl;
	std::cout << static_cast<float>(int4)/tot*100 << '%' << " on interval [75, 100]" << endl;

	return EXIT_SUCCESS;
}