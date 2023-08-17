#pragma once
#include "field.h"

#include <atomic>
#include <thread>
#include <windows.h>

class Level
{

protected:	

	Field* _field {};

	Food* _food {};

	Snake* _snake {};

	sf::RenderWindow* _window {};

	int SNAKE_SPEED {};

	std::atomic<bool> _isSnakeMoving;

	sf::Color _backgroundColor;

public:

	explicit Level(const sf::Color& backgroundColor, int snakeSpeed);

	explicit Level(const sf::Color& backgroundColor);

	void StartGame();

	virtual ~Level();

	Level(const Level& other) = delete;
	Level(Level&& other) = delete;
	Level& operator=(const Level& other) = delete;
	Level& operator=(Level&& other) = delete;

private:

	virtual void StartMovingSnake();

	void InitializeLevel();

};

