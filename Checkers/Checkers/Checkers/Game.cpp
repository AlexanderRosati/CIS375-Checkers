#include "Game.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Description: Resets certain variables in the game class e.g., numCheckersPlayerOne,
//player'sTurn, etc.
void Game::resetGame()
{
	playersTurn = 1; //player one goes first
	numCheckersPlayerOne = 12; //player one starts off with 12 checkers
	numCheckersPlayerTwo = 12; //player two starts off with 12 checkers
	selectedChecker = -1; //no checker selected at start
	possibleLandingPositions.clear(); //no landing positions at start of game
	numCheckersPlayerOneLabel.setString("P1: " + std::to_string(numCheckersPlayerOne)); //P1 starts off with 12 checkers
	numCheckersPlayerTwoLabel.setString("P2: " + std::to_string(numCheckersPlayerTwo)); //P2 starts off with 12 checkers
	playerXsTurnLabel.setString("Player 1's Turn"); //player one starts off
}

//Description: Constructor for Game class
Game::Game(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//local vars
	float x = 20;
	float y = 20;
	int row;
	int col;

	//keep reference for sound board
	soundBoard = refToSoundBoard;

	//keep reference to game window
	window = refToWindow;

	//player one goes first
	playersTurn = 1;

	//both players start with 12 checkers
	numCheckersPlayerOne = 12;
	numCheckersPlayerTwo = 12;

	//no checker selected at start
	selectedChecker = -1;

	//create a square for each space
	for (int i = 0; i < 32; ++i)
	{
		//determine row and col of space
		row = i / 4;
		col = i % 4;

		//addjust for alternating rows
		if ((row % 2) == 0)
		{
			x += 50.0;
		}

		//adjust for column
		x += (col * 100.0);

		//adjust for row
		y += (row * 50.0);

		//set size
		boardSpaces[i].setSize(sf::Vector2f(50.0, 50.0));

		//set position
		boardSpaces[i].setPosition(sf::Vector2f(x, y));

		//reset coordinates
		x = 20.0;
		y = 20.0;
	}

	//load super mario font
	if (!superMarioFont.loadFromFile("../../FONTS/SuperMario256.ttf"))
	{
		std::cout << "Did not load Super Mario Font. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	//initialize landing position marker
	landingPositionMarker.setFont(superMarioFont);
	landingPositionMarker.setString("m");
	landingPositionMarker.setCharacterSize(36);
	landingPositionMarker.setPosition(sf::Vector2f(24.0, 20.0));

	//initialize labels
	//'checkers'
	numCheckersLabel.setString("checkers");
	numCheckersLabel.setCharacterSize(24);
	numCheckersLabel.setFont(superMarioFont);
	numCheckersLabel.setStyle(sf::Text::Underlined);
	numCheckersLabel.setColor(sf::Color(255, 0, 0));

	//'p1: x1'
	numCheckersPlayerOneLabel.setString("p1: " + std::to_string(numCheckersPlayerOne));
	numCheckersPlayerOneLabel.setCharacterSize(24);
	numCheckersPlayerOneLabel.setFont(superMarioFont);

	//'p2':
	numCheckersPlayerTwoLabel.setString("p2: " + std::to_string(numCheckersPlayerTwo));
	numCheckersPlayerTwoLabel.setCharacterSize(24);
	numCheckersPlayerTwoLabel.setFont(superMarioFont);

	//'colors'
	colorsLabel.setString("colors: ");
	colorsLabel.setCharacterSize(24);
	colorsLabel.setFont(superMarioFont);
	colorsLabel.setStyle(sf::Text::Underlined);
	colorsLabel.setColor(sf::Color(255, 0, 0));

	//'P1'
	colorPlayerOneLabel.setString("P1");
	colorPlayerOneLabel.setCharacterSize(24);
	colorPlayerOneLabel.setFont(superMarioFont);

	//'P2'
	colorPlayerTwoLabel.setString("P2");
	colorPlayerTwoLabel.setCharacterSize(24);
	colorPlayerTwoLabel.setFont(superMarioFont);

	//'Player X's Turn'
	playerXsTurnLabel.setString("Player 1's Turn");
	playerXsTurnLabel.setCharacterSize(24);
	playerXsTurnLabel.setFont(superMarioFont);
	playerXsTurnLabel.setCharacterSize(48);

	//put everything into position
	numCheckersLabel.setPosition(sf::Vector2f(440.0, 20.0)); //'checkers'
	numCheckersPlayerOneLabel.setPosition(sf::Vector2f(440.0, 50.0)); //'p1: x1'
	numCheckersPlayerTwoLabel.setPosition(sf::Vector2f(440.0, 80.0)); //'p2: x2'
	colorsLabel.setPosition(sf::Vector2f(440.0, 140.0)); //'colors'
	colorPlayerOneLabel.setPosition(sf::Vector2f(440.0, 190.0)); //'p1'
	colorPlayerTwoLabel.setPosition(sf::Vector2f(440.0, 250.0)); //'p2'
	playerXsTurnLabel.setPosition(sf::Vector2f(20.0, 460.0)); //'Player X's Turn'
}

//Description: Move all 32 rectangles offscreen so that user is no longer
//able to click them.
void Game::moveBoardSpacesOffscreen()
{

}

//Description: Move all 32 rectangles on screen in position so that user can click them
void Game::moveBoardSpacesOnscreen()
{

}

//Desciption: Draw game screen.
void Game::drawGame()
{
	//local vars
	float x = 23.0;
	float y = 20.0;
	int row;
	int col;
	int spaceNum;

	window->draw(numCheckersLabel); //draw 'checkers' label
	window->draw(numCheckersPlayerOneLabel); //draw 'P1: X1'
	window->draw(numCheckersPlayerTwoLabel); //draw 'P2: X2'
	window->draw(colorsLabel); //'colors'
	window->draw(colorPlayerOneLabel); //'p1'
	window->draw(colorPlayerTwoLabel); //'p2'
	window->draw(playerXsTurnLabel); //'Player X's Turn'
	
	//draw 'm's on board to signify where piece can be moved
	for (int i = 0; i < possibleLandingPositions.size(); ++i)
	{
		spaceNum = possibleLandingPositions.at(i); //get space number
		row = spaceNum / 4; //get row of space number
		col = spaceNum % 4; //get col of space number

		//adjust for alternating rows
		if (row % 2 == 0)
		{
			x += 50.0;
		}

		x += (col * 100.0); //adjust for column
		y += (row * 50.0); //adjust for row

		landingPositionMarker.setPosition(sf::Vector2f(x, y)); //put marker in position
		window->draw(landingPositionMarker); //draw maker on possible landing spot

		x = 23.0; //reset x coordinate
		y = 20.0; //reset y coordinate
	}
}