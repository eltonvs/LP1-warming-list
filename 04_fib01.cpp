#include <iostream>

using namespace std;

int fib(int n) {
	return (n == 0 || n == 1) ? 1 : fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[]) {
	int l;

	cout << "Enter a number: ";
	cin >> l;

	for (int i = 0; fib(i) < l; i++)
		cout << fib(i) << " ";

	cout << endl;

	return EXIT_SUCCESS;
}