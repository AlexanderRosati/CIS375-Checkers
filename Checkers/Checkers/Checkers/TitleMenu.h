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
		sf::Sprite playGameButton; //button that says 'Play Game'
		sf::Sprite musicSelectionButton; //button that says 'Music Selection Menu'
		sf::Sprite customizationsButton; //button that says 'Customizations'
		sf::Sprite tutorialButton; //button that says 'Tutorial'
		sf::Sprite marioHead; //sprite for mario's head
		enum Selection { Nothing, PlayGame, Customizations, MusicSelection, Tutorial };
		Selection selection;
	private:
		sf::Sprite title; //label that says 'Checkers' at top of title menu.
		sf::Texture titleTexture; //texture for title
		sf::Texture texturePlayGame; //texture for play game button
		sf::Texture textureMusicButton; //texture for music button
		sf::Texture textureCustomizationButton; //texture for customixation button
		sf::Texture textureTutorialButton; //texture for tutorial button
		sf::Texture textyMarioHead; //texture for mario's head
		sf::RenderWindow* window; //ref to game window
		SoundBoard* soundBoard;
};