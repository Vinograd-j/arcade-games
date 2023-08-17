#pragma once

#include "button.h"

class Menu
{

private:

	Button* _easyLevel{};
	Button* _normalLevel{};
	Button* _hardLevel{};
	Button* _witchLevel{};

	sf::RenderWindow _window;

public:

	explicit Menu(unsigned int textSize, sf::Vector2f buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont);

	void Open();

	~Menu();

private:

	void Initialize(unsigned textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont);

	void OnEasyLevelChosen() const;

	void OnNormalLevelChosen() const;

	void OnHardLevelChosen() const;

	void OnWitchLevelChosen() const;

};

