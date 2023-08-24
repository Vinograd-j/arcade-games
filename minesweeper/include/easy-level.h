#pragma once

#include "level.h"

namespace Minesweeper
{

	class EasyLevel : public Level
	{

	public:

		explicit EasyLevel() : Level(15, 15, 15, sf::Vector2f(50,50), sf::VideoMode(900, 900)) {}

	};

}