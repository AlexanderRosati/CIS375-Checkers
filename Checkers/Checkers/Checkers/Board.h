#pragma once

#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundBoard.h"
#include <vector>
#include <utility>

class Board
{
	public:
		//data members
		sf::Sprite playerOneCheckerImg; //image for player one's checker
		sf::Sprite playerTwoCheckerImg; //image for player two's checker
		sf::Sprite playerOneKingImg; //image for player one's king
		sf::Sprite playerTwoKingImg; //image for player two's king
		sf::Sprite boardImage; //image for the board
		SoundBoard* soundBoard; //ref to sound board
		std::string content[32]; //says what is on the board

		//methods
		bool isSpaceEmpty(int); //tells you if a space is empty
		bool isRightPlayer(int, int); //used to determine if a checker belongs to a player
		bool canCheckerMove(int); //tells you if a checker on a space can move
		std::vector < std::pair<int, std::vector<int>>> possibleMoves(int); //returns spaces a checker can be moved to
		void removeChecker(int); //removes a checker from the board
		void move(int, int); //moves a checker
		void resetBoard(); //resets game board
		bool canPlayerMove(int); //determines if a player can move
		void kingMe(int); //kings a checker
		Board(); //constructor
		void drawBoard(); //draws board
		std::vector<int> adjSpaces(char, char, int, int); //tells you adjacent spaces of a space

	private:
		//data members
		sf::RenderWindow* window; //ref to game window
};