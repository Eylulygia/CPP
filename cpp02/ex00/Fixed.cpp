#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    // this->_fixedPointValue = src.getRawBits(); // Alternatif
    *this = src; // Assignment operator'ı kullanmak daha best practice
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// getRawBits member function
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

// setRawBits member function
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}
