#include <iostream>
#include "Fixed.hpp"

/**
* @brief Main function to demonstrate the usage of the Fixed class.
* 
* This function creates three Fixed objects, `a`, `b`, and `c`, and demonstrates
* the use of the copy constructor and copy assignment operator. It then prints
* the raw bit values of each object.
* 
* @return 0 on success.
*/

int main(void) 
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
   
    return 0;
}