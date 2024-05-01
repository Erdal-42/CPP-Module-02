#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    private:
    int                     value;          // The raw value of the fixed-point number.
        static const int    binaryPos;      // The position of the binary point.

    public:
        //Default constructor
        Fixed(void);
        //Copy constructor
        Fixed(const Fixed&);
        //Copy assignment operator
        Fixed   &operator=(const Fixed  &other);
        //Destructor
        ~Fixed();
        //Returns the raw value of the fixed-point value
        int     getRawBits(void) const;
        //Sets the raw value of the fixed-point number
        void    setRawBits(int const);
};

#endif