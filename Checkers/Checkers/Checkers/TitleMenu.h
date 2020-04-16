#pragma once

#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include "SoundBoard.h"

class TitleMenu
{
	public:
		TitleMenu() {} //worthless default constructor. DO NOT USE.
		TitleMenu(sf::RenderWindow*, SoundBoard*); //constructor
		void draw(); //draws title menu
		void movesOffscreen(); //moves title menu offscreen
		void movesOnscreen(); //moves title menu onscreen
	private:
		sf::Sprite title; //label that says 'Checkers' at top of title menu.
		sf::Texture titleTexture; //texture for title
		sf::Sprite playGameButton; //button that says 'Play Game'
		sf::Texture texturePlayGame; //texture for play game button
		sf::Sprite musicSelectionButton; //button that says 'Music Selection Menu'
		sf::Texture textureMusicButton; //texture for music button
		sf::Sprite customizationsButton; //button that says 'Customizations'
		sf::Texture textureCustomizationButton; //texture for customixation button
		sf::Sprite tutorialButton; //button that says 'Tutorial'
		sf::Texture textureTutorialButton; //texture for tutorial button
		sf::RenderWindow* window; //ref to game window
		SoundBoard* soundBoard;
};