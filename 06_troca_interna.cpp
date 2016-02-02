#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int a[20];

	// Read vector values
	for (int i = 0; i < 20; i++)
		cin >> a[i];

	// Display vector values
	for (int i = 0; i < 20; i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	cout << "Changing values..." << endl;

	// Change values
	for (int i = 0; i < 20/2; i++) {
		int t;
		t = a[i], a[i] = a[20-i-1], a[20-i-1] = t;
	}

	// Display vector values
	for (int i = 0; i < 20; i++)
		cout << "a[" << i << "] = " << a[i] << endl;

	return EXIT_SUCCESS;
}