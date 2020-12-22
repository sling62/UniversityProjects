#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
    private:
		//declaring a double pointer to a private Polynomial coefficients array as it should be not modified outside of the Polynomial Class
        double* coefficients;
    public:
		// degree of the polynomial is stored as an integer
        int degree; 
		//default constructor 
        Polynomial();
		//copy constructor
        Polynomial(const Polynomial &rhs);
		//destructor 
        ~Polynomial();
		//normal constructor declared to initialise a passed in coefficients array and degree to Polynomial 
        Polynomial(double* coefficients, int degree);
		//gets a coefficient based on the power (passed in by the user) of the coefficient 
        double getCoefficient(int power) const;
		//returns the Polynomial value when the value of x is supplied by the user
        double getPolynomialValue (double x);
		//assignment operator (to assign one Polynomial to another) then return a pointer to the Polynomial
        Polynomial& operator=(const Polynomial& rhs);
		//+, -, * operators to add or subtract or mutiply one polynomial and another, this then returns a new polynomial with the result of the operation 
        Polynomial operator+(const Polynomial& rhs);
        Polynomial operator-(const Polynomial& rhs);
        Polynomial operator*(const Polynomial& rhs);
		//mutiply function to mutiply a polynomial with a int or double, this then returns a pointer to the polynomial with the polynomial coefficients changed as a result of the mutiplication 
        Polynomial& multiply(double k);

		//boolean operators to compare if one polynomial is equal to or not equal to another polynomial, this checks all the internal coefficients at the indexes(or the power value) of the coefficients array to see if they are the same and returns 0 or 1   
        bool operator==(const Polynomial& rhs);
        bool operator!=(const Polynomial& rhs);
		//same as +, - or * operators however applies operation to the current polynomial which is being pointed to and returns the pointer
        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);

        //declared own implemented functions for cleaner code
		//getBiggestDegree takes two polynomials and compares their degrees to see which is the bigger degree and returns that value 
        int getBiggestDegree(const Polynomial& rhs);
		//mutiply polynomial returns a pointer to a double coefficients array which is the result of the mutiplication of two polynomials operation
        double* multiplyPolynomials(const Polynomial& rhs, int degree);


};

//io operators overloaded to print and take in polynomial coefficient values 
std::ostream & operator << (std::ostream &out, const Polynomial &rhs); 
std::istream & operator >> (std::istream &in, Polynomial &rhs); 

#endif // POLYNOMIAL_H