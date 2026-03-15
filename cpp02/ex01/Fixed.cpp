#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int Constructor
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Float Constructor
Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
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

// Raw Bits accessors
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Conversions
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// Insertion operator overload
std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}
