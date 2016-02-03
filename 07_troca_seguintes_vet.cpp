#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int b[20];

	// Read vector values
	for (int i = 0; i < 20; i++)
		cin >> b[i];

	// Print vector
	for (int i = 0; i < 20; i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	cout << "Changing positions (odd <-> even)..." << endl;

	// Change positions (odd <-> even)
	for (int i = 0, t; i < 20 - 1; i += 2)
		t = b[i], b[i] = b[i+1], b[i+1] = t;

	// Print new vector
	for (int i = 0; i < 20; i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	return EXIT_SUCCESS;
}