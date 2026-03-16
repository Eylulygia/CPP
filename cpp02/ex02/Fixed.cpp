#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

Fixed::Fixed(const float f) : _fixedPointValue(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& src) {
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& target) {
    if (this != &target) {
        this->_fixedPointValue = target.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// --- COMPARISON OPERATORS ---

bool Fixed::operator>(const Fixed& target) const { return this->_fixedPointValue > target.getRawBits(); }
bool Fixed::operator<(const Fixed& target) const { return this->_fixedPointValue < target.getRawBits(); }
bool Fixed::operator>=(const Fixed& target) const { return this->_fixedPointValue >= target.getRawBits(); }
bool Fixed::operator<=(const Fixed& target) const { return this->_fixedPointValue <= target.getRawBits(); }
bool Fixed::operator==(const Fixed& target) const { return this->_fixedPointValue == target.getRawBits(); }
bool Fixed::operator!=(const Fixed& target) const { return this->_fixedPointValue != target.getRawBits(); }

// --- ARITHMETIC OPERATORS ---

Fixed Fixed::operator+(const Fixed& target) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue + target.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed& target) const {
    Fixed res;
    res.setRawBits(this->_fixedPointValue - target.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed& target) const {
    return Fixed(this->toFloat() * target.toFloat());
}

Fixed Fixed::operator/(const Fixed& target) const {
    if (target.getRawBits() == 0) {
        std::cout << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / target.toFloat());
}

// --- INCREMENT / DECREMENT OPERATORS ---

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

// --- STATIC MIN/MAX FUNCTIONS ---

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

// --- STREAM OPERATOR ---

std::ostream & operator<<(std::ostream & o, Fixed const & target) {
    o << target.toFloat();
    return o;
}
