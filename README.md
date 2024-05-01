In this module I had to demonstrate polymorphism, operator overloading and Orthodox Canonical class formations in C++. I had to structure my files as header files and source files.  

**TASKS**

---

**Ex00:**

Write a class in Orthodox Canonical Form that represents a fixed-point number:

- Private members:
  - An integer to store the fixed-point number value.
  - A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.

- Public members:
  - A default constructor that initializes the fixed-point number value to 0.
  - A copy constructor.
  - A copy assignment operator overload.
  - A destructor.
  - A member function `int getRawBits( void ) const;` that returns the raw value of the fixed-point value.
  - A member function `void setRawBits( int const raw );` that sets the raw value of the fixed-point number.

---

**Ex01:**

Add the following public constructors and public member functions to your class:

- A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in ex 00.
- A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in ex 00.
- A member function `float toFloat( void ) const;` that converts the fixed-point value to a floating-point value.
- A member function `int toInt( void ) const;` that converts the fixed-point value to an integer value.

And add the following function to the Fixed class files:

- An overload of the insertion (`<<`) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.

---

**Ex02:**

Add public member functions to your class to overload the following operators:

- The 6 comparison operators: >, <, >=, <=, == and !=.
- The 4 arithmetic operators: +, -, *, and /.
- The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators, that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.

Add these four public overloaded member functions to your class:

- A static member function `min` that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
- A static member function `min` that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
- A static member function `max` that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
- A static member function `max` that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.

---
