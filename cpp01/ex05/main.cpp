#include "Harl.hpp"

int main(void) {
	Harl harl;

	std::cout << "--- Harl starts his usual day ---" << std::endl << std::endl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "--- Test with an unknown level ---" << std::endl;
	harl.complain("I_WANT_FREE_FOOD");

	return 0;
}
