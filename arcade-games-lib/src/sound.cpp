#include "sound.h"

ArcadeGame::Sound::Sound(const std::string& path) : _path(path)
{
	_buffer.loadFromFile(path);
	_sound.setBuffer(_buffer);
}

void ArcadeGame::Sound::Play()
{
	_sound.play();
}

sf::SoundSource::Status ArcadeGame::Sound::GetStatus()
{
	return _sound.getStatus();
}

