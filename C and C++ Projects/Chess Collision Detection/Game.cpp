/**author: Samantha Ling(ID:160720604)
 * Title: Games.cpp
 * Description: program to run a game of chess (creating a 2D chess board with chess pieces that are picked at random and move at small random distances to see if they collide with other chess pieces)
 * Date: 30/11/19
 **/

#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include <iostream>
#include <vector>
#include <time.h>
//defining a invalid_argument exception to throw and (if thrown eventually) catch in the main program
#define throw(invalid_argument)
using namespace std;

//function declarations 
void fillChessBoard();
void changePiecePosition (int i);
const int checkCollisions(int i);
void printPiece (const Piece &piece);
void removePiece(const int k);
float generateRandomFloat(float min, float max);

//global vector of chess board pieces (vector contains pointers to pieces)
vector<Piece*> chessBoardPieces;

//defining a 2D chess board by height and width (100x100 chess board)
const int chessBoardHeight = 100;
const int chessBoardWidth = 100;
//defining the number of pieces on the chess board
const int numberOfPieces = 30;
//defining the maximum speed of which selected pieces can move at a time to get to a destination 
const float maxPieceSpeed = 0.3f;

//total scores are updated for the number of pieces captured by rook, bishop and queen types 
int rookCaptures = 0;
int bishopCaptures = 0;
int queenCaptures = 0;

int main () {

	//setting the random number generator to NULL 
	srand (time(NULL));

	//calls the function to fill the chess board with rook, bishop and queen pieces 
	fillChessBoard();

		//try and catch block to catch any exceptions which are thrown during the running of the program
		try {
			//iterates for max 100 turns, selecting in total max 100 pieces during the game
			for(int k = 1; k <= 100; k++) {
				//if the number of pieces left on the board is 0 (ie. only one piece remains) before the 100 turns is over then exit out of the for loop and end game
				if(chessBoardPieces.size() == 1) { 
					break; 
				}

				//gets the total number of pieces on the chess board (-1 as the number of pieces start from a 0 index)
				int numOfTotalPieces = chessBoardPieces.size() - 1;

				//selects a random piece on the chess board to move 
				int selectedPiece = rand() % numOfTotalPieces + 0;

				//changes the position of the piece
				changePiecePosition(selectedPiece);
			}

		}
		catch (exception &e) {
			cerr << "Caught exception: " << e.what( ) << endl;
			cerr << "Type: " << typeid( e ).name( ) << endl;
		}

		//prints out the total scores at the end of the game for the number of pieces each piece type (rook, bishop and queen) had captured during the game
		cout << "--------------------------- Total Scores ----------------------------- " << endl << endl;
		cout << "Number of rook captures: " << rookCaptures << endl;
		cout << "Number of bishop captures: " << bishopCaptures << endl;
		cout << "Number of queen captures: " << queenCaptures << endl << endl;

		//outputs the number of pieces still left on the chessboard 
		cout << "Chess game has ended with " << chessBoardPieces.size() << " number of pieces still left on the chessboard" << endl;
		cout << "---------------------------------------------------------------------- " << endl << endl;
		
		// Clean up the remaining pieces still on the chessboard by end of games
		chessBoardPieces.clear();
		// shows no more pieces on the board
		cout << "Number of chess pieces on the board after clearing (expecting 0): " << chessBoardPieces.size() << endl;

		return 0;
}

/**
 * function to fill the chess board with rook, bishop and queen pieces 
*/
void fillChessBoard() {

	//for the number of chess pieces stated (at top of Game.cpp file) create random chess pieces which are rooks or bishops or queens
	for(int i = 0; i < numberOfPieces; i++) {
		
		//creating a piece on the chess board: 

		// Random integer number is generated between 0 - 2 to either create a new Rook(0), Bishop (1) or Queen (2)
		int randomPieceType = rand() % 3 + 0;

		//selects a random x and y starting point for the piece which will be within the 2D chess board 
		float randomStartPosition = generateRandomFloat(0, chessBoardHeight);
		float startXPosition = randomStartPosition;
		float startYPosition = randomStartPosition;

		//if the random generated integer is 0 then create a new rook piece from the random starting point defined and add to the chess board pieces 
		if(randomPieceType == 0) {
			chessBoardPieces.push_back(new Rook(startXPosition, startYPosition));
		}
		//if the random generated integer is 1 then create a new Bishop piece from the random starting point defined and add to the chess board pieces
		else if(randomPieceType == 1){
			chessBoardPieces.push_back(new Bishop(startXPosition, startYPosition));
		}
		//if the random generated integer is 2 then create a new Queen piece from the random starting point defined and add to the chess board pieces
		else if(randomPieceType == 2) {
			chessBoardPieces.push_back(new Queen(startXPosition, startYPosition));
		}
		//if the integer generated is not between 0 -2 then will print out a message 
		else {
			cout << "Chess board piece could not be created" << endl;
		}
	}
}

/**
 * function to change the position of a piece
*/
void changePiecePosition(int i) {

	// if the piece(i) does not exist within the chessBoardPieces will throw an out_of_range exception
	if((i < 0) || (i > chessBoardPieces.size()-1)){
		throw out_of_range("piece does not exist");
	}

	//generates a random speed in which to move the x and y position of the piece in either a positive or negative direction 
	float yPosition = generateRandomFloat(-maxPieceSpeed, maxPieceSpeed);
	float xPosition =  generateRandomFloat( -maxPieceSpeed, maxPieceSpeed);

	//checks to see if the piece is on or approaching the border of the chess board 
	//if the piece is approaching the top border of the chess board 
	if(chessBoardPieces[i]->getTopYLocation() >= (chessBoardHeight - maxPieceSpeed)) { 
		//change the speed of the y direction to be negative so that the piece moves south
		yPosition = generateRandomFloat(-maxPieceSpeed, 0);
	//if the piece is approaching the bottom border of the chess board 
	}else if(chessBoardPieces[i]->getBottomYLocation() <= (0 + maxPieceSpeed)){
		//change the speed of the y direction to be positive so that the piece moves north 
		yPosition = generateRandomFloat(0, maxPieceSpeed);
	}

	//if the piece is approaching the left border of the chess board 
	if(chessBoardPieces[i]->getLeftXLocation() <= (0 + maxPieceSpeed)) { 
		//change the speed of the x direction to be positive so that the piece moves east
		xPosition = generateRandomFloat(0, maxPieceSpeed);
	//if the piece is approaching the right border of the chess board 
	}else if(chessBoardPieces[i]->getRightXLocation() >= (chessBoardWidth -maxPieceSpeed)) {
		//change the speed of the x direction to be negative so that the piece moves west
		xPosition = generateRandomFloat(-maxPieceSpeed, 0);
	}

	//generating a random integer to choose on moving the rook in either a vertical(0) or horizontal(1) direction - see rook.cpp
	int rookQueenDirection = rand() % 2 + 0;
	//generating a random integer to choose on moving the queen either vertically/horizontally(0) or diagonally(1)
	int queenDirection = rand() % 2 + 0;
	//bishop does not need a direction as will always move diagonally 45 degrees by positive/negative xPosition or yPosition values

	//moves the piece 100x by the small random speed created 
	for (int k = 1; k<=100; k++){
		//checks the type of the chessboard piece to see if it is a rook, if it is then it calls the function to move the rook horizontally or vertically bit by bit on the chessboard 
		if(typeid(*chessBoardPieces[i]) == typeid(Rook)){
			dynamic_cast<Rook*>(chessBoardPieces[i]) -> moveVerticalHorizontal(xPosition, yPosition, rookQueenDirection);
		}
		//else if the type of the chessboard piece is a Bishop,  then it calls the function to move the bishop diagonally (at 45 degrees - as the position moved vertically and horizontally is the same)  bit by bit on the chessboard 
		else if (typeid(*chessBoardPieces[i]) == typeid(Bishop)){
			dynamic_cast<Bishop*>(chessBoardPieces[i]) -> moveDiagonal(xPosition);
		}
		//otherwise if the type of the chessboard piece is a Queen,  then it calls the function to move the Queen either vertically or horizontally or diagonally bit by bit on the chessboard 
		else if(typeid(*chessBoardPieces[i]) == typeid(Queen)){
			if(queenDirection == 0){
				dynamic_cast<Queen*>(chessBoardPieces[i]) -> moveVerticalHorizontal(xPosition, yPosition, rookQueenDirection);
			}
			else if(queenDirection == 1){
				dynamic_cast<Queen*>(chessBoardPieces[i]) -> moveDiagonal(xPosition);
			}
			//if the random integer generated is not between 0 -1 then a message is outputted 
			else{
				cout << "could not find the direction to move the queen piece" << endl;
			}
		}
		//if the piece is neither a rook, bishop or queen then function will throw a invalid_argument as the type of piece is undefined 
		else {
			throw invalid_argument("undefined type of piece");
		}

		//calls checkCollisions to see if the piece has collided with any other pieces on the board 
		//if it had then it marks the index of the piece which needs to be removed 
		//otherwise if no collisions has occured then markedRemovedPiece = -1 (not found)
		const int markedRemovedPiece = checkCollisions(i);

		//this checks to see if the piece collided with any other pieces on the board, if it had collided with a piece, removes the collided piece and exit and move onto next piece
		if(markedRemovedPiece >= 0){
			//removes (or more specifically erases) piece from the chess board 
			removePiece(markedRemovedPiece);
			//outputs the number of pieces still left after the collision occured 
			cout << "Pieces still left on the chessboard after collision: " << chessBoardPieces.size() << endl;
			break;
		}
		
		// this checks to see if the piece is approaching to be outside of the board - if it us stop moving the piece when it gets close to the border 
		if((chessBoardPieces[i]->getTopYLocation() >= chessBoardHeight - maxPieceSpeed) || (chessBoardPieces[i]->getBottomYLocation() <= 0 + maxPieceSpeed) || (chessBoardPieces[i]->getLeftXLocation() <= 0 + maxPieceSpeed) || (chessBoardPieces[i]->getRightXLocation() >= chessBoardWidth - maxPieceSpeed)){
				break;
		}
	}
			
}


/**
 * function which calls the collision methods in rook, queen and bishop .cpp files
 * checks to see if the piece(i) when moved by a small distance has collided with any other pieces
*/
const int checkCollisions(int i) {

	// if the piece does not exist within the chessBoardPieces will throw an out_of_range exception
	if((i < 0) || (i > chessBoardPieces.size() -1)){
		throw out_of_range("piece does not exist");
	}

	//iterates through the chessboard pieces, seeing if the piece passed in (i) had collided with any other chess pieces when moved 
	for(int j = 0; j < chessBoardPieces.size(); j++) {
		// however does not include itself
		if(chessBoardPieces[i] != chessBoardPieces[j]) {
			// calls the collision methods in rook, queen and bishop .cpp files depending on the type of chessBoardPiece[i]
			if(chessBoardPieces[i]->hasCollided(*chessBoardPieces[j])) {

				//if the piece had collided with another piece, the piece type is updated for number of captures
				//if the piece is a rook 
				if(typeid(*chessBoardPieces[i]) == typeid(Rook))
				{
					//update the number of rook captures/collisions 
					rookCaptures = rookCaptures + 1;
				}
				//else if the piece is a Bishop  
				else if(typeid(*chessBoardPieces[i]) == typeid(Bishop)){
					//update the number of bishop captures/collisions 
					bishopCaptures = bishopCaptures + 1;
				}
				//else if the piece is a Queen
				else if(typeid(*chessBoardPieces[i]) == typeid(Queen)) {
					//update the number of Queen captures/collisions 
					queenCaptures = queenCaptures + 1;
				}
				//if the piece is neither a rook, bishop or queen then function will throw a invalid_argument as the type of piece is undefined 
				else {
					throw invalid_argument("undefined type of piece");
				}
				
				//prints out the collision details 
				cout << "------------------------------------------------------------------- " << endl;
				cout << "--------------------------- Collision ----------------------------- " << endl << endl;

				//prints out the piece which had moved 
				cout << "Moved piece: " << endl;
				printPiece(*chessBoardPieces[i]);
				//prints out the piece which the moved piece collided with (and is being removed from the board)
				cout << "Has collided with (static) piece: " << endl;
				printPiece(*chessBoardPieces[j]);

				//returns the index of the static piece which is being removed 
				return j;
			}
		}
	}
	//if no collisions occured function will return -1
	return -1;

}

/**
 * function to remove (erase) piece from the chess board (from chessBoardPieces vector)
*/
void removePiece(const int k) {
	//try, catch block in case it erases a piece which does not exist 
	try {
		chessBoardPieces.erase(chessBoardPieces.begin() + k);
	}
	catch (exception &e) {
		cerr << "Caught exception on removing piece: " << e.what( ) << endl;
      	cerr << "Type: " << typeid( e ).name( ) << endl;
	}
}

/**
 * function to print a piece from the chess board (from chessBoardPieces vector), will throw a invalid_argument in case piece type is not defined
*/
void printPiece (const Piece &piece) throw (invalid_argument){
	cout << endl;

	//if the piece is a Rook
	if(typeid(piece) == typeid(Rook)){
		//will print out Rook as the type of the piece 
		cout << "Rook" << endl;
	}
	//else if the piece is a Bishop
	else if (typeid(piece) == typeid(Bishop)){
		//will print out Bishop as the type of the piece 
		cout << "Bishop" << endl;
	}
	//else if the piece is a Queen
	else if(typeid(piece) == typeid(Queen)){
		//will print out Queen as the type of the piece 
		cout << "Queen" << endl;
	}
	//if the piece is neither a rook, bishop or queen then function will throw a invalid_argument as the type of piece is undefined 
	else {
		throw invalid_argument("undefined type of piece");
	}
	//prints the piece' top,bottom,left and right locations on the chess board
	cout << piece << endl;
}

/**
 * function to generate a random float for the piece' x and y position on the chessboard, takes in a minimum and maximum value to return a float within these bounds
*/
float generateRandomFloat(float min, float max) {
    float smallRandomFloat = ((float) rand()) / (float) RAND_MAX;
    float minMaxDifference = max - min;
    float result = smallRandomFloat * minMaxDifference;
    return min + result;
}
