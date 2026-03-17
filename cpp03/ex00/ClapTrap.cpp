#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Name constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& target) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &target) {
        this->_name = target._name;
        this->_hitPoints = target._hitPoints;
        this->_energyPoints = target._energyPoints;
        this->_attackDamage = target._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount 
              << " points of damage! Current hit points: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no hit points left to repair itself!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy points left to repair itself!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself, regaining " << amount 
              << " hit points! Current hit points: " << this->_hitPoints << std::endl;
}
