#include "Game.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Description: Resets certain variables in the game class e.g., numCheckersPlayerOne,
//player'sTurn, etc.
void Game::resetGame()
{

}

//Description: Constructor for Game class
Game::Game(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//keep reference for sound board
	soundBoard = refToSoundBoard;

	//keep reference to game window
	window = refToWindow;
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