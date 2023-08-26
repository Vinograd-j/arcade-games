#include "main-menu.h"

int main()
{
	sf::Font font;

	if (!font.loadFromFile("resources/font/rubik-spray.ttf"))
		throw std::logic_error("Can`t load font rubik-spray");

	MainMenu(font).Open();

}