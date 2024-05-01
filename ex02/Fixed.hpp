
#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>
//#define DEBUG

class Fixed
{
    private:
        int                 value;        //value of the fixed point number
        static const int    binaryPos;    //binary position of the fixed point number

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
        Fixed   &operator=(const Fixed &other);
        //Destructor
        ~Fixed();
        //Returns the raw value of the fixed-point value
        int     getRawBits(void) const;
        //Sets the raw value of the fixed-point number
        void    setRawBits(int const);
        //Converts the fixed-point value to a floating-point value.
        float toFloat(void) const;
        //Converts the fixed-point value to an int value.
        int toInt(void) const;
        //An overload of the greater than operator
        bool operator>(const Fixed &);
        //An overload of the less than operator
        bool operator<(const Fixed &);
        //An overload of the greater than or equal to operator
        bool operator>=(const Fixed &);
        //An overload of the less than or equal to operator
        bool operator<=(const Fixed &);
        //An overload of the equal to operator
        bool operator==(const Fixed &);
        //An overload of the not equal to operator
        bool operator!=(const Fixed &);
        //An overload operator for the plus operator
        Fixed   operator+(const Fixed &);
        //An overload operator for the minus operator
        Fixed   operator-(const Fixed &);
        //An overload operator for the multiply operator
        Fixed   operator*(const Fixed &);        
        //An overload operator for the divide operator
        Fixed   operator/(const Fixed &);
        //An overload operator for the pre-increment operator
        Fixed   operator++();
        //An overload operator for the post-increment operator
        Fixed   operator++(int);
        //An overload operator for the pre-decrement operator
        Fixed   operator--();
        //An overload operator for the post-decrement operator
        Fixed   operator--(int);
        /*
         * A static member function min that takes as parameters 
         * two references on fixed-point numbers and returns a 
         * reference to the smallest one.
         */
        static Fixed &min(Fixed &, Fixed &);
        /*
         * A static member function min that takes as parameters 
         * two references to constant fixed-point numbers and 
         * returns a reference to the smallest one.
         */
        static const Fixed &min(const Fixed &, const Fixed &);
        /*
         * A static member function min that takes as parameters 
         * two references on fixed-point numbers and returns a 
         * reference to the smallest one.
         */
         static Fixed &max(Fixed &, Fixed &);
        /*
         * A static member function min that takes as parameters 
         * two references to constant fixed-point numbers and 
         * returns a reference to the smallest one.
         */
         static const Fixed &max(const Fixed &, const Fixed &);
};

//An overload of the insert operator
std::ostream   &operator<<(std::ostream &o, Fixed const &fixed);

#endif