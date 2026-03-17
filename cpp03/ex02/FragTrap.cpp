#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Name constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& target) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &target) {
        ClapTrap::operator=(target);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called for " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints == 0) {
        std::cout << "FragTrap " << this->_name << " is dead and cannot high five anyone." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " enthusiastically shouts: \"Hey guys, positive high fives all around! Come on! 🙌\"" << std::endl;
}
