#include <SFML/Graphics.hpp>

#include "include/main-menu.h"

int main()
{

    sf::Font font;
    
    if (!font.loadFromFile("rubik-spray.ttf"))
        throw std::logic_error("Can`t load font rubik-spray");
    
    Menu menu(28, sf::Vector2f(240, 50), sf::VideoMode(450, 800), font);

    menu.Open();

    return 0;
 }
