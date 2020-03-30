#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Board.h"
#include "CustomizationMenu.h"
#include "Game.h"
#include "MusicSelectionMenu.h"
#include "SoundBoard.h"
#include "TitleMenu.h"
#include "Tutorial.h"
#include "VictoryScreen.h"

//prototypes
void gameLoop();

//enum
enum Screen { GameScreen, CustomizationScreen, MusicSelectionScreen, TitleScreen, TutorialScreen, Victory };

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
	Screen whatsDisplaying = TitleScreen; //keep track of which screen is displaying
	CustomizationMenu customizationMenu; //customization menu object
	Game game; //object for game screen
	MusicSelectionMenu musicSelectionMenu; //object for music selection menu
	SoundBoard soundBoard; //contains all sound objects
	TitleMenu titleMenu; //object for title menu
	Tutorial tutorial; //object for tutorial
	VictoryScreen victoryScreen; //object for victory screen


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

		//draw game
		switch (whatsDisplaying)
		{
			//draw game screen
			case GameScreen:
				game.drawGame();
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