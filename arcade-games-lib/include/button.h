#pragma once

#include <SFML/Graphics.hpp>

namespace ArcadeGame{

	class Button final : public sf::Drawable
	{

	private:

		sf::RectangleShape _button;
		sf::Text _buttonText;

		sf::Vector2f _size;
		sf::Vector2f _position;

		sf::Clock _clock;

		std::function<void()> _onClick;

	public:

		explicit Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::function<void(void)>& onClick);

		explicit Button(const sf::Vector2f& size, const sf::Vector2f& position, sf::Text text, const sf::Color& color, const std::function<void(void)>& onClick);

		void SetText(const sf::Text& text);

		void SetColor(const sf::Color& color);

		void Resize(const sf::Vector2f& size);

		void SetPosition(const sf::Vector2f& position);

		[[nodiscard]] bool IsMouseInArea(const sf::Vector2f& mousePosition) const;

		void CenterText();

		void Invoke() const;

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	};
}