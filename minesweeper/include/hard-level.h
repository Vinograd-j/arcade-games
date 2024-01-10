#pragma once

#include "level.h"

namespace Minesweeper
{

	class HardLevel : public Level
	{

	public:

		explicit HardLevel() : Level(20, 20, 0, sf::Vector2f(35,35), sf::VideoMode(900, 900)) {}

	};

}
