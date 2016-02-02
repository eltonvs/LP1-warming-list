#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int c[20];

	// Get vector data
	for (int i = 0; i < 20; i++)
		cin >> c[i];

	// Print vector
	for (int i = 0; i < 20; i++)
		cout << "c[" << i << "] = " << c[i] << endl;

	// Remove negative/null values from vector
	for (int i = 0; i < 20; i++)
		if (c[i] <= 0) c[i] = 0;

	// Print new vector
	for (int i = 0; i < 20; i++)
		if (c[i] != 0)
			cout << "c[" << i << "] = " << c[i] << endl;

	return EXIT_SUCCESS;
}