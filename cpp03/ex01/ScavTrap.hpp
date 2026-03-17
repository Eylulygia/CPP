#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const ScavTrap& src);
    ScavTrap& operator=(const ScavTrap& target);
    ~ScavTrap();

    ScavTrap(std::string name);

    void attack(const std::string& target);
    void guardGate();
};

#endif
