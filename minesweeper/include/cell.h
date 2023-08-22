#pragma once

#include <SFML/Graphics.hpp>

namespace Minesweeper
{

	enum class CellState
	{
		HIDDEN, REVEALED, FLAGGED
	};

	class Cell final : public sf::Drawable
	{

	private:

		CellState _state;

		bool _isBomb;

		int _neighborMinesCount;

		sf::Text _neighborCountText;

		sf::Font _textFont;

		sf::RectangleShape _cell;

	public:

		explicit Cell(const sf::Vector2f size, bool isBomb);

		void Reveal();

		void ToggleFlag();

		bool IsBomb() const { return _isBomb; };

		const CellState& GetState() const { return _state; }

		void SetPosition(const sf::Vector2f& position);

		void SetNeighborMinesCount(int count) { _neighborMinesCount = count; }

		int GetNeighborMinesCount() const { return _neighborMinesCount; }

		bool IsMouseInArea(const sf::Vector2f& mousePosition) const;

	private:

		void SetNeighborCountTest();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};

}