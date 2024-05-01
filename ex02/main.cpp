#include <iostream>
#include "Fixed.hpp"

/**
 * @brief Main function to demonstrate the usage of the Fixed class.
 * 
 * The main function creates instances of the Fixed class and performs various operations
 * to demonstrate the functionality of the Fixed class, including initialization, 
 * arithmetic operations, prefix and postfix increment, and using static member functions.
 * 
 * @return 0 indicating successful execution.
 */
int main( void ) 
{
    Fixed a;
    
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}