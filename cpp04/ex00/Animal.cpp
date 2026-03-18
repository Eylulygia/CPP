#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& src) : type(src.type) {
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
    std::cout << "Animal copy assignment" << std::endl;
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "Animal is confused and stays quiet" << std::endl;
}
