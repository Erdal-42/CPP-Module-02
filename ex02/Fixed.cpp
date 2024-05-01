
#include "Fixed.hpp"

const int Fixed::binaryPos = 8;

//Default Constructor
Fixed::Fixed() : value(0)
{
#ifdef DEBUG    
    std::cout << "Default constructor called" << std::endl;
#endif
}

/*
 * An overloaded constructor that takes a constant 
 * integer as a parameter. It converts it to the 
 * corresponding fixed-point value. 
 */
Fixed::Fixed(const int anInteger)
{
#ifdef DEBUG 
    std::cout << "Int constructor called" << std::endl;
#endif
    value = anInteger << binaryPos;
}

/*
 * A constructor that takes a constant floating-point 
 * number as a parameter. It converts it to the 
 * corresponding fixed-point value. The fractional 
 * bits value is initialized to 8 like in exercise 00.
 */

Fixed::Fixed(const float aFloat)
{
#ifdef DEBUG 
    std::cout << "Float constructor called" << std::endl;
#endif
    value = roundf(aFloat * (1 << binaryPos));
}

/* 
 * 
 * Copy constructor: Is is used to clone a new object from an existing object.
 * It is used to generate a new object and initialize it with the values of
 * another object.
 * 
 * @param: The cloned object is the parameter.
 */

Fixed::Fixed(const Fixed& other) 
{
#ifdef DEBUG 
    std::cout << "Copy constructor called" << std::endl;
#endif
    *this = other;
}

/*
 *
 * Copy assignment operator: This function is used
 * to assign the values of the data members of one
 * object to another existing object of the same class 
 * that needs to be initialized. It is directly 
 * invoked by using the "=" operator between the two 
 * objects.
 * 
 * @return the left side of the "=" equation to itself. 
 */

Fixed &Fixed::operator=(const Fixed  &other)
{
#ifdef DEBUG 
    std::cout << "Copy assignment operator called" << std::endl;
#endif
    if (this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

//Destructor
Fixed::~Fixed()
{
#ifdef DEBUG 
    std::cout << "Destructor called" << std::endl;
#endif
}

//Returns the raw value of the fixed-point value
int     Fixed::getRawBits(void) const
{
    return (value);
}

//Sets the raw value of the fixed-point number
void    Fixed::setRawBits(int const theValue)
{
#ifdef DEBUG 
    std::cout << "setRawBits member function called" << std::endl;
#endif
    value = theValue;
}

/*
 * A member function that converts the fixed-point 
 * value to a floating-point value. (Burada constructordakinin tersini gerçekleştirebilirim.)
 */

float   Fixed::toFloat(void) const
{
#ifdef DEBUG
    std::cout << "toFloat member function called" << std::endl;
#endif
    return (float)value / (float)(1 << binaryPos);
}

/*
 * A member function that converts the 
 * fixed-point value to an integer value.
 */

int Fixed::toInt(void) const
{
#ifdef DEBUG
    std::cout << "toInt member function called" << std::endl;
#endif
    return ((int)value >> binaryPos);
}


/*
 * An overload of the > operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool Fixed::operator>(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator > member function called" << std::endl;
#endif
    return (toFloat() > other.toFloat());
}

/*
 * An overload of the < operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool Fixed::operator<(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator < member function called" << std::endl;
#endif
    return (toFloat() < other.toFloat());
}

/*
 * An overload of the >= operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool Fixed::operator>=(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator >= member function called" << std::endl;
#endif    
    return (toFloat() >= other.toFloat());
}

/*
 * An overload of the <= operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool Fixed::operator<=(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator <= member function called" << std::endl;
#endif
    return (toFloat() >= other.toFloat());
}

/*
 * An overload of the == operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool Fixed::operator==(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator == member function called" << std::endl;
#endif
    return (toFloat() == other.toFloat());
}

/*
 * An overload of the != operator for type field objects.
 *  
 * @return: Returns a true/false bool. 
 */

bool    Fixed::operator!=(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator != member function called" << std::endl;
#endif
    return (toFloat() != other.toFloat());
}

/*
 * An overload of the + operator for type field objects.
 *  
 * @return: Returns the current fixed object wih the 
 * preceeding value added. 
 */

Fixed   Fixed::operator+(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator + member function called" << std::endl;
#endif
    return Fixed(toFloat() + other.toFloat());
}

/*
 * An overload of the - operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * preceeding value subtracted. 
 */

Fixed   Fixed::operator-(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator - member function called" << std::endl;
#endif
    return Fixed(toFloat() - other.toFloat());
}

/*
 * An overload of the * operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value multiplied by the preceeding value. 
 */

Fixed   Fixed::operator*(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator - member function called" << std::endl;
#endif
    return Fixed(toFloat() * other.toFloat());
}

/*
 * An overload of the / operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value divided by the preceeding value. 
 */

Fixed   Fixed::operator/(const Fixed &other)
{
#ifdef DEBUG
    std::cout << "operator / member function called" << std::endl;
#endif
    return Fixed(toFloat() / other.toFloat());
}

/*
 * An overload of the pre increment operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value pre incremented. 
 */

Fixed   Fixed::operator++(void)
{
#ifdef DEBUG
    std::cout << "operator pre ++ member function called" << std::endl;
#endif
    ++ value;
    return (*this);
}

/*
 * An overload of the post increment operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value post incremented. 
 */

Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
#ifdef DEBUG
    std::cout << "operator post ++ member function called" << std::endl;
#endif
    value ++;
    return (temp);
}

/*
 * An overload of the pre decrement operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value pre decremented. 
 */

Fixed   Fixed::operator--(void)
{
#ifdef DEBUG
    std::cout << "operator pre -- member function called" << std::endl;
#endif
    -- value;
    return (*this);
}

/*
 * An overload of the post decrement operator for type field objects.
 *  
 * @return: Returns the current fixed object with the 
 * value pre incremented. 
 */

Fixed   Fixed::operator--(int)
{
    Fixed temp(*this);
#ifdef DEBUG
    std::cout << "operator post -- member function called" << std::endl;
#endif
    value --;
    return (temp);
}

/*
 * This function finds the smallest of two fixed numbers.
 *  
 * @return: Returns the current fixed object with the 
 * value pre incremented. 
 */

Fixed   &Fixed::min(Fixed &f1, Fixed &f2)
{
#ifdef DEBUG
    std::cout << "Min member function called" << std::endl;
#endif    
    if (f1.toFloat() <= f2.toFloat())
        return (f1);
    return (f2);
}

/*
 * A static member function min that takes as parameters 
 * two references to constant fixed-point numbers, and 
 * returns a reference to the smallest one.
 */

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
#ifdef DEBUG
    std::cout << "Const min member function called" << std::endl;
#endif 
    if (f1.toFloat() <= f2.toFloat())
		return (f1);
    return (f2);
}

/*
 * This function finds the largest of two fixed numbers.
 *  
 * @return: Returns the fixed object with the 
 * maximum value. 
 */

Fixed   &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return (f1);
    return (f2);
}

/*
 * A static member function that takes as parameters 
 * two references to constant fixed-point numbers and 
 * returns a reference to the fixed object with largest
 * value.
 * 
 * @return: Returns the fixed object with the 
 * maximum value.
 */

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1.toFloat() >= f2.toFloat())
		return (f1);
    return (f2);
}

/*
 * An overload of the print operator.
 * 
 * @return: the new output stream.
 */
std::ostream   &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
	return o;
}