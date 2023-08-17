#include "../include/level.h"

Level::Level(const sf::Color& backgroundColor, int snakeSpeed) : SNAKE_SPEED(snakeSpeed), _isSnakeMoving(true), _backgroundColor(backgroundColor)
{
	InitializeLevel();
}

Level::Level(const sf::Color& backgroundColor) : _isSnakeMoving(true), _backgroundColor(backgroundColor)
{
	InitializeLevel();
}


void Level::InitializeLevel()
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

	_window = new sf::RenderWindow;
	_window->create(windowSize, "SnakeGame", sf::Style::Titlebar | sf::Style::Close);

	_snake = new Snake(snakeSize, snakePosition, snakeColor);
	_food = new Food(centerPosition, foodSize, foodColor);

	_field = new Field(fieldSize, fieldThickness, windowSize, _snake, _food);

}

void Level::StartGame()
{
	sf::Thread movingThread([&]
	{
		StartMovingSnake();
	});

	movingThread.launch();

	_window->setFramerateLimit(60);

	while (_window->isOpen())
	{

		sf::Event event {};

		while (_window->pollEvent(event))
		{

			if (_isSnakeMoving == false || event.type == sf::Event::Closed)
			{
				movingThread.terminate();
				_window->close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					_field->ChangeSnakeDirection(Direction::UP);
					break;

				case sf::Keyboard::Down:
					_field->ChangeSnakeDirection(Direction::DOWN);
					break;

				case sf::Keyboard::Left:
					_field->ChangeSnakeDirection(Direction::LEFT);
					break;

				case sf::Keyboard::Right:
					_field->ChangeSnakeDirection(Direction::RIGHT);
					break;

				default:;
				}

			}

		}

		if (_window->hasFocus())
		{
			_window->clear(_backgroundColor);
			_window->draw(*_field);
			_window->display();
		}
	}

}


void Level::StartMovingSnake()
{
	while (_isSnakeMoving)
	{
		if (_field->TryMoveSnake() == false)
		{
			_isSnakeMoving = false;
			break;
		}
		Sleep(1000 / SNAKE_SPEED);
	}
}

Level::~Level()
{
	delete _window;
	delete _food;
	delete _snake;
	delete _field;
}


