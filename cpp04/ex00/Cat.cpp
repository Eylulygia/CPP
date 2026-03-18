#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat copy assignment" << std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat says: Meow!" << std::endl;
}
