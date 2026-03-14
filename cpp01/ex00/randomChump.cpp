#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie temporaryZombie(name);
	temporaryZombie.announce();
}
