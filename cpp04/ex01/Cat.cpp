#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), brain(new Brain(*src.brain)) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat copy assignment" << std::endl;
    if (this != &src) {
        Animal::operator=(src);
        *this->brain = *src.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat: Purr meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}
