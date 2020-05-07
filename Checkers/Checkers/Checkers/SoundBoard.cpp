#include "SoundBoard.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>
#include <string>

//Description: Constructor
SoundBoard::SoundBoard()
{
	//load sound effect for moving checker into memory
	if (!soundBuffers[0].loadFromFile("../../SOUND/checker-move.wav"))
	{
		std::cout << "Did not load checker-move.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[0].setBuffer(soundBuffers[0]);

	//load sound effect for clicking buttons into memory
	if (!soundBuffers[1].loadFromFile("../../SOUND/click.wav"))
	{
		std::cout << "Did not load click.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[1].setBuffer(soundBuffers[1]);

	//load sound effect that plays when a checker is kinged
	if (!soundBuffers[2].loadFromFile("../../SOUND/kinged.wav"))
	{
		std::cout << "Did not load kinged.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[2].setBuffer(soundBuffers[2]);

	//load sound effect that plays when you go to title
	if (!soundBuffers[3].loadFromFile("../../SOUND/letsa-play.wav"))
	{
		std::cout << "Did not load letsa-play.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[3].setBuffer(soundBuffers[3]);

	//load sound effect that plays when player advances tutorial
	if (!soundBuffers[4].loadFromFile("../../SOUND/page-turn.wav"))
	{
		std::cout << "Did not load page-turn.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[4].setBuffer(soundBuffers[4]);

	//load end game sound effect
	if (!soundBuffers[5].loadFromFile("../../SOUND/victory.wav"))
	{
		std::cout << "Did not load victory.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[5].setBuffer(soundBuffers[5]);

	//load sound effect that plays when the player makes an invalid move
	if (!soundBuffers[6].loadFromFile("../../SOUND/wrong.wav"))
	{
		std::cout << "Did not load wrong.wav" << std::endl;
		system("pause");
		exit(-1);
	}

	soundEffects[6].setBuffer(soundBuffers[6]);
}

//Description: Plays the .wav file whose name you hand it
//Precondition: must hand name of file that is in SOUND folder
void SoundBoard::play(std::string soundEffect)
{
	//play checker-move.wav
	if (soundEffect == "checker-move")
	{
		soundEffects[0].play();
	}

	//play click.wav
	else if (soundEffect == "click")
	{
		soundEffects[1].play();
	}

	//play kinged.wav
	else if (soundEffect == "kinged")
	{
		soundEffects[2].play();
	}

	//play letsa-play.wav
	else if (soundEffect == "letsa-play")
	{
		soundEffects[3].play();
	}

	//play page-turn.wav
	else if (soundEffect == "page-turn")
	{
		soundEffects[4].play();
	}

	//play victory.wav
	else if (soundEffect == "victory")
	{
		soundEffects[5].play();
	}

	//play wrong.wav
	else if (soundEffect == "wrong")
	{
		soundEffects[6].play();
	}

	//default
	else
	{
		std::cout << "Error: '" << soundEffect << ".wav' is not in SOUND directory. Terminatring program." << std::endl;
		system("pause");
		exit(-1);
	}
}