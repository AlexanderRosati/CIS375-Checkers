#include "Board.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Description: Returns true if space number 'spaceNum' is empty. Otherwise,
//return false.
bool Board::isSpaceEmpty(int spaceNum)
{
	//temporary please delete
	return true;
}

//Precondition: spaceNum has a checker on it
//Description: Returns true if the checker on spaceNum is controlled by player 'playerNum'.
bool Board::isRightPlayer(int playerNum, int spaceNum)
{
	//temporary please delete
	return true;
}

//Precondition: spaceNum has a checker on it.
//Description: Determines if checker can move
bool Board::canCheckerMove(int spaceNum)
{
	//temporary please delete
	return true;
}

//Description: Returns where a checker can be moved and what needs to be
//removed from the board if it is moved there.
std::vector<std::pair<int, std::vector<int>>>
Board::possibleMoves(int spaceNum)
{
	//temporary please delete
	std::vector<std::pair<int, std::vector<int>>> temp;
	return temp;
}

//Desciption: Removes a checker from the board by putting an "E" at that index.
void Board::removeChecker(int spaceNum)
{

}

//Precondition: spaceNum must contain a checker, whereTo does not contain a checker
//and the move is valid.
//Description: Moves what's at spaceNum to what's at whereTo
void Board::move(int spaceNum, int whereTo)
{

}

//Description: Resets game board (i.e., moves pieces to where they should be at the
//beginning of a game.
void Board::resetBoard()
{

}

//Description: Player number is given as input and true is returned if that player can
//move
bool Board::canPlayerMove(int playerNum)
{
	//This isn't a priority. If this isn't implemented, we'll be fine.
	//Do other things first.

	//temporary please detele
	return true;
}

//Precondition: checker at spaceNum is one that made it to the opposite end of the board.
//Description: Kings the checer at spaceNum
void Board::kingMe(int spaceNum)
{

}

//Description: constructor
Board::Board()
{

}

//Description: should draw the game board and all the pieces
void Board::drawBoard()
{

}