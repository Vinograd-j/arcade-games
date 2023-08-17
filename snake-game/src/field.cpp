#include "field.h"


Field::Field(const sf::Vector2f& fieldSize, float outlineThickness, const sf::VideoMode& windowSize, Snake* snake, Food* food) : _snake(snake), _food(food),
                                                                                                                                 _size(fieldSize), _outlineThickness(outlineThickness)
{
	InitializeField(windowSize);
}

bool Field::TryMoveSnake()
{

	const std::lock_guard lock(_lockObject);

	if (!_snake->CanMove())
		return false;

	auto nextPart = _snake->GetNextPartCoords();

	auto frameBounds = _border.getGlobalBounds();

	if (!frameBounds.contains(nextPart))
		return false;

	sf::FloatRect foodRect(_food->GetPoint(), _food->GetSize());
	sf::FloatRect snakeHeadRect(sf::Vector2f(nextPart.x, nextPart.y), _snake->GetSize());

	if (snakeHeadRect.intersects(foodRect))
	{
		_snake->Grow();

		bool spawnFoodResult = TrySpawnFood();

		if (!spawnFoodResult)
			return false;

	}else
	{
		_snake->Move();
	}

	return true;
}

bool Field::TrySpawnFood()
{

	auto foodSize = _food->GetSize();
	
	auto fieldBounds = _field.getGlobalBounds();

	std::vector<sf::Vector2f> points;
	
	for (float y = fieldBounds.top + _outlineThickness; y + foodSize.y <= fieldBounds.top + fieldBounds.height - _outlineThickness; y += foodSize.y)
	{

		for (float x = fieldBounds.left + _outlineThickness; x + foodSize.x <= fieldBounds.left + fieldBounds.width - _outlineThickness; x += foodSize.x) 
		{
			points.emplace_back(x, y);
		}

	}

	if (points.empty())
		return false;

	Random random;

	size_t randomPoint = random.GenerateRandomLong(0, points.size() - 1);

	_food->ChangePosition(points[randomPoint]);

	return true;
}

void Field::ChangeSnakeDirection(const Direction& direction)
{
	const std::lock_guard lock(_lockObject);

	_snake->ChangeDirection(direction);
}

void Field::InitializeField(const sf::VideoMode& windowSize)
{
	_field.setSize(_size);
	_field.setOrigin(_size / 2.f);
	_field.setPosition(static_cast<float>(windowSize.width) / 2.f, static_cast<float>(windowSize.height) / 2.f);
	_field.setFillColor(sf::Color::Transparent);
	_field.setOutlineThickness(_outlineThickness);
	_field.setOutlineColor(sf::Color(87, 16, 25));

	sf::Vector2f frameSize = sf::Vector2f(_size.x - _outlineThickness, _size.y - _outlineThickness);

	_border.setSize(frameSize);
	_border.setOrigin(frameSize / 2.f);
	_border.setFillColor(sf::Color::Transparent);
	_border.setOutlineThickness(_outlineThickness / 2);
	_border.setPosition(static_cast<float>(windowSize.width) / 2.f, static_cast<float>(windowSize.height) / 2.f);

}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	auto snakeParts = _snake->GetParts();

	target.draw(_field);

	for (const auto& part : snakeParts)
		target.draw(part);

	target.draw(_food->GetFood());

}
