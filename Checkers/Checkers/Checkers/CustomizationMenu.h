#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundBoard.h"
#include "Board.h"

#define NUM_DIFF_CHECKERS 8
#define NUM_DIFF_KINGS 8
#define NUM_BOARDS 4

class CustomizationMenu
{
	public:
		SoundBoard* soundBoard; //ref to sound board
		sf::Sprite backToTitleButton; //back to title button
		sf::Sprite customizations[4]; //images for customizations
		int currCustomization; //keeps track of current customization
		CustomizationMenu(SoundBoard*, sf::RenderWindow*); //constructor
		CustomizationMenu() {} //worthless default constructor
		void changeCustomization(Board*, int); //method to change customizations
		void draw(); //draw customization menu
		void moveOffScreen(); //move customization menu offscreen
		void moveOnscreen(); //move customization menu onscreen
		void moveSelection(int); //move selection outline
	private:
		sf::Sprite title; //label that says 'Customization Menu'
		sf::Texture textTitle; //texture for title of menu
		sf::Texture textCustomizations[4]; //textures for images for customizations
		sf::Texture textBackToTitleButton; //texture for back button
		sf::RenderWindow* window; //ref to game window
};