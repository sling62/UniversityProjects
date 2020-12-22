/**author: Samantha Ling(ID:160720604)
 * Title: Queen.cpp
 * Description: create a Queen chess piece 
 * Date: 30/11/19
 **/

#include "Queen.h"
#include "Collision.h"
#include <iostream>
using namespace std;
//defining a invalid_argument exception to throw in collision function call
#define throw(invalid_argument)

//the radius a Queen
const int radius = 1;
//the diameter a Queen
const int diameter = 2;


/**
 *	Default constructor which calls piece default constructor 
 */
Queen::Queen() : Piece() {

}

/**
 *	Constructor which calls the piece constructor that creates the Queen on a explicit location (defined by x and y passed in float values as well as the diameter of a Queen (see top of file)) on the chessboard
 */
Queen::Queen(const float x, const float y) : Piece(x, y, diameter) {
	
}

/**
 *	Copy constructor which calls the piece constructor that creates the Queen on a explicit location (ie. from another Queen location) on the chessboard, defined by the left and bottom side location of the piece as well as the diameter of a Queen
 */
Queen::Queen(const Piece& rhs): Piece(rhs.getLeftXLocation(), rhs.getBottomYLocation(), diameter) {

}
/**
 *	Destructor
 */
Queen::~Queen() {
}

/**
 * Assignment operator to assign a piece (Queen) to a Queen
 */
Queen& Queen::operator=(const Piece &rhs) {
	//checks to see if this Queen is the same as the right hand side piece (Queen)
	if(this != &rhs){
		//if not, assign the Queen' top, bottom, left and right side location values to the same as the right hand side piece
		this -> setTopYLocation(rhs.getTopYLocation());
		this -> setBottomYLocation(rhs.getBottomYLocation());
		this -> setRightXLocation(rhs.getRightXLocation());
		this -> setLeftXLocation(rhs.getLeftXLocation());
	}
	//if it is the same piece then return a pointer to the piece
	return *this;
}

/**
 * Function to move the queen either horizontally (x) or vertically (y) depending on the direction, and in either a negative or positive direction (depending on the values of x and y)
 */
void Queen::moveVerticalHorizontal(const float x, const float y, const int direction) {
	//if the direction passed in is 0 
	if (direction == 0){
		//then move the queen vertically by setting the top and bottom side locations on the Y axis, to the current locations + y amount
		this -> setTopYLocation (this -> getTopYLocation() + y);
		this -> setBottomYLocation (this -> getBottomYLocation() + y);
	}
	else if(direction == 1){
		//else move the queen horizontally by setting the left and right side locations on the X axis, to the current locations + x amount
		this -> setLeftXLocation (this -> getLeftXLocation() + x);
		this -> setRightXLocation (this -> getRightXLocation() + x);
	}
	else{
		//if the direction is neither 0 or 1 then will print out a message
		cout << "could not identify direction to move rook piece, piece has not been moved" << endl;

	}
}

/**
 * Function for a Queen to check if it has collided with other pieces (Rook, Bushop or Queen), will throw an invalid argument if piece is undefined - cannot identify type
 */
bool Queen::hasCollided(const Piece &piece) const throw (invalid_argument) {
	//try, catch block in case Bishop collision with a piece throws an exception
	try {
		//checks the type of the piece to see if it is a Bishop or a Queen
        if(typeid(piece) == typeid(Queen) || typeid(piece) == typeid(Bishop)) {
			//if it is then pass to the hasCollided function in collision.cpp which detects if a Queen has collided with a Bishop/Queen
			//note: queen is a derived class from bishop hence have put a dynamic_cast in case it is a queen to reference a bishop as they have a similar functionality for collision
            return Collision::hasCollided(dynamic_cast<const Bishop&>(*this), dynamic_cast<const Bishop&>(piece)); 
		
		//if it isn't either a Queen or a Bishop then checks to see type of the piece to see is a Rook
		} else if(typeid(piece) == typeid(Rook)) {
			//if it is a rook then pass to the hasCollided function in collision.cpp which detects if a Queen (referenced as a Bishop) and a Rook have collided 
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


