#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors & Destructor (From ex00 & ex01)
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& target);
    ~Fixed();

    // Raw bits accessors
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed& target) const;
    bool operator<(const Fixed& target) const;
    bool operator>=(const Fixed& target) const;
    bool operator<=(const Fixed& target) const;
    bool operator==(const Fixed& target) const;
    bool operator!=(const Fixed& target) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& target) const;
    Fixed operator-(const Fixed& target) const;
    Fixed operator*(const Fixed& target) const;
    Fixed operator/(const Fixed& target) const;

    // Increment/Decrement operators
    Fixed& operator++(void);       // Pre-increment
    Fixed operator++(int);        // Post-increment
    Fixed& operator--(void);       // Pre-decrement
    Fixed operator--(int);        // Post-decrement

    // Static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream operator
std::ostream & operator<<(std::ostream & o, Fixed const & target);

#endif
