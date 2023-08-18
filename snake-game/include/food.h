#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{

	class Food
	{

	private:

		sf::RectangleShape _food;

	public:

		explicit Food(const sf::Vector2f& position, float size, const sf::Color& color);

		const sf::Vector2f& GetPoint() const
		{
			return _food.getPosition();
		}

		void ChangePosition(const sf::Vector2f& position)
		{
			_food.setPosition(position);
		}

		sf::Vector2f GetSize() const
		{
			return _food.getSize();
		}

		const sf::RectangleShape& GetFood() const
		{
			return _food;
		}

	};
}