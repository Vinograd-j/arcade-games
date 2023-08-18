#include "main-menu.h"

Minesweeper::MainMenu::MainMenu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont) :
		_menu(sf::Color(78, 66, 105), windowSize, "Minesweeper", sf::Style::Titlebar | sf::Style::Close),
		_textSize(textSize), _windowSize(windowSize), _textFont(textFont), _buttonSize(buttonSize)
{
	Initialize();
}

void Minesweeper::MainMenu::Initialize()
{
	CreateTexts();
	CreateButtons();
}

void Minesweeper::MainMenu::Open()
{
	_menu.Open();
}

void Minesweeper::MainMenu::Close()
{
	_menu.Close();
}

void Minesweeper::MainMenu::CreateTexts()
{
	auto* title = new sf::Text("MINESWEEPER", _textFont, 42);

	_easyButtonText = new sf::Text("Easy Level", _textFont, _textSize);
	_normalButtonText = new sf::Text("Normal Level", _textFont, _textSize);
	_hardButtonText = new sf::Text("Hard Level", _textFont, _textSize);

	_easyButtonText->setFillColor(sf::Color(235, 38, 176));
	_normalButtonText->setFillColor(sf::Color(235, 195, 87));
	_hardButtonText->setFillColor(sf::Color(120, 28, 117));

	title->setPosition(((float)_windowSize.width - title->getGlobalBounds().width) / 2, ((float)_windowSize.height - title->getGlobalBounds().height) / 2 - 250);
	title->setFillColor(sf::Color(87, 227, 59));

	_menu.AddText(title);
}


void Minesweeper::MainMenu::CreateButtons()
{

	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu.AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 100), *_easyButtonText, sf::Color(201, 209, 180), [this](){MainMenu::OnEasyLevelChosen();}));
	_menu.AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), *_normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu.AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), *_hardButtonText, sf::Color(194, 129, 25), [this](){MainMenu::OnHardLevelChosen();}));
}


void Minesweeper::MainMenu::OnEasyLevelChosen() const
{

}

void Minesweeper::MainMenu::OnNormalLevelChosen() const
{

}

void Minesweeper::MainMenu::OnHardLevelChosen() const
{

}

Minesweeper::MainMenu::~MainMenu()
{
	delete _easyButtonText;
	delete _normalButtonText;
	delete _hardButtonText;
}


