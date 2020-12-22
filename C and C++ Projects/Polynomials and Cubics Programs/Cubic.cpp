#include "Cubic.h"
#include <math.h>
#include <iostream>

using namespace std;

/*
default constructor which assigns this cubic to coefficient values of 0 for each power (0 to the power zero, 0 to the power one, 0 to the power two, 0 to the power three) - ie 0^3 + 0^2 + 0^1 + 0
*/
Cubic::Cubic() {
	//coefficients represented as zero, one, two, three double fields
    this -> zero = 0.0; 
    this -> one = 0.0;
    this -> two = 0.0;
    this -> three = 0.0;
}

/*
normal constructor which assigns this cubic to the coefficient values passed in for each power ie. three^3 + two^2 + one^1 + zero
*/
Cubic::Cubic(double three, double two, double one, double zero) {
   this -> zero = zero; 
   this -> one = one;
   this -> two = two;
   this -> three = three;
}

/*
gets the coefficient field(zero, one, two, three) of the cubic by passing in/referring to the power value of either 0,1,2 or 3
*/
double Cubic::getCoefficient(int power) const{
    if(power == 0){
        return zero;
    }
    else if(power == 1){
        return one;
    }
    else if(power == 2){
        return two;
    }
    else if(power == 3){
        return three;
    }
    else{
		//in case if the user passes in a int which is greater than 3 or less than 0, will return 0 
        return 0;
    }
}

/*
gets the cubic value by passing in the value of x then mutiplying the coefficients(zero, one, two, three) by the value of x to the power of the associated power eg. one * pow(x,1) by using math.h 
*/
double Cubic::getCubicValue (double x) {
    double cubicVal = 0.0;
    cubicVal = (zero * pow (x, 0)) + (one * pow (x, 1)) + (two * pow (x, 2)) + (three * pow (x, 3));
    return cubicVal;
}

/*
adds two cubic values by referring to their coefficient member fields then places the result in double fields 
*/
Cubic Cubic:: operator+(const Cubic &rhs) {
    double outputValZero = zero + rhs.zero;
    double outputValOne  = one + rhs.one;
    double outputValTwo  = two + rhs.two;
    double outputValThree = three + rhs.three;
	//these values are passed in to initialise a new cubic called outputCubic
    Cubic outputCubic(outputValThree, outputValTwo, outputValOne, outputValZero);
	//returns the new cubic 
    return outputCubic;
}


/*
subtracts two cubic values by referring to their coefficient member fields then places the result in double fields - same as + operation above but for - 
*/
Cubic Cubic:: operator-(const Cubic &rhs) {
    double outputValZero = zero - rhs.zero;
    double outputValOne  = one - rhs.one;
    double outputValTwo  = two - rhs.two;
    double outputValThree = three - rhs.three;

    Cubic outputCubic(outputValThree, outputValTwo, outputValOne, outputValZero);
    return outputCubic;
}

/*
mutiplies the cubic coefficient field values by double k then returns a pointer to the cubic 
*/
Cubic& Cubic::multiply(double k){
    zero *= k;
    one *= k;
    two *= k;
    three *= k;

    return *this;
    
}

/*
compares the coefficient member fields of two cubics to see if they have the same values 
*/
bool Cubic:: operator==(const Cubic &rhs){

    if((zero == rhs.zero) && (one == rhs.one) && (two == rhs.two) && (three == rhs.three)){
        return true;
    }
    return false;
}

/*
compares the coefficient member fields of two cubics to see if the cubics don't have the values
*/
bool Cubic:: operator!=(const Cubic &rhs){
    if((zero != rhs.zero) || (one != rhs.one) || (two != rhs.two) || (three != rhs.three)){
        return true;
    }
    return false;
}

/*
adds the two cubic coefficient field values then assigns the result to the current cubic coefficient field, returns a pointer to the current cubic
*/
Cubic& Cubic:: operator+=(const Cubic &rhs) {

    zero += rhs.zero;
    one += rhs.one;
    two += rhs.two;
    three += rhs.three;

    return *this;
}

/*
subtracts the two cubic coefficient field values then assigns the result to the current cubic coefficient field, returns a pointer to the current cubic
*/
Cubic& Cubic:: operator-=(const Cubic &rhs) {
    zero -= rhs.zero;
    one -= rhs.one;
    two -= rhs.two;
    three -= rhs.three;

    return *this;
}

/*
prints out the passed in cubic by printing out the cubic coefficient field values
*/
ostream& operator<< (ostream &out, const Cubic &rhs) 
{ 
    out << "\n" << "Cubic coefficient values " << "\n" ; 
    out << "coefficient for x^3: " <<  rhs.getCoefficient(3) << endl;
    out << "coefficient for x^2: " <<  rhs.getCoefficient(2) << endl;
    out << "coefficient for x: " <<  rhs.getCoefficient(1) << endl;
    out << "coefficient for constant: " <<  rhs.getCoefficient(0) << "\n" << endl;
    return out; 
} 

/*
takes in cubic coefficient field values and is passed to a new cubic which is then assigned to a cubic pointer 
*/
istream& operator>> (istream &in, Cubic &rhs) 
{ 
    cout << "\n" << "Input Cubic values: " << endl; 
    cout << "\n" << "Enter in the coefficient of x^3: " << endl; 
    double coefficientThree = 0.0;
    in >> coefficientThree;
     
    cout << "\n" << "Enter in the coefficient of x^2: " << endl; 
    double coefficientTwo = 0.0;
    in >> coefficientTwo;

    cout << "\n" << "Enter in the coefficient of x: " << endl; 
    double coefficientOne = 0.0;
    in >> coefficientOne;
    
    cout << "\n" << "Enter in the coefficient of constant: " << endl; 
    double coefficientConstant = 0.0;
    in >> coefficientConstant;
    
    Cubic x(coefficientThree, coefficientTwo, coefficientOne, coefficientConstant);
    
    rhs = x;
    return in; 
} 