#pragma once
#include "menu.h"
#include "minesweeper-game-menu.h"
#include "snake-main-menu.h"


class MainMenu
{

private:

	ArcadeGame::Menu* _menu;

	sf::Font _textFont;

	unsigned int _textSize;

	sf::VideoMode _windowSize;

	sf::Vector2f _buttonSize;

	sf::Text _snakeButtonText;
	sf::Text _minesweeperButtonText;

	class SnakeMenu* _snakeMenu;
	class MinesweeperMenu* _minesweeperMenu;

public:

	explicit MainMenu(const sf::Font& textFont);

	void Open();
	void Close();

	~MainMenu();

private:

	void Initialize();

	void CreateTexts();
	void CreateButtons();

	void OnSnakeGameChosen();

	void OnMinesweeperChanged();

};