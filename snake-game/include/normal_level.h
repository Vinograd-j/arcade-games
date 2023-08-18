#pragma once
#include "level.h"

namespace SnakeGame
{

	class NormalLevel final : public Level
	{

	public:

		explicit NormalLevel(const sf::Color& backgroundColor) : Level(backgroundColor, 25) {}

	};

}