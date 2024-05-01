#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int                 value;              // The raw value of the fixed-point number.
        static const int    binaryPos;      // The position of the binary point.


    public:
        //Default constructor
        Fixed(void);
        //A constructor that takes a constant integer as a parameter.
        Fixed(const int);
        //A constructor that takes a constant float as a parameter.
        Fixed(const float);
        //Copy constructor
        Fixed(const Fixed&);
        //An overload of the copy assignment operator
        Fixed   &operator=(const Fixed  &other);
        //Destructor
        ~Fixed();
        //Returns the raw value of the fixed-point value
        int     getRawBits(void) const;
        //Sets the raw value of the fixed-point number
        void    setRawBits(int const);
        //Converts the fixed-point value to a floating-point value.
        float   toFloat(void) const;
        //Converts the fixed-point value to an int value.
        int     toInt(void) const;
};

//An overload of the insert operator
std::ostream   &operator<<(std::ostream &o, Fixed const &fixed);

#endif