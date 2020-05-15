#pragma once

#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundBoard.h"
#include <vector>
#include <utility>
#include <iostream>

typedef std::vector<std::pair<int, std::vector<int>>> PossibleMoves;

class Board
{
public:
	//data members
	sf::Sprite playerOneCheckerImg; //image for player one's checker
	sf::Texture texturePlayerOneChecker; //texture for player one checker
	sf::Sprite playerTwoCheckerImg; //image for player two's checker
	sf::Texture texturePlayerTwoChecker; //texture for player two checker
	sf::Sprite playerOneKingImg; //image for player one's king
	sf::Texture texturePlayerOneKing; //texture for player one king
	sf::Sprite playerTwoKingImg; //image for player two's king
	sf::Texture texturePlayerTwoKing; //texture for player two king
	sf::Sprite boardImage; //image for the board
	sf::Texture textureBoard; //texture for board
	SoundBoard* soundBoard; //ref to sound board
	std::string content[32]; //says what is on the board

	//methods
	bool isSpaceEmpty(int); //tells you if a space is empty
	bool isRightPlayer(char, int); //used to determine if a checker belongs to a player
	PossibleMoves possibleMoves(int); //returns spaces a checker can be moved to
	void removeChecker(int); //removes a checker from the board
	void move(int, int); //moves a checker
	void resetBoard(); //resets game board
	bool canPlayerMove(int); //determines if a player can move
	Board() {} //worthless default constructor. DO NOT USE.
	Board(SoundBoard*, sf::RenderWindow*); //constructor
	void drawBoard(); //draws board
	void emptyBoard(); //empties board

private:
	//data members
	sf::RenderWindow* window; //ref to game window
	std::vector<int> adjSpaces(char, char, int, int); //tells you adjacent spaces of a space
	char determineDirection(int, int, int, char); //determine which direction opponent is
	void Board::determineLandingPositions(int, char, char, int, int, PossibleMoves*, int); //determines landing positions
	bool isEdgeSpace(int); //returns true if given space is an edge space
};