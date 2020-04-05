#include "Board.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>

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


//Description: returns adjacent spaces. helper method of possibleMoves
std::vector<int> Board::adjSpaces(char status, char player, int row, int contentIndx)
{
	//vector for adjacent spaces
	std::vector<int> adjSpaces;

	//if it's a regular checker and player 2
	if (status == 'P' && player == '2')
	{
		//look at row on board
		switch (row)
		{
			//4-5 rows
			case 0:
			case 2:
			case 4:
			case 6:
				
				//edge cases that only have one adj space
				if (contentIndx == 3)
				{
					adjSpaces.push_back(7);
				}

				else if (contentIndx == 11)
				{
					adjSpaces.push_back(15);
				}

				else if (contentIndx == 19)
				{
					adjSpaces.push_back(23);
				}

				else if (contentIndx == 27)
				{
					adjSpaces.push_back(31);
				}

				//two adj spaces
				else
				{
					adjSpaces.push_back(contentIndx + 4);
					adjSpaces.push_back(contentIndx + 5);
				}

				break;

			//3-4 cases
			case 1:
			case 3:
			case 5:
				//edge cases that have only one adj space
				if (contentIndx == 4)
				{
					adjSpaces.push_back(8);
				}

				else if (contentIndx == 12)
				{
					adjSpaces.push_back(16);
				}

				else if (contentIndx == 20)
				{
					adjSpaces.push_back(24);
				}

				//two adj spaces
				else
				{
					adjSpaces.push_back(contentIndx + 3);
					adjSpaces.push_back(contentIndx + 4);
				}

				break;
		}
	}

	//its a regular checker and player one
	else if (status == 'P' && player == '1')
	{
		switch (row)
		{
			case 7:
			case 5:
			case 3:
			case 1:
				if (contentIndx == 28)
				{
					adjSpaces.push_back(24);
				}

				else if (contentIndx == 20)
				{
					adjSpaces.push_back(16);
				}

				else if (contentIndx == 12)
				{
					adjSpaces.push_back(8);
				}

				else if (contentIndx == 4)
				{
					adjSpaces.push_back(0);
				}

				else
				{
					adjSpaces.push_back(contentIndx - 4);
					adjSpaces.push_back(contentIndx - 5);
				}

				break;

			case 6:
			case 4:
			case 2:
				if (contentIndx == 27)
				{
					adjSpaces.push_back(23);
				}

				else if (contentIndx == 19)
				{
					adjSpaces.push_back(15);
				}

				else if (contentIndx == 11)
				{
					adjSpaces.push_back(7);
				}

				else
				{
					adjSpaces.push_back(contentIndx - 3);
					adjSpaces.push_back(contentIndx - 4);
				}

				break;
		}
	}

	//its a king
	else if (status == 'K')
	{
		//look at each row on board
		switch (row)
		{
			//top row
			case 0:
				//corner
				if (contentIndx == 3)
				{
					adjSpaces.push_back(7);
				}

				//top edge of board
				else
				{
					adjSpaces.push_back(contentIndx + 4);
					adjSpaces.push_back(contentIndx + 5);
				}

				break;

			//-5, -4, +3, +4
			case 1:
			case 3:
			case 5:
				//left edge of board
				if (contentIndx == 4)
				{
					adjSpaces.push_back(0);
					adjSpaces.push_back(8);
				}

				else if (contentIndx == 12)
				{
					adjSpaces.push_back(8);
					adjSpaces.push_back(16);
				}

				else if (contentIndx == 20)
				{
					adjSpaces.push_back(16);
					adjSpaces.push_back(24);
				}

				//center of board
				else
				{
					adjSpaces.push_back(contentIndx - 5);
					adjSpaces.push_back(contentIndx - 4);
					adjSpaces.push_back(contentIndx + 3);
					adjSpaces.push_back(contentIndx + 4);
				}

				break;

			//-4. -3, +4, +5
			case 2:
			case 4:
			case 6:

				//right edge of board
				if (contentIndx == 11)
				{
					adjSpaces.push_back(7);
					adjSpaces.push_back(15);
				}

				else if (contentIndx == 19)
				{
					adjSpaces.push_back(15);
					adjSpaces.push_back(23);
				}

				else if (contentIndx == 27)
				{
					adjSpaces.push_back(23);
					adjSpaces.push_back(31);
				}

				//center of board
				else
				{
					adjSpaces.push_back(contentIndx - 4);
					adjSpaces.push_back(contentIndx - 3);
					adjSpaces.push_back(contentIndx + 4);
					adjSpaces.push_back(contentIndx + 5);
				}

				break;

			case 7:
				
				//corner
				if (contentIndx == 28)
				{
					adjSpaces.push_back(24);
				}

				//bottom edge of board
				else
				{
					adjSpaces.push_back(contentIndx - 4);
					adjSpaces.push_back(contentIndx - 5);
				}

				break;
		}
	}

	//return adj spaces
	return adjSpaces;
}

//Description: Returns where a checker can be moved and what needs to be
//removed from the board if it is moved there.
//Precondition: Space is not empty. spaceNum is between 1 and 32.
std::vector<std::pair<int, std::vector<int>>>
Board::possibleMoves(int spaceNum)
{
	//local vars
	int contentIndx = spaceNum - 1;
	int row = contentIndx / 4;
	char status = content[contentIndx].at(0);
	char player = content[contentIndx].at(1);
	std::vector<int> adjacent;

	adjacent = adjSpaces(status, player, row, contentIndx);

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