/**author: Samantha Ling(ID:160720604)
 * Title: Collision.h
 * Description: define functions for algorithms to detect overlap (collision) between Rook, Queen and Bishop pieces
 * Date: 30/11/19
 **/

#ifndef COLLISION_H
#define COLLISION_H

#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"


class Collision {

private:
	//default constructor and destructor
	Collision();
	~Collision();
public:
	/**
	 * collision functions which implement the piece class hasCollided function 
	 */

	//function to detect collision between a rook (square) and rook (square) (see rook.cpp file)
	static bool hasCollided(const Rook &rookOne, const Rook &rookTwo);
	//function to detect collision between a bishop (circle) or queen (circle) and a bishop (circle) or queen (circle) (see queen and bishop .cpp files)
	static bool hasCollided(const Bishop &bishopOne, const Bishop &bishopTwo);
	//function to detect collision beteen a bishop (circle) or queen (circle) and a rook(square) (see rook, queen and bishop .cpp files)
	static bool hasCollided(const Bishop &bishop, const Rook &rook);

};

#endif