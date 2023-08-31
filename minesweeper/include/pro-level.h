#pragma once
#include "level.h"

namespace Minesweeper
{

	class ProLevel : public Level
	{

	public:

		explicit ProLevel() : Level(10, 10, 70, sf::Vector2f(73,73), sf::VideoMode(900, 900)) {}

	};

}