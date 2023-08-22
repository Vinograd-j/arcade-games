#pragma once

#include "SFML/Graphics.hpp"
#include "cell.h"
#include "Windows.h"

namespace Minesweeper
{

	class LevelWindow
	{

	private:

		sf::RenderWindow _window;

		sf::VideoMode _windowSize;

		std::vector<std::vector<Minesweeper::Cell>> _level;

	public:

		explicit LevelWindow(std::vector<std::vector<Minesweeper::Cell>>& level, const sf::VideoMode windowSize) : _level(level), _windowSize(windowSize) {}

		void Open();

	private:

		bool HandleLeftClick(const sf::Vector2f& mousePosition);

		void HandleRightClick(const sf::Vector2f& mousePosition);

		void RevealAll();

		void Draw();

	};

}