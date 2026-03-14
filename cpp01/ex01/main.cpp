#include "Zombie.hpp"

int main(void) {
	int hordeSize = 5;
	
	std::cout << BLUE << "=== INITIALIZING THE HORDE (Size: " << hordeSize << ") ===" << RESET << std::endl;
	
	Zombie* myHorde = zombieHorde(hordeSize, "EYLUL");

	if (!myHorde) {
		std::cout << "Failed to summon the horde!" << std::endl;
		return (1);
	}

	std::cout << "\n=== THE HORDE STARTS ANNOUNCING ===" << std::endl;
	for (int i = 0; i < hordeSize; i++) {
		std::cout << "[" << i << "] ";
		myHorde[i].announce();
	}

	std::cout << "\n=== CLEANING UP THE STREETS (Deallocating...) ===" << RESET << std::endl;
	delete[] myHorde;

	std::cout << BLUE << "\n=== MISSION ACCOMPLISHED ===" << RESET << std::endl;
	return (0);
}
