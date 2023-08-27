#pragma once

#include "SFML/Audio.hpp"

namespace ArcadeGame
{


	class Sound
	{

	private:

		sf::SoundBuffer _buffer;
		sf::Sound _sound;

		std::string _path;

	public:

		explicit Sound(const std::string& path);

		Sound() = default;

		void Play();

		sf::SoundSource::Status GetStatus();
	};

}