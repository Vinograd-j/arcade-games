#pragma once

#include "menu.h"
#include "main-menu.h"
#include <memory>

class MinesweeperMenu
{

private:

	ArcadeGame::Menu* _menu{};

	sf::Font _textFont;

	unsigned int _textSize;

	sf::VideoMode _windowSize;

	sf::Vector2f _buttonSize;

	sf::Text _easyButtonText{};
	sf::Text _normalButtonText{};
	sf::Text _hardButtonText{};

	sf::Text _returnButtonText{};

	class MainMenu* _mainMenu;

public:

	explicit MinesweeperMenu(const sf::Font& textFont, class MainMenu* mainMenu);

	void Open();

	void Close();
	~MinesweeperMenu();

private:

	void Initialize();

	void CreateTexts();
	void CreateButtons();

	void OnEasyLevelChosen() const;

	void OnNormalLevelChosen() const;

	void OnHardLevelChosen() const;

	void OnReturnChosen();

};
