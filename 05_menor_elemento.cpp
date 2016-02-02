#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	float vet[20], smaller_num;
	int smaller_p;

	// Read vector values
	for (int i = 0; i < 20; i++)
		cin >> vet[i];

	// Print vector
	for (int i = 0; i < 20; i++)
		cout << "vet[" << i << "] = " << vet[i] << endl;

	// Find the smaller number on vector
	for (int i = 0; i < 20; i++)
		if (i == 0) smaller_num = vet[0], smaller_p = 0;
		else if (vet[i] < smaller_num) smaller_num = vet[i], smaller_p = i;

	cout << "The smaller number on given vector is " << smaller_num << " and is on position " << smaller_p << endl;

	return EXIT_SUCCESS;
}