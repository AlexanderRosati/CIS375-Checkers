#pragma once

#include <SFML\Graphics.hpp>
#include "SoundBoard.h"

#define NUM_SLIDES 6

class Tutorial
{
	public:
		Tutorial(SoundBoard*, sf::RenderWindow*); //Constructor
		Tutorial() {} //worthless default constructor
		void drawCurrSlide(); //draw current slide
		bool nextSlide(); //move to next slide

	private:
		sf::Sprite slides[NUM_SLIDES]; //array full of slides for tutorial
		sf::Texture textsForSlides[NUM_SLIDES]; //array full of textures for slides
		int currSlide; //index of current slide
		sf::RenderWindow* window; //ref to game window
		SoundBoard* soundBoard; //ref to sound board
};