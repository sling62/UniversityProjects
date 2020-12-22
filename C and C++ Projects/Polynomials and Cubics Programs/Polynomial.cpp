#include "Polynomial.h"
#include <math.h>
#include <iostream>
using namespace std;

/*
default constructor which initialises a polynomial of zero degree, a coefficients array which only holds one value (the power of zero coefficient) and initialises that value to 0.0
*/
Polynomial::Polynomial() {
    degree = 0;
	this->coefficients = new double[1];
	this->coefficients[0] = 0.0;
}

/*
copy constructor to initialise a polynomial from another polynomial degree and coefficient values 
*/
Polynomial::Polynomial(const Polynomial &rhs){
    degree = rhs.degree;
	// + 1 for the zero coefficient onto degree 
	this->coefficients = new double[degree+1];
    for (int i=0; i<=degree; i++) 
    {
		//copies over coefficient array values to new polynomial  
		this->coefficients[i] = rhs.coefficients[i];
    }
}

/*
initialing a polynomial by passing in the coefficient values as an array(from degree index to 0 index), also passes in the degree to initilaise array - if polynomial has already been initialised memory will need to be deleted later after use  
*/
Polynomial::Polynomial(double* inputCoefficients, int inputDegree) {
    degree = inputDegree;
    this->coefficients = new double[degree + 1];
    for (int i=0; i<=degree; i++) 
    {
		//copies over coefficient array values to new polynomial  
		this->coefficients[i] = inputCoefficients[i];
    }
};

/*
destructor to delete the coefficient values stored on the heap (when out of scope) by coefficients array by deleting the pointer to the array
*/
Polynomial::~Polynomial() 
{
    if (coefficients != nullptr)
    {
        delete[] this->coefficients;
    }
}

/*
gets the coefficient value of a power passed in by referring to the index of the coefficients array 
*/

double Polynomial::getCoefficient(int power) const{
   if(power <= degree){
       return this->coefficients[power];
   }
    return 0;
}

/*
gets the polynomial value after passing in the value of x, this iterates through the coefficients array and uses math.h to calculate the coefficient * x ^ i(index of the array/power) 
*/
double Polynomial::getPolynomialValue (double x) {
    double polynomialVal = 0.0;
    for (int i=0; i<=degree; i++)
    {
        polynomialVal =  polynomialVal + (this->coefficients [i] * pow (x, i));
    }
    return polynomialVal;
}

/*
mutiply polynomial coefficient values by double value k - iterates through coefficients array and mutiplies the coefficient by k then returns polynomial  
*/
Polynomial& Polynomial::multiply(double k){

    for(int i = 0; i<= degree; i++){
		this->coefficients[i] *= k;
    }
    return *this;
}

/*
assignment operator 
*/
Polynomial& Polynomial:: operator=(const Polynomial& rhs) {

	//this checks if the assignment is trying to assign the polynomial to the same polynomial by looking at the memory address of each polynomial 
    if(this == &rhs){
		//if so return pointer to the polynomial 
        return *this;
    }

	//checks to see if the degree of the polynomial passed in is the same as the current polynomial it is assigning to
    if (this -> degree != rhs.degree){
		//if it is not then it will delete the coefficients array of the current polynomial which is being assigned 
        delete [] this->coefficients;
		//assigns the degree
        degree = rhs.degree;
		//creates a new double coefficients array to store the new coefficients 
        double* outputCoefficients = new double[degree+1];
		//assigns the coefficients array 
		this->coefficients = outputCoefficients;
    }

	//copies over coefficients 
    for (int i=0; i<=degree; i++) 
    {
		this->coefficients[i] = rhs.coefficients[i];
    }
	//returns a pointer to the assigned polynomial 
    return *this;
}

/*
//getBiggestDegree takes two polynomials and compares their degrees to see which is the bigger degree and returns that value
*/
int Polynomial:: getBiggestDegree(const Polynomial& rhs){
    if(rhs.degree >= degree){
        return rhs.degree;
    }
    else{
        return degree;
    }

}

/*
adding polynomials together and returning the result of the operation to a new polynomial  
*/
Polynomial Polynomial:: operator+(const Polynomial& rhs) {

	//gets the biggest degree between the two polynomials 
	int biggestDegree = getBiggestDegree(rhs);

	//creates a new coefficients array to store the added values 
	double* outputCoefficients = new double[biggestDegree + 1];

	//iterates through the index of both coefficients array until the max degree is reached
	for (int i = biggestDegree; i >= 0; i--)
	{
		//checks to see if the current polynomial degree index of the coefficients array is less than or the same as the other polynomial 
		if (i <= degree && i <= rhs.degree) {
			//if so its okay to add both coefficient values 
			outputCoefficients[i] = coefficients[i] + rhs.coefficients[i];
		}
		else if (i <= degree && i > rhs.degree) {
			//else if the degree of the other polynomial is greater than the current polnomial, add the coefficient of the current polynomial 
			outputCoefficients[i] = coefficients[i];
		}
		else {
			//else if its the other way round add the other polynomial coefficient 
			outputCoefficients[i] = rhs.coefficients[i];
		}

	}
	//return a new polynomial with the result of the the above 
	Polynomial x(outputCoefficients, biggestDegree);
	return x;
}

//subtracting polynomials from one another - same as addition (see above)
Polynomial Polynomial:: operator-(const Polynomial& rhs) {

    int biggestDegree = getBiggestDegree(rhs);

    double* outputCoefficients = new double[biggestDegree+1];
    for (int i=biggestDegree; i>=0; i--) 
    {
		if (i <= degree && i<=rhs.degree) {
			outputCoefficients[i] = coefficients[i] - rhs.coefficients[i];
		}
		else if (i <= degree && i > rhs.degree) {
			outputCoefficients[i] = coefficients[i];
		}
		else {
			//i have put a - in front of the rhs coefficients as you can have a posotive rhs coefficient which needs to be subtracted 
			outputCoefficients[i] = -(rhs.coefficients[i]);
		}
			
    }
    Polynomial x(outputCoefficients, biggestDegree);
    return x;
}

/*
own function created to calculate the multiplication of polynomials together 
*/
double* Polynomial:: multiplyPolynomials(const Polynomial& rhs, int newDegree){
	//creates a new coefficients array with newDegree (this is both degrees of the polynomials added together) 
	double* outputCoefficients = new double[newDegree + 1];

	//initialises outputCoefficients to make sure its not empty or pointing to random memory addresses before storing polynomial mutiplication 
	for (int j = 0; j <= newDegree; j++) {
		outputCoefficients[j] = 0;
	}

	//loops through first polynomial to get coefficient values by index(power)
	for (int i = 0; i <= degree; i++)
	{
		//loops through second polynomial to get coefficient values by index(power)
		for (int k = 0; k <= rhs.degree; k++)
		{
			//gets the value of the coefficient in the first polynomial array mutiplied by the value in the second polynomial array then stores this at the index of the added powers/indexes (as when you multiply powers you add the powers) 
			outputCoefficients[i + k] += coefficients[i] * rhs.coefficients[k];
		}
	}

	//returns new coefficients array 
	return outputCoefficients;
}

/* mutiply polynomials (*) operator which uses multiplyPolynomials function 
*/
Polynomial Polynomial:: operator*(const Polynomial& rhs) {

	//adds degrees of polynomials that are to be multiplied together 
    int biggestDegree = rhs.degree + degree;
	//creates a new polynomial from the returned multiplyPolynomials function and the biggestDegree (new degree of polynomial after mutiplied is carried out) 
    Polynomial x(multiplyPolynomials(rhs, biggestDegree), biggestDegree);
	//returns polynomial 
    return x;
}

/* mutiply polynomials (*=) operator which uses multiplyPolynomials function
*/
Polynomial& Polynomial:: operator*=(const Polynomial &rhs) {

	//same as * function 
    int biggestDegree = rhs.degree + degree;
	//stores the coefficients returned from multiplyCoefficients into a new pointer 
	double* newCoefficients = multiplyPolynomials(rhs, biggestDegree);

	//deletes the old coefficients 
	delete [] this->coefficients;
	//assigns the new coefficients and degree 
	this->coefficients = newCoefficients;
    this-> degree = biggestDegree;
	//returns pointer to polynomial 
    return *this;
}

/*
compares the coefficients in each array to see if equal to one other 
*/
bool Polynomial:: operator==(const Polynomial &rhs){

    int biggestDegree = getBiggestDegree(rhs);

	//counts the number of matched coefficients at the indexes(powers) 
    int count =0;
    for(int i=0; i <=biggestDegree; i++){
        if(getCoefficient(i) == rhs.getCoefficient(i))
        {
			//increments if equal 
            count = count+1;
        }
    }

	//checks to see if count is at the maximum value ie. if all coefficients in each array equal each other 
    if(count-1 == biggestDegree){
		//returns true 
        return true;
    }
    //else returns false 
    return false;
}

/*
compares the coefficients in each array to see if they are not equal to one other (similar to equals above)
*/
bool Polynomial:: operator!=(const Polynomial &rhs){

    int biggestDegree = getBiggestDegree(rhs);

    for(int i=0; i <=biggestDegree; i++){
		//if the element at the current polynomial index is not the same as the other polynomial index
        if(getCoefficient(i) != rhs.getCoefficient(i))
        {
			//then can immediatly return true 
            return true;
        }
    }
	//else returns false 
    return false;
}

/*
gets the current polynomial which is being pointed to then adds to their coefficient array the other polynomial coefficent array values 
*/
Polynomial& Polynomial:: operator+=(const Polynomial &rhs) {

    int biggestDegree = getBiggestDegree(rhs);

    for(int i = 0; i<=biggestDegree; i++){
		this->coefficients[i] += rhs.getCoefficient(i);
    }
	//returns a pointer to the polynomial 
    return *this;
}

/*
gets the current polynomial which is being pointed to then subtracts their coefficient array values from the other polynomial coefficent array values
*/
Polynomial& Polynomial:: operator-=(const Polynomial &rhs) {

    int biggestDegree = getBiggestDegree(rhs);

    for(int i = 0; i<=biggestDegree; i++){
		this->coefficients[i] -= rhs.getCoefficient(i);
    }
	//returns a pointer to the polynomial 
    return *this;
}

/*
overloading io operators to take in/output polynomial values  
*/
istream & operator>> (istream &in, Polynomial &rhs) 
{ 
    cout << "\n" << "Enter the degree of your polynomial: " << endl; 
    int degree = 0;
    in >> degree;

    double* inputCoefficients = new double[degree + 1];
    
    for(int i = degree; i>=0; i--){
        cout << "\n" << "Enter in the coefficient of x^" << i << " :" << endl ; 
        in >> inputCoefficients[i];
    }

	//assigns the input values to a new polynomial 
    Polynomial x(inputCoefficients, degree);
	//assigns the new polynomial to the passed in polynomial pointer 
    rhs = x;
    return in; 
} 

ostream & operator<< (ostream &out, const Polynomial &rhs) 
{
	//prints out coefficient values 
    out << endl << "Polynomial coefficient values " << endl; 

    for(int i = rhs.degree; i>=0 ; i--)
    {
        out << "x^" << i << ": " << rhs.getCoefficient(i) << endl;
    }
    return out; 
} 