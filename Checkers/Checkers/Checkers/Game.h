#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Vector>
#include "Soundboard.h"
#include "Board.h"


class Game
{
	public:
		//data members
		int playersTurn; //whose turn it is (either 1 or 2)
		int numCheckersPlayerOne; //how many checkers player one has left
		int numCheckersPlayerTwo; //how many chceckers player two has left
		int selectedChecker; //space number for selected checker
		SoundBoard* soundBoard; //reference to sound board
		sf::RectangleShape boardSpaces[32]; //array of rectangles; each coresponsds to a board space
		std::vector<int> possibleLandingPositions; //where selected checker could be moved
		sf::Text landingPositionMarker; //character 'M' that will be drawn to screen whereever checker can be moved

		//methods
		Game(SoundBoard*, sf::RenderWindow*); //constructor
		Game() {} //worthless default constructor
		void resetGame(); //resets the game
		void drawGame(); //draws the game screen
		void moveBoardSpacesOffscreen();
		void moveBoardSpacesOnscreen();

	private:
		//data members
		sf::RenderWindow* window; //refernce to game window
		sf::Text numCheckersLabel; //label that says 'Checkers'
		sf::Text numCheckersPlayerOneLabel; //label that says 'P1: X' where X is number of checkers player one has
		sf::Text numCheckersPlayerTwoLabel; //label that says 'P2: X' where X is number of checkers player two has
		sf::Text colorsLabel; //label that says 'Colors'
		sf::Text colorPlayerOneLabel; //label that says 'P1'
		sf::Text colorPlayerTwoLabel; //label that says 'P2'
		sf::Text playerXsTurnLabel; //label that says 'Player X's Turn'
};