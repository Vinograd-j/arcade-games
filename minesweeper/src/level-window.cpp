#include "level-window.h"
#include "../../snake-game/include/level-window.h"


void Minesweeper::LevelWindow::Open()
{

	_window.create(_windowSize, "MINESWEEPER", sf::Style::Titlebar | sf::Style::Close);

	sf::SoundBuffer openBuffer;
	sf::SoundBuffer lostBuffer;
	sf::SoundBuffer wonBuffer;

	openBuffer.loadFromFile("resources/sounds/open.wav");
	_openSound.setBuffer(openBuffer);

	lostBuffer.loadFromFile("resources/sounds/lost.wav");
	_lostSound.setBuffer(lostBuffer);

	wonBuffer.loadFromFile("resources/sounds/won.wav");
	_wonSound.setBuffer(wonBuffer);

	while (_window.isOpen())
	{

		sf::Event event{};

		while (_window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				_window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{

				sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);
				sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y));

				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					bool isGameLost = HandleLeftClick(mousePositionFloat);
					bool isWon = CheckWin();

					if (isGameLost || isWon)
					{
						isWon ? _wonSound.play() : _lostSound.play();

						RevealAll();
						Draw();
						Sleep(3000);
						_window.close();
					}

				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					HandleRightClick(mousePositionFloat);
				}
			}

			if(_window.hasFocus())
			{
				Draw();
			}


		}

	}
}

bool Minesweeper::LevelWindow::HandleLeftClick(const sf::Vector2f& mousePosition)
{

	for (size_t i = 0; i < _level.size(); ++i)
	{
		for (size_t j = 0; j < _level[i].size(); ++j)
		{
			if(_level[i][j].IsMouseInArea(mousePosition))
			{
				if(_level[i][j].GetState() == CellState::HIDDEN || _level[i][j].GetState() == CellState::FLAGGED)
				{

					_level[i][j].Reveal();

					if (!_level[i][j].IsBomb())
						_openSound.play();

					if(_level[i][j].GetNeighborMinesCount() == 0)
						RevealNeighbor(i, j);

					if(_level[i][j].IsBomb())
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void Minesweeper::LevelWindow::HandleRightClick(const sf::Vector2f& mousePosition)
{
	for (size_t i = 0; i < _level.size(); ++i)
	{
		for (size_t j = 0; j < _level[i].size(); ++j)
		{
			if(_level[i][j].IsMouseInArea(mousePosition))
			{
				if (_level[i][j].GetState() == CellState::HIDDEN)
					_level[i][j].ToggleFlag();
			}
		}
	}
}

void Minesweeper::LevelWindow::RevealAll()
{

	for (size_t i = 0; i < _level.size(); ++i)
	{
		for (size_t j = 0; j < _level[i].size(); ++j)
		{
			if (_level[i][j].GetState() == CellState::HIDDEN || _level[i][j].GetState() == CellState::FLAGGED)
			{
				_level[i][j].Reveal();
			}

		}
		Draw();
	}
	

}

void Minesweeper::LevelWindow::RevealNeighbor(int i, int j)
{

	for (int k = -1; k <= 1; ++k)
	{
		for (int l = -1; l <= 1; ++l)
		{

			int nk = i + k;
			int nl = j + l;

			if (nk >= 0 && nk < _level.size() && nl >= 0 && nl < _level[i].size() && _level[nk][nl].GetNeighborMinesCount() == 0 && _level[nk][nl].GetState() != CellState::REVEALED)
				_level[nk][nl].Reveal();
		}

	}

}

bool Minesweeper::LevelWindow::CheckWin()
{


	for (size_t i = 0; i < _level.size(); ++i)
	{
		for (size_t j = 0; j < _level[i].size(); ++j)
		{
			if(_level[i][j].GetState() != CellState::REVEALED && !_level[i][j].IsBomb())
				return false;
		}
	}

	return true;
}

void Minesweeper::LevelWindow::Draw()
{

	_window.clear(_backgroundColor);

	for (size_t i = 0; i < _level.size(); ++i)
	{
		for (size_t j = 0; j < _level[i].size(); ++j)
		{
			_window.draw(_level[i][j]);
		}
	}

	_window.display();
}
