#pragma once
#include "level.h"

namespace SnakeGame
{

	class WitchLevel final : public Level
	{

	private:

		const int START_SPEED = 5;

	public:

		explicit WitchLevel(const sf::Color& backgroundColor) : Level(backgroundColor)
		{
		}

	private:

		void StartMovingSnake() override;

	};

}