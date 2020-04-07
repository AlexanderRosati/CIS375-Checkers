#include "Board.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include <iostream>
#include <cstdlib>

//Description: Returns true if space number 'spaceNum' is empty. Otherwise,
//return false. Input is between 1 and 32.
bool Board::isSpaceEmpty(int spaceNum)
{
	return content[spaceNum - 1] == "E";
}

//Precondition: spaceNum has a checker on it
//Description: Returns true if the checker on spaceNum is controlled by player 'playerNum'.
bool Board::isRightPlayer(int playerNum, int spaceNum)
{

	return content[spaceNum - 1].at(1) == (char) playerNum;
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
PossibleMoves Board::possibleMoves(int spaceNum)
{
	//local vars
	int contentIndx = spaceNum - 1;
	int row = contentIndx / 4;
	char status = content[contentIndx].at(0);
	char player = content[contentIndx].at(1);
	char turningDirection = NULL;
	std::vector<int> adjacent;
	PossibleMoves possibleMoves;
	PossibleMoves somePossibleMoves;

	adjacent = adjSpaces(status, player, row, contentIndx);

	//its a checker controlled by player one
	if (player == '1' && status == 'P')
	{
		//current space
		int space;

		//iterating through adjacent spaces
		while (!adjacent.empty())
		{
			//get space at end of vector
			space = adjacent.at(adjacent.size() - 1);
			adjacent.pop_back();

			//if space is empty
			if (isSpaceEmpty(space + 1))
			{
				possibleMoves.push_back(std::pair<int, std::vector<int>>(space, std::vector<int>()));
			}

			//if space contains checker controlled by same player
			else if (isRightPlayer((int)player, space + 1))
			{
				continue;
			}

			//space is occupied by opponents checker
			else
			{
				//local vars
				int possibleLandingSpace = 0;

				//opponent is at edge so cannot jump
				if (space == 0 || space == 1 || space == 2 || space == 3 || space == 11 ||
					space == 19 || space == 27 || space == 20 || space == 12 || space == 4)
				{
					continue;
				}

				//figure out if opponent is to the right or left
				turningDirection = determineDirection(contentIndx, space, row);

				//determine where we may land
				if (turningDirection == 'R') { possibleLandingSpace = contentIndx - 7; }
				if (turningDirection == 'L') { possibleLandingSpace = contentIndx - 9; }

				//don't add anything b/c landing space is occupied
				if (!isSpaceEmpty(possibleLandingSpace + 1)) { continue; }

				//determine possible landing positions
				determineLandingPositions(possibleLandingSpace, status, player, row - 2, space, &somePossibleMoves);

				//put all moves into possible moves
				for (int i = 0; i < somePossibleMoves.size(); ++i)
				{
					possibleMoves.push_back(somePossibleMoves.at(i));
				}

				//empty somePossibleMoves
				somePossibleMoves = PossibleMoves();
			}
		}
	}

	//its a checker controlled by player two
	else if (player == '2' && status == 'P')
	{

	}

	//its a king controlled by player one
	else if (player == '1' && status == 'K')
	{

	}

	//its a king controlled by player two
	else if (player == '2' && status == 'K')
	{

	}

	//transalte indexes into values between 1 and 32
	for (int i = 0; i < possibleMoves.size(); ++i)
	{
		possibleMoves.at(i).first += 1;

		for (int j = 0; j < possibleMoves.at(i).second.size(); ++j)
		{
			possibleMoves.at(i).second.at(j) += 1;
		}
	}

	//return possible moves
	return possibleMoves;
}

//Description: Determines landing positions
void Board::determineLandingPositions(int possibleLandingPosition, char status, char player, int row, int opponentSpace, PossibleMoves* somePossibleMoves)
{
	//determine adjacent spaces
	std::vector<int> adjacent;
	int adjSpace = NULL;
	char leftOrRight = NULL;
	int anotherPossibleLandingSpace = NULL;
	bool isLandingSpace = true;

	//calcualte adjacent spaces
	adjacent = adjSpaces(status, player, row, possibleLandingPosition);

	//iterate through adjacent spaces
	while (!adjacent.empty())
	{
		//select and adjacent space
		adjSpace = adjacent.at(adjacent.size() - 1);
		adjacent.pop_back();

		//if adjacent space is empty
		if (isSpaceEmpty(adjSpace + 1))
		{
			continue;
		}

		//if adjacent space contains checker controlled by the same player
		else if (isRightPlayer((int)status, adjSpace + 1))
		{
			continue;
		}

		//opponent checker is on space
		else
		{
			//opponent checker is on edge
			if (adjSpace == 0 || adjSpace == 1 || adjSpace == 2 || adjSpace == 3 || adjSpace == 11 ||
				adjSpace == 19 || adjSpace == 27 || adjSpace == 20 || adjSpace == 12 || adjSpace == 4)
			{
				continue;
			}

			//determine whether opponent is to the left of space or right of space
			leftOrRight = determineDirection(possibleLandingPosition, adjSpace, row);

			//determine whether space is empty or not
			if (leftOrRight == 'R') anotherPossibleLandingSpace = possibleLandingPosition - 7;
			if (leftOrRight == 'L') anotherPossibleLandingSpace = possibleLandingPosition - 9;
			if (!isSpaceEmpty(anotherPossibleLandingSpace + 1)) { continue; }

			//possibleLandingPostion is not a landing position
			isLandingSpace = false;

			//recursive call
			determineLandingPositions(anotherPossibleLandingSpace, status, player, row - 2, adjSpace, somePossibleMoves);

			//adding checkers to remove for certain moves
			for (int i = 0; i < somePossibleMoves->size(); ++i)
			{
				if (std::count(somePossibleMoves->at(i).second.begin(), somePossibleMoves->at(i).second.end(), opponentSpace) == 0)
				{
					somePossibleMoves->at(i).second.push_back(opponentSpace);
				}
			}
		}
	}

	//if its a landing space
	if (isLandingSpace)
	{
		std::vector<int> tmp;
		tmp.push_back(opponentSpace);
		somePossibleMoves->push_back(std::pair<int, std::vector<int>>(possibleLandingPosition, tmp));
	}
}

//Description: figure out if opponent is to the left or right
char Board::determineDirection(int spaceNum, int opponentNum, int row)
{
	//local vars
	int diff = abs(spaceNum - opponentNum);
	char dir = NULL;

	//break it down by row on board
	switch (row)
	{
		case 7:
		case 5:
		case 3:
			if (diff == 5) dir = 'L';
			if (diff == 4) dir = 'R';
			
			break;

		case 6:
		case 4:
		case 2:
			if (diff == 4) dir = 'L';
			if (diff == 3) dir = 'R';

			break;
	}

	return dir;
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