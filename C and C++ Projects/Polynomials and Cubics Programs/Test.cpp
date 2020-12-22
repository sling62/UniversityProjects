#include <iostream>
#include "Cubic.h" 
#include "Polynomial.h" 
using namespace std; 

int main()
{

    cout << "\n" << "Cubic Class Testing" << endl;

    cout << "\n" << "Input from user testing" << endl;
    //testing iostream to input (>>) a cubic and then output (<<) the mutiplication of the cubic by 2
    Cubic h; //default values are 0x^3 + 0x^2 + 0x +0
    cin >> h; 

    cout << "\n" << "Printing out your cubic you entered (by overloading the out operator): " << endl;
    cout << h << endl;

    cout << "Printing out your cubic mutiplied by int value 2 (using overloaded out operator and mutliply function): " << endl;
    cout << h.multiply(2) << "\n" << endl;


    cout << "\n" << "Passed in values testing" << endl;
    //Initialising and printing out (using overloaded out operator - <<) cubic a which is:  3x^3 + 6x^2 -2x -5   
    Cubic a(3,6,-2,-5);
    cout << "\n" <<"Printing out cubic a values (by overloading the out operator - expected cubic is 3x^3 + 6x^2 -2x -5): " << endl;
    cout << a << endl;
 
    //testing getCoefficient and getCubicValue on Cubic a 
    cout << "Getting Cubic a' ^3 coefficient (expected value is 3): " << a.getCoefficient(3) << endl ;
    cout << "Getting Cubic a' value when x=2 (expected value is 39): " <<  a.getCubicValue(2) << "\n" << endl;

    //Initialising and printing out cubic b which is:  5x^3 - x^2 +9x -2 
    Cubic b(5,-1,9,-2);
    cout << "Printing out cubic b values (by overloading the out operator - expected cubic is 5x^3 - x^2 +9x -2): " << endl;
    cout << b << endl;


    //Initialising by calling default constructor and printing out cubic c which is by default:  0x^3 + 0^2 +0x +0 
    Cubic c;
    cout << "Printing out cubic c default initialised values (by overloading the out operator - expected cubic is 0x^3 + 0x^2 +0x +0): " << endl;
    cout << c << endl;

    //testing + operator 
    cout << "Printing out Cubic c after c = a + b (overloading + operator - expected cubic is 8x^3 + 5x^2 +7x -7): " << endl;
    c = a + b;
    cout << c << endl;

    cout << "Printing out Cubic c after c = c - b (overloading + operator - expected cubic is Cubic a values: " << endl;
    c = c - b;
    cout << c << endl;

    //testing multiplying cubic by an int or double value 
    cout << "Multiplying Cubic c by int value 2 (expected values of cubic is 6x^3 + 12x^2 -4x -10) " << endl;
    c.multiply(2);
    cout << c << endl;
    cout << "Multiplying Cubic c (after multiplying by int value 2 - see above) by double value 2.2 (expected value of cubic is 13.2x^3 + 26.4x^2 -8.8x -22)" <<endl;
    c.multiply(2.2);
    cout << c << endl;

    //Initialising and printing out cubic d which is:  4.2x^3 + 6.2x^2 + 9.5x +3
    Cubic d(4.2,6.2,9.5,3);
    cout << "\n" <<"Printing out cubic d values (by overloading the out operator - expected value of cubic is 4.2x^3 + 6.2x^2 + 9.5x +3): " << endl;
    cout << d << endl;

    //Initialising and printing out cubic e which is:  4.2x^3 + 6.2x^2 + 9.5x +3
    Cubic e(4.2,6.2,9.5,3);
    cout << "\n" <<"Printing out cubic e values (by overloading the out operator - expected value of cubic is 4.2x^3 + 6.2x^2 + 9.5x +3): " << endl;
    cout << e << endl;

    //testing overloading == and != operator 
    cout << "Printing out if d == e (expected return value is 1 (true): "<< (d == e) << endl;
    cout << "Printing out if d != e (expected return value is 0 (false): "<< (d != e) << "\n" << endl;

    //Initialising and printing out cubic f which is:  2.7x^3 + 1.2x^2 + 3x +4.8
    Cubic f(2.7,1.2,3,4.8);
    cout << "\n" <<"Printing out cubic f values (by overloading the out operator - expected value of cubic is 2.7x^3 + 1.2x^2 + 3x +4.8): " << endl;
    cout << f << endl;

    //testing += operator 
    cout << "Printing out Cubic f after f+= e (expected cubic is 6.9x^3 + 7.4x^2 +12.5x +7.8): " << endl;
    f += e;
    cout << f << endl;

    //Initialising and printing out cubic g which is:  -6x^3 + 2x^2 - 5.2x +9
    Cubic g(-6,2,-5.2,9);
    cout << "\n" <<"Printing out cubic g values (by overloading the out operator - expected value of cubic is -6x^3 + 2x^2 - 5.2x +9): " << endl;
    cout << g << endl;

    //testing -= operator 
    cout << "Printing out Cubic g after g-= f (expected cubic is -12.9x^3 -5.4x^2 -17.7x +1.2): " << endl;
    g -= f;
    cout << g << endl;





    cout << "\n" << "Polynomial Class Testing" << "\n" << endl;

    //testing initialising polynomials using constructors 

    //i) initialising Polynomial i by calling default constructor  
    Polynomial i;
    cout << "Polynomial i initialised to default values: "<< i << endl;

    //testing overloaded assignment (=) and input (>>) operator on Polynomial i 
    cout << "Input values for Polynomial i: "<< endl;
    cin >> i;
    cout << "\n" << "Polynomial i has been assigned (using assignment operator) values: "<< i << endl;
    
    //ii) initialising Polynomial j by passing in coefficient and degree values directly
    int degree=1;
    double* polynomialCoefficients1 = new double[degree + 1];
    //initialising Polynomial to x + 1;
    polynomialCoefficients1[0] = 2;
    polynomialCoefficients1[1] = 1;
    Polynomial j(polynomialCoefficients1, degree);
    cout << "Polynomial j initialised (by passing in array values - expected Polynomial is x + 2) to: "<< j << endl;

    //iii) initialising Polynomial k by copy constructor 
    Polynomial k = Polynomial(j);
    cout << "Polynomial k initialised (by copy constructor on j) to same values as j(expected Polynomial is x + 2): "<< k << endl;
    

    //testing getCoefficient and getPolynomialValue and multiply function on polynomial k
    cout << "Getting Polynomial k' ^0 coefficient (expected value is 2): " << k.getCoefficient(0) << endl ;
    cout << "Getting Polynomial k' ^4 coefficient (expected default value is 0 - as ^4 is higher than the degree (1) of polynomial k): " <<k.getCoefficient(4) << endl;

    cout << "Getting Polynomial k' value when x=3 (expected value is 5): " <<  k.getPolynomialValue(3) << endl;

    cout << "Multiplying polynomial k by int value 2 (expected value is 2x + 4): " << k.multiply(2) << endl;
    cout << "Multiplying polynomial k (after being mutiplied by 2 - see above) by double 2.8 (expected value is 5.6x + 11.2): " << k.multiply(2.8) << endl;


    //testing assignment operator
    degree=3;
    double* polynomialCoefficients2 = new double[degree + 1];
    //initialising Polynomial l to 4x^3 + 2x^2 + 9x +7;
    polynomialCoefficients2[0] = 7;
    polynomialCoefficients2[1] = 9;
    polynomialCoefficients2[2] = 2;
    polynomialCoefficients2[3] = 4; 
    Polynomial l(polynomialCoefficients2, degree);
    cout << "Polynomial l initialised (by passing in array values - expected Polynomial is 4x^3 + 2x^2 + 9x +7) to: "<< l << endl;
    
    //testing assignment operator, assigning Polynomial k to l
    k = l;
    cout << "Polynomial k after being assigned to l: " << k << endl;


    // testing overloading + and - operators 
    l = k + j;
    cout << "Polynomial l after carrying out l = k + j(expected Polynomial is 4x^3 + 2x^2 +10x + 9 ): " << l << endl;

    j = k - j; 
    cout << "Polynomial j after carrying out j = k - j(expected Polynomial is 4x^3 +2x^2 +8x +5 ): " << j << endl;
    

    // testing overloading * operator
    degree=1;
    double* polynomialcoefficients3 = new double[degree + 1];
    //initialising polynomial m to x + 1
    polynomialcoefficients3[0] = 1;
    polynomialcoefficients3[1] = 1;
    Polynomial m(polynomialcoefficients3, degree);
    cout << "polynomial m initialised (by passing in array values - expected polynomial is x + 1) to: "<< m << endl;

    double* polynomialcoefficients4 = new double[degree + 1];
    //initialising polynomial n to x - 1
    polynomialcoefficients4[0] = -1;
    polynomialcoefficients4[1] = 1;
    Polynomial n(polynomialcoefficients4, degree);
    cout << "polynomial n initialised (by passing in array values - expected polynomial is x - 1) to: "<< n << endl;
    
    Polynomial o; 
    cout << "Polynomial o initialised to default values: "<< o << endl;

    o = m * n; 
    cout << "Polynomial o after carrying out o = m * n (expected Polynomial is x^2 - 1): " << o << endl;

    //testing overloading +=, -= and *= operators 
    o += m;
    cout << "Polynomial o after carrying out o += m (expected Polynomial is x^2 + x): " << o << endl;
    
    o -= n;
    cout << "Polynomial o after carrying out o -= n (expected Polynomial is x^2 + 1): " << o << endl;

    degree = 3;
    double* polynomialCoefficients5 = new double[degree + 1];
    //initialising Polynomial p to 3x^3 + 2x^2 + 5x +3
    polynomialCoefficients5[0] = 3;
    polynomialCoefficients5[1] = 5;
    polynomialCoefficients5[2] = 2;
    polynomialCoefficients5[3] = 3; 
    Polynomial p(polynomialCoefficients5, degree);
    cout << "Polynomial p initialised (by passing in array values - expected Polynomial is  3x^3 + 2x^2 + 5x +3) to: "<< p << endl;

    degree = 2;
    double* polynomialCoefficients6 = new double[degree +1];
    //initialising Polynomial q to 3x^2 + 2x + 1
    polynomialCoefficients6[0] = 1;
    polynomialCoefficients6[1] = 2;
    polynomialCoefficients6[2] = 3;
    Polynomial q(polynomialCoefficients6, degree);
    cout << "Polynomial q initialised (by passing in array values - expected Polynomial is 3x^2 + 2x + 1) to: "<< q << endl;
    
    p *= q;
    cout << "Polynomial p after carrying out p *= q (expected Polynomial is 9x^5 + 12x^4 + 22x^3 + 21x^2 + 11x + 3): " << p << endl;

    degree = 2;
    double* polynomialCoefficients7 = new double[degree +1];
    //initialising Polynomial r to 3x^2 + 2x + 1
    polynomialCoefficients7[0] = 1;
    polynomialCoefficients7[1] = 2;
    polynomialCoefficients7[2] = 3;
    Polynomial r(polynomialCoefficients7, degree);
    cout << "Polynomial r initialised (by passing in array values - expected Polynomial is 3x^2 + 2x + 1) to: "<< r << endl;


    //testing overloading == and != operator 
    cout << "Printing out if q == r (expected return value is 1 (true): "<< (q == r) << endl;
    cout << "Printing out if q != r (expected return value is 0 (false): "<< (q != r) << endl;

    return 0;
}