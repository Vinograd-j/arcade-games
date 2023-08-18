#pragma once

#include "button.h"
#include "menu.h"

namespace SnakeGame{

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
		sf::Text* _witchButtonText{};

	public:

		explicit MainMenu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize,
				const sf::Font& textFont);

		void Open();
		void Close();

		~MainMenu();

	private:

		void Initialize();

		void CreateTexts();
		void CreateButtons();

		void OnEasyLevelChosen() const;

		void OnNormalLevelChosen() const;

		void OnHardLevelChosen() const;

		void OnWitchLevelChosen() const;

	};

}