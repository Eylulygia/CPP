#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog copy assignment" << std::endl;
    if (this != &src) {
        Animal::operator=(src);
        *this->brain = *src.brain;
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog: Woof woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}
