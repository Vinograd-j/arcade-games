#pragma once

#include <SFML/Graphics.hpp>

#include "button.h"

namespace ArcadeGame{

	class Menu
	{

	private:

		std::vector<const Button*> _buttons;

		std::vector<sf::Text> _texts;

		sf::RenderWindow _window;

		sf::Color _backgroundColor;

		sf::VideoMode _windowSize;
		sf::String _windowTitle;
		sf::Uint32 _style;

	public:

		explicit Menu(const sf::Color& backgroundColor, const sf::VideoMode& windowSize, const sf::String& windowTitle, sf::Uint32 style);

		void AddButton(const Button* button);

		void AddText(const sf::Text& text);

		void Open();
		void Close();

		inline const sf::RenderWindow& GetWindow() const { return _window; };

		virtual ~Menu();

	};

}