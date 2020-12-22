#ifndef CUBIC_H
#define CUBIC_H
#include <iostream>

class Cubic {
    private:
		//private fields declared for each coefficient of the cubic as the known degree is 3

		//zero is the coefficient of power 0 
        double zero; 
		//one is the coefficient of power 1 
        double one;
		//two is the coefficient of power 2 
        double two;
		//three is the coefficient of power 3 
        double three;
         
    public:
		//default constructor
        Cubic();
		//initialisng a cubic by passing in the cubic coefficient values for each power 
        Cubic(double three, double two, double one, double zero);
		//getting a coefficient depending on the power passed in by the user  
        double getCoefficient(int power) const;
		//returning the value of the cubic when x value is supplied by the user 
        double getCubicValue (double x);
		//+ and - operators to add or subtract cubic coefficient values from one another and the result of the operation is returned as a cubic 
        Cubic operator+(const Cubic& rhs);
        Cubic operator-(const Cubic& rhs);
		//mutiply function to multiply the currently pointed to cubic coefficient values by a int or double, this then returns a pointer to the cubic   
        Cubic& multiply(double k);
		//boolean operators to compare if one cubic is equal to or not equal to another cubic, this checks private fields zero, one, two, three (coefficients of indexes) to see if they are the same and returns 0 or 1   
        bool operator==(const Cubic& rhs);
        bool operator!=(const Cubic& rhs);
		//same as + and - operators however applies operation to the current polynomial which is being pointed to and returns the pointer
        Cubic& operator+=(const Cubic & rhs);
        Cubic& operator-=(const Cubic & rhs);
};

//io operators overloaded to print and take in cubic coefficient values 
std::ostream& operator << (std::ostream &out, const Cubic &rhs); 
std::istream& operator >> (std::istream &in, Cubic &rhs); 

#endif // CUBIC_H