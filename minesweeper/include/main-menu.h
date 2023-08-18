#pragma once
#include "menu.h"

namespace Minesweeper
{

	class MainMenu
	{

	private:

		ArcadeGame::Menu _menu;

		sf::Font _textFont;

		unsigned int _textSize;

		sf::VideoMode _windowSize;

		sf::Vector2f _buttonSize;

		sf::Text* _easyButtonText{};
		sf::Text* _normalButtonText{};
		sf::Text* _hardButtonText{};

	public:

		explicit MainMenu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize,
				const sf::Font& textFont);

		void Open();

	private:

		void Initialize();

		void OnEasyLevelChosen() const;

		void OnNormalLevelChosen() const;

		void OnHardLevelChosen() const;

		void CreateTexts();
		void CreateButtons();

	public:

		~MainMenu();

	};

}