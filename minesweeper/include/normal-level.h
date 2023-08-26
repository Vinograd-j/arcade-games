#pragma once

#include "level.h"

namespace Minesweeper
{

	class NormalLevel : public Level
	{

	public:

		explicit NormalLevel() : Level(15, 15, 25, sf::Vector2f(45,45), sf::VideoMode(900, 900)) {}

	};

}