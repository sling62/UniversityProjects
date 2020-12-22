/**author: Samantha Ling(ID:160720604)
 * Title: Rook.h
 * Description: define functions to create a rook chess piece on the chessboard
 * Date: 30/11/19
 **/

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

//Rook class inherits from the Piece class in order to create a chess piece
class Rook : virtual public Piece {

	private:
	//member function for a Rook to check for collisions with other pieces (Rook, Bushop or Queen)
	bool hasCollided(const Piece &piece) const;
	//rook overloaded assignment operator to assign a piece (Rook) to another Rook  
	Rook& operator=(const Piece &piece );

	public: 
	//default constructor which calls piece default constructor 
	Rook();
	//constructor which calls the piece constructor that sets the Rook on a explicit location (defined by x and y float values) on the chessboard
	Rook(const float x, const float y);
	//copy constructor 
	Rook(const Piece& copy);
	//destructor 
	~Rook();

	//get function to get the length (length = 2) of the Rook, defined in Rook.cpp 
	int getLength() const;

	//function to move the rook either horizontally (x) or vertically (y) depending on the direction, and in either a negative or positive direction (depending on the values of x and y)
	void moveVerticalHorizontal(const float x, const float y, const int direction);
		
};

#endif