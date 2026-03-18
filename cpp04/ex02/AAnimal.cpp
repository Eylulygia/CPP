#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : type(src.type) {
    std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
    std::cout << "AAnimal copy assignment" << std::endl;
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
