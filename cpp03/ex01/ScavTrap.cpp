#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Name constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& target) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &target) {
        ClapTrap::operator=(target);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy points left to attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target 
              << ", causing " << this->_attackDamage << " points of massive damage!" << std::endl;
}

void ScavTrap::guardGate() {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot guard the gate." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode. None shall pass!" << std::endl;
}
