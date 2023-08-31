#pragma once
#include "level.h"

namespace Minesweeper
{

	class LuckyLevel : public Level
	{

	public:

		explicit LuckyLevel() : Level(7, 7, 80, sf::Vector2f(100,100), sf::VideoMode(900, 900)) {}

	};

}