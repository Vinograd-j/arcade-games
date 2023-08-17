#include "../include/witch_level.h"


void WitchLevel::StartMovingSnake()
{

	sf::Clock clock;

	int speed = START_SPEED;

	float interval = 1.f;

	float elapsedTime = 0.0f;

	while (_isSnakeMoving)
	{

		elapsedTime += clock.restart().asSeconds();

		if (elapsedTime >= interval)
		{
			speed += 2;
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
