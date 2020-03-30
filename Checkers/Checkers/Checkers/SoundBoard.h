#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundBoard.h"

#define NUM_SOUND_EFFECTS 10

class SoundBoard
{
	public:
		sf::Sound soundsEffects[NUM_SOUND_EFFECTS]; //array full of sound effects
		SoundBoard(); //constructor
	private:
		SoundBoard* soundBoard; //ref to sound board
};