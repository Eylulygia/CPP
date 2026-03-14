#include "Zombie.hpp"

int main(void) {
	std::cout << "[STACK] - Creating a temporary zombie in randomChump..." << std::endl;
	randomChump("I am short lived");
	std::cout << "[STACK] - Execution has returned to main. The zombie should be already dead." << std::endl;

	std::cout << "\n------------------------------------------------\n" << std::endl;

	std::cout << "[HEAP] - Creating a long living zombie using newZombie..." << std::endl;
	Zombie* persistentZombie = newZombie("I live longer");
	std::cout << "[HEAP] - The zombie has been created but hasn't announced yet." << std::endl;
	
	persistentZombie->announce();

	std::cout << "[HEAP] - main is about to delete the persistent zombie..." << std::endl;
	delete persistentZombie; 
	std::cout << "[HEAP] - persistentZombie is now deleted." << std::endl;

	std::cout << "\n[FINAL] - The program is finishing now." << std::endl;
	return (0);
}
