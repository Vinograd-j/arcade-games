#pragma once

#include <SFML/Graphics.hpp>
#include <atomic>
#include "snake.h"
#include "food.h"
#include "field.h"

namespace SnakeGame
{


	class LevelWindow
	{

	private:

		sf::RenderWindow _window;

		Snake* _snake;

		Food* _food;

		Field* _field;

		sf::Color _backgroundColor;

		const std::atomic<bool>& _isSnakeMoving;

		sf::VideoMode _windowSize;

		sf::Thread& _movingThread;

	public:

		explicit LevelWindow(Snake* snake, Food* food, Field* field, const sf::Color& backgroundColor, const std::atomic<bool>& isSnakeMoving, const sf::VideoMode& windowSize, sf::Thread& movingThread) :
							_snake(snake), _food(food), _field(field), _backgroundColor(backgroundColor), _isSnakeMoving(isSnakeMoving), _windowSize(windowSize),
							_movingThread(movingThread) {}

		void Open();

	};

}