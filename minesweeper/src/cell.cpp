#include <SFML/Graphics/Text.hpp>
#include "cell.h"

Minesweeper::Cell::Cell(const sf::Vector2f size, bool isBomb) : _cell(size), _isBomb(isBomb), _state(CellState::HIDDEN), _neighborMinesCount(0)
{
	_cell.setFillColor(sf::Color::White);
}

void Minesweeper::Cell::Reveal()
{
	_state = CellState::REVEALED;

	if (_isBomb)
	{
		_cell.setFillColor(sf::Color::Red);
	}
	else
	{
		_cell.setFillColor(sf::Color::Green);
		SetNeighborCountTest();
	}


}

void Minesweeper::Cell::ToggleFlag()
{
	_state = CellState::FLAGGED;
	_cell.setFillColor(sf::Color::Blue);
}

void Minesweeper::Cell::SetPosition(const sf::Vector2f& position)
{
	_cell.setPosition(position);
}

bool Minesweeper::Cell::IsMouseInArea(const sf::Vector2f& mousePosition) const
{
	return _cell.getGlobalBounds().contains(mousePosition);
}

void Minesweeper::Cell::SetNeighborCountTest()
{

	if(!_textFont.loadFromFile("rubik-spray.ttf"))
		throw std::logic_error("Can`t load rubik-spray font");

	_neighborCountText.setString(std::to_string(_neighborMinesCount));
	_neighborCountText.setCharacterSize(20);
	_neighborCountText.setFont(_textFont);
	_neighborCountText.setOutlineColor(sf::Color::Black);

	sf::Vector2f centerPosition(_cell.getPosition().x + _cell.getSize().x / 2, _cell.getPosition().y + _cell.getSize().y / 2);

	auto textBounds = _neighborCountText.getGlobalBounds();

	_neighborCountText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);

	_neighborCountText.setPosition(centerPosition);

}

void Minesweeper::Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_cell);
	target.draw(_neighborCountText);
}


