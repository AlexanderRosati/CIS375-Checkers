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

	//get bounds
	sf::FloatRect playGameButtonBounds = titleMenu.playGameButton.getGlobalBounds(); //get rect for play game button
	sf::FloatRect customizationButtonBounds = titleMenu.customizationsButton.getGlobalBounds(); //get rect for customization button
	sf::FloatRect musicSelectionButtonBounds = titleMenu.musicSelectionButton.getGlobalBounds(); //get rect for customization button
	sf::FloatRect tutorialButtonBounds = titleMenu.tutorialButton.getGlobalBounds(); //get rect for customization button
	sf::FloatRect leftArrowBounds = musicSelectionMenu.leftArrow.getGlobalBounds(); //get rect for left arrow
	sf::FloatRect rightArrowBounds = musicSelectionMenu.rightArrow.getGlobalBounds(); //get rect for right arrow
	sf::FloatRect backButtonMusicSelectionMenuBounds = musicSelectionMenu.backToTitleScreen.getGlobalBounds(); //get rect for back button on music selection menu
	sf::FloatRect backButtonCustMenuBounds = customizationMenu.backToTitleButton.getGlobalBounds(); //get rect for back button in customization menu
	sf::FloatRect custButtonBounds[4]; //array full of bounds for cust buttons
	for (int i = 0; i < 4; ++i) custButtonBounds[i] = customizationMenu.customizations[i].getGlobalBounds(); //getting bounds for cust buttons

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
		//world coordinates of mouse
		sf::Vector2f mouseCoord = window.mapPixelToCoords(sf::Mouse::getPosition(window));

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
								
								//if click back button
								if (backButtonCustMenuBounds.contains(mouseCoord))
								{
									soundBoard.play("click");
									whatsDisplaying = TitleScreen;
								}

								//click on cust1 button
								else if (customizationMenu.currCustomization != 0 && custButtonBounds[0].contains(mouseCoord))
								{
									//change to customization 1
									customizationMenu.changeCustomization(&board, 1);
								}

								//click on cust2 button
								else if (customizationMenu.currCustomization != 1 && custButtonBounds[1].contains(mouseCoord))
								{
									//change to customization 2
									customizationMenu.changeCustomization(&board, 2);
								}

								//click on cust3 button
								else if (customizationMenu.currCustomization != 2 && custButtonBounds[2].contains(mouseCoord))
								{
									//change to customization 3
									customizationMenu.changeCustomization(&board, 3);
								}

								//click on cust4 button
								else if (customizationMenu.currCustomization != 3 && custButtonBounds[3].contains(mouseCoord))
								{
									//change to customization 4
									customizationMenu.changeCustomization(&board, 4);
								}

								break;

							//events for music selection screen
							case MusicSelectionScreen:
								
								//click left arrow
								if (leftArrowBounds.contains(mouseCoord))
								{
									musicSelectionMenu.goPrevSong();
									soundBoard.play("click");
								}

								//click right arrow
								else if (rightArrowBounds.contains(mouseCoord))
								{
									musicSelectionMenu.goNextSong();
									soundBoard.play("click");
								}

								//click back button
								else if (backButtonMusicSelectionMenuBounds.contains(mouseCoord))
								{
									soundBoard.play("click");
									whatsDisplaying = TitleScreen;
								}

								break;

							//events for title screen
							case TitleScreen:
								
								//if play game button is clicked
								if (playGameButtonBounds.contains(mouseCoord))
								{
									whatsDisplaying = GameScreen;
									soundBoard.play("click");
								}

								//if customization button is clicked
								else if (customizationButtonBounds.contains(mouseCoord))
								{
									whatsDisplaying = CustomizationScreen;
									soundBoard.play("click");
								}

								//if music selection button is clicked
								else if (musicSelectionButtonBounds.contains(mouseCoord))
								{
									whatsDisplaying = MusicSelectionScreen;
									soundBoard.play("click");
								}

								//if tutorial button is clicked
								else if (tutorialButtonBounds.contains(mouseCoord))
								{
									whatsDisplaying = TutorialScreen;
									soundBoard.play("click");
								}

								break;

							//events for tutorial
							case TutorialScreen:
								
								//go to next slide or back to title if at end
								if (tutorial.nextSlide()) whatsDisplaying = TitleScreen;

								break;

							//events for victory screen
							case Victory:

								break;
						}
					}
			}
		}

		//for hovering over sprites
		switch (whatsDisplaying)
		{
			case TitleScreen:

				//determine if mouse is inside play game button
				bool insidePlayGame = playGameButtonBounds.contains(mouseCoord);

				//determine if mouse is inside customization button
				bool insideCustomizations = customizationButtonBounds.contains(mouseCoord);

				//determine if mouse is inside music selection button
				bool insideMusicSelection = musicSelectionButtonBounds.contains(mouseCoord);

				//determine if mouse is inside tutorial button
				bool insideTutorial = tutorialButtonBounds.contains(mouseCoord);

				//if enter play game button start drawing mario head next to it
				if (titleMenu.selection != TitleMenu::Selection::PlayGame && insidePlayGame)
				{
					titleMenu.selection = TitleMenu::Selection::PlayGame;
					titleMenu.marioHead.setPosition(sf::Vector2f(25.0, 195.0));
				}

				//if enter customization button start drawing mario head next to it
				else if (titleMenu.selection != TitleMenu::Selection::Customizations && insideCustomizations)
				{
					titleMenu.selection = TitleMenu::Selection::Customizations;
					titleMenu.marioHead.setPosition(sf::Vector2f(25.0, 295.0));
				}

				//if enter music selection button start drawing mario head next to it
				else if (titleMenu.selection != TitleMenu::Selection::MusicSelection && insideMusicSelection)
				{
					titleMenu.selection = TitleMenu::Selection::MusicSelection;
					titleMenu.marioHead.setPosition(sf::Vector2f(25.0, 395.0));
				}

				//if enter tutorial button start drawing mario head next to it
				else if (titleMenu.selection != TitleMenu::Selection::Tutorial && insideTutorial)
				{
					titleMenu.selection = TitleMenu::Selection::Tutorial;
					titleMenu.marioHead.setPosition(sf::Vector2f(25.0, 490.0));
				}

				//if outside of all buttons
				else if (titleMenu.selection != TitleMenu::Selection::Nothing && !insidePlayGame && !insideCustomizations && 
					!insideMusicSelection && !insideTutorial)
				{
					titleMenu.selection = TitleMenu::Selection::Nothing;
				}

				break;
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