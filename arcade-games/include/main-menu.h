#pragma once
#include "menu.h"

namespace Games
{

	class Menu
	{

	private:

		ArcadeGame::Menu* _menu;

		sf::Font _textFont;

		unsigned int _textSize;

		sf::VideoMode _windowSize;

		sf::Vector2f _buttonSize;

		sf::Text _snakeButtonText;
		sf::Text _minesweeperButtonText;

	public:

		explicit Menu(const sf::Font& textFont);

		void Open();
		void Close();

		~Menu();

	private:

		void Initialize();

		void CreateTexts();
		void CreateButtons();

		void OnSnakeGameChosen();

		void OnMinesweeperChanged();


	};

}