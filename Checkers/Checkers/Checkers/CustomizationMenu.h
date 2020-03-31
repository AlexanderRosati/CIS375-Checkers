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
		CustomizationMenu(); //constructor
		void changeCustomization(Board*, int); //method to change customizations
		void draw(); //draw customization menu
		void moveOffScreen(); //move customization menu offscreen
		void moveOnscreen(); //move customization menu onscreen
		void moveSelectionOutline(int); //move selection outline
	private:
		sf::Sprite title; //label that says 'Customization Menu'
		sf::Sprite customizations[4]; //images for customizations
		sf::Sprite backToTitleButton; //back to title button
		int currCustomization; //keeps track of current customization
		sf::Texture checkerTextures[NUM_DIFF_CHECKERS]; //all checker images
		sf::Texture kingTextures[NUM_DIFF_KINGS]; //all kings images
		sf::Texture boardTextures[NUM_BOARDS]; //all board images
		sf::RenderWindow* window; //ref to game window
};