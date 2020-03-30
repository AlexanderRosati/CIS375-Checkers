#pragma once

#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>

class TitleMenu
{
	public:
		TitleMenu(); //constructor
		void draw(); //draws title menu
		void movesOffscreen(); //moves title menu offscreen
		void movesOnscreen(); //moves title menu onscreen
	private:
		sf::Text title; //label that says 'Checkers' at top of title menu.
		sf::Sprite playGameButton; //button that says 'Play Game'
		sf::Sprite musicSelectionButton; //button that says 'Music Selection Menu'
		sf::Sprite customizationsButton; //button that says 'Customizations'
		sf::Sprite tutorialButton; //button that says 'Tutorial'
		sf::RenderWindow* window; //ref to game window
};