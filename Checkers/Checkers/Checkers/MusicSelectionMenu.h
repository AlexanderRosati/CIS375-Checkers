#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Soundboard.h"

class MusicSelectionMenu
{
	public:
		SoundBoard* soundBoard; //ref to sound board
		sf::Sprite leftArrow; //left arrow image
		sf::Sprite rightArrow; //right arrow image
		sf::Sprite backToTitleScreen; //back button; image
		void goNextSong(); //go to next song
		void goPrevSong(); //go to prev song
		void draw(); //draw music selection menu
		void moveMenuOffScreen(); //move music selection menu offscreen
		void moveMenuOnscreen();  //move music selection menu onscreen
		MusicSelectionMenu() {}; //worthless default constructor
		MusicSelectionMenu(SoundBoard*, sf::RenderWindow*); //constructor

	private:
		//data members
		sf::Texture textLeftArrow; //texture for left arrow
		sf::Texture textRightArrow; //texture for right arrow
		sf::Sprite title; //title of menu
		sf::Texture textTitle; //texture for title of menu
		sf::Text songName; //song name that is displayed
		sf::Music songs[3]; //songs that play
		int currSong; //keep track of song that's playing
		sf::Texture textBackToTitleScreen; //texture for back button
		sf::RenderWindow* window; //ref to game window
		sf::Font superMarioFont; //object for mario sytle font
		std::string songNamesArr[3]; //array that contains song names
		sf::Vector2f labelPositions[3]; //so song name is displayed correctly
};