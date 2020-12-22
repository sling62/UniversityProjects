/**author: Samantha Ling(ID:160720604)
 * Title: Queen.h
 * Description: define functions to create a Queen chess piece on the chessboard
 * Date: 30/11/19
 **/

#ifndef QUEEN_H
#define QUEEN_H

#include "Bishop.h"

//Queen class inherits from the Bishop (to move diagonally and for collision type checks) which inherits from the piece class to create a chess piece
class Queen : virtual public Bishop {
	
private:
	//member function for a Queen to check for collisions with other pieces (Rook, Bushop or Queen)
	bool hasCollided(const Piece &piece) const;
	//rook overloaded assignment operator to assign a piece (Queen) to another Queen
	Queen& operator=(const Piece &queen);

public:
	//default constructor which calls piece default constructor 
	Queen();
	//constructor which calls the piece constructor that sets the piece on a explicit location (defined by x and y float values) on the chessboard
	Queen(const float x, const float y);
	//copy constructor 
	Queen(const Piece& rhs);
	//destructor 
	~Queen();

	//function to move the queen either horizontally (x) or vertically (y) depending on the direction, and in either a negative or positive direction (depending on the values of x and y)
	void moveVerticalHorizontal(const float x, const float y, const int direction);

};

#endif