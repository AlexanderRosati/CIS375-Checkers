#pragma once

#include <SFML\Graphics.hpp>

class VictoryScreen
{
	public:
		sf::Text victoryMessage; //Label that says 'Player X Wins!!!'
		VictoryScreen(); //constructor
		void draw(); //draws victory screen
};