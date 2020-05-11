#pragma once

#include <SFML\Graphics.hpp>
#include "SoundBoard.h"

class VictoryScreen
{
	public:
		sf::Text victoryMessage; //Label that says 'Player X Wins!!!'
		sf::Text backToTitleLabel; //label that says 'Click left to go back to title'
		sf::Font superMarioFont; //font object
		SoundBoard* soundBoard;
		sf::RenderWindow* window;
		VictoryScreen(SoundBoard*, sf::RenderWindow*); //constructor
		VictoryScreen() {} //worthless default constructor
		void draw(); //draws victory screen
};