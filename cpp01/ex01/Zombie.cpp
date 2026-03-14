#include "Zombie.hpp"

Zombie::Zombie() : _personalName("Unnamed") {
}

Zombie::Zombie(std::string name) : _personalName(name) {
}

Zombie::~Zombie() {
	std::cout << RED << "Zombie " << _personalName << " successfully neutralised." << RESET << std::endl;
}

void Zombie::announce(void) {
	std::cout << GREEN << _personalName << RESET << ": BraiiiiiiinnnzzzZ... " << YELLOW << "[Hrr-gh]" << RESET << std::endl;
}

void Zombie::setName(std::string name) {
	_personalName = name;
}
