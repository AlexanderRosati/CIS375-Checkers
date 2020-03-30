#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Soundboard.h"

class MusicSelectionMenu
{
	public:
		SoundBoard* soundBoard; //ref to sound board
		void goNextSong(); //go to next song
		void goPrevSong(); //go to prev song
		void draw(); //draw music selection menu
		void moveMenuOffScreen(); //move music selection menu offscreen
		void moveMenuOnscreen();  //move music selection menu onscreen
		MusicSelectionMenu(); //constructor

	private:
		//data members
		sf::Sprite leftArrow; //left arrow image
		sf::Sprite rightArrow; //right arrow image
		sf::Text title; //title of menu
		sf::Text songName; //song name that is displayed
		sf::Music songs[3]; //songs that play
		int currSong; //keep track of song that's playing
		sf::Sprite backToTitleScreen; //back button; image
		sf::RenderWindow* window; //ref to game window
};