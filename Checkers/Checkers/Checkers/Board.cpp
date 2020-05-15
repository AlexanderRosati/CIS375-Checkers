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
bool Board::isRightPlayer(char playerNum, int spaceNum)
{
	std::string tmp1 = "";
	tmp1 += content[spaceNum - 1].at(1);
	std::string tmp2 = (playerNum == '1') ? "1" : "2";
	return tmp1 == tmp2;
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
	int jumpFactor = NULL;
	char aboveOrBelow = NULL;
	std::string orignalContentOfBoard = content[contentIndx];
	std::vector<int> adjacent;
	PossibleMoves possibleMoves;
	PossibleMoves somePossibleMoves;

	adjacent = adjSpaces(status, player, row, contentIndx);

	//remove piece were examining from board
	content[contentIndx] = "E";

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
		else if (isRightPlayer(player, space + 1))
		{
			continue;
		}

		//space is occupied by opponents checker
		else
		{
			//local vars
			int possibleLandingSpace = 0;

			//opponent is at edge so cannot jump
			if (isEdgeSpace(space))
			{
				continue;
			}

			//determine whether opponent is above or below
			if ((contentIndx - space) > 0)
			{
				aboveOrBelow = 'A';
				jumpFactor = -2;
			}

			else
			{
				aboveOrBelow = 'B';
				jumpFactor = 2;
			}

			//figure out if opponent is to the right or left
			turningDirection = determineDirection(contentIndx, space, row, aboveOrBelow);

			//determine where we may land
			if (aboveOrBelow == 'A')
			{
				if (turningDirection == 'R') possibleLandingSpace = contentIndx - 7;
				if (turningDirection == 'L') possibleLandingSpace = contentIndx - 9;
			}

			else if (aboveOrBelow == 'B')
			{
				if (turningDirection == 'L') possibleLandingSpace = contentIndx + 7;
				if (turningDirection == 'R') possibleLandingSpace = contentIndx + 9;
			}

			//don't add anything b/c landing space is occupied
			if (!isSpaceEmpty(possibleLandingSpace + 1)) { continue; }

			//determine possible landing positions
			determineLandingPositions(possibleLandingSpace, status, player, row + jumpFactor, space, &somePossibleMoves, contentIndx);


			std::vector<int> currLandingSpaces;
			for (int i = 0; i < possibleMoves.size(); ++i)
			{
				currLandingSpaces.push_back(possibleMoves.at(i).first);
			}

			//put all moves into possible moves
			for (int i = 0; i < somePossibleMoves.size(); ++i)
			{
				if (std::count(currLandingSpaces.begin(), currLandingSpaces.end(), somePossibleMoves.at(i).first) == 0)
				{
					possibleMoves.push_back(somePossibleMoves.at(i));
				}
			}

			//empty somePossibleMoves
			somePossibleMoves = PossibleMoves();
		}
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

	//remove piece were examining from board
	content[contentIndx] = orignalContentOfBoard;

	//return possible moves
	return possibleMoves;
}

//Description: Determines landing positions
void Board::determineLandingPositions(int possibleLandingPosition, char status, char player, int row,
	                                  int opponentSpace, PossibleMoves* somePossibleMoves, int originalPos)
{
	//determine adjacent spaces
	std::vector<int> adjacent;
	int adjSpace = NULL;
	char leftOrRight = NULL;
	char aboveOrBelow = NULL;
	int anotherPossibleLandingSpace = NULL;
	bool isLandingSpace = true;
	int jumpFactor = NULL;
	
	//we went in a loop i.e., Test 58
	if (possibleLandingPosition == originalPos)
	{
		//add move
		std::vector<int> tmp;
		tmp.push_back(opponentSpace);
		somePossibleMoves->push_back(std::pair<int, std::vector<int>>(possibleLandingPosition, tmp));
		return;
	}

	//calcualte adjacent spaces
	adjacent = adjSpaces(status, player, row, possibleLandingPosition);

	//don't consider space we're going to jump over
	for (int i = 0; i < adjacent.size(); ++i)
	{
		if (adjacent.at(i) == opponentSpace)
		{
			adjacent.erase(adjacent.begin() + i);
			--i;
		}
	}

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
		else if (isRightPlayer(player, adjSpace + 1))
		{
			continue;
		}

		//opponent checker is on space
		else
		{
			//opponent checker is on edge
			if (isEdgeSpace(adjSpace))
			{
				continue;
			}

			if ((possibleLandingPosition - adjSpace) > 0)
			{
				aboveOrBelow = 'A';
				jumpFactor = -2;
			}

			else
			{
				aboveOrBelow = 'B';
				jumpFactor = 2;
			}

			//determine whether opponent is to the left of space or right of space
			leftOrRight = determineDirection(possibleLandingPosition, adjSpace, row, aboveOrBelow);

			//determine whether space is empty or not
			if (aboveOrBelow == 'A')
			{
				if (leftOrRight == 'R') anotherPossibleLandingSpace = possibleLandingPosition - 7;
				if (leftOrRight == 'L') anotherPossibleLandingSpace = possibleLandingPosition - 9;
			}
			
			else if (aboveOrBelow == 'B')
			{
				if (leftOrRight == 'L') anotherPossibleLandingSpace = possibleLandingPosition + 7;
				if (leftOrRight == 'R') anotherPossibleLandingSpace = possibleLandingPosition + 9;
			}

			if (!isSpaceEmpty(anotherPossibleLandingSpace + 1)) { continue; }

			//possibleLandingPostion is not a landing position
			isLandingSpace = false;

			//recursive call
			determineLandingPositions(anotherPossibleLandingSpace, status, player, row + jumpFactor, adjSpace, somePossibleMoves, originalPos);

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
char Board::determineDirection(int spaceNum, int opponentNum, int row, char aboveOrBelow)
{
	//local vars
	int diff = abs(spaceNum - opponentNum);
	char dir = NULL;

	//if its player one
	if (aboveOrBelow == 'A')
	{
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
	}

	//if its player two
	else if (aboveOrBelow == 'B')
	{
		switch (row)
		{
			case 0:
			case 2:
			case 4:
				if (diff == 4) dir = 'L';
				if (diff == 5) dir = 'R';

				break;
			case 1:
			case 3:
			case 5:
				if (diff == 3) dir = 'L';
				if (diff == 4) dir = 'R';

				break;
		}
	}

	return dir;
}

//Desciption: Removes a checker from the board by putting an "E" at that index.
void Board::removeChecker(int spaceNum)
{
	content[spaceNum - 1] = "E";
}

//Precondition: spaceNum must contain a checker, whereTo does not contain a checker
//and the move is valid.
//Description: Moves what's at spaceNum to what's at whereTo
void Board::move(int spaceNum, int whereTo)
{
	std::string pieceBeingMoved = content[spaceNum - 1]; //save what's being moved
	content[spaceNum - 1] = "E"; //remove piece from board
	content[whereTo - 1] = pieceBeingMoved; //put piece back on board

	//if player one reaches end of board
	if (pieceBeingMoved == "P1" && (whereTo >= 1 && whereTo <= 4))
	{
		content[whereTo - 1] = "K1";
		soundBoard->play("kinged");
	}

	//if player two reaches the end of the board
	else if (pieceBeingMoved == "P2" && (whereTo >= 29 && whereTo <= 32))
	{
		content[whereTo - 1] = "K2";
		soundBoard->play("kinged");
	}
}

//Description: Empties board
void Board::emptyBoard()
{
	for (int i = 0; i < 32; ++i)
	{
		content[i] = "E";
	}
}

//Description: Resets game board (i.e., moves pieces to where they should be at the
//beginning of a game.
void Board::resetBoard()
{
	//remove all pieces from board
	emptyBoard();

	//put checkers on board
	for (int i = 0; i < 12; ++i)
	{
		content[i] = "P2";
	}

	for (int i = 20; i < 32; ++i)
	{
		content[i] = "P1";
	}
}

//Description: Player number is given as input and true is returned if that player can
//move
bool Board::canPlayerMove(int playerNum)
{
	//looking for checkers and kings for given player
	std::string match1 = "P"; match1 += std::to_string(playerNum);
	std::string match2 = "K"; match2 += std::to_string(playerNum);

	//iterate through board
	for (int i = 0; i < 32; ++i)
	{
		//if we find a checker or king controlled by the given player
		if (content[i] == match1 || content[i] == match2)
		{
			PossibleMoves moves = possibleMoves(i + 1);

			//if there is a move the player can make
			if (moves.size() != 0)
			{
				return true;
			}
		}
	}

	//player can't make a move
	return false;
}

//Description: constructor
Board::Board(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//load player one regular checker into memory
	if (!texturePlayerOneChecker.loadFromFile("../../IMAGES/customizations/customization1/player-one-checker-customization1.png"))
	{
		std::cout << "Player one checker image did not load for customization 1. Exiting program" << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite a texture
	else
	{
		playerOneCheckerImg.setTexture(texturePlayerOneChecker);
	}

	//load player two regular checker into memory
	if (!texturePlayerTwoChecker.loadFromFile("../../IMAGES/customizations/customization1/player-two-checker-customization1.png"))
	{
		std::cout << "Player two checker image did not load for customization 1. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite a texture
	else
	{
		playerTwoCheckerImg.setTexture(texturePlayerTwoChecker);
	}

	//load player one king image into memory
	if (!texturePlayerOneKing.loadFromFile("../../IMAGES/customizations/customization1/player-one-king-customization1.png"))
	{
		std::cout << "Player one king image did not load for customization 1. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite a texture
	else
	{
		playerOneKingImg.setTexture(texturePlayerOneKing);
	}

	//load player two king image into memory
	if (!texturePlayerTwoKing.loadFromFile("../../IMAGES/customizations/customization1/player-two-king-customization1.png"))
	{
		std::cout << "Player two king image did not load for customization 1. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite a texture
	else
	{
		playerTwoKingImg.setTexture(texturePlayerTwoKing);
	}

	//load board image into memory
	if (!textureBoard.loadFromFile("../../IMAGES/customizations/customization1/board-customization1.png"))
	{
		std::cout << "Board image for customization 1 did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite texture
	else
	{
		boardImage.setTexture(textureBoard);
	}

	//keep reference to sound board object
	soundBoard = refToSoundBoard;

	//put checkers on board
	resetBoard();

	//keep reference to game window
	window = refToWindow;

	//put board in right position
	boardImage.setPosition(sf::Vector2f(20.0, 20.0));
}

//Description: should draw the game board and all the pieces
void Board::drawBoard()
{
	//draw board
	window->draw(boardImage);

	//draw piecies
	for (int i = 0; i < 32; ++i)
	{
		//if space contains regular checker controlled by player one
		if (content[i] == "P1")
		{
			//vars for coordinates
			float x = 20;
			float y = 20;
			int row = i / 4;
			int col = i % 4;

			//adjust for alternating rows
			if ((row % 2) == 0)
			{
				x += 50;
			}

			//adjust for column
			x += (col * 100);

			//adjust for row
			y += (row * 50);

			//move rectangle
			playerOneCheckerImg.setPosition(sf::Vector2f(x, y));

			//draw checker
			window->draw(playerOneCheckerImg);
		}

		//if space contains regular checker controlled by player two
		else if (content[i] == "P2")
		{
			//vars for coordinates
			float x = 20;
			float y = 20;
			int row = i / 4;
			int col = i % 4;

			//addjust for alternating rows
			if ((row % 2) == 0)
			{
				x += 50;
			}

			//adjust for column
			x += (col * 100);

			//adjust for row
			y += (row * 50);

			//move rectangle
			playerTwoCheckerImg.setPosition(sf::Vector2f(x, y));

			//draw checker
			window->draw(playerTwoCheckerImg);
		}

		//if space contains king controlled by player one
		else if (content[i] == "K1")
		{
			//vars for coordinates
			float x = 20;
			float y = 20;
			int row = i / 4;
			int col = i % 4;

			//addjust for alternating rows
			if ((row % 2) == 0)
			{
				x += 50;
			}

			//adjust for column
			x += (col * 100);

			//adjust for row
			y += (row * 50);

			//move rectangle
			playerOneKingImg.setPosition(sf::Vector2f(x, y));

			//draw checker
			window->draw(playerOneKingImg);
		}

		//if space contains king controlled by player two
		else if (content[i] == "K2")
		{
			//vars for coordinates
			float x = 20;
			float y = 20;
			int row = i / 4;
			int col = i % 4;

			//addjust for alternating rows
			if ((row % 2) == 0)
			{
				x += 50;
			}

			//adjust for column
			x += (col * 100);

			//adjust for row
			y += (row * 50);

			//move rectangle
			playerTwoKingImg.setPosition(sf::Vector2f(x, y));

			//draw checker
			window->draw(playerTwoKingImg);
		}
	}
}

//Description: Returns true if given number is edge space. Expects between 0-31.
bool Board::isEdgeSpace(int spaceNum)
{
	return (spaceNum == 0) || (spaceNum == 1) || (spaceNum == 2) || (spaceNum == 3) ||
		(spaceNum == 11) || (spaceNum == 19) || (spaceNum == 27) || (spaceNum == 31) ||
		(spaceNum == 30) || (spaceNum == 29) || (spaceNum == 28) || (spaceNum == 20) ||
		(spaceNum == 12) || (spaceNum == 4);
}