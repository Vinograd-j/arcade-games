#include "menu.h"

ArcadeGame::Menu::Menu(const sf::Color& backgroundColor, const sf::VideoMode& windowSize, const sf::String& windowTitle, sf::Uint32 style) : _backgroundColor(backgroundColor)
{
	_window.create(windowSize, windowTitle, style);
}

void ArcadeGame::Menu::AddText(const sf::Text* text)
{
	_texts.push_back(text);
}

void ArcadeGame::Menu::AddButton(const Button* button)
{
	_buttons.push_back(button);
}


void ArcadeGame::Menu::Open()
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

					for (const auto& button : _buttons)
						if(button->IsMouseInArea(mousePositionFloat))
							button->Invoke();
				}
			}

			if(_window.hasFocus())
			{

				_window.clear(_backgroundColor);

				for (const auto& button : _buttons)
					_window.draw(*button);

				for (const auto& text : _texts)
					_window.draw(*text);

				_window.display();
			}

		}
	}
}

ArcadeGame::Menu::~Menu()
{
	for (auto button : _buttons)
		delete button;

	for (auto text : _texts)
		delete text;
}