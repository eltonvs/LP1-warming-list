#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int m, n, sum;
	cout << "Enter two integer numbers (Press Ctrl + D to exit):" << endl;

	while(cin >> m && cin >> n) {
		for (int i = 0; i < n; i++)
			sum += m + i + 1; // +1 because i starts with 0
		cout << "The sum of " << n << " consecutive integers from " << m << " is " << sum << endl;
		sum = 0;
	}

	return EXIT_SUCCESS;
}