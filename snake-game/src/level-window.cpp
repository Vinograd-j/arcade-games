#include "level-window.h"
#include "Windows.h"
#include "json_config.h"

void SnakeGame::LevelWindow::Open()
{

	_window.create(_windowSize, "SnakeGame", sf::Style::Titlebar | sf::Style::Close);
	_window.setFramerateLimit(100);

	Config config = JsonConfig().ParseFromConfigFile();

	ArcadeGame::Sound lostSound(config.GetLostSoundPath());

	_movingThread.launch();

	while (_window.isOpen())
	{

		if (!_isSnakeMoving)
		{
			lostSound.Play();

			_movingThread.terminate();

			while (lostSound.GetStatus() == sf::Sound::Playing);

			_window.close();
		}

		sf::Event event {};

		while (_window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				_movingThread.terminate();
				_window.close();
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

		if (_window.hasFocus())
		{
			_window.clear(_backgroundColor);
			_window.draw(*_field);
			_window.display();
		}
	}
}

