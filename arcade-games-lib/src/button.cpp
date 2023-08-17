#include "button.h"

#include <utility>

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position)  : _size(size), _position(position)
{
	_button.setSize(_size);
	_button.setPosition(_position);
}

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, sf::Text  text, const sf::Color& color) : _size(size), _position(position), _buttonText(std::move(text))
{
	_button.setSize(_size);
	_button.setPosition(_position);
	_button.setFillColor(color);
	SetText(_buttonText);
}

void Button::SetText(const sf::Text& text)
{
	_buttonText = text;
	CenterText();
}

void Button::SetColor(const sf::Color& color)
{
	_button.setFillColor(color);
}

void Button::Resize(const sf::Vector2f& size)
{
	_button.setSize(size);
	CenterText();
}

void Button::SetPosition(const sf::Vector2f& position)
{
	_button.setPosition(position);
	CenterText();
}

void Button::CenterText()
{
	sf::Vector2f centerPosition(_button.getPosition().x + _button.getSize().x / 2, _button.getPosition().y + _button.getSize().y / 2);
	auto textBounds = _buttonText.getGlobalBounds();

	_buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	_buttonText.setPosition(centerPosition);
}

bool Button::IsMouseInArea(const sf::Vector2f& mousePosition) const
{
	return _button.getGlobalBounds().contains(mousePosition) || _buttonText.getGlobalBounds().contains(mousePosition);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_button);
	target.draw(_buttonText);
}