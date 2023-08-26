#include "level.h"
#include "../../minesweeper/include/level.h"
#include "level-window.h"

SnakeGame::Level::Level(const sf::Color& backgroundColor, int snakeSpeed) : SNAKE_SPEED(snakeSpeed), _isSnakeMoving(true), _backgroundColor(backgroundColor)
{
	InitializeLevel();
}

SnakeGame::Level::Level(const sf::Color& backgroundColor) : _isSnakeMoving(true), _backgroundColor(backgroundColor)
{
	InitializeLevel();
}

void SnakeGame::Level::InitializeLevel()
{

	sf::Color foodColor(138, 7, 27);
	sf::Color snakeColor(113, 128, 124);

	constexpr float snakeSize = 25.f;
	constexpr float foodSize = 25.f;
	constexpr float fieldThickness = 25.f;

	sf::VideoMode windowSize = sf::VideoMode::getDesktopMode();
	sf::Vector2f centerPosition(static_cast<float>(windowSize.width) / 2.f, static_cast<float>(windowSize.height) / 2.f);

	float fieldWidth = std::floor((static_cast<float>(windowSize.width) * 0.9f) / snakeSize) * snakeSize;
	float fieldHeight = std::floor((static_cast<float>(windowSize.height) * 0.9f) / snakeSize) * snakeSize;
	sf::Vector2f fieldSize(fieldWidth, fieldHeight);

	sf::Vector2f outlineTopLeft = centerPosition - (fieldSize / 2.f);
	sf::Vector2f snakePosition = outlineTopLeft + sf::Vector2f(fieldThickness, fieldThickness);

	_snake = new Snake(snakeSize, snakePosition, snakeColor);
	_food = new Food(centerPosition, foodSize, foodColor);

	_field = new Field(fieldSize, fieldThickness, windowSize, _snake, _food);

}


void SnakeGame::Level::StartGame()
{

	sf::Thread movingThread([&] {
		StartMovingSnake();
	});

	LevelWindow(_snake, _food, _field, _backgroundColor, _isSnakeMoving, sf::VideoMode::getDesktopMode(), movingThread).Open();
}

void SnakeGame::Level::StartMovingSnake()
{

	while (_isSnakeMoving)
	{
		if (!_field->TryMoveSnake())
		{
			_isSnakeMoving = false;

			break;
		}

		Sleep(1000 / SNAKE_SPEED);
	}
}

SnakeGame::Level::~Level()
{
	delete _food;
	delete _snake;
	delete _field;
}

