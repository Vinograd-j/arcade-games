#include "food.h"

SnakeGame::Food::Food(const sf::Vector2f& position, float size, const sf::Color& color)
{
	_food.setPosition(position);
	_food.setFillColor(color);
	_food.setSize(sf::Vector2f(size, size));
}

