#pragma once
#include "level.h"

namespace SnakeGame
{

	class HardLevel final : public Level
	{

	public:

		explicit HardLevel(const sf::Color& backgroundColor) : Level(sf::Color(backgroundColor), 50) {}

	};

}