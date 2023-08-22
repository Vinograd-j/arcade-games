#include "level.h"
#include "random.h"
#include "level-window.h"

Minesweeper::Level::Level(size_t cellsHeight, size_t cellsWidth, size_t bombChance) : _cellsHeight(cellsHeight), _cellsWidth(cellsWidth), _bombChance(bombChance), _windowSize(900, 900),
																					  _cellSize(50, 50)
{
	Initialize();
}

void Minesweeper::Level::Initialize()
{
	CreateLevel();
}

void Minesweeper::Level::StartGame()
{
	LevelWindow window(_level, _windowSize);
	window.Open();
}

void Minesweeper::Level::CreateLevel()
{
	_level.resize(_cellsHeight);

	for (size_t i = 0; i < _cellsHeight; ++i)
	{
		_level[i].resize(_cellsWidth, Cell(sf::Vector2f(), false));
	}

	Random random;

	float startX = (_windowSize.width - (_cellsWidth * _cellSize.x + (_cellsWidth - 1) * 10)) / 2;
	float startY = (_windowSize.height - (_cellsHeight * _cellSize.y + (_cellsHeight - 1) * 10)) / 2;

	for (size_t i = 0; i < _cellsHeight; ++i)
	{
		for (size_t j = 0; j < _cellsWidth; ++j)
		{
			double randomValue = random.GenerateRandomDouble(0.0, 1.0);

			randomValue <= static_cast<float>(_bombChance / 100.f) ? _level[i][j] = Cell(_cellSize, true) : _level[i][j] = Cell(_cellSize, false);

			float cellX = startX + j * (_cellSize.x + 10);
			float cellY = startY + i * (_cellSize.y + 10);

			_level[i][j].SetPosition(sf::Vector2f(cellX, cellY));

		}
	}

	SetNeighborBombsCount();
}

void Minesweeper::Level::SetNeighborBombsCount()
{

	for (size_t i = 0; i < _cellsHeight; ++i)
	{
		for (size_t j = 0; j < _cellsWidth; ++j)
		{

			int bombsCount = 0;

			for (int k = -1; k <= 1; ++k)
			{
				for (int l = -1; l <= 1; ++l)
				{

					int nk = i + k;
					int nl = j + l;

					if (nk >= 0 && nk < _cellsHeight && nl >= 0 && nl < _cellsWidth && _level[nk][nl].IsBomb())
						bombsCount++;
				}
			}

			_level[i][j].SetNeighborMinesCount(bombsCount);
		}
	}

}
