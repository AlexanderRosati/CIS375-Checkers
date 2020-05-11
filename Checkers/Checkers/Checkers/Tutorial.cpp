#include "Tutorial.h"
#include <iostream>

//Description: Constructor
Tutorial::Tutorial(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//load textures for slides
	for (int i = 0; i < 6; ++i)
	{
		if (!textsForSlides[i].loadFromFile("../../IMAGES/tutorial-slides/tut-slide-" + std::to_string(i + 1) + ".png"))
		{
			std::cout << "Did not load texture for slide " + std::to_string(i + 1) + ". Terminating." << std::endl;
			system("pause");
			exit(-1);
		}

		else
		{
			slides[i].setTexture(textsForSlides[i]);
		}
	}

	//initialize currSlide
	currSlide = 0;
	
	//keep ref to sound board
	soundBoard = refToSoundBoard;
	
	//keep ref to game window
	window = refToWindow;
}

//Description: Draws current slide
void Tutorial::drawCurrSlide()
{
	window->draw(slides[currSlide]);
}

//Desciption: Advances to next slide. If on last slide, go to first. If advancing from last to first
//return true. Otherwise, return false.
bool Tutorial::nextSlide()
{
	currSlide = (currSlide + 1) % NUM_SLIDES; //do wrap around
	return (currSlide == 0) ? true : false; //return true if going back to first slide
}