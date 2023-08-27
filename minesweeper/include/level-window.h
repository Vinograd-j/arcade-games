#pragma once

#include "SFML/Graphics.hpp"
#include "cell.h"
#include "Windows.h"
#include "SFML/Audio.hpp"
#include "sound.h"
#include "json_config.h"

namespace Minesweeper
{

	class LevelWindow
	{

	private:

		sf::RenderWindow _window;

		sf::VideoMode _windowSize;

		sf::Color _backgroundColor;

		std::vector<std::vector<Minesweeper::Cell>> _level;

		ArcadeGame::Sound _openSound;
		ArcadeGame::Sound _lostSound;
		ArcadeGame::Sound _wonSound;


	public:

		explicit LevelWindow(std::vector<std::vector<Minesweeper::Cell>>& level, const sf::VideoMode windowSize, const sf::Color backgroundColor) :
							 _level(level), _windowSize(windowSize), _backgroundColor(backgroundColor), _openSound(JsonConfig().ParseFromConfigFile().GetOpenSoundPath()),
							 _lostSound(JsonConfig().ParseFromConfigFile().GetLostSoundPath()), _wonSound(JsonConfig().ParseFromConfigFile().GetWonSoundPath()) {}

		void Open();

	private:

		bool HandleLeftClick(const sf::Vector2f& mousePosition);

		void HandleRightClick(const sf::Vector2f& mousePosition);

		void RevealAll();

		void RevealNeighbor(int i, int j);

		bool CheckWin();

		void Draw();

	};

}