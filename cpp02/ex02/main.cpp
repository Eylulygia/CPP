#include <iostream>
#include "Fixed.hpp"

int main( void ) {

    std::cout << "=== Subject Tests ===" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;


    std::cout << "\n=== Comparison Operators ===" << std::endl;
    Fixed f1(10);
    Fixed f2(20);
    std::cout << "f1 is " << f1 << " | f2 is " << f2 << std::endl;
    std::cout << "f1 > f2  : " << (f1 > f2) << std::endl;
    std::cout << "f1 < f2  : " << (f1 < f2) << std::endl;
    std::cout << "f1 >= f2 : " << (f1 >= f2) << std::endl;
    std::cout << "f1 <= f2 : " << (f1 <= f2) << std::endl;
    std::cout << "f1 == f2 : " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2 : " << (f1 != f2) << std::endl;

    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed f3(2);
    Fixed f4(4.25f);
    std::cout << "f3 is " << f3 << " | f4 is " << f4 << std::endl;
    std::cout << "f3 + f4 = " << (f3 + f4) << std::endl;
    std::cout << "f4 - f3 = " << (f4 - f3) << std::endl;
    std::cout << "f3 * f4 = " << (f3 * f4) << std::endl;
    std::cout << "f4 / f3 = " << (f4 / f3) << std::endl;


    std::cout << "\n=== Min/Max Functions ===" << std::endl;
    std::cout << "Min of (f1, f2): " << Fixed::min(f1, f2) << std::endl;
    std::cout << "Max of (f1, f2): " << Fixed::max(f1, f2) << std::endl;

    return 0;
}
