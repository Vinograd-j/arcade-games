#pragma once

#include <mutex>

#include "food.h"
#include "snake.h"
#include "random.h"
#include "direction.h"

namespace SnakeGame
{

	class Field final : public sf::Drawable
	{

	private:

		Snake* _snake{};
		Food* _food{};

		sf::RectangleShape _field;
		sf::RectangleShape _border;

		sf::Vector2f _size;

		float _outlineThickness;

		std::mutex _lockObject;

	public:

		explicit Field(const sf::Vector2f& fieldSize, float outlineThickness, const sf::VideoMode& windowSize,
				Snake* snake, Food* food);

		bool TryMoveSnake();

		bool TrySpawnFood();

		void ChangeSnakeDirection(const Direction& direction);

	private:

		void InitializeField(const sf::VideoMode& windowSize);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	};

}