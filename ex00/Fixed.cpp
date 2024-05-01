
#include "Fixed.hpp"

const int Fixed::binaryPos = 8;

/**
* @brief Default constructor.
*/
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
* @brief Copy constructor.
* @param other The Fixed object to copy from.
*/
Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
* @brief Overload of the copy assignment operator.
* @param other The Fixed object to assign from.
* @return A reference to the assigned Fixed object.
*/
Fixed &Fixed::operator=(const Fixed  &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

/**
* @brief Destructor.
*/
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/**
* @brief Returns the raw value of the fixed-point number.
* @return The raw value of the fixed-point number.
*/
int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

/**
* @brief Sets the raw value of the fixed-point number.
* @param theValue The raw value to set.
*/
void    Fixed::setRawBits(int const theValue)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = theValue;
}