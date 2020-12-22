/**author: Samantha Ling(ID:160720604)
 * Title: Piece.h
 * Description: function declarations to create a chess piece on a 2D chessboard 
 * Date: 30/11/19
 **/

#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {

private:
	//defining the default top (on y axis), bottom (on y axis), left (on x axis) and right (on x axis) side locations of the piece on the chessboard
	//set to 0.0f (bottom left point of the chessboard (0,0))
	float topYLocation = 0.0f;
	float bottomYLocation = 0.0f;
	float leftXLocation = 0.0f;
	float rightXLocation = 0.0f;

public:

	// default piece constructor to place a piece at the bottom left hand side of the chessboard
	Piece();
	// piece constructor to place a piece at a random position on the chessboard
	Piece(const float x, const float y, const int size);
	//copy constructor 
	Piece(const Piece& rhs);
	//destructor 
	~Piece();

	//overloading assignment operator 
	Piece& operator=(const Piece &rhs);

	
	//virtual collision method to be overidden by children classes (rook, bishop, queen) 
	//so that pieces of different class types (rook, bishop, queen) can detect collisions with one another
	virtual bool hasCollided(const Piece &piece) const = 0;

	//setter functions to set the top (on y axis), bottom (on y axis), left (on x axis) and right (on x axis) side locations of the piece on the chessboard
	//this will help move the piece 
	void setTopYLocation(float location);
	void setBottomYLocation(float location);
	void setLeftXLocation(float location);
	void setRightXLocation(float location);

	//getting the piece' top (on y axis), bottom (on y axis), left (on x axis) and right (on x axis) side locations on the chessboard
	float getTopYLocation() const { return topYLocation; };
	float getBottomYLocation() const { return bottomYLocation; };
	float getLeftXLocation() const { return leftXLocation; };
	float getRightXLocation() const { return rightXLocation; };

	//getting the the x co-ordinate of the centre of the piece (by adding the location of the left and right side of the piece and halving)
	float getCentreXLocation() const { return (leftXLocation + rightXLocation) / 2; }
	//getting the the y co-ordinate of the centre of the piece (by adding the location of the top and bottom side of the piece and halving)
	float getCentreYLocation() const { return (bottomYLocation + topYLocation) / 2; }

	//operator overloading functions to compare two pieces
	bool operator==(const Piece &rhs) const;	
	bool operator!=(const Piece &rhs) const;	

};

//overloading output operator to print out a piece top (on y axis), bottom (on y axis), left (on x axis) and right (on x axis) side locations on the chessboard
std::ostream & operator << (std::ostream &out, const Piece &rhs); 

#endif