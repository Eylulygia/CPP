#include "HumanA.hpp"

// Referans olan üyeler MUTLAKA initialization list içinde ilklendirilmelidir.
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
