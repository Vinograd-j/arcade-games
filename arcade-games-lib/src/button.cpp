#include "button.h"

#include <utility>

ArcadeGame::Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::function<void(void)>& onClick)  : _size(size), _position(position), _onClick(onClick)
{
	_button.setSize(_size);
	_button.setPosition(_position);

}

ArcadeGame::Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, sf::Text  text, const sf::Color& color, const std::function<void(void)>& onClick) : _size(size),
						   _position(position), _buttonText(std::move(text)), _onClick(onClick)
{
	_button.setSize(_size);
	_button.setPosition(_position);
	_button.setFillColor(color);
	SetText(_buttonText);
}

void ArcadeGame::Button::SetText(const sf::Text& text)
{
	_buttonText = text;
	CenterText();
}

void ArcadeGame::Button::SetColor(const sf::Color& color)
{
	_button.setFillColor(color);
}

void ArcadeGame::Button::Resize(const sf::Vector2f& size)
{
	_button.setSize(size);
	CenterText();
}

void ArcadeGame::Button::SetPosition(const sf::Vector2f& position)
{
	_button.setPosition(position);
	CenterText();
}

void ArcadeGame::Button::CenterText()
{
	sf::Vector2f centerPosition(_button.getPosition().x + _button.getSize().x / 2, _button.getPosition().y + _button.getSize().y / 2);
	auto textBounds = _buttonText.getGlobalBounds();

	_buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	_buttonText.setPosition(centerPosition);
}

bool ArcadeGame::Button::IsMouseInArea(const sf::Vector2f& mousePosition) const
{
	return _button.getGlobalBounds().contains(mousePosition) || _buttonText.getGlobalBounds().contains(mousePosition);
}

void ArcadeGame::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_button);
	target.draw(_buttonText);
}

void ArcadeGame::Button::Invoke() const
{
	_onClick();
}
