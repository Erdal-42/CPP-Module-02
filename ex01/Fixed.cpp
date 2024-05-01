
#include "Fixed.hpp"
#include <cmath>

const int Fixed::binaryPos = 8;


/**
* @brief Default constructor.
*/
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/**
* @brief Constructor that takes an integer as a parameter.
* @param anInteger The integer value to be converted to a fixed-point number.
*/
Fixed::Fixed(const int anInteger)
{
    std::cout << "Int constructor called" << std::endl;
    value = anInteger << binaryPos;
}

/**
* @brief Constructor that takes a float as a parameter.
* @param aFloat The float value to be converted to a fixed-point number.
*/
Fixed::Fixed(const float aFloat)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(aFloat * (1 << binaryPos));  
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

/**
* @brief Converts the fixed-point value to a floating-point value.
* @return The floating-point representation of the fixed-point value.
*/
float   Fixed::toFloat(void) const
{
    return (float)value / (float)(1 << binaryPos);
}

/**
* @brief Converts the fixed-point value to an integer value.
* @return The integer representation of the fixed-point value.
*/
int Fixed::toInt(void) const
{
//    std::cout << "toInt member function called" << std::endl;
    return ((int)value >> binaryPos);
}

/**
* @brief Overload of the insertion operator for Fixed objects.
* @param o The output stream.
* @param fixed The Fixed object to output.
* @return The output stream.
*/
std::ostream   &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
	return o;
}