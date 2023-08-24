#pragma once

#include "level.h"

namespace Minesweeper
{

	class NormalLevel : public Level
	{

	public:

		explicit NormalLevel() : Level(20, 20, 25, sf::Vector2f(35,35), sf::VideoMode(900, 900)) {}

	};

}