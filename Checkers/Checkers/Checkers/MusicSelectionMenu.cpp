#include "MusicSelectionMenu.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

//Description: Stop playing current song and move to next one.
void MusicSelectionMenu:: goNextSong()
{
	//stop current song
	songs[currSong].stop();

	//go to next song
	currSong = (currSong + 1) % 3;

	//play next song
	songs[currSong].play();

	//set song name for display
	songName.setString(songNamesArr[currSong]);

	//change position of label
	songName.setPosition(labelPositions[currSong]);
}

//Description: Stop playing current song and go to previous one.
void MusicSelectionMenu::goPrevSong()
{
	//stop current song
	songs[currSong].stop();

	//go to prev song
	currSong = (currSong == 0 ? 2 : currSong - 1);

	//play prev song
	songs[currSong].play();

	//set song name for display
	songName.setString(songNamesArr[currSong]);

	//change position of label
	songName.setPosition(labelPositions[currSong]);
}

//Description: Draws music selection menu
void MusicSelectionMenu:: draw()
{
	window->draw(title); //draw title for music selection menu
	window->draw(leftArrow); //draw left arrow
	window->draw(rightArrow); //draw right arrow
	window->draw(songName); //draw song name
	window->draw(backToTitleScreen); //draw back button
}

//Description: Moves music selection menu offscreen.
void MusicSelectionMenu:: moveMenuOffScreen()
{

}

//Description: Moves music selectio menu on screen.
void MusicSelectionMenu:: moveMenuOnscreen()
{

}

//constructor
MusicSelectionMenu::MusicSelectionMenu(SoundBoard* refToSoundBoard, sf::RenderWindow* refToWindow)
{
	//keep ref to soundboard
	soundBoard = refToSoundBoard;

	//keep ref to game window for drawing 
	window = refToWindow;

	//store song names
	songNamesArr[0] = "the world was ours";
	songNamesArr[1] = "go to bed";
	songNamesArr[2] = "cold existence";

	//store positions of song names
	labelPositions[0] = sf::Vector2f(170.0, 210.0);
	labelPositions[1] = sf::Vector2f(235.0, 210.0);
	labelPositions[2] = sf::Vector2f(210.0, 210.0);

	//load texture for left arrow
	if (!textLeftArrow.loadFromFile("../../IMAGES/music-selection-menu/leftarrow.png"))
	{
		std::cout << "Texture for left arrow did not load. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		leftArrow.setTexture(textLeftArrow);
	}

	//load texture for right arrow
	if (!textRightArrow.loadFromFile("../../IMAGES/music-selection-menu/rightarrow.png"))
	{
		std::cout << "Texture for right arrow did not load. Terminating" << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		rightArrow.setTexture(textRightArrow);
	}

	//load texture for title of menu
	if (!textTitle.loadFromFile("../../IMAGES/music-selection-menu/title-music-selection-menu.png"))
	{
		std::cout << "Texture for title did not load. Terminating." << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		title.setTexture(textTitle);
	}

	//load font file
	if (!superMarioFont.loadFromFile("../../FONTS/SuperMario256.ttf"))
	{
		std::cout << "Font file did not load. Terminating." << std::endl;
	}

	//initialize text object that displays song name
	songName.setFont(superMarioFont); //set font
	songName.setString("The world was ours"); //set text
	songName.setCharacterSize(20); //set font size

	//load 'the-world-was-ours.ogg'
	if (!songs[0].openFromFile("../../SONGS/the-world-was-ours.ogg"))
	{
		std::cout << "'the-world-was-ours.ogg' did not load." << std::endl;
		system("pause");
		exit(-1);
	}

	//load 'go-to-bed.ogg'
	if (!songs[1].openFromFile("../../SONGS/go-to-bed.ogg"))
	{
		std::cout << "'go-to-bed.ogg' did not load." << std::endl;
		system("pause");
		exit(-1);
	}

	//load 'cold-existence.ogg'
	if (!songs[2].openFromFile("../../SONGS/cold-existence.ogg"))
	{
		std::cout << "'cold-existence.ogg' did not load." << std::endl;
		system("pause");
		exit(-1);
	}

	//initialize currSong
	currSong = 0;

	//load back to title screen button
	if (!textBackToTitleScreen.loadFromFile("../../IMAGES/music-selection-menu/backtotitlebutton.png"))
	{
		std::cout << "Back button for music selection menu did not load." << std::endl;
		system("pause");
		exit(-1);
	}

	else
	{
		backToTitleScreen.setTexture(textBackToTitleScreen);
	}

	//move left arrow into position
	leftArrow.setPosition(sf::Vector2f(5.0, 170.0));

	//move right arrow into position
	rightArrow.setPosition(sf::Vector2f(440.0, 170.0));

	//move text displaying song name into position
	songName.setPosition(labelPositions[0]);

	//move back button into position
	backToTitleScreen.setPosition(sf::Vector2f(0.0, 460.0));

	//make songs repeat
	songs[0].setLoop(true);
	songs[1].setLoop(true);
	songs[2].setLoop(true);

	//start playing first songs
	songs[0].play();
}