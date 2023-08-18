#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "direction.h"

namespace SnakeGame
{

	class Snake
	{

	private:

		std::vector<sf::RectangleShape> _parts;

		sf::Vector2f _partSize;

		sf::Color _color;

		Direction _direction;

	public:

		explicit Snake(float partSize, const sf::Vector2f& startPosition, const sf::Color& color);

	public:

		void Grow();

		[[nodiscard]] bool CanMove() const;

		void Move();

		void ChangeDirection(const Direction& direction)
		{
			_direction = direction;
		}

	public:

		[[nodiscard]] sf::Vector2f GetSize() const
		{
			return _partSize;
		}

		[[nodiscard]] const std::vector<sf::RectangleShape>& GetParts() const
		{
			return _parts;
		}

		[[nodiscard]] sf::Vector2f GetNextPartCoords() const;

	private:

		[[nodiscard]] sf::RectangleShape CreateNewPart() const;

	};

}