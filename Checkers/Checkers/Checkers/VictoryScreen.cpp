#include "VictoryScreen.h"
#include <iostream>

//Description: Constuctor
VictoryScreen::VictoryScreen(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//load font file
	if (!superMarioFont.loadFromFile("../../FONTS/SuperMario256.ttf"))
	{
		std::cout << "Did not load super mario font. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	//set font for text
	victoryMessage.setFont(superMarioFont);

	//put in dummy text
	victoryMessage.setString("Player X Wins!!!");

	//set font size
	victoryMessage.setCharacterSize(40);

	//set font for text
	backToTitleLabel.setFont(superMarioFont);

	//put in message
	backToTitleLabel.setString("click left to go\n  back to title");

	//set color of label to red
	backToTitleLabel.setColor(sf::Color(255, 0, 0));

	//set font size
	backToTitleLabel.setCharacterSize(40);

	//keep ref to sound board
	soundBoard = refToSoundBoard;

	//keep ref to game window
	window = refToWindow;

	//put everything into position
	victoryMessage.setPosition(sf::Vector2f(100.0, 200.0));
	backToTitleLabel.setPosition(sf::Vector2f(100.0, 300.0));
}

//Description: Draw victory screen
void VictoryScreen::draw()
{
	window->draw(victoryMessage); //draw victory message
	window->draw(backToTitleLabel); //draw back to title label
}