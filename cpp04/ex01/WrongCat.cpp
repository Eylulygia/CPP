#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
    std::cout << "WrongCat copy assignment" << std::endl;
    if (this != &src) {
        WrongAnimal::operator=(src);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Mismatched meow" << std::endl;
}
