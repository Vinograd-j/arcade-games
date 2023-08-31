#pragma once
#include "level.h"

namespace SnakeGame
{

	class MadnessLevel final : public Level
	{

	public:

		explicit MadnessLevel(const sf::Color& backgroundColor) : Level(backgroundColor, 120) {}

	};

}
