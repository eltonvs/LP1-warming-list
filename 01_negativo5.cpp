#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	auto a(0);
	auto n_neg(0u);

	for (int i = 0; i < 5; i++) {
		cout << "Enter the " << i+1 << "º number: ";
		cin >> a;
		if (a < 0) n_neg++;
	}

	cout << n_neg << " negative numbers " << (n_neg > 1 ? "were" : "was") << " entered" << endl;

	return EXIT_SUCCESS;
}