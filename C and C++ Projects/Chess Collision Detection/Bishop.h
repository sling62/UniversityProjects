/**author: Samantha Ling(ID:160720604)
 * Title: Bishop.h
 * Description: define functions to create a Bishop chess piece on the chessboard
 * Date: 30/11/19
 **/

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

//Bishop class inherits from the Piece class in order to create a chess piece
class Bishop : virtual public Piece {

private:
	//member function for a Bishop to check for collisions with other pieces (Rook, Bushop or Queen)
	bool hasCollided(const Piece &piece) const;
	//Bishop overloaded assignment operator to assign a piece (Bishop or Queen) to a Bishop
	Bishop& operator=(const Piece &rhs);

public:
	//default constructor which calls piece default constructor 
	Bishop();
	//constructor which calls the piece constructor that sets the Bishop on a explicit location (defined by x and y float values) on the chessboard
	Bishop(const float x, const float y);
	//copy constructor 
	Bishop(const Piece& rhs);
	//destructor 
	~Bishop();

	//get function to get the radius (radius = 1) of the Bishop, defined in Bishop.cpp 
	int getRadius() const;
	//get function to get the diameter (diameter = 2) of the Bishop, defined in Bishop.cpp 
	int getDiameter() const;

	//function to move the Bishop or Queen Diagonally in either 2 directions (depending on if the value of x is positive or negative)
	virtual void moveDiagonal(const float x);

};

#endif