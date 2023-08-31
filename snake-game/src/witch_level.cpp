#include "witch_level.h"


void SnakeGame::WitchLevel::StartMovingSnake()
{

	sf::Clock clock;

	int speed = START_SPEED;

	float interval = 0.5f;

	float elapsedTime = 0.0f;

	while (_isSnakeMoving)
	{

		elapsedTime += clock.restart().asSeconds();

		if (elapsedTime >= interval)
		{
			speed += 3;
			elapsedTime = 0.0f;
		}

		if (!_field->TryMoveSnake())
		{
			_isSnakeMoving = false;
			break;
		}
		Sleep(1000 / speed);
	}


}
