#pragma once

#include <SFML/Graphics.hpp>

class Button final : public sf::Drawable
{

private:

	sf::RectangleShape _button;
	sf::Text _buttonText;

	sf::Vector2f _size;
	sf::Vector2f _position;

	sf::Clock _clock;

public:

	explicit Button(const sf::Vector2f& size, const sf::Vector2f& position);

	explicit Button(const sf::Vector2f& size, const sf::Vector2f& position, sf::Text text, const sf::Color& color);

	void SetText(const sf::Text& text);

	void SetColor(const sf::Color& color);

	void Resize(const sf::Vector2f& size);

	void SetPosition(const sf::Vector2f& position);

	[[nodiscard]] bool IsMouseInArea(const sf::Vector2f& mousePosition) const;

	void CenterText();

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
