/**author: Samantha Ling(ID:160720604)
 * Title: Bishop.cpp
 * Description: create a Bishop chess piece 
 * Date: 30/11/19
 **/

#include "Bishop.h"
#include "Collision.h"
#include <iostream>
using namespace std;
//defining a invalid_argument exception to throw in collision function call
#define throw(invalid_argument)

//the radius a Bishop
const int radius = 1;
//the diameter a Bishop
const int diameter = 2;


/**
 * Default constructor which calls piece default constructor 
 */
Bishop::Bishop() : Piece() {

}

/**
 * Constructor which calls the piece constructor that creates the Bishop on a explicit location (defined by x and y passed in float values as well as the diameter of a Bishop (see top of file)) on the chessboard
 */
Bishop::Bishop(const float x, const float y) : Piece(x, y, diameter) {
	
}


/**
 *	Copy constructor which calls the piece constructor that creates the Bishop on a explicit location (ie. from another Bishop/Queen location) on the chessboard, defined by the left and bottom side location of the piece as well as the diameter of a Bishop/Queen
 */
Bishop::Bishop(const Piece& rhs) : Piece(rhs.getLeftXLocation(), rhs.getBottomYLocation(), diameter) {
	
}

/**
 *	Destructor
 */
Bishop::~Bishop() {
}

/*
 * Function to return the radius of the Bishop/Queen, used in collision detection (collision.cpp)
 */
int Bishop::getRadius() const {
	return radius;
}

/*
 * Function to return the diameter of the Bishop/Queen, used in collision detection (collision.cpp)
 */
int Bishop::getDiameter() const {
	return diameter;
}

/**
 * Assignment operator to assign a piece (Bishop or Queen) to a Bishop
 */
Bishop& Bishop::operator=(const Piece &rhs) {
	//checks to see if this Bishop is the same as the right hand side piece (Bishop)
	if(this != &rhs){
		//if not, assign the Bishop' top, bottom, left and right side location values to the same as the right hand side piece
		this -> setTopYLocation(rhs.getTopYLocation());
		this -> setBottomYLocation(rhs.getBottomYLocation());
		this -> setRightXLocation(rhs.getRightXLocation());
		this -> setLeftXLocation(rhs.getLeftXLocation());
	}
	//if it is the same piece then return a pointer to the piece
	return *this;
}

/**
 * Function to move the Bishop or Queen Diagonally in either 2 directions (depending on the value of x is positive or negative)
 */
void Bishop::moveDiagonal (const float x) {
	//moves the Bishop or Queen at 45 degree angles to the horizontal/vertical as the increese in the horizontal and vertical direction is the same:

		//sets the top and bottom side locations of the Bishop or Queen piece to either move north (positive y value) or south (negative y value)
		this -> setTopYLocation (this -> getTopYLocation() + x);
		this -> setBottomYLocation (this -> getBottomYLocation() + x);
		// then sets the left and right side locations of the Bishop or Queen piece to either move east (positive x value) or west (negative x value)
		this -> setLeftXLocation (this -> getLeftXLocation() + x);
		this -> setRightXLocation (this -> getRightXLocation() + x);

		//so that it moves in a continous way 


}

/**
 * Function for a Bishop to check if it has collided with other pieces (Rook, Bushop or Queen), will throw an invalid argument if piece is undefined - cannot identify type
 */
bool Bishop::hasCollided(const Piece &piece) const throw (invalid_argument) {
	//try, catch block in case Bishop collision with a piece throws an exception
	try {
		//checks the type of the piece to see if it is a Bishop or a Queen
        if(typeid(piece) == typeid(Bishop) || typeid(piece) == typeid(Queen)) {
			//if it is then pass to the hasCollided function in collision.cpp which detects if a Bishop has collided with a Bishop/Queen
			//note: queen is a derived class from Bishop hence have put a dynamic_cast in case it is a Queen to reference a Bishop as they have a similar functionality for collision
            return Collision::hasCollided(*this, dynamic_cast<const Bishop&>(piece)); 

		//if it isn't either a Queen or a Bishop then checks to see type of the piece to see is a Rook
		} else if(typeid(piece) == typeid(Rook)) {
			//if it is a rook then pass to the hasCollided function in collision.cpp which detects if a Bishop and a Rook have collided  
            return Collision::hasCollided(dynamic_cast<const Bishop&>(*this), dynamic_cast<const Rook&>(piece));
		} 
        else {
			//if the type of the piece is neither a rook, queen or bishop then the piece has not been defined as a derived type and is an invalid piece so will throw an invalid_argument
			throw invalid_argument("undefined type of piece");
		}
	}catch (exception &e) {
		cerr << "Caught exception on collision: " << e.what( ) << endl;
		cerr << "Type: " << typeid( e ).name( ) << endl;
	}

}


