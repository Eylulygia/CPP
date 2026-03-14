#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define YELLOW "\033[33m"
# define BLUE   "\033[34m"
# define RESET  "\033[0m"

class Zombie {
public:

	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void setName(std::string name);

private:
	std::string _personalName;
};

Zombie* zombieHorde(int N, std::string name);

#endif
