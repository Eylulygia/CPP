#include "Replacer.hpp"

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << "Usage: ./sed_for_losers <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cout << "Error: The string to be replaced (s1) cannot be empty." << std::endl;
		return 1;
	}

	return Replacer::process(filename, s1, s2);
}
