#include "menu.h"
#include "button.h"

#include "easy_level.h"
#include "hard_level.h"
#include "normal_level.h"
#include "witch_level.h"


Menu::Menu(unsigned int textSize, sf::Vector2f buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont)
{
	Initialize(textSize, buttonSize, windowSize, textFont);
}

void Menu::Initialize(unsigned int textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont)
{

	_window.create(windowSize, "Snake", sf::Style::Titlebar | sf::Style::Close);

	sf::Text easyButtonText("Easy Level", textFont, textSize);
	sf::Text normalButtonText("Normal Level", textFont, textSize);
	sf::Text witchButtonText("Witch Level", textFont, textSize);
	sf::Text hardButtonText("Hard Level", textFont, textSize);

	easyButtonText.setFillColor(sf::Color(235, 38, 176));
	normalButtonText.setFillColor(sf::Color(235, 195, 87));
	hardButtonText.setFillColor(sf::Color(120, 28, 117));
	witchButtonText.setFillColor(sf::Color(33, 207, 111));

	float centerX = (static_cast<float>(_window.getSize().x) - buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_window.getSize().y) - buttonSize.y) / 2.f;

	_easyLevel = new Button(buttonSize, sf::Vector2f(centerX, centerY - 200), easyButtonText, sf::Color(201, 209, 180));
	_normalLevel = new Button( buttonSize, sf::Vector2f(centerX, centerY -100), normalButtonText, sf::Color(23, 138, 50));
	_hardLevel = new Button(buttonSize, sf::Vector2f(centerX, centerY), hardButtonText, sf::Color(194, 129, 25));
	_witchLevel = new Button(buttonSize, sf::Vector2f(centerX, centerY + 100), witchButtonText, sf::Color(142, 68, 227));

}

void Menu::Open() 
{
	while (_window.isOpen())
	{
		sf::Event event{};

		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();

			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{

					sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);

					sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

					if (_easyLevel->IsMouseInArea(mousePositionFloat))
						OnEasyLevelChosen();

					if (_normalLevel->IsMouseInArea(mousePositionFloat))
						OnNormalLevelChosen();

					if (_witchLevel->IsMouseInArea(mousePositionFloat))
						OnWitchLevelChosen();

					if (_hardLevel->IsMouseInArea(mousePositionFloat))
						OnHardLevelChosen();

				}
			}

			if(_window.hasFocus())
			{
				_window.clear(sf::Color(42, 51, 82));
				_window.draw(*_easyLevel);
				_window.draw(*_normalLevel);
				_window.draw(*_hardLevel);
				_window.draw(*_witchLevel);

				_window.display();
			}

		}
	}
}


void Menu::OnEasyLevelChosen() const
{
	EasyLevel(sf::Color::Black).StartGame();
}

void Menu::OnNormalLevelChosen() const 
{
	NormalLevel(sf::Color(4, 14, 64)).StartGame();
}

void Menu::OnHardLevelChosen() const
{
	HardLevel(sf::Color(20, 56, 29)).StartGame();
}

void Menu::OnWitchLevelChosen() const
{
	WitchLevel(sf::Color(57, 7, 79)).StartGame();
}


Menu::~Menu()
{
	delete _easyLevel;
	delete _normalLevel;
	delete _hardLevel;
	delete _witchLevel;
}