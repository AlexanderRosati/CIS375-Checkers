#include "TitleMenu.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

//Desciption: Constructor
TitleMenu::TitleMenu(sf::RenderWindow* refToGameWindow, SoundBoard* refToSoundBoard)
{
	//load image for title
	if (!titleTexture.loadFromFile("../../IMAGES/title-screen/title-titlemenu.png"))
	{
		std::cout << "Image for title did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//asign sprite texture
	else
	{
		title.setTexture(titleTexture);
	}

	//load image for play game button
	if (!texturePlayGame.loadFromFile("../../IMAGES/title-screen/title-playgame-button.png"))
	{
		std::cout << "Image for play game button did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite texture
	else
	{
		playGameButton.setTexture(texturePlayGame);
	}

	//load image for music selection button
	if (!textureMusicButton.loadFromFile("../../IMAGES/title-screen/title-music-selection-button.png"))
	{
		std::cout << "Image for music selection menu button did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite texture
	else
	{
		musicSelectionButton.setTexture(textureMusicButton);
	}

	//load image for customization menu button
	if (!textureCustomizationButton.loadFromFile("../../IMAGES/title-screen/customizations-titlemenu-button.png"))
	{
		std::cout << "Image for customization menu button did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite texture
	else
	{
		customizationsButton.setTexture(textureCustomizationButton);
	}

	//load image for tutorial button
	if (!textureTutorialButton.loadFromFile("../../IMAGES/title-screen/title-tutorial-button.png"))
	{
		std::cout << "Image for tutorial button did not load. Exiting program." << std::endl;
		system("pause");
		exit(-1);
	}

	//assign sprite texture
	else
	{
		tutorialButton.setTexture(textureTutorialButton);
	}

	//keep track of game window
	window = refToGameWindow;

	//keep track of sound board
	soundBoard = refToSoundBoard;

	//move all images into position
	playGameButton.setPosition(sf::Vector2f(0, 160));
	customizationsButton.setPosition(sf::Vector2f(0, 260));
	musicSelectionButton.setPosition(sf::Vector2f(0, 360));
	tutorialButton.setPosition(sf::Vector2f(0, 460));
}

//Description: Draws title menu.
void TitleMenu::draw()
{
	window->draw(title);
	window->draw(playGameButton);
	window->draw(customizationsButton);
	window->draw(musicSelectionButton);
	window->draw(tutorialButton);
}

//Description: Moves all the buttons offscreen so user cannot click on them. By move offscreen,
//I mean move them like 2000 units down.
void TitleMenu::movesOffscreen()
{

}

//Description: Opposite of movesOffscreen
void TitleMenu::movesOnscreen()
{

}