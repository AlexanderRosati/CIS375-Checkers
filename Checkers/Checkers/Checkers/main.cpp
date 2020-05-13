#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Board.h"
#include "CustomizationMenu.h"
#include "Game.h"
#include "MusicSelectionMenu.h"
#include "SoundBoard.h"
#include "TitleMenu.h"
#include "Tutorial.h"
#include "VictoryScreen.h"

#define BABY_BLUE sf::Color(17, 166, 236)

//prototypes
void gameLoop();
void boardClassTestDriver();

//enum
enum Screen { GameScreen, CustomizationScreen, MusicSelectionScreen, TitleScreen,
			  TutorialScreen, Victory, Nothing };

int main()
{
	gameLoop();
}

//Description: Game loop (aka Where everything happens).
void gameLoop()
{
	//vars
	sf::RenderWindow window(sf::VideoMode(600, 600), "Checkers"); //game window
	sf::Event event; //event object
	Screen whatsDisplaying; //keep track of which screen is displaying
	SoundBoard soundBoard; //contains all sound objects
	CustomizationMenu customizationMenu(&soundBoard, &window); //customization menu object
	MusicSelectionMenu musicSelectionMenu(&soundBoard, &window); //object for music selection menu
	TitleMenu titleMenu(&window, &soundBoard); //object for title menu
	Tutorial tutorial(&soundBoard, &window); //object for tutorial
	VictoryScreen victoryScreen(&soundBoard, &window); //object for victory screen
	Game game(&soundBoard, &window); //object for game screen
	Board board(&soundBoard, &window); //board object

	//rectangle that covers whole screen
	sf::RectangleShape wholeScreen;
	wholeScreen.setPosition(sf::Vector2f(0, 0));
	wholeScreen.setSize(sf::Vector2f(600, 600));
	wholeScreen.setFillColor(BABY_BLUE);

	//play sound effect for title
	soundBoard.play("letsa-play");

	//set enum
	whatsDisplaying = TitleScreen;

	//game loop; loops as long as game window is open
	while (window.isOpen())
	{
		//loops that handles all events (i.e., mouse click)
		while (window.pollEvent(event))
		{
			//types of events
			switch (event.type)
			{
				//X at top is clicked
				case sf::Event::Closed:
					window.close();
					exit(0);
					break;

				//mouse button is clicked
				case sf::Event::EventType::MouseButtonPressed:
					//its left mouse button
					if (event.key.code == sf::Mouse::Button::Left)
					{
						//break down by screen
						switch (whatsDisplaying)
						{
							//events for game screen
							case GameScreen:
							
								break;

							//events for custmoziaton screen
							case CustomizationScreen:
								
								break;

							//events for music selection screen
							case MusicSelectionScreen:
								
								break;

							//events for title screen
							case TitleScreen:
								
								break;

							//events for tutorial
							case TutorialScreen:
								
								break;

							//events for victory screen
							case Victory:

								break;
						}
					}
			}
		}

		//wipes everything off screen
		window.clear();

		//draw baby blue background
		window.draw(wholeScreen);;

		//draw game
		switch (whatsDisplaying)
		{
			//draw game screen
			case GameScreen:
				//draw board
				board.drawBoard();

				//draw interface
				game.drawGame();

				//draw checker for player one in interface
				board.playerOneCheckerImg.setPosition(sf::Vector2f(490.0, 180.0));
				window.draw(board.playerOneCheckerImg);

				//draw checker for player two in interface
				board.playerTwoCheckerImg.setPosition(sf::Vector2f(490.0, 240.0));
				window.draw(board.playerTwoCheckerImg);
				break;

			//draw customization menu
			case CustomizationScreen:
				customizationMenu.draw();
				break;

			//draw music selection screen
			case MusicSelectionScreen:
				musicSelectionMenu.draw();
				break;

			//draw title screen
			case TitleScreen:
				titleMenu.draw();
				break;

			//draw tutorial screen
			case TutorialScreen:
				tutorial.drawCurrSlide();
				break;

			//draw victory screen
			case Victory:
				victoryScreen.draw();
				break;
		}

		//push frame to screen
		window.display();
	}
}