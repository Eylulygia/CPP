#include "Fixed.hpp"

// Constructors & Destructor
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& src) {
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

// Raw bits
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

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const { return this->_fixedPointValue > rhs.getRawBits(); }
bool Fixed::operator<(const Fixed& rhs) const { return this->_fixedPointValue < rhs.getRawBits(); }
bool Fixed::operator>=(const Fixed& rhs) const { return this->_fixedPointValue >= rhs.getRawBits(); }
bool Fixed::operator<=(const Fixed& rhs) const { return this->_fixedPointValue <= rhs.getRawBits(); }
bool Fixed::operator==(const Fixed& rhs) const { return this->_fixedPointValue == rhs.getRawBits(); }
bool Fixed::operator!=(const Fixed& rhs) const { return this->_fixedPointValue != rhs.getRawBits(); }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue + rhs.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue - rhs.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment / Decrement
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

// Static min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Stream operator
std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}
