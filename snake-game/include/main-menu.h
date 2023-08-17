#pragma once

#include "button.h"
#include "menu.h"

class Menu
{

private:

	ArcadeGame::Menu _menu;

public:

	explicit Menu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont);

	void Open();

private:

	void Initialize(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont);

	void OnEasyLevelChosen() const;

	void OnNormalLevelChosen() const;

	void OnHardLevelChosen() const;

	void OnWitchLevelChosen() const;

};

