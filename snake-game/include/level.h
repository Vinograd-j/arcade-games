#pragma once
#include "field.h"

#include <atomic>
#include <thread>
#include <windows.h>

namespace SnakeGame
{

	class Level
	{

	protected:

		Field* _field{};

		Food* _food{};

		Snake* _snake{};

		int SNAKE_SPEED{};

		std::atomic<bool> _isSnakeMoving;

		sf::Color _backgroundColor;

	public:

		explicit Level(const sf::Color& backgroundColor, int snakeSpeed);

		explicit Level(const sf::Color& backgroundColor);

		void StartGame();

		virtual ~Level();

	private:

		virtual void StartMovingSnake();

		void InitializeLevel();

	};

}