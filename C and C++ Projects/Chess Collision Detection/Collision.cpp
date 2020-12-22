/**author: Samantha Ling(ID:160720604)
 * Title: Collision.cpp
 * Description: functions for algorithms to detect overlap(collision) between Rook, Queen and Bishop pieces
 * Date: 30/11/19
 **/

#include "Collision.h"
#include<cmath>
#include <iostream>
#define throw(runtime_error)
using namespace std;

/**
 *	Default constructor
 */
Collision::Collision() {
}

/**
 *	Destructor
 */
Collision::~Collision() {
}

/**
 *	function to detect collision between two rooks (two squares)
 *	by checking to see if the left/right (x) and top/bottom (y) side locations of both rooks on the chessboard to see if they are overlapping
 */
bool Collision::hasCollided(const Rook &rookOne, const Rook &rookTwo) {
	return rookOne.getLeftXLocation() < rookTwo.getRightXLocation() && rookOne.getRightXLocation() > rookTwo.getLeftXLocation() &&
		   rookOne.getBottomYLocation() < rookTwo.getTopYLocation() && rookOne.getTopYLocation() > rookTwo.getBottomYLocation();
}

/**
 *	function to check the collision between a Bishop or Queen and a Bishop or Queen (two circles)
 	checking the x and y distance between the centres of the first Bishop/Queen and the second Bishop/Quuen 
	to see if it is less than the total of both the Bishop/Queen and Bishop/Queen radius's combined 
	if it is then it has collided and will return true.
 */
bool Collision::hasCollided(const Bishop &bishopOne, const Bishop &bishopTwo) {
	return sqrt(pow((bishopOne.getCentreXLocation() - bishopTwo.getCentreXLocation()),2) + pow((bishopOne.getCentreYLocation() - bishopTwo.getCentreYLocation()),2)) <= bishopOne.getRadius() + bishopTwo.getRadius();
}

/**
 *	function to check the collision between a Bishop or Queen and a Rook (ie. a circle and a square)
	Will throw a runtime error in the case that the length of a rook is 0 as the algorithm requires divisison by rook length
 */
bool Collision::hasCollided(const Bishop &bishop, const Rook &rook) throw(runtime_error) {
	
	// finding the x and y difference between the center of the Queen/Bishop and the center of the Rook.
	float xCentreLocationDifference= abs(bishop.getCentreXLocation() - rook.getCentreXLocation());
	float yCentreLocationDifference = abs(bishop.getCentreYLocation() - rook.getCentreYLocation());

	//if the rook length is 0 then throw a runtime error before dividing by rook length 
	if(rook.getLength() == 0){
		throw runtime_error("invalid rook length: 0");
	}
	//if rook length is not 0 then will not produce a runtime error and can proceed
	else{
		// This checks if the Bishop/Queen is heavily overlapping with Rook or vice versa in either the x or y direction
		if (xCentreLocationDifference <= (rook.getLength()/2) || yCentreLocationDifference <= (rook.getLength()/2)) { 
			//if it is then return true 
			return true; 
		} 
		// This checks for the case where the Bishop/Queen is not touching or overlapping at all with the Rook and vice versa in either the x or y direction  
		if (xCentreLocationDifference > (rook.getLength()/2 + bishop.getRadius()) || yCentreLocationDifference > (rook.getLength()/2 + bishop.getRadius())) { 
			//if its not then can return false
			return false; 
		}
	
		// This checks to see if a Bishop/Queen has intersected with the corner of a Rook or vice versa in either the x or y direction 
		// below calculates the corner distance of the rook from the centre
		float cornerOfRookDistance = pow(xCentreLocationDifference- rook.getLength()/2, 2) + pow(yCentreLocationDifference - rook.getLength()/2, 2);
		// check to see if the corner distance is less than the the area of the Bishop/Queen
		//if it is then the corner of the rook has intersected the Bishop/Queen and return true, otherwise return false
		return (cornerOfRookDistance <= pow(bishop.getRadius(), 2));
	}
}


