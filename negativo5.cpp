#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	auto a(0);
	auto n_neg(0u);

	for (int i = 0; i < 5; i++) {
		std::cout << "Enter the " << i+1 << "º number: ";
		std::cin >> a;
		if (a < 0) n_neg++;
	}

	std::cout << n_neg << " negative numbers " << (n_neg > 1 ? "were" : "was") << " entered" << "\n";

	return EXIT_SUCCESS;
}