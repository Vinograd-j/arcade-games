#include "snake.h"

SnakeGame::Snake::Snake(float partSize, const sf::Vector2f& startPosition, const sf::Color& color) : _partSize(sf::Vector2f(partSize, partSize)), _color(color), _direction(SnakeGame::Direction::RIGHT)
{

	sf::RectangleShape head;

	head.setSize(_partSize);
	head.setFillColor(_color);
	head.setPosition(startPosition);

	_parts.push_back(head);

}

void SnakeGame::Snake::Grow()
{
	_parts.push_back(CreateNewPart());
}

bool SnakeGame::Snake::CanMove() const
{
	return std::ranges::all_of(_parts, [&](const auto& part)
	{
		return part.getPosition() != GetNextPartCoords();
	});
}

void SnakeGame::Snake::Move()
{
	for (size_t i = 0; i < _parts.size() - 1; i++)
		_parts[i] = _parts[i + 1];

	_parts[_parts.size() - 1] = CreateNewPart();
}

sf::Vector2f SnakeGame::Snake::GetNextPartCoords() const
{

	auto head = _parts.back();

	sf::Vector2f headPosition = head.getPosition();
	sf::Vector2f headSize = head.getSize();


	switch (_direction)
	{

	case SnakeGame::Direction::UP:
		return { headPosition.x, headPosition.y - headSize.y };

	case SnakeGame::Direction::DOWN:
		return  { headPosition.x, headPosition.y + headSize.y };

	case SnakeGame::Direction::LEFT:
		return { headPosition.x - headSize.x, headPosition.y };

	case SnakeGame::Direction::RIGHT:
		return { headPosition.x + headSize.x, headPosition.y };
	}


	return {};
}

sf::RectangleShape SnakeGame::Snake::CreateNewPart() const
{
	sf::RectangleShape part;

	part.setSize(_partSize);
	part.setFillColor(_color);
	part.setPosition(GetNextPartCoords());

	return part;
}

