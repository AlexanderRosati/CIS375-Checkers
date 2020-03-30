#pragma once

#include <SFML\Graphics.hpp>
#include "SoundBoard.h"

#define NUM_SLIDES 10

class Tutorial
{
	public:
		Tutorial(); //Constructor
		void drawCurrSlide(); //draw current slide
		bool nextSlide(); //move to next slide

	private:
		sf::Sprite slides[NUM_SLIDES]; //array full of slides for tutorial
		int currSlide; //index of current slide
		sf::RenderWindow* window; //ref to game window
		SoundBoard* soundBoard; //ref to sound board
};