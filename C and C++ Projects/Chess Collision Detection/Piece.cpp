/**author: Samantha Ling(ID:160720604)
 * Title: Piece.cpp
 * Description: Create a chess piece which is bounded by top/bottom/left/right point locations on a 2D chessboard 
 * Date: 30/11/19
 **/

#include "Piece.h"
#include <iostream>
using namespace std;

/**
 * Piece default constructor to initialise a piece at the bottom left hand side (0,0) of the chessboard 
 */
Piece::Piece() {
	//bottom side location of the piece on the Y axis is set to 0  
	bottomYLocation = 0;
	//top side location of the piece on the Y axis is set to the bottom location (0) + 2
	//as 2 is the size of both the length of the Rook, and diameter of a Bishop/Queen
	topYLocation = bottomYLocation + 2;
	//left side location of the piece on the X axis is set to 0
	leftXLocation = 0;
	//right side location of the piece on the X axis is set to 0 + 2, (similar reasoning to topYLocation)
	rightXLocation = leftXLocation + 2;
}

/**
 *	Piece constructor with explicitly defined x, y and size (length or length) values
 */
Piece::Piece(const float x, const float y, const int size) {
	
	//similar reasoning to default constructor however initialises the piece' bottom,top, left and right side locations to specific locations on the chessboard 
	//size is passed in as 2 as both Rook length and Bishop/Queen diameter is 2 
	bottomYLocation = y;
	topYLocation = y + size;
	leftXLocation = x;
	rightXLocation = x + size;
}

/**
 *	Copy constructor
 */
Piece::Piece(const Piece& rhs) {
	//initialises piece' top, bottom, left and right side locations to the same as the right hand side piece
	leftXLocation = rhs.leftXLocation;
	topYLocation = rhs.topYLocation;
	rightXLocation = rhs.rightXLocation;
	bottomYLocation = rhs.bottomYLocation;
}

/**
 *	Destructor
 */
Piece::~Piece() {
}

/**
 * Assignment operator to assign a piece (from the children class) to another piece (from the children class)
 */
Piece& Piece::operator=(const Piece &rhs) {
	//checks to see if this piece is the same as the right hand side piece 
	if(this != &rhs) {
		//if not, assign the piece' top, bottom, left and right side location values to the same as the right hand side piece
		topYLocation = rhs.topYLocation;
		bottomYLocation = rhs.bottomYLocation;
		leftXLocation = rhs.leftXLocation;
		rightXLocation = rhs.rightXLocation;
	}
	//if it is the same piece then return a pointer to the piece
	return *this;
}

/**
 * function to set the top side location of the piece on the Y axis to a different location 
 */
void Piece:: setTopYLocation(float location) { 
	topYLocation = location; 
}

/**
 * function to set the bottom side location of the piece on the Y axis to a different location 
 */
void Piece:: setBottomYLocation(float location) { 
	bottomYLocation = location; 
};

/**
 * function to set the left side location of the piece on the X axis to a different location 
 */
void Piece:: setLeftXLocation(float location) { 
	leftXLocation = location; 
};


/**
 * function to set the right side location of the piece on the X axis to a different location 
 */
void Piece:: setRightXLocation(float location) { 
	rightXLocation = location; 
}


/**
 * equals operator overloading to compare two pieces to see if equal to one another (ie. the same piece)
 */
bool Piece::operator ==(const Piece &rhs) const{
	//compares the type of the piece object to the right hand side object to see if the same, then compares the top,bottom, left and right side locations to see if exactly the same
	if((typeid(rhs) == typeid(*this)) && (leftXLocation == rhs.leftXLocation && topYLocation == rhs.topYLocation && rightXLocation == rhs.rightXLocation && bottomYLocation == rhs.bottomYLocation))
	{
		//if so return true
		return true;
	}
}

/**
 * Not equals operator overloading to compare two pieces to see if they are not equal to one another (ie. not the same piece)
 */
bool Piece::operator !=(const Piece &rhs) const{
	//negates the == operator to see if not the same piece
	if(!(*this == (rhs))) 
	{
		//if so return true
		return true;
	}
}

/**
 * output operator overloading to print out to print out a piece top (on y axis), bottom (on y axis), left (on x axis) and right (on x axis) side locations on the chessboard
 */
ostream & operator<< (ostream &out, const Piece &piece) 
{
	//try, catch method is implemented in case piece cannot be identified or printed  
	try{
		out << "Top location on y axis: " << piece.getTopYLocation() << endl;
		out << "Bottom location on y axis: " << piece.getBottomYLocation() << endl;
		out << "Left location on x axis: " << piece.getLeftXLocation() << endl;
		out << "Right location on x axis: " << piece.getRightXLocation() << endl;

		return out;
	}
	catch ( exception &e )
   	{
		cerr << "Caught exception on printing piece: " << e.what( ) << endl;
		cerr << "Type: " << typeid( e ).name( ) << endl;
	}
}



