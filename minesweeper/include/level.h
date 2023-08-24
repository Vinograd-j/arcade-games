#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "cell.h"
#include "Windows.h"

namespace Minesweeper
{

	class Level
	{

	private:

		sf::VideoMode _windowSize;

		sf::Vector2f _cellSize;

		size_t _cellsHeight;
		size_t _cellsWidth;

		size_t _bombChance;

		std::vector<std::vector<Cell>> _level;

	public:

		explicit Level(size_t cellsHeight, size_t cellsWidth, size_t bombChance, const sf::Vector2f& cellSize, const sf::VideoMode& windowSize);

		void StartGame();

	private:

		void Initialize();

		void CreateLevel();

		void SetNeighborBombsCount();

	};
}