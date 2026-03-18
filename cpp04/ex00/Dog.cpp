#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog copy assignment" << std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog says: Woof!" << std::endl;
}
