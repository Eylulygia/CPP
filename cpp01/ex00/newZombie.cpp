#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* createdZombie = new Zombie(name);
	return (createdZombie);
}
