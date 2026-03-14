#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _zName(name) {

}

Zombie::~Zombie() {
	std::cout << "--- " << _zName << " finally returned to the graveland. Rest in pieces." << std::endl;
}

void Zombie::announce(void) {
	std::cout << _zName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
