#pragma once

#include "level.h"

namespace Minesweeper
{

	class EasyLevel : public Level
	{

	public:

		explicit EasyLevel() : Level(13, 13, 20, sf::Vector2f(55,55), sf::VideoMode(900, 900)) {}

	};

}