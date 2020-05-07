#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "SoundBoard.h"
#include <string>

#define NUM_SOUND_EFFECTS 7

class SoundBoard
{
	public:
		sf::SoundBuffer soundBuffers[NUM_SOUND_EFFECTS]; //array full of sound buffers
		sf::Sound soundEffects[NUM_SOUND_EFFECTS]; //array full of sound effects
		SoundBoard(); //constructor
		void play(std::string);
};