#include "CustomizationMenu.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//constructor
CustomizationMenu::CustomizationMenu(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//keep ref to sound board
	soundBoard = refToSoundBoard;

	//keep ref to game window
	window = refToWindow;

	//load texture for title of menu
	if (!textTitle.loadFromFile("../../IMAGES/customization-selection-menu/title-customization-selection-menu.png"))
	{
		std::cout << "Title image did not load. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		title.setTexture(textTitle);
	}

	//load textures for buttons
	for (int i = 0; i < 4; ++i)
	{
		if (!textCustomizations[i].loadFromFile("../../IMAGES/customization-selection-menu/customization" + std::to_string(i + 1) + "-button.png"))
		{
			std::cout << "Did not load texture for button " + std::to_string(i + 1) + ". Terminating" << std::endl;
			system("pause");
			exit(-1);
		}

		else
		{
			customizations[i].setTexture(textCustomizations[i]);
		}
	}

	//load texture for back to title button
	if (!textBackToTitleButton.loadFromFile("../../IMAGES/customization-selection-menu/back-button-customizatin-menu.png"))
	{
		std::cout << "Did not load texture for back button. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		backToTitleButton.setTexture(textBackToTitleButton);
	}

	//make three of the buttons slightly transparent
	customizations[1].setColor(sf::Color(255, 255, 255, 150));
	customizations[2].setColor(sf::Color(255, 255, 255, 150));
	customizations[3].setColor(sf::Color(255, 255, 255, 150));

	//set current customization to 1
	currCustomization = 0;

	//put customization buttons into position
	customizations[0].setPosition(sf::Vector2f(30.0, 120.0));
	customizations[1].setPosition(sf::Vector2f(160.0, 120.0));
	customizations[2].setPosition(sf::Vector2f(290.0, 120.0));
	customizations[3].setPosition(sf::Vector2f(420.0, 120.0));

	//put back to title button in position
	backToTitleButton.setPosition(sf::Vector2f(0.0, 480.0));
}

//Description: Sets textures for the following sprite objects which are data members of 
//board: playerOneCheckerImg, playerTwoCheckerImg, playerOneKingImg, playerTwoKingImg, boardImg
void CustomizationMenu::changeCustomization(Board* refToBoard, int customizationNum)
{
	//turn customization number into string
	std::string custNum = std::to_string(customizationNum);

	//create path to regular checker for player one
	std::string pathToCheckerOne = "../../IMAGES/customizations/customization" + custNum + "/player-one-checker-customization" + custNum + ".png";

	//create path to texture for regular checker for player two
	std::string pathToCheckerTwo = "../../IMAGES/customizations/customization" + custNum + "/player-two-checker-customization" + custNum + ".png";

	//create path to texture for king for player one
	std::string pathToKingOne = "../../IMAGES/customizations/customization" + custNum + "/player-one-king-customization" + custNum + ".png";

	//create path to texture for king for player two
	std::string pathToKingTwo = "../../IMAGES/customizations/customization" + custNum + "/player-two-king-customization" + custNum + ".png";

	//create path to texture for board
	std::string pathToBoard = "../../IMAGES/customizations/customization" + custNum + "/board-customization" + custNum + ".png";

	//load textures for given customization
	if (!refToBoard->texturePlayerOneChecker.loadFromFile(pathToCheckerOne))
	{
		std::cout << "Did not change texture for player one checker." << std::endl;
		system("pause");
		exit(-1);
	}

	if (!refToBoard->texturePlayerTwoChecker.loadFromFile(pathToCheckerTwo))
	{
		std::cout << "Did not change texture for player two checker." << std::endl;
		system("pause");
		exit(-1);
	}

	if (!refToBoard->texturePlayerOneKing.loadFromFile(pathToKingOne))
	{
		std::cout << "Did not change texture for player one king." << std::endl;
		system("pause");
		exit(-1);
	}

	if (!refToBoard->texturePlayerTwoKing.loadFromFile(pathToKingTwo))
	{
		std::cout << "Did not change texture for player two king." << std::endl;
		system("pause");
		exit(-1);
	}

	if (!refToBoard->textureBoard.loadFromFile(pathToBoard))
	{
		std::cout << "Did not change texture for board." << std::endl;
		system("pause");
		exit(-1);
	}

	//move selection
	moveSelection(customizationNum);

	//play click sound effect
	soundBoard->play("click");
}

//Description: Draw customization menu.
void CustomizationMenu::draw()
{
	window->draw(title); //draw title
	for (int i = 0; i < 4; ++i) window->draw(customizations[i]); //draw customization buttons
	window->draw(backToTitleButton); //draw back to title button
}

//Description: Moves 'Back to Title' button and customization images offscreen so the user
//cannot click on them. 
void CustomizationMenu::moveOffScreen()
{

}

//Description: Opposite of moveOffScreen.
void CustomizationMenu::moveOnscreen()
{

}

//Description: Make currently selected button slightly transparent and make newly selected button opaque.
void CustomizationMenu::moveSelection(int newCustomization)
{
	customizations[currCustomization].setColor(sf::Color(255, 255, 255, 150)); //make curr cust slightly transparent
	customizations[newCustomization - 1].setColor(sf::Color(255, 255, 255, 255)); //make new cust oqaue
	currCustomization = newCustomization - 1; //set curr customization to new customization
}